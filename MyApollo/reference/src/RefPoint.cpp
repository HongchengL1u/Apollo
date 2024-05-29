#include "RefPoint.h"

double RefPoint::x(void) const
{
    return x_;
}
double RefPoint::y(void) const
{
    return y_;
}
double RefPoint::theta(void) const
{
    return theta_;
}
double RefPoint::kappa(void) const
{
    return kappa_;
}
std::vector<double> RefPoint::data(void)
{
    return std::vector<double> {x_,y_,theta_,kappa_};
}

RefPoint::RefPoint(std::vector<double>& xytk)
{
    x_ = xytk[0];
    y_ = xytk[1];
    theta_ = xytk[2];
    kappa_ = xytk[3];
}

RefPoint::RefPoint(double x,double y,double theta,double kappa)
{
    x_ = x;
    y_ = y;
    theta_ = theta;
    kappa_ = kappa;
}

// 重载 << 操作符
std::ostream& operator<<(std::ostream& os, RefPoint& refpoint) {
    os << refpoint.x() << ", " << refpoint.y()<< ", " << refpoint.theta()<< ", " << refpoint.kappa();
    return os;
}