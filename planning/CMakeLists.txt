cmake_minimum_required(VERSION 3.10)

project(PNC)

include_directories(include)
include_directories(third_party/include)
add_executable(${PROJECT_NAME} src/SpeedPlanQPProblem.cpp src/STPlan.cpp src/QPProblem.cpp)
# add_executable(${PROJECT_NAME} src/test.cpp)
find_package(Eigen3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIRS})

# find_package(proxsuite REQUIRED)
# set(CMAKE_CXX_STANDARD 17) # set(CMAKE_CXX_STANDARD 14) will work too
# target_link_libraries(${PROJECT_NAME} PUBLIC proxsuite::proxsuite)
# target_link_libraries(${PROJECT_NAME} PUBLIC proxsuite::proxsuite-vectorized)
# target_compile_options(${PROJECT_NAME} PUBLIC "-march=native")

find_package(PythonLibs REQUIRED)
include_directories(
        ${PYTHON_INCLUDE_DIRS}
)
message(STATUS ${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${PYTHON_LIBRARIES})

include_directories(
    /home/liuhongcheng/.local/lib/python3.6/site-packages/numpy/core/include
)




find_package(OsqpEigen)
target_link_libraries(${PROJECT_NAME} PUBLIC OsqpEigen::OsqpEigen)




