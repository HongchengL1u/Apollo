#ifndef SPEED_QP
#define SPEED_QP

#include "QPProblem.h"
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
class SpeedPlanQPProblem: private QPProblem
{
    public:
        SpeedPlanQPProblem(int dimtime,int dimstate,int dimeq,int dimineq,double deltat);
        ~SpeedPlanQPProblem()=default;
        void set_w(vector<double> w);
        void set_endref(vector<double> endref);
        void set_cruisespeed(double vref);
        void set_siref(vector<double> siref);
        void set_startstate(vector<double> startstate);
        void set_pi(vector<double> pi);
        void set_sboundary(vector<double> sl_boundary,vector<double> su_boundary);
        void set_vajboundary(vector<vector<double>>& vaj_boundary);
        void init(void) ;
        void solve_OSQP(void);
        // void solve_ProxQP(void);
        vector<double>& get_result(void);
    private:
        double vref_;
        vector<double> w_;
        vector<double> siref_;
        bool has_siref_ = false;
        vector<double> pi_;
        bool has_pi_ = false;
        vector<double> startstate_;
        vector<double> endref_;
        bool has_end_ref_ = false;
        vector<double> s_lbound_;
        vector<double> s_ubound_;
        double vmin_ ;
        double amin_ ;
        double jmin_ ;
        double vmax_ ;
        double amax_ ;
        double jmax_ ;
        OsqpEigen::Solver solver;

};
#endif