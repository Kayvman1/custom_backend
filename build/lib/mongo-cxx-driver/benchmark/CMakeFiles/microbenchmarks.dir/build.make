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
include lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/depend.make

# Include the progress variables for this target.
include lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/progress.make

# Include the compile flags for this target's objects.
include lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/flags.make

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/flags.make
lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o: ../lib/mongo-cxx-driver/benchmark/benchmark_runner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/benchmark_runner.cpp

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/benchmark_runner.cpp > CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.i

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/benchmark_runner.cpp -o CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.s

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o.requires

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o.provides: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/build.make lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o.provides

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o.provides.build: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o


lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/flags.make
lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o: ../lib/mongo-cxx-driver/benchmark/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/microbenchmarks.dir/main.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/main.cpp

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/microbenchmarks.dir/main.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/main.cpp > CMakeFiles/microbenchmarks.dir/main.cpp.i

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/microbenchmarks.dir/main.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/main.cpp -o CMakeFiles/microbenchmarks.dir/main.cpp.s

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o.requires

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o.provides: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/build.make lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o.provides

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o.provides.build: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o


lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/flags.make
lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o: ../lib/mongo-cxx-driver/benchmark/microbench.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/microbenchmarks.dir/microbench.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/microbench.cpp

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/microbenchmarks.dir/microbench.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/microbench.cpp > CMakeFiles/microbenchmarks.dir/microbench.cpp.i

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/microbenchmarks.dir/microbench.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/microbench.cpp -o CMakeFiles/microbenchmarks.dir/microbench.cpp.s

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o.requires

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o.provides: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/build.make lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o.provides

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o.provides.build: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o


lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/flags.make
lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o: ../lib/mongo-cxx-driver/benchmark/score_recorder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/score_recorder.cpp

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/microbenchmarks.dir/score_recorder.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/score_recorder.cpp > CMakeFiles/microbenchmarks.dir/score_recorder.cpp.i

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/microbenchmarks.dir/score_recorder.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark/score_recorder.cpp -o CMakeFiles/microbenchmarks.dir/score_recorder.cpp.s

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o.requires

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o.provides: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/build.make lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o.provides

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o.provides.build: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o


# Object files for target microbenchmarks
microbenchmarks_OBJECTS = \
"CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o" \
"CMakeFiles/microbenchmarks.dir/main.cpp.o" \
"CMakeFiles/microbenchmarks.dir/microbench.cpp.o" \
"CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o"

# External object files for target microbenchmarks
microbenchmarks_EXTERNAL_OBJECTS =

lib/mongo-cxx-driver/benchmark/microbenchmarks: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o
lib/mongo-cxx-driver/benchmark/microbenchmarks: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o
lib/mongo-cxx-driver/benchmark/microbenchmarks: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o
lib/mongo-cxx-driver/benchmark/microbenchmarks: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o
lib/mongo-cxx-driver/benchmark/microbenchmarks: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/build.make
lib/mongo-cxx-driver/benchmark/microbenchmarks: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable microbenchmarks"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/microbenchmarks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/build: lib/mongo-cxx-driver/benchmark/microbenchmarks

.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/build

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/requires: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/benchmark_runner.cpp.o.requires
lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/requires: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/main.cpp.o.requires
lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/requires: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/microbench.cpp.o.requires
lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/requires: lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/score_recorder.cpp.o.requires

.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/requires

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/clean:
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark && $(CMAKE_COMMAND) -P CMakeFiles/microbenchmarks.dir/cmake_clean.cmake
.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/clean

lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/depend:
	cd /home/kayvan/Repos/custom_backend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kayvan/Repos/custom_backend /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/benchmark /home/kayvan/Repos/custom_backend/build /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/mongo-cxx-driver/benchmark/CMakeFiles/microbenchmarks.dir/depend
