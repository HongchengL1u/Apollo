#ifndef QP_PROBLEM
#define QP_PROBLEM

#include <iostream>
#include <Eigen/Core>
using namespace Eigen;
using namespace std;
#include "OsqpEigen/OsqpEigen.h"
// #include <proxsuite/helpers/optional.hpp> // for c++14
// #include <proxsuite/proxqp/dense/dense.hpp>
// #include <proxsuite/proxqp/sparse/sparse.hpp>

// using namespace proxsuite::proxqp;
// using proxsuite::nullopt; // c++17 simply use std::nullopt
// Q,p,A,l,u

class QPProblem
{
    public:
        
        QPProblem(int dimtime,int dimstate,int dimeq,int dimineq,double delta_t);
        ~QPProblem()=default;
        
        int dim_time_ = 0;
        int dim_state_ = 0;
        int dim_eq_ = 0;
        int dim_ineq_ = 0;
        double delta_t_ = 0;
        MatrixXd Q;
        VectorXd p;
        MatrixXd A;
        VectorXd l;
        VectorXd u;
        vector<double> result_;

};

#endif