#include "SpeedPlanQPProblem.h"

using namespace std;
using namespace Eigen;

void SpeedPlanQPProblem::set_pi(vector<double> pi)
{
    pi_ = std::move(pi);
    has_pi_ = true;
}

void SpeedPlanQPProblem::set_sboundary(vector<double> sl_boundary,vector<double> su_boundary)
{
    if(sl_boundary.size() != dim_time_ || su_boundary.size() != dim_time_) cout<<"s_boundary dim error!" << endl;
    s_lbound_ = std::move(sl_boundary);
    s_ubound_ = std::move(su_boundary);
}

void SpeedPlanQPProblem::set_vajboundary(vector<vector<double>>& vajboundary)
{
    if(vajboundary.size() != 3) cout<<"vajboundary dim error!" << endl;
    vmin_ = vajboundary[0][0];
    vmax_ = vajboundary[0][1];
    amin_ = vajboundary[1][0];
    amax_ = vajboundary[1][1];
    jmin_ = vajboundary[2][0];
    jmax_ = vajboundary[2][1];

}

void SpeedPlanQPProblem::set_startstate(vector<double> startstate)
{
    startstate_ = std::move(startstate);
}

void SpeedPlanQPProblem::set_siref(vector<double> siref)
{
    siref_ = std::move(siref);
    has_siref_ = true;
}

void SpeedPlanQPProblem::set_cruisespeed(double vref)
{
    vref_ = vref;
}

void SpeedPlanQPProblem::set_endref(vector<double> endref)
{
    endref_ = std::move(endref);
    has_end_ref_ = true;
}

void SpeedPlanQPProblem::set_w(vector<double> w)
{
    w_ = std::move(w);
}

vector<double>& SpeedPlanQPProblem::get_result(void)
{
    return result_;
}

SpeedPlanQPProblem::SpeedPlanQPProblem(int dimtime,int dimstate,int dimeq,int dimineq,double deltat):
                            QPProblem(dimtime,dimstate,dimeq,dimineq,deltat)
                            {
                                cout << "SpeedQP Problem: "<<endl;
                                cout << "   eq dim: "<< dimeq << endl;
                                cout << "   ineq dim: "<< dimineq << endl;

                                cout << "   Optimized val has dim: " << dimstate << endl;
                                cout << "   the step is: " << deltat << endl;
                                cout << "   total steps are: " << dimtime << endl;
                            };
void SpeedPlanQPProblem::init(void)
{
    
    cout << "init begin" << endl;

    double wsref = w_[0];
    double wvref = w_[1];
    double wa = w_[2];
    double wj = w_[3];
    double wsend = w_[4];
    double wvend = w_[5];
    double waend = w_[6];
    Q = MatrixXd(dim_time_*dim_state_,dim_time_*dim_state_);
    p = VectorXd(dim_time_*dim_state_);
    A = MatrixXd(dim_time_*(dim_eq_+dim_ineq_),dim_time_*dim_state_);
    l = VectorXd(dim_time_*(dim_eq_+dim_ineq_));
    u = VectorXd(dim_time_*(dim_eq_+dim_ineq_));
    int s_index = 0;
    int v_index = 1*dim_time_;
    int a_index = 2*dim_time_;
    int j_index = 3*dim_time_;
    //Q
    for(int i=0;i<dim_time_-1;i++)
    {
        Q(s_index+i,s_index+i) = wsref;
        Q(v_index+i,v_index+i) = wvref;
        if (i==0) Q(a_index,a_index) = wa+(wj)/(delta_t_*delta_t_);
        else Q(a_index+i,a_index+i) = wa+(2*wj)/(delta_t_*delta_t_);
        Q(a_index+i+1,a_index+i) = -1*wj/(delta_t_*delta_t_);
        Q(a_index+i,a_index+i+1) = -1*wj/(delta_t_*delta_t_);
        
    }
    Q(s_index+dim_time_-1,s_index+dim_time_-1) = wsref+wsend;
    Q(v_index+dim_time_-1,v_index+dim_time_-1) = wvref+wvend;
    Q(a_index+dim_time_-1,a_index+dim_time_-1) = waend+wa+(wj)/(delta_t_*delta_t_);
    if(has_pi_)
    {
        for(int i=0;i<dim_time_;i++)
        {
            Q(v_index+i,v_index+i) += pi_[i];
        }
    }
    cout << "Q init finish" << endl;

    //p
    if(has_siref_)
    {
        for(int i=0;i<dim_time_;i++)
        {
            p(s_index+i) = -1*wsref*siref_[i];
        }
    }

    for(int i=0;i<dim_time_;i++)
    {
        p(v_index+i) = -1*wvref*vref_;
    }


    if(has_end_ref_)
    {
        // p(s_index+dim_time_-1) += -1*wsend*endref_[0];
        p(v_index+dim_time_-1) += -1*wvend*endref_[1];
        p(a_index+dim_time_-1) += -1*waend*endref_[2];
    }
    cout << "p init finish" << endl;
    //A
    
    // in_eq
    // 3 for init s,v,a
    // 1 free for init j
    // 4n-4 for 1-(n-1) s,v,a,j
    // smin<s<smax
    // vmin<v<vmax
    // amin<a<max
    // jmin<j<jmax 
    int ineqindex = 0;
    int eq_index = dim_ineq_*dim_time_;

    A(ineqindex+0*dim_ineq_+0,s_index+0) = 1;
    A(ineqindex+0*dim_ineq_+1,v_index+0) = 1;
    A(ineqindex+0*dim_ineq_+2,a_index+0) = 1;
    A(ineqindex+0*dim_ineq_+3,j_index+0) = 1;

    l(ineqindex+0*dim_ineq_+0) = startstate_[0];
    l(ineqindex+0*dim_ineq_+1) = startstate_[1];
    l(ineqindex+0*dim_ineq_+2) = startstate_[2];
    l(ineqindex+0*dim_ineq_+3) = jmin_;

    u(ineqindex+0*dim_ineq_+0) = startstate_[0];
    u(ineqindex+0*dim_ineq_+1) = startstate_[1];
    u(ineqindex+0*dim_ineq_+2) = startstate_[2];
    u(ineqindex+0*dim_ineq_+3) = jmax_;

    for (int i=1;i<dim_time_;i++)
    {
        A(ineqindex+i*dim_ineq_+0,s_index+i) = 1;
        A(ineqindex+i*dim_ineq_+1,v_index+i) = 1;
        A(ineqindex+i*dim_ineq_+2,a_index+i) = 1;
        A(ineqindex+i*dim_ineq_+3,j_index+i) = 1;

        l(ineqindex+i*dim_ineq_+0) = s_lbound_[i];
        l(ineqindex+i*dim_ineq_+1) = vmin_;
        l(ineqindex+i*dim_ineq_+2) = amin_;
        l(ineqindex+i*dim_ineq_+3) = jmin_;

        u(ineqindex+i*dim_ineq_+0) = s_ubound_[i];
        u(ineqindex+i*dim_ineq_+1) = vmax_;
        u(ineqindex+i*dim_ineq_+2) = amax_;
        u(ineqindex+i*dim_ineq_+3) = jmax_;
    }


    // eq

    for (int i=1;i<dim_time_;i++)
    {
        // si + vit + 1/3ait2 + 1/6(ai+1)t2 -si+1
        A(eq_index+i*dim_eq_+0,s_index+i) = -1;
        A(eq_index+i*dim_eq_+0,s_index+i-1) = 1;
        A(eq_index+i*dim_eq_+0,v_index+i-1) = delta_t_;
        A(eq_index+i*dim_eq_+0,a_index+i-1) = (1.0/3.0)*delta_t_*delta_t_;
        A(eq_index+i*dim_eq_+0,a_index+i) = (1.0/6.0)*delta_t_*delta_t_;
        l(eq_index+i*dim_eq_+0) = 0;
        u(eq_index+i*dim_eq_+0) = 0;

        // vi + 1/2ait + 1/2 (ai+1)t - vi+1  
        A(eq_index+i*dim_eq_+1,v_index+i) = -1;
        A(eq_index+i*dim_eq_+1,v_index+i-1) = 1;
        A(eq_index+i*dim_eq_+1,a_index+i-1) = (1.0/2.0)*delta_t_;
        A(eq_index+i*dim_eq_+1,a_index+i) = (1.0/2.0)*delta_t_;
        l(eq_index+i*dim_eq_+1) = 0;
        u(eq_index+i*dim_eq_+1) = 0;

        // 0*a =0*a

        // (ai+1 - ai ) -jit
        A(eq_index+i*dim_eq_+3,j_index+i-1) = -1*delta_t_;
        A(eq_index+i*dim_eq_+3,a_index+i-1) = -1;
        A(eq_index+i*dim_eq_+3,a_index+i) = 1;
        l(eq_index+i*dim_eq_+3) = 0;
        u(eq_index+i*dim_eq_+3) = 0;
    }
    cout << "ALU finish" << endl;
    // std::ofstream outFile;

    // // 以追加模式打开文件
    // outFile.open("../result/log.txt", std::ios::trunc);

    // if (!outFile) {
    //     std::cerr << "Error opening file for writing" << std::endl;
    // }
    
    // outFile << "Q: "<< endl;
    // outFile << Q << endl;
    // outFile << "p: "<< endl;
    // outFile << p << endl;
    // outFile << "A: "<< endl;
    // outFile << A << endl;
    // outFile << "l: "<< endl;
    // outFile << l << endl;
    // outFile << "u: "<< endl;
    // outFile << u << endl;
    // outFile.close();
}

void SpeedPlanQPProblem::solve_OSQP(void)
{
    
    solver.settings()->setPolish(true);
    solver.settings()->setScaledTerimination(true);
    solver.settings()->setDualInfeasibilityTolerance(1e-5);
    solver.settings()->setPrimalInfeasibilityTolerance(1e-5);
    solver.settings()->setRelativeTolerance(1e-4);
    solver.settings()->setAbsoluteTolerance(1e-4);
    solver.settings()->setVerbosity(false);
    solver.settings()->setWarmStart(true);
    // set the initial data of the QP solver
    solver.data()->setNumberOfVariables(dim_time_*dim_state_);   //变量数n
    solver.data()->setNumberOfConstraints(dim_time_*(dim_eq_+dim_ineq_)); //约束数m
    // if (!solver.data()->setHessianMatrix(hessian))
    //     return 1;
    // if (!solver.data()->setGradient(gradient))
    //     return 1;
    // if (!solver.data()->setLinearConstraintsMatrix(linearMatrix))
    //     return 1;
    // if (!solver.data()->setLowerBound(lowerBound))
    //     return 1;
    // if (!solver.data()->setUpperBound(upperBound))
    //     return 1;
 
    // // instantiate the solver
    // if (!solver.initSolver())
    //     return 1;
    // Eigen::VectorXd QPSolution;
    // // solve the QP problem
    // if (!solver.solve())
    // {
    //     return 1;
    // }
    // QPSolution = solver.getSolution();
    Eigen::SparseMatrix<double> Q_spa(dim_time_*dim_state_, dim_time_*dim_state_);
    Q_spa = Q.sparseView();
    Eigen::SparseMatrix<double> A_spa(dim_time_*(dim_eq_+dim_ineq_), dim_time_*dim_state_);
    A_spa = A.sparseView();
    if(!solver.data()->setHessianMatrix(Q_spa)) cout <<"Q set error" <<endl;
    if(!solver.data()->setGradient(p)) cout <<"p set error" <<endl;
    if(!solver.data()->setLinearConstraintsMatrix(A_spa)) cout <<"A set error" <<endl;
    if(!solver.data()->setLowerBound(l)) cout <<"l set error" <<endl;
    if(!solver.data()->setUpperBound(u)) cout <<"u set error" <<endl;

    cout << "init state: "<< bool(solver.initSolver()) << endl;
    auto start = std::chrono::high_resolution_clock::now();
    cout << "solve state: "<< bool(solver.solveProblem()) << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "OSQP solver time cost: " << duration.count()/1000.0 << " seconds" << std::endl;
        
    Eigen::VectorXd opt = solver.getSolution();
    std::vector<double> vec;
    vec.reserve(opt.size());

    for (int j = 0; j < opt.cols(); ++j) {
        for (int i = 0; i < opt.rows(); ++i) {
            vec.push_back(opt(i, j));
        }
    }
    result_ = vec;
    
}


// void SpeedPlanQPProblem::solve_ProxQP(void)
// {
//     Eigen::SparseMatrix<double> Q_spa(dim_time_*dim_state_, dim_time_*dim_state_);
//     Q_spa = Q.sparseView();
//     Eigen::SparseMatrix<double> A_spa(dim_time_*(dim_eq_+dim_ineq_), dim_time_*dim_state_);
//     A_spa = A.sparseView();

//     sparse::QP<double, long long> qp(dim_time_*dim_state_, 0, dim_time_*(dim_eq_+dim_ineq_));
//     qp.settings.initial_guess = InitialGuessStatus::NO_INITIAL_GUESS;
    
//     qp.init(Q_spa,p,nullopt,nullopt,A_spa,l,u);
//     auto start = std::chrono::high_resolution_clock::now();
//     qp.solve();
//     auto end = std::chrono::high_resolution_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
//     std::cout << "ProxQP solver time cost: " << duration.count()/1000.0 << " seconds" << std::endl;


//     Eigen::MatrixXd opt = qp.results.x;
//     std::vector<double> vec;
//     vec.reserve(opt.size());

//     for (int j = 0; j < opt.cols(); ++j) {
//         for (int i = 0; i < opt.rows(); ++i) {
//             vec.push_back(opt(i, j));
//         }
//     }
//     result_ = vec;
// }

