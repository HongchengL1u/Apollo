#include "interface.h"
using namespace std;
// TODO define your interface func

void test_Reference(vector<double>& xytk_onedim)
{
    if(xytk_onedim.size() % 4) cout << "ERROR! the num cant be divided by 4" << endl;
    int dur = xytk_onedim.size()/4;
    cout << "the raw data: "<<endl;
    for (int i=0;i<dur;i++)
    {
        cout << xytk_onedim[4*i+0] << " " << xytk_onedim[4*i+1] << " " <<xytk_onedim[4*i+2] << " " << xytk_onedim[4*i+3] << endl;
    }
    
    Reference ref = Reference();
    ref.set_reference_from_Commonroad(xytk_onedim);
    cout << "the data from class: " << endl;
    cout << ref << endl;
}

void test_VehiclePoint(vector<double> xyvaht)
{
    if(xyvaht.size() % 6) cout << "ERROR! the num cant be divided by 6" << endl;
    int dur = xyvaht.size()/6;
    cout << "the raw data: "<<endl;
    for (int i=0;i<dur;i++)
    {
        cout << xyvaht[6*i+0] << " " << xyvaht[6*i+1] << " " <<xyvaht[6*i+2] << " " << xyvaht[6*i+3] << " " << xyvaht[6*i+4] << " " << xyvaht[6*i+5] << " " << endl;
    }
    
    VehicleTrajectory traj = VehicleTrajectory();
    traj.set_traj_from_commonroad(xyvaht);
    cout << "the data from class: " << endl;
    cout << traj << endl;
}

vector<double> test_proj(vector<double> xyvaht,vector<double> xytk_onedim)
{
    vector<vector<double>> sl;
    vector<vector<double>> xy;
    vector<vector<double>> ref;

    int dur = xyvaht.size()/6;
    for (int i=0;i<dur;i++)
    {
        xy.push_back(std::move(vector<double>({xyvaht[6*i+0],xyvaht[6*i+1]})));
    }

    dur = xytk_onedim.size()/4;
    for (int i=0;i<dur;i++)
    {
        ref.push_back(std::move(vector<double>({xytk_onedim[4*i+0],xytk_onedim[4*i+1]})));
    }
    traj_xy2sl(xy,ref,sl);
    vector<double> res;
    for(auto el:sl)
    {
        res.push_back(el[0]);
        res.push_back(el[1]);
    }
    return res;
    
}