#include "VehiclePoint.h"


VehiclePoint::VehiclePoint(double x,double y,double v,double a,double heading,double t):x_(x),y_(y),v_(v),a_(a),heading_(heading),t_(t) {};
double VehiclePoint::x() const
{
    return x_;
}
double VehiclePoint::y() const
{
    return y_;
}
double VehiclePoint::v() const
{
    return v_;
}
double VehiclePoint::a() const
{
    return a_;
}
double VehiclePoint::heading() const
{
    return heading_;
}
double VehiclePoint::t() const
{
    return t_;
}
std::vector<double> VehiclePoint::data()const
{
    return std::vector<double> {x_,y_,v_,a_,heading_,t_};
}




// 重载 << 操作符
std::ostream& operator<<(std::ostream& os, VehiclePoint& point) {
    const std::vector<double>& data =  point.data();
    os << data[0]<<","<<data[1]<<","<<data[2]<<","<<data[3]<<","<<data[4]<<","<<data[5];
    return os;
}