# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example/build

# Include any dependencies generated for this target.
include CMakeFiles/gflag-example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gflag-example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gflag-example.dir/flags.make

CMakeFiles/gflag-example.dir/gflag-example.cxx.o: CMakeFiles/gflag-example.dir/flags.make
CMakeFiles/gflag-example.dir/gflag-example.cxx.o: ../gflag-example.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/public/Project/cplus_plus_code/002_apollo/004_gflags_example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gflag-example.dir/gflag-example.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gflag-example.dir/gflag-example.cxx.o -c /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example/gflag-example.cxx

CMakeFiles/gflag-example.dir/gflag-example.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gflag-example.dir/gflag-example.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example/gflag-example.cxx > CMakeFiles/gflag-example.dir/gflag-example.cxx.i

CMakeFiles/gflag-example.dir/gflag-example.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gflag-example.dir/gflag-example.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example/gflag-example.cxx -o CMakeFiles/gflag-example.dir/gflag-example.cxx.s

# Object files for target gflag-example
gflag__example_OBJECTS = \
"CMakeFiles/gflag-example.dir/gflag-example.cxx.o"

# External object files for target gflag-example
gflag__example_EXTERNAL_OBJECTS =

gflag-example: CMakeFiles/gflag-example.dir/gflag-example.cxx.o
gflag-example: CMakeFiles/gflag-example.dir/build.make
gflag-example: /usr/local/lib/libgflags.so
gflag-example: CMakeFiles/gflag-example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/public/Project/cplus_plus_code/002_apollo/004_gflags_example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gflag-example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gflag-example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gflag-example.dir/build: gflag-example

.PHONY : CMakeFiles/gflag-example.dir/build

CMakeFiles/gflag-example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gflag-example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gflag-example.dir/clean

CMakeFiles/gflag-example.dir/depend:
	cd /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example/build /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example/build /home/public/Project/cplus_plus_code/002_apollo/004_gflags_example/build/CMakeFiles/gflag-example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gflag-example.dir/depend
