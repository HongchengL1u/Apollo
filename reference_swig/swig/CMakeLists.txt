cmake_minimum_required(VERSION 3.20)
# TODO
PROJECT(ref)

#这是 工程.h 和 接口.h 路径，因为在编译接口文件时main.h中包含了这些头文件
include_directories(src)

#寻找PYTHON的环境变量，因为编译时需要包含Python.h文件
find_package (Python3 COMPONENTS Interpreter Development)
include_directories(${Python3_INCLUDE_DIRS})
link_libraries(${Python3_LIBRARIES})

#寻找安装好的swig,其实就是去电脑中找你安装好的Swig环境，所以我们需要提前安装环境。
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

#Python文件输出目录 -outdir
set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR}/python)
#指定一个输出目录名，用于放置生成的源文件。xxx_wrap.cxx文件等的位置
set(SWIG_OUTFILE_DIR ${CMAKE_CURRENT_BINARY_DIR}/cpp)

#以下为需要改变的
#C++
set_property(SOURCE src/interface.i PROPERTY CPLUSPLUS ON)
#开始生成，此处只能填一个.i文件和一个.cpp文件
swig_add_library(${PROJECT_NAME} LANGUAGE python SOURCES src/interface.i src/interface.cpp)

# TODO
swig_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/libReference.so)
#我觉得还可以再链接其他动态库