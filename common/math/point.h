#pragma once

#include <iostream>
#include <cmath>
#include "segment.h"
#include "Vec2d.h"

class Point
{
    public:
        Point(double x,double y):x_(x),y_(y){}

        double Distanceto (const Point p2) const;
        double Distanceto(const Segment s2) const;

        double x_;
        double y_;
};



 