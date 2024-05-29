#include "planninglog.h"

std::ofstream get_CLOG(std::string out_dir)
{
    try
    {
        // 创建一个 ofstream 对象
        std::ofstream outFile;

        // 打开一个文件，如果文件不存在则创建文件
        outFile.open(out_dir);

        return outFile;
    }
    catch(const std::exception& e)
    {
        std::cerr << "get_CLOG error" << '\n';
    }
    

}
    

