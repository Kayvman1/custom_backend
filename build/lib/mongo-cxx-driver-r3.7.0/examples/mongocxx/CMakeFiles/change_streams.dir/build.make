# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kayvan/Repos/custom_backend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kayvan/Repos/custom_backend/build

# Include any dependencies generated for this target.
include lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/depend.make

# Include the progress variables for this target.
include lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/progress.make

# Include the compile flags for this target's objects.
include lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/flags.make

lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o: lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/flags.make
lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o: ../lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/change_streams.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/change_streams.dir/change_streams.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/change_streams.cpp

lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/change_streams.dir/change_streams.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/change_streams.cpp > CMakeFiles/change_streams.dir/change_streams.cpp.i

lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/change_streams.dir/change_streams.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/change_streams.cpp -o CMakeFiles/change_streams.dir/change_streams.cpp.s

lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o.requires

lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o.provides: lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/build.make lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o.provides

lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o.provides.build: lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o


# Object files for target change_streams
change_streams_OBJECTS = \
"CMakeFiles/change_streams.dir/change_streams.cpp.o"

# External object files for target change_streams
change_streams_EXTERNAL_OBJECTS =

lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/change_streams: lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o
lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/change_streams: lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/build.make
lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/change_streams: lib/mongo-cxx-driver-r3.7.0/src/mongocxx/libmongocxx.so.3.7.0
lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/change_streams: lib/mongo-cxx-driver-r3.7.0/src/bsoncxx/libbsoncxx.so.3.7.0
lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/change_streams: lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable change_streams"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/change_streams.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/build: lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/change_streams

.PHONY : lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/build

lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/requires: lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/change_streams.cpp.o.requires

.PHONY : lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/requires

lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/clean:
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx && $(CMAKE_COMMAND) -P CMakeFiles/change_streams.dir/cmake_clean.cmake
.PHONY : lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/clean

lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/depend:
	cd /home/kayvan/Repos/custom_backend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kayvan/Repos/custom_backend /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx /home/kayvan/Repos/custom_backend/build /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/mongo-cxx-driver-r3.7.0/examples/mongocxx/CMakeFiles/change_streams.dir/depend
