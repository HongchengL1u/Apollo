#ifndef VEHICLEPOINT
#define VEHICLEPOINT

#include <vector>
#include <iostream>

class VehiclePoint
{
    public:
        VehiclePoint()=default;
        ~VehiclePoint()=default;
        VehiclePoint(std::vector<double>& xytk);
        VehiclePoint(double x,double y,double v,double a,double heading,double t);
        double x(void) const;
        double y(void) const;
        double v(void) const;
        double a(void) const;
        double heading(void) const;
        double t(void) const;
        std::vector<double> data()const;

    private:
        double x_;
        double y_;
        double v_;
        double a_;
        double heading_;
        double t_;

};
// 重载 << 操作符
std::ostream& operator<<(std::ostream& os, VehiclePoint& point);

#endif