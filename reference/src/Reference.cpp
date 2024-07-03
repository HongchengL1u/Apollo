#include "Reference.h"

void Reference::set_reference_from_Commonroad(std::vector<double>& xytk_onedim)
{
    if(xytk_onedim.size() % 4 !=0)
    {
        std::cout<<"Commonroad data error" << std::endl;
    }
    int size = xytk_onedim.size()/4;
    for (int i=0;i<size;i++)
    {
        reference_line_.push_back(std::move(RefPoint(xytk_onedim[i*4+0],xytk_onedim[i*4+1],xytk_onedim[i*4+2],xytk_onedim[i*4+3])));
    }
}

std::vector<RefPoint> Reference::reference_line(void) const
{
    return reference_line_;
}






// 重载 << 操作符
std::ostream& operator<<(std::ostream& os, Reference& refline) {
    for(RefPoint& el:refline.reference_line()) 
    {
        os << el <<"\n";
    }
    return os;
}



