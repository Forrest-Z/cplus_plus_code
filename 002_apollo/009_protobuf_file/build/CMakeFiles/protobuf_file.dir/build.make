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
CMAKE_SOURCE_DIR = /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/build

# Include any dependencies generated for this target.
include CMakeFiles/protobuf_file.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/protobuf_file.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/protobuf_file.dir/flags.make

CMakeFiles/protobuf_file.dir/main.cc.o: CMakeFiles/protobuf_file.dir/flags.make
CMakeFiles/protobuf_file.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/protobuf_file.dir/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/protobuf_file.dir/main.cc.o -c /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/main.cc

CMakeFiles/protobuf_file.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/protobuf_file.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/main.cc > CMakeFiles/protobuf_file.dir/main.cc.i

CMakeFiles/protobuf_file.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/protobuf_file.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/main.cc -o CMakeFiles/protobuf_file.dir/main.cc.s

CMakeFiles/protobuf_file.dir/file.cc.o: CMakeFiles/protobuf_file.dir/flags.make
CMakeFiles/protobuf_file.dir/file.cc.o: ../file.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/protobuf_file.dir/file.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/protobuf_file.dir/file.cc.o -c /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/file.cc

CMakeFiles/protobuf_file.dir/file.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/protobuf_file.dir/file.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/file.cc > CMakeFiles/protobuf_file.dir/file.cc.i

CMakeFiles/protobuf_file.dir/file.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/protobuf_file.dir/file.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/file.cc -o CMakeFiles/protobuf_file.dir/file.cc.s

# Object files for target protobuf_file
protobuf_file_OBJECTS = \
"CMakeFiles/protobuf_file.dir/main.cc.o" \
"CMakeFiles/protobuf_file.dir/file.cc.o"

# External object files for target protobuf_file
protobuf_file_EXTERNAL_OBJECTS =

bin/protobuf_file: CMakeFiles/protobuf_file.dir/main.cc.o
bin/protobuf_file: CMakeFiles/protobuf_file.dir/file.cc.o
bin/protobuf_file: CMakeFiles/protobuf_file.dir/build.make
bin/protobuf_file: /usr/local/lib/libprotobuf.so
bin/protobuf_file: CMakeFiles/protobuf_file.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/protobuf_file"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/protobuf_file.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/protobuf_file.dir/build: bin/protobuf_file

.PHONY : CMakeFiles/protobuf_file.dir/build

CMakeFiles/protobuf_file.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/protobuf_file.dir/cmake_clean.cmake
.PHONY : CMakeFiles/protobuf_file.dir/clean

CMakeFiles/protobuf_file.dir/depend:
	cd /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/build /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/build /home/public/Project/cplus_plus_code/002_apollo/009_protobuf_file/build/CMakeFiles/protobuf_file.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/protobuf_file.dir/depend
