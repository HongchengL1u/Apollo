#include "VehicleTrajectory.h"


std::vector<VehiclePoint> VehicleTrajectory::trajectory() const
{
    return trajectory_;
}

void VehicleTrajectory::set_traj_from_commonroad(std::vector<double>& xyvaht)
{
    if(xyvaht.size() % 6 !=0)
    {
        std::cout<<"Commonroad data error" << std::endl;
    }
    int size = xyvaht.size()/6;
    for (int i=0;i<size;i++)
    {
        trajectory_.push_back(std::move(VehiclePoint(xyvaht[i*6+0],xyvaht[i*6+1],xyvaht[i*6+2],xyvaht[i*6+3],xyvaht[i*6+4],xyvaht[i*6+5])));
    }
}

void VehicleTrajectory::set_step(double step)
{
    step_ = step;
}

// 重载 << 操作符
std::ostream& operator<<(std::ostream& os, VehicleTrajectory& traj) {
    for(VehiclePoint& el:traj.trajectory()) 
    {
        os << el <<"\n";
    }
    return os;
}