#include "PathPlanQPProblem.h"
PathPlanQPProblem::PathPlanQPProblem(int dimtime,int dimstate,int dimeq,int dimineq,double deltat):
                            QPProblem(dimtime,dimstate,dimeq,dimineq,deltat)
                            {
                                delat_s_ = delta_t_;
                                cout << "PathQP Problem: "<<endl;
                                cout << "   eq dim: "<< dimeq << endl;
                                cout << "   ineq dim: "<< dimineq << endl;

                                cout << "   Optimized val has dim: " << dimstate << endl;
                                cout << "   the step is: " << deltat << endl;
                                cout << "   total steps are: " << dimtime << endl;
                            }; 
vector<double> PathPlanQPProblem::get_result(void)
{
    return result_;
}
void PathPlanQPProblem::set_w(vector<double> w)
{
    w_ = std::move(w);
}
void PathPlanQPProblem::set_wrefi(vector<double> wlrefi)
{
    wlrefi_ = std::move(wlrefi);
}
void PathPlanQPProblem::set_lrefi(vector<double> lrefi)
{
    lrefi_ = std::move(lrefi);
}
void PathPlanQPProblem::set_startstate(vector<double> startstate)
{
    startstate_ = std::move(startstate);
}
void PathPlanQPProblem::set_endref(vector<double> endref)
{
    endref_ = std::move(endref);
    has_endref_ = true;
}

void PathPlanQPProblem::set_lbound(vector<double> l_lbound,vector<double> l_ubound)
{
    l_lbound_ = std::move(l_lbound);
    l_ubound_ = std::move(l_ubound);
}
void PathPlanQPProblem::set_dlbound(double dlmin,double dlmax)
{
    dlmin_ = dlmin;
    dlmax_ = dlmax;
}
void PathPlanQPProblem::set_ddlbound(vector<double> ddlmin,vector<double> ddlmax)
{
    ddlmin_ = std::move(ddlmin);
    ddlmax_ = std::move(ddlmax);
}
void PathPlanQPProblem::set_dddlbound(double dddlmin,double dddlmax)
{
    dddlmin_ = dddlmin;
    dddlmax_ = dddlmax;
}
void PathPlanQPProblem::init(void)
{
    //TODO
    // solver.settings

    double wl = w_[0];
    double wdl = w_[1];
    double wddl = w_[2];
    double wdddl = w_[3];
    double wlend = w_[4];
    double wdlend = w_[5];
    double wddlend = w_[6];

    int N = dim_time_;
    int n = dim_time_ * dim_state_;
    int m = (dim_eq_+dim_ineq_) * dim_time_;
    Q = MatrixXd::Zero(n, n);
    p = MatrixXd::Zero(n, 1);
    A = MatrixXd::Zero(m,n);
    l = MatrixXd::Zero(m,1);
    u = MatrixXd::Zero(m,1);

    int l_index = 0;
    int dl_index = dim_time_;
    int ddl_index = 2*dim_time_;
    int dddl_index = 3*dim_time_;
    //Q
    for (int i=0;i<N-1 ;i++)
    {
        Q(l_index+i,l_index+i) = wl+wlrefi_[i];
        Q(dl_index+i,dl_index+i) = wdl;
        Q(ddl_index+i,ddl_index+i) = wddl;
        Q(ddl_index+i+1,ddl_index+i) = -1*wdddl/(delat_s_*delat_s_);
        Q(ddl_index+i,ddl_index+i+1) = -1*wdddl/(delat_s_*delat_s_);
        if(i == 0)
        {
            Q(ddl_index+i,ddl_index+i) += wdddl/(delat_s_*delat_s_);
        }
        else 
        {
            Q(ddl_index+i,ddl_index+i) += 2*wdddl/(delat_s_*delat_s_);
        }  
    }
    Q(l_index+N-1,l_index+N-1) = wl+wrefi_[N-1]+wlend;
    Q(dl_index+N-1,dl_index+N-1) = wdl+wdlend;
    Q(ddl_index+N-1,ddl_index+N-1) = wddl+wddlend+wdddl/(delat_s_*delat_s_);

    //p
    for (int i=0;i<N;i++)
    {
        p(l_index+i) = -1*wrefi_[i]*lrefi_[i];
    }

    if(has_endref_)
    {
        p(l_index+N-1) += -1*wlend*endref_[0];
        p(dl_index+N-1) = -1*wdlend*endref_[1];
        p(dl_index+N-1) = -1*wddlend*endref[2];
    }


    //A
    //lmin < l < lmax
    //dlmin < dl < dlmax
    //ddlmin < ddl < ddlmax
    //dddlmin < dddl < dddlmax
    int ineq_index = 0;
    int eq_index = dim_time_ * dim_ineq_;

    A(ineq_index+0*dim_ineq_+0,l_index+0) = 1;
    A(ineq_index+0*dim_ineq_+1,dl_index+0) = 1;
    A(ineq_index+0*dim_ineq_+2,ddl_index+0) = 1;
    A(ineq_index+0*dim_ineq_+3,dddl_index+0) = 1;

    l(ineq_index+0*dim_ineq_+0) = startstate_[0];
    l(ineq_index+0*dim_ineq_+1) = startstate_[1];
    l(ineq_index+0*dim_ineq_+2) = startstate_[2];
    l(ineq_index+0*dim_ineq_+3) = dddlmin_;

    u(ineq_index+0*dim_ineq_+0) = startstate_[0];
    u(ineq_index+0*dim_ineq_+1) = startstate_[1];
    u(ineq_index+0*dim_ineq_+2) = startstate_[2];
    u(ineq_index+0*dim_ineq_+3) = dddlmax_;

    for(int i=1;i<N;i++)
    {
        A(ineq_index+i*dim_ineq_+0,l_index+i) = 1;
        A(ineq_index+i*dim_ineq_+1,dl_index+i) = 1;
        A(ineq_index+i*dim_ineq_+2,ddl_index+i) = 1;
        A(ineq_index+i*dim_ineq_+3,dddl_index+i) = 1;

        l(ineq_index+i*dim_ineq_+0) = l_lbound_[i];
        u(ineq_index+i*dim_ineq_+0) = l_ubound_[i];

        l(ineq_index+i*dim_ineq_+1) = dlmin_;
        u(ineq_index+i*dim_ineq_+1) = dlmax_;

        l(ineq_index+i*dim_ineq_+2) = ddlmin_[i];
        u(ineq_index+i*dim_ineq_+2) = ddlmax_[i];

        l(ineq_index+i*dim_ineq_+3) = dddlmin_;
        u(ineq_index+i*dim_ineq_+3) = dddlmax_;
    }


    // eq
    for (int i=1;i<dim_time_;i++)
    {
        // si + vit + 1/3ait2 + 1/6(ai+1)t2 -si+1
        A(eq_index+i*dim_eq_+0,l_index+i) = -1;
        A(eq_index+i*dim_eq_+0,l_index+i-1) = 1;
        A(eq_index+i*dim_eq_+0,dl_index+i-1) = delta_s_;
        A(eq_index+i*dim_eq_+0,ddl_index+i-1) = (1.0/3.0)*delta_s_*delta_s_;
        A(eq_index+i*dim_eq_+0,ddl_index+i) = (1.0/6.0)*delta_s_*delta_s_;
        l(eq_index+i*dim_eq_+0) = 0;
        u(eq_index+i*dim_eq_+0) = 0;

        // vi + 1/2ait + 1/2 (ai+1)t - vi+1  
        A(eq_index+i*dim_eq_+1,dl_index+i) = -1;
        A(eq_index+i*dim_eq_+1,dl_index+i-1) = 1;
        A(eq_index+i*dim_eq_+1,ddl_index+i-1) = (1.0/2.0)*delta_s_;
        A(eq_index+i*dim_eq_+1,ddl_index+i) = (1.0/2.0)*delta_s_;
        l(eq_index+i*dim_eq_+1) = 0;
        u(eq_index+i*dim_eq_+1) = 0;

        // 0*a =0*a

        // (ai+1 - ai ) -jit
        A(eq_index+i*dim_eq_+3,dddl_index+i-1) = -1*delta_s_;
        A(eq_index+i*dim_eq_+3,ddl_index+i-1) = -1;
        A(eq_index+i*dim_eq_+3,ddl_index+i) = 1;
        l(eq_index+i*dim_eq_+3) = 0;
        u(eq_index+i*dim_eq_+3) = 0;
    }
    
}

void PathPlanQPProblem::solve_OSQP(void)
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