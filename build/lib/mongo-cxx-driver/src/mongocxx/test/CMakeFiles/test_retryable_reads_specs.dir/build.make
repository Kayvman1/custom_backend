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
include lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/depend.make

# Include the progress variables for this target.
include lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/progress.make

# Include the compile flags for this target's objects.
include lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/flags.make

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/flags.make
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o: ../lib/mongo-cxx-driver/src/mongocxx/test_util/client_helpers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test_util/client_helpers.cpp

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test_util/client_helpers.cpp > CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.i

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test_util/client_helpers.cpp -o CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.s

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o.requires

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o.provides: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build.make lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o.provides

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o.provides.build: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o


lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/flags.make
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o: ../lib/mongo-cxx-driver/src/third_party/catch/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/third_party/catch/main.cpp

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/third_party/catch/main.cpp > CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.i

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/third_party/catch/main.cpp -o CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.s

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o.requires

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o.provides: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build.make lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o.provides

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o.provides.build: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o


lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/flags.make
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o: ../lib/mongo-cxx-driver/src/mongocxx/test/spec/retryable-reads.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/retryable-reads.cpp

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/retryable-reads.cpp > CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.i

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/retryable-reads.cpp -o CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.s

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o.requires

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o.provides: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build.make lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o.provides

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o.provides.build: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o


lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/flags.make
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o: ../lib/mongo-cxx-driver/src/mongocxx/test/spec/operation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/operation.cpp

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/operation.cpp > CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.i

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/operation.cpp -o CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.s

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o.requires

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o.provides: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build.make lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o.provides

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o.provides.build: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o


lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/flags.make
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o: ../lib/mongo-cxx-driver/src/mongocxx/test/spec/unified_tests/entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/unified_tests/entity.cpp

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/unified_tests/entity.cpp > CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.i

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/unified_tests/entity.cpp -o CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.s

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o.requires

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o.provides: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build.make lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o.provides

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o.provides.build: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o


lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/flags.make
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o: ../lib/mongo-cxx-driver/src/mongocxx/test/spec/unified_tests/assert.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/unified_tests/assert.cpp

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/unified_tests/assert.cpp > CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.i

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/unified_tests/assert.cpp -o CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.s

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o.requires

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o.provides: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build.make lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o.provides

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o.provides.build: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o


lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/flags.make
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o: ../lib/mongo-cxx-driver/src/mongocxx/test/spec/monitoring.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/monitoring.cpp

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/monitoring.cpp > CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.i

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/monitoring.cpp -o CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.s

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o.requires

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o.provides: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build.make lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o.provides

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o.provides.build: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o


lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/flags.make
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o: ../lib/mongo-cxx-driver/src/mongocxx/test/spec/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o -c /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/util.cpp

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/util.cpp > CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.i

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test/spec/util.cpp -o CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.s

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o.requires:

.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o.requires

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o.provides: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o.requires
	$(MAKE) -f lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build.make lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o.provides.build
.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o.provides

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o.provides.build: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o


# Object files for target test_retryable_reads_specs
test_retryable_reads_specs_OBJECTS = \
"CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o" \
"CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o" \
"CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o" \
"CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o" \
"CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o" \
"CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o" \
"CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o" \
"CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o"

# External object files for target test_retryable_reads_specs
test_retryable_reads_specs_EXTERNAL_OBJECTS =

lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build.make
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/libmongocxx-mocked.so.3.7.0
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: /usr/local/lib/libmongoc-1.0.so.0.0.0
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: /usr/local/lib/libbson-1.0.so.0.0.0
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/bsoncxx/libbsoncxx-testing.so.3.7.0
lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable test_retryable_reads_specs"
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_retryable_reads_specs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build: lib/mongo-cxx-driver/src/mongocxx/test/test_retryable_reads_specs

.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/build

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/requires: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/test_util/client_helpers.cpp.o.requires
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/requires: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/__/__/third_party/catch/main.cpp.o.requires
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/requires: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/retryable-reads.cpp.o.requires
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/requires: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/operation.cpp.o.requires
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/requires: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/entity.cpp.o.requires
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/requires: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/unified_tests/assert.cpp.o.requires
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/requires: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/monitoring.cpp.o.requires
lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/requires: lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/spec/util.cpp.o.requires

.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/requires

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/clean:
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test && $(CMAKE_COMMAND) -P CMakeFiles/test_retryable_reads_specs.dir/cmake_clean.cmake
.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/clean

lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/depend:
	cd /home/kayvan/Repos/custom_backend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kayvan/Repos/custom_backend /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver/src/mongocxx/test /home/kayvan/Repos/custom_backend/build /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/mongo-cxx-driver/src/mongocxx/test/CMakeFiles/test_retryable_reads_specs.dir/depend
