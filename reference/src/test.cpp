#include "Reference.h"
#include <vector>
#include <iostream>
#include "VehicleTrajectory.h"
int main()
{
    std::vector<double> commonroaddata={0,0,0,0,1,1,1,1,2,2,2,2};
    Reference ref;
    ref.set_reference_from_Commonroad(commonroaddata);
    commonroaddata={0,0,0,0,0,0,1,1,1,1,2,2};
    VehicleTrajectory traj;
    traj.set_traj_from_commonroad(commonroaddata);
    std::cout << "refline: " << std::endl << ref ;
    std::cout << "traj: " << std::endl << traj;
}