PROJECT(Reference)

include_directories(include)
set(EXE_LIST  src/Reference.cpp src/RefPoint.cpp src/test.cpp)
add_executable(${PROJECT_NAME} ${EXE_LIST})