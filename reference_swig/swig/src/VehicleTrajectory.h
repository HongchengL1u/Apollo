#ifndef VEHICLETRAJECTORY
#define VEHICLETRAJECTORY

#include <iostream>
#include <vector>
#include "VehiclePoint.h"

class VehicleTrajectory
{
    public:
        VehicleTrajectory()=default;
        VehicleTrajectory(std::vector<VehiclePoint> traj):trajectory_(traj){};
        ~VehicleTrajectory()=default;
        void set_dt(double dt);
        void set_traj_from_commonroad(std::vector<double>& xyvaht);
        std::vector<VehiclePoint>trajectory() const;
    private:
        std::vector<VehiclePoint> trajectory_;
        double dt_;
};
// 重载 << 操作符
std::ostream& operator<<(std::ostream& os, VehicleTrajectory& traj);

#endif