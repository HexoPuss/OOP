# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/octopussy/stud/OOP-1/lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/octopussy/stud/OOP-1/lab4/build2

# Include any dependencies generated for this target.
include CMakeFiles/PolygonTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PolygonTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PolygonTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PolygonTest.dir/flags.make

CMakeFiles/PolygonTest.dir/figures_tests.cpp.o: CMakeFiles/PolygonTest.dir/flags.make
CMakeFiles/PolygonTest.dir/figures_tests.cpp.o: ../figures_tests.cpp
CMakeFiles/PolygonTest.dir/figures_tests.cpp.o: CMakeFiles/PolygonTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/octopussy/stud/OOP-1/lab4/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PolygonTest.dir/figures_tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PolygonTest.dir/figures_tests.cpp.o -MF CMakeFiles/PolygonTest.dir/figures_tests.cpp.o.d -o CMakeFiles/PolygonTest.dir/figures_tests.cpp.o -c /home/octopussy/stud/OOP-1/lab4/figures_tests.cpp

CMakeFiles/PolygonTest.dir/figures_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PolygonTest.dir/figures_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/octopussy/stud/OOP-1/lab4/figures_tests.cpp > CMakeFiles/PolygonTest.dir/figures_tests.cpp.i

CMakeFiles/PolygonTest.dir/figures_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PolygonTest.dir/figures_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/octopussy/stud/OOP-1/lab4/figures_tests.cpp -o CMakeFiles/PolygonTest.dir/figures_tests.cpp.s

# Object files for target PolygonTest
PolygonTest_OBJECTS = \
"CMakeFiles/PolygonTest.dir/figures_tests.cpp.o"

# External object files for target PolygonTest
PolygonTest_EXTERNAL_OBJECTS =

PolygonTest: CMakeFiles/PolygonTest.dir/figures_tests.cpp.o
PolygonTest: CMakeFiles/PolygonTest.dir/build.make
PolygonTest: /usr/lib/x86_64-linux-gnu/libgtest.a
PolygonTest: /usr/lib/x86_64-linux-gnu/libgtest_main.a
PolygonTest: /usr/lib/x86_64-linux-gnu/libgtest.a
PolygonTest: CMakeFiles/PolygonTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/octopussy/stud/OOP-1/lab4/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PolygonTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PolygonTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PolygonTest.dir/build: PolygonTest
.PHONY : CMakeFiles/PolygonTest.dir/build

CMakeFiles/PolygonTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PolygonTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PolygonTest.dir/clean

CMakeFiles/PolygonTest.dir/depend:
	cd /home/octopussy/stud/OOP-1/lab4/build2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/octopussy/stud/OOP-1/lab4 /home/octopussy/stud/OOP-1/lab4 /home/octopussy/stud/OOP-1/lab4/build2 /home/octopussy/stud/OOP-1/lab4/build2 /home/octopussy/stud/OOP-1/lab4/build2/CMakeFiles/PolygonTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PolygonTest.dir/depend

