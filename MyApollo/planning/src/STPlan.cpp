#include "STPlan.h"
#include "matplotlibcpp.h"

#include <map>
// #include "Reference_module.h"

using namespace std;
namespace plt = matplotlibcpp;
// // proxuite
// using namespace proxsuite::proxqp;
// using proxsuite::nullopt; // c++17 simply use std::nullopt

// input：根据底盘信息，根据LSPlan规划结果，根据Boundary
// output：生成ST曲线
int main()
{
    // Chassis -> start_state
    // LSPlaningTraj
    // STBonundary
    double delta_t = 0.1; 
    double plan_length = 8;
    int dim_state = 4;
    int dim_time = (plan_length/delta_t);
    int dim_ineq = 4;
    int dim_eq = 4;
    SpeedPlanQPProblem qp_problem(dim_time,dim_state,dim_eq,dim_ineq,delta_t);

    
    
    // from the obstacle
    vector<double>ST_Boundary_l(dim_time,0);
    vector<double>ST_Boundary_u(dim_time,0);
    vector<double>t(dim_time,0);
    for(int i=0;i<dim_time;i++)
    {
        t[i]=i*delta_t;
        if (i>=(4.8/delta_t) && i<=(5.2/delta_t)) ST_Boundary_l[i] = 50;
    }
    for(int i=0;i<dim_time;i++)
    {
        int init_v = 10;
        int init_s = 100;
        ST_Boundary_u[i] = init_s+init_v*delta_t*i;
    }
    qp_problem.set_sboundary(ST_Boundary_l,ST_Boundary_u);


    // from the usr set
    double vref = 15;
    qp_problem.set_cruisespeed(vref);


    // from the vehicle state
    vector<double> start_state = {20,10,0,0};
    qp_problem.set_startstate(start_state);
    // vector<double> end_state = {0,0,0};
    // qp_problem.set_endref(end_state);
    vector<double> siref(dim_time,0);
    double follow_dis = 60;
    for(int i=0;i<siref.size();i++)
    {

        siref[i] = ST_Boundary_u[i]-follow_dis;
    }
    qp_problem.set_siref(siref);
    //vector<double> pi;
    // qp_problem.set_pi(pi);
    


    //from config or traffic
    vector<double> w = {1,1,1,1,1,1,1};
    qp_problem.set_w(w);
    double vmax = 100/3.6;
    double vmin = 0;
    double amax = 6;
    double amin = -4;
    double jmax = 1;
    double jmin = -1;
    vector<vector<double>> vaj_boundary = {{vmin,vmax},{amin,amax},{jmin,jmax}};
    qp_problem.set_vajboundary(vaj_boundary);
    
    
    // qpsolve
    qp_problem.init();
    qp_problem.solve_OSQP();
    // qp_problem.solve_ProxQP();    
    
    //result
    vector<double>& result = qp_problem.get_result();
    vector<double> s_result(dim_time,0);
    vector<double> v_result(dim_time,0);
    vector<double> a_result(dim_time,0);
    vector<double> j_result(dim_time,0);
    for (int i=0;i<dim_time;i++)
    {
        s_result[i] = result[i];
        v_result[i] = result[dim_time+i];
        a_result[i] = result[2*dim_time+i];
        j_result[i] = result[3*dim_time+i];
    }

    // plot
    cout << "plot begin" << endl;
    vector<double> VT_Boundary_l(dim_time,vmin);
    vector<double> VT_Boundary_u(dim_time,vmax);
    vector<double> VT_vref(dim_time,vref);
    vector<double> AT_Boundary_l(dim_time,amin);
    vector<double> AT_Boundary_u(dim_time,amax);
    vector<double> JT_Boundary_l(dim_time,jmin);
    vector<double> JT_Boundary_u(dim_time,jmax);
    
    map<string, string> purplecolor;
    purplecolor.insert(make_pair("color","purple"));
    map<string, string> redcolor;
    redcolor.insert(make_pair("color","red"));
    map<string, string> orangecolor;
    orangecolor.insert(make_pair("color","orange"));
    map<string, string> bluecolor;
    bluecolor.insert(make_pair("color","blue"));
    plt::clf();
    plt::subplot(2,2,1);
    
    plt::plot(t,siref,purplecolor);
    plt::plot(t,ST_Boundary_u,redcolor);
    plt::plot(t,ST_Boundary_l,redcolor);
    plt::plot(t,s_result,orangecolor);
    plt::subplot(2,2,2);
    plt::plot(t,VT_vref,bluecolor);
    plt::plot(t,VT_Boundary_l,redcolor);
    plt::plot(t,v_result,orangecolor);
    plt::plot(t,VT_Boundary_u,redcolor);
    plt::subplot(2,2,3);
    plt::plot(t,AT_Boundary_l,redcolor);
    plt::plot(t,a_result,orangecolor);
    plt::plot(t,AT_Boundary_u,redcolor);
    plt::subplot(2,2,4);
    plt::plot(t,JT_Boundary_l,redcolor);
    plt::plot(t,j_result,orangecolor);
    plt::plot(t,JT_Boundary_u,redcolor);
    plt::save("../result/1.png");

}