#ifndef REFERENCE
#define REFERENCE

#include <vector>
#include "RefPoint.h"

class Reference
{
    public:
        Reference()=default;
        ~Reference()=default;
        void set_reference_from_Commonroad(std::vector<double>& xytk_onedim);
        // std::vector<double> xy_to_frenet_once(std::vector<double> points);
        std::vector<RefPoint> reference_line(void) const;

    private:
        std::vector<RefPoint> reference_line_;

};

std::ostream& operator<<(std::ostream& os, Reference& refline);
#endif