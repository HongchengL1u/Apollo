# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/liuhongcheng/cmake-3.20.0-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/liuhongcheng/cmake-3.20.0-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build

# Include any dependencies generated for this target.
include CMakeFiles/Reference.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Reference.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Reference.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Reference.dir/flags.make

CMakeFiles/Reference.dir/src/Reference.o: CMakeFiles/Reference.dir/flags.make
CMakeFiles/Reference.dir/src/Reference.o: ../src/Reference.cpp
CMakeFiles/Reference.dir/src/Reference.o: CMakeFiles/Reference.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Reference.dir/src/Reference.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Reference.dir/src/Reference.o -MF CMakeFiles/Reference.dir/src/Reference.o.d -o CMakeFiles/Reference.dir/src/Reference.o -c /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/Reference.cpp

CMakeFiles/Reference.dir/src/Reference.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reference.dir/src/Reference.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/Reference.cpp > CMakeFiles/Reference.dir/src/Reference.i

CMakeFiles/Reference.dir/src/Reference.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reference.dir/src/Reference.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/Reference.cpp -o CMakeFiles/Reference.dir/src/Reference.s

CMakeFiles/Reference.dir/src/RefPoint.o: CMakeFiles/Reference.dir/flags.make
CMakeFiles/Reference.dir/src/RefPoint.o: ../src/RefPoint.cpp
CMakeFiles/Reference.dir/src/RefPoint.o: CMakeFiles/Reference.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Reference.dir/src/RefPoint.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Reference.dir/src/RefPoint.o -MF CMakeFiles/Reference.dir/src/RefPoint.o.d -o CMakeFiles/Reference.dir/src/RefPoint.o -c /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/RefPoint.cpp

CMakeFiles/Reference.dir/src/RefPoint.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reference.dir/src/RefPoint.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/RefPoint.cpp > CMakeFiles/Reference.dir/src/RefPoint.i

CMakeFiles/Reference.dir/src/RefPoint.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reference.dir/src/RefPoint.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/RefPoint.cpp -o CMakeFiles/Reference.dir/src/RefPoint.s

CMakeFiles/Reference.dir/src/trajectory_projection.o: CMakeFiles/Reference.dir/flags.make
CMakeFiles/Reference.dir/src/trajectory_projection.o: ../src/trajectory_projection.cpp
CMakeFiles/Reference.dir/src/trajectory_projection.o: CMakeFiles/Reference.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Reference.dir/src/trajectory_projection.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Reference.dir/src/trajectory_projection.o -MF CMakeFiles/Reference.dir/src/trajectory_projection.o.d -o CMakeFiles/Reference.dir/src/trajectory_projection.o -c /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/trajectory_projection.cpp

CMakeFiles/Reference.dir/src/trajectory_projection.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reference.dir/src/trajectory_projection.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/trajectory_projection.cpp > CMakeFiles/Reference.dir/src/trajectory_projection.i

CMakeFiles/Reference.dir/src/trajectory_projection.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reference.dir/src/trajectory_projection.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/trajectory_projection.cpp -o CMakeFiles/Reference.dir/src/trajectory_projection.s

CMakeFiles/Reference.dir/src/VehiclePoint.o: CMakeFiles/Reference.dir/flags.make
CMakeFiles/Reference.dir/src/VehiclePoint.o: ../src/VehiclePoint.cpp
CMakeFiles/Reference.dir/src/VehiclePoint.o: CMakeFiles/Reference.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Reference.dir/src/VehiclePoint.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Reference.dir/src/VehiclePoint.o -MF CMakeFiles/Reference.dir/src/VehiclePoint.o.d -o CMakeFiles/Reference.dir/src/VehiclePoint.o -c /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/VehiclePoint.cpp

CMakeFiles/Reference.dir/src/VehiclePoint.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reference.dir/src/VehiclePoint.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/VehiclePoint.cpp > CMakeFiles/Reference.dir/src/VehiclePoint.i

CMakeFiles/Reference.dir/src/VehiclePoint.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reference.dir/src/VehiclePoint.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/VehiclePoint.cpp -o CMakeFiles/Reference.dir/src/VehiclePoint.s

CMakeFiles/Reference.dir/src/VehicleTrajectory.o: CMakeFiles/Reference.dir/flags.make
CMakeFiles/Reference.dir/src/VehicleTrajectory.o: ../src/VehicleTrajectory.cpp
CMakeFiles/Reference.dir/src/VehicleTrajectory.o: CMakeFiles/Reference.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Reference.dir/src/VehicleTrajectory.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Reference.dir/src/VehicleTrajectory.o -MF CMakeFiles/Reference.dir/src/VehicleTrajectory.o.d -o CMakeFiles/Reference.dir/src/VehicleTrajectory.o -c /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/VehicleTrajectory.cpp

CMakeFiles/Reference.dir/src/VehicleTrajectory.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reference.dir/src/VehicleTrajectory.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/VehicleTrajectory.cpp > CMakeFiles/Reference.dir/src/VehicleTrajectory.i

CMakeFiles/Reference.dir/src/VehicleTrajectory.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reference.dir/src/VehicleTrajectory.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/src/VehicleTrajectory.cpp -o CMakeFiles/Reference.dir/src/VehicleTrajectory.s

# Object files for target Reference
Reference_OBJECTS = \
"CMakeFiles/Reference.dir/src/Reference.o" \
"CMakeFiles/Reference.dir/src/RefPoint.o" \
"CMakeFiles/Reference.dir/src/trajectory_projection.o" \
"CMakeFiles/Reference.dir/src/VehiclePoint.o" \
"CMakeFiles/Reference.dir/src/VehicleTrajectory.o"

# External object files for target Reference
Reference_EXTERNAL_OBJECTS =

libReference.so: CMakeFiles/Reference.dir/src/Reference.o
libReference.so: CMakeFiles/Reference.dir/src/RefPoint.o
libReference.so: CMakeFiles/Reference.dir/src/trajectory_projection.o
libReference.so: CMakeFiles/Reference.dir/src/VehiclePoint.o
libReference.so: CMakeFiles/Reference.dir/src/VehicleTrajectory.o
libReference.so: CMakeFiles/Reference.dir/build.make
libReference.so: CMakeFiles/Reference.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libReference.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Reference.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Reference.dir/build: libReference.so
.PHONY : CMakeFiles/Reference.dir/build

CMakeFiles/Reference.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Reference.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Reference.dir/clean

CMakeFiles/Reference.dir/depend:
	cd /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference/build/CMakeFiles/Reference.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Reference.dir/depend

