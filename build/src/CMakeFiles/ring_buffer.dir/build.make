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
include src/CMakeFiles/ring_buffer.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ring_buffer.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ring_buffer.dir/flags.make

src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o: src/CMakeFiles/ring_buffer.dir/flags.make
src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o: ../src/ring_buffer/ring_buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o"
	cd /home/kayvan/Repos/custom_backend/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o -c /home/kayvan/Repos/custom_backend/src/ring_buffer/ring_buffer.cpp

src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.i"
	cd /home/kayvan/Repos/custom_backend/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kayvan/Repos/custom_backend/src/ring_buffer/ring_buffer.cpp > CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.i

src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.s"
	cd /home/kayvan/Repos/custom_backend/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kayvan/Repos/custom_backend/src/ring_buffer/ring_buffer.cpp -o CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.s

src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o.requires:

.PHONY : src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o.requires

src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o.provides: src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ring_buffer.dir/build.make src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o.provides.build
.PHONY : src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o.provides

src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o.provides.build: src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o


# Object files for target ring_buffer
ring_buffer_OBJECTS = \
"CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o"

# External object files for target ring_buffer
ring_buffer_EXTERNAL_OBJECTS =

src/libring_buffer.a: src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o
src/libring_buffer.a: src/CMakeFiles/ring_buffer.dir/build.make
src/libring_buffer.a: src/CMakeFiles/ring_buffer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kayvan/Repos/custom_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libring_buffer.a"
	cd /home/kayvan/Repos/custom_backend/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ring_buffer.dir/cmake_clean_target.cmake
	cd /home/kayvan/Repos/custom_backend/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ring_buffer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ring_buffer.dir/build: src/libring_buffer.a

.PHONY : src/CMakeFiles/ring_buffer.dir/build

src/CMakeFiles/ring_buffer.dir/requires: src/CMakeFiles/ring_buffer.dir/ring_buffer/ring_buffer.cpp.o.requires

.PHONY : src/CMakeFiles/ring_buffer.dir/requires

src/CMakeFiles/ring_buffer.dir/clean:
	cd /home/kayvan/Repos/custom_backend/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ring_buffer.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ring_buffer.dir/clean

src/CMakeFiles/ring_buffer.dir/depend:
	cd /home/kayvan/Repos/custom_backend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kayvan/Repos/custom_backend /home/kayvan/Repos/custom_backend/src /home/kayvan/Repos/custom_backend/build /home/kayvan/Repos/custom_backend/build/src /home/kayvan/Repos/custom_backend/build/src/CMakeFiles/ring_buffer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ring_buffer.dir/depend

