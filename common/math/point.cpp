#include "point.h"

double Point::Distanceto (const Point p2) const
{
    double x1 = this->x_;
    double y1 = this->y_;
    double x2 = p2.x_;
    double y2 = p2.y_;
    double result = std::sqrt(std::pow(x1-x2,2) + std::pow(y1-y2,2));
    return result;

}


double Point::Distanceto(Segment s2) const
{
    double xstart = s2.start.x_;
    double ystart = s2.start.y_;
    double xend = s2.end.x_;
    double yend = s2.end.y_;
    double x0 = this->x_;
    double y0 = this->y_;

    // 3 conditions
    // 1: d.dot(u) < 0 夹角为钝角
    Vec2d d1 = Vec2d(x0-xstart,y0-ystart);
    Vec2d d2 = Vec2d(x0-xend,y0-yend);
    Vec2d t1 = Vec2d(xend-xstart,yend-ystart);
    Vec2d t2 = -t1;
    if(d1.dot(t1)<0) return this->Distanceto(s2.start);
    if(d2.dot(t2)<0) return this->Distanceto(s2.end);

    return t1.cross(d1) / t1.mod();
}