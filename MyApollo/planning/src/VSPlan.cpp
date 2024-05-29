#include "VSPlan.h"


int main()
{
    int dim_state = 4;
    int plan_length = 100;
    double delta_s = 0.1;
    int dim_eq = 4;
    int dim_ineq = 4;
    int N = double(plan_length)/delta_s;
    PathPlanQPProblem qp_solver(N,dim_state,dim_eq,dim_ineq,delta_s);


    vector<double> w = {1,1,1,1,1,1,1}; // wl,wdl,wddl,wdddl,wled,wdled,wddled
    qp_solver.set_w(w);
    
    // TODO
    qp_solver.set_wrefi(vector<double> wlrefi);
    qp_solver.set_lrefi(vector<double> lrefi);
    // END
    



    vector<double> startstate = {10,0,0,0};
    qp_solver.set_startstate(vector<double> startstate);

    vector<double> endref = {0,0,0,0};
    qp_solver.set_endref(endref);

    void set_lbound(vector<double> l_lbound,vector<double> l_ubound);

    double dlmin = -2;
    double dlmax = 2;
    qp_solver.set_dlbound(dlmin,dlmax);

    // TODO
    double theta_max = ;
    double dot_theta_max = ;
    // double thread ; //轮距
    double wheelbase ; //轴距
    // END


    vector<double> kmax (N,theta_max/wheelbase);
    vector<double> kmin (N,-1*theta_max/wheelbase);
    vector<double> kappa (N,0);
    for(int i=0;i<N;i++)
    {
        kmax[i]-=kappa[i];
        kmin[i]-=kappa[i];
    }
    qp_solver.set_ddlbound(kmin,kmax);

    double dddlmax = dot_theta_max/startstate[1]/wheelbase;
    double dddlmin = -1*dot_theta_max/startstate[1]/wheelbase
    qp_solver.set_dddlbound(dddlmin,dddlmax);

    qp_solver.init();
    qp_solver.solve_OSQP();

}