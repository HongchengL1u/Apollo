#include "Reference.h"
#include <vector>
#include <iostream>

int main()
{
    std::vector<double> commonroaddata={0,0,0,0,1,1,1,1,2,2,2,2};
    Reference ref;
    ref.set_reference_from_Commonroad(commonroaddata);
    std::cout << ref ;
}