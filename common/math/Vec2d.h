#pragma once

#include <iostream>
#include <cmath>

class Vec2d
{
    public:
        Vec2d(double x,double y):x_(x),y_(y){}
        double mod() const;
        double dot(const Vec2d v2) const;
        double cross(const Vec2d v2) const;
        Vec2d operator-();
        double x_;
        double y_;
};

double Vec2d::mod() const
{
    return std::sqrt(std::pow(this->x_,2)+std::pow(this->y_,2));
}
double Vec2d::dot(const Vec2d v2) const
{
    return this->x_*v2.x_ + this->y_*v2.y_;
}
double Vec2d::cross(const Vec2d v2) const
{
    return (this->x_*v2.y_ - v2.x_*this->y_);
}

Vec2d Vec2d::operator-()
{
    return Vec2d(-this->x_,-this->y_);
}