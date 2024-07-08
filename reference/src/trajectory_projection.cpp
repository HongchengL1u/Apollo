#include "trajectory_projection.h"
using namespace std;

bool point_proj2ref(vector<double>& xy, vector<vector<double>>& ref, vector<double>& sl)
{
    // ref: x y s h k dk
    // TODO:需要加入判断,因为会出现多个最近的
    int index = get_nearest_point_index(ref,xy);
    vector<double> matched_point = ref[index];

    
}

bool point_cartersian2frenet(double x,double y,double theta,double v,double a,double x_r,double y_r,double s_r,double K_r,double dK_r,double theta_r)
{
    // 只有控制关注l_dot
    /*
        l = d
        s = s_matched

        delta_theta = theta_x - theta_r
        s_dot = v*cos(delta_theta)/(1-l*K_r)
        l_dot = v*sin(delta_theta)
        l_prime = l_dot/s_dot = (1-l*K_r)*tan(delta_theta)

        s_ddot = (a*cos(delta_theta)+ s_dot^2{l_prime*[(-K_x)(1-l*K_r)/cos(delta_theta)+K_r]+l_prime*K_r+l*dK_r})
                    /(1-lK_r)
        l_pprime 
    */
    double l = sqrt((x-x_r)*(x-x_r)+(y-y_r)*(y-y_r));
    double s = s_r;
    double delta_theta = theta-theta_r;
    double one_minus_l_multi_K_r = 1-l*K_r;
    double one_minus_l_multi_K_r_div_cos = one_minus_l_multi_K_r/cos(delta_theta);
    double s_dot = v/one_minus_l_multi_K_r_div_cos;
    double l_dot = v*sin(delta_theta);
    double l_prime = l_dot/s_dot;
    double K_x = a/(v*v);
    double lK_prime = l_prime*K_r+l*dK_r;
    double s_ddot = (a*cos(delta_theta)+ (s_dot*s_dot)*(l_prime*((-K_x)*one_minus_l_multi_K_r_div_cos+K_r)+lK_prime))/one_minus_l_multi_K_r;

    // TODO: 跟Apollo不一样，我是在tan阶段就展开成向量，然后求导
    double n_r_t_x_prime = (-K_r*cos(delta_theta)+K_x*one_minus_l_multi_K_r);
    double t_x_t_r_prime = (K_r-K_x*one_minus_l_multi_K_r_div_cos)*sin(delta_theta);
    double l_pprime = -lK_prime*tan(delta_theta)+(one_minus_l_multi_K_r_div_cos)*n_r_t_x_prime-(t_x_t_r_prime)*tan(delta_theta)*(one_minus_l_multi_K_r_div_cos);


    // s,s_dot,s_ddot l,l_prime,l_pprime
}

bool get_traj_slist(vector<vector<double>>& traj,vector<double>& s)
{
    int size = traj.size();
    if(size<=1) return false;

    vector<double> temp_s(size,0);
    int length = 0;

    for(int i=1;i<size;i++)
    {
        length+= calculate_distance(traj[i],traj[i-1]);
        temp_s[i] = length;
    }
    s = std::move(temp_s);
    return true;
}

int get_nearest_point_index(vector<vector<double>>& traj,vector<double>& point)
{
    // 返回第一个最小的
    int size = traj.size();
    double min = std::numeric_limits<double>::max();
    int min_index = -1;
    for(int i=0;i<size;i++)
    {
        double dis = calculate_distance(traj[i],point);
        if(dis<min)
        {
            min_index = i;
            min = dis;
        }
    }
    return min_index;
}

int calculate_distance(vector<double>& a,vector<double>& b)
{
    // get the distance a to b
    return sqrt(pow((a[0]-b[0]),2) + pow((a[1]-b[1]),2));
}