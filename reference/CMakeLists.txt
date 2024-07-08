PROJECT(Reference)

include_directories(include)
# set(EXE_LIST  src/Reference.cpp src/RefPoint.cpp src/VehiclePoint.cpp src/VehicleTrajectory.cpp src/test.cpp)
# add_executable(${PROJECT_NAME} ${EXE_LIST})

set(OUT_LIB_LIST src/Reference.cpp src/RefPoint.cpp src/trajectory_projection.cpp src/VehiclePoint.cpp src/VehicleTrajectory.cpp)
add_library(${PROJECT_NAME} SHARED ${OUT_LIB_LIST})

