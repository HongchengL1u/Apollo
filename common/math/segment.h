# pragma once

#include <iostream>
#include "point.h"

class Segment
{
    public:
        Point start;
        Point end;

        double Distanceto(const Segment s2) const;
};


double Segment::Distanceto(const Segment s2) const
{
    //对于2d的segment，也就是对比一下start、end两点到线段的距离
    return std::min(this->start.Distanceto(s2),this->end.Distanceto(s2));
}

