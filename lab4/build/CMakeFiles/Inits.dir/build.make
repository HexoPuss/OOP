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
CMAKE_BINARY_DIR = /home/octopussy/stud/OOP-1/lab4/build

# Include any dependencies generated for this target.
include CMakeFiles/Inits.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Inits.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Inits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Inits.dir/flags.make

CMakeFiles/Inits.dir/inits.cpp.o: CMakeFiles/Inits.dir/flags.make
CMakeFiles/Inits.dir/inits.cpp.o: ../inits.cpp
CMakeFiles/Inits.dir/inits.cpp.o: CMakeFiles/Inits.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/octopussy/stud/OOP-1/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Inits.dir/inits.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Inits.dir/inits.cpp.o -MF CMakeFiles/Inits.dir/inits.cpp.o.d -o CMakeFiles/Inits.dir/inits.cpp.o -c /home/octopussy/stud/OOP-1/lab4/inits.cpp

CMakeFiles/Inits.dir/inits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Inits.dir/inits.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/octopussy/stud/OOP-1/lab4/inits.cpp > CMakeFiles/Inits.dir/inits.cpp.i

CMakeFiles/Inits.dir/inits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Inits.dir/inits.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/octopussy/stud/OOP-1/lab4/inits.cpp -o CMakeFiles/Inits.dir/inits.cpp.s

# Object files for target Inits
Inits_OBJECTS = \
"CMakeFiles/Inits.dir/inits.cpp.o"

# External object files for target Inits
Inits_EXTERNAL_OBJECTS =

libInits.a: CMakeFiles/Inits.dir/inits.cpp.o
libInits.a: CMakeFiles/Inits.dir/build.make
libInits.a: CMakeFiles/Inits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/octopussy/stud/OOP-1/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libInits.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Inits.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Inits.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Inits.dir/build: libInits.a
.PHONY : CMakeFiles/Inits.dir/build

CMakeFiles/Inits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Inits.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Inits.dir/clean

CMakeFiles/Inits.dir/depend:
	cd /home/octopussy/stud/OOP-1/lab4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/octopussy/stud/OOP-1/lab4 /home/octopussy/stud/OOP-1/lab4 /home/octopussy/stud/OOP-1/lab4/build /home/octopussy/stud/OOP-1/lab4/build /home/octopussy/stud/OOP-1/lab4/build/CMakeFiles/Inits.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Inits.dir/depend

