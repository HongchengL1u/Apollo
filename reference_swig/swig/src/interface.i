//这个地方模块名，我之前用hello，但是在调用的时候就会报错，尽量避免h开头的名字吧
// TODO Change the name of the module
%module ref
//如果要使用string和double就得这么包含一下
%include "std_string.i"
%include "std_vector.i"

namespace std {
  %template(DoubleVector) vector<double>;
  %template(IntVector) vector<int>;
  
  //对于不同元素类型的容器，也需要这么标明一下
}

//这下面是对接口的编写，建议都写在.h文件中，然后这么包含一下
%{
#include "interface.h"
%}
%include "interface.h"