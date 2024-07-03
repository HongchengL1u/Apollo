#ifndef REFPOINT
#define REFPOINT
#include <iostream>
#include <vector>
class RefPoint
{
    public:
        RefPoint()=default;
        RefPoint(std::vector<double>& xytk);
        RefPoint(double x,double y,double theta,double kappa);
        ~RefPoint()=default;

        double x(void) const;
        double y(void) const;
        double theta(void) const;
        double kappa(void) const;
        std::vector<double> data(void);
        
    private:
        double x_;
        double y_;
        double theta_;
        double kappa_;

};

std::ostream& operator<<(std::ostream& os, RefPoint& refpoint);



#endif