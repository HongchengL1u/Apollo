#ifndef PATH_QP
#define PATH_QP

#include "QPProblem.h"
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
class PathPlanQPProblem: private QPProblem
{
    public:
        PathPlanQPProblem(int dimtime,int dimstate,int dimeq,int dimineq,double deltat);
        ~PathPlanQPProblem()=default;
        void init(void);
        void solve_OSQP(void);
        void set_w(vector<double> w);
        void set_wrefi(vector<double> wlrefi);
        void set_lrefi(vector<double> lrefi);
        void set_startstate(vector<double> startstate);
        void set_endref(vector<double> endref);

        void set_lbound(vector<double> l_lbound,vector<double> l_ubound);
        void set_dlbound(double dlmin,double dlmax);
        void set_ddlbound(vector<double> ddlmin,vector<double> ddlmax);
        void set_dddlbound(double dddlmin,double dddlmax);
        
        vector<double>& get_result(void);

    private:
        // wl wdl wddl wdddl wlend wdlend wddlend 
        vector<double> w_; // dim=7
        vector<double> wlrefi_; 
        vector<double> lrefi_;

        vector<double> startstate_;
        vector<double> endref_;
        bool has_endref_ = false;
        double delta_s_;

        vector<double> l_lbound_;
        vector<double> l_ubound_;

        double dlmin_; // 一般为 -2
        double dlmax_; // 一般为 2

        vector<double> ddlmin_;// Kmax - Kref
        vector<double> ddlmax_;// Kmin - Kref

        double dddlmin_;// 前轮最大转速/当前车速/汽车前后轴距
        double dddlmax_;
        vector<double> result_;
        OsqpEigen::Solver solver;

};
#endif