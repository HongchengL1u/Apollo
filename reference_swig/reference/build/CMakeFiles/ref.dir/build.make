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
CMAKE_SOURCE_DIR = /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/build

# Include any dependencies generated for this target.
include CMakeFiles/ref.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ref.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ref.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ref.dir/flags.make

CMakeFiles/ref.dir/src/Reference.o: CMakeFiles/ref.dir/flags.make
CMakeFiles/ref.dir/src/Reference.o: ../src/Reference.cpp
CMakeFiles/ref.dir/src/Reference.o: CMakeFiles/ref.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ref.dir/src/Reference.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ref.dir/src/Reference.o -MF CMakeFiles/ref.dir/src/Reference.o.d -o CMakeFiles/ref.dir/src/Reference.o -c /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/src/Reference.cpp

CMakeFiles/ref.dir/src/Reference.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ref.dir/src/Reference.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/src/Reference.cpp > CMakeFiles/ref.dir/src/Reference.i

CMakeFiles/ref.dir/src/Reference.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ref.dir/src/Reference.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/src/Reference.cpp -o CMakeFiles/ref.dir/src/Reference.s

CMakeFiles/ref.dir/src/RefPoint.o: CMakeFiles/ref.dir/flags.make
CMakeFiles/ref.dir/src/RefPoint.o: ../src/RefPoint.cpp
CMakeFiles/ref.dir/src/RefPoint.o: CMakeFiles/ref.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ref.dir/src/RefPoint.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ref.dir/src/RefPoint.o -MF CMakeFiles/ref.dir/src/RefPoint.o.d -o CMakeFiles/ref.dir/src/RefPoint.o -c /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/src/RefPoint.cpp

CMakeFiles/ref.dir/src/RefPoint.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ref.dir/src/RefPoint.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/src/RefPoint.cpp > CMakeFiles/ref.dir/src/RefPoint.i

CMakeFiles/ref.dir/src/RefPoint.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ref.dir/src/RefPoint.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/src/RefPoint.cpp -o CMakeFiles/ref.dir/src/RefPoint.s

# Object files for target ref
ref_OBJECTS = \
"CMakeFiles/ref.dir/src/Reference.o" \
"CMakeFiles/ref.dir/src/RefPoint.o"

# External object files for target ref
ref_EXTERNAL_OBJECTS =

libref.so: CMakeFiles/ref.dir/src/Reference.o
libref.so: CMakeFiles/ref.dir/src/RefPoint.o
libref.so: CMakeFiles/ref.dir/build.make
libref.so: CMakeFiles/ref.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libref.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ref.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ref.dir/build: libref.so
.PHONY : CMakeFiles/ref.dir/build

CMakeFiles/ref.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ref.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ref.dir/clean

CMakeFiles/ref.dir/depend:
	cd /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/build /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/build /home/liuhongcheng/Desktop/AS_cpp/MyApollo/reference_swig/reference/build/CMakeFiles/ref.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ref.dir/depend

