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

# Utility rule file for format.

# Include the progress variables for this target.
include lib/mongo-cxx-driver/CMakeFiles/format.dir/progress.make

lib/mongo-cxx-driver/CMakeFiles/format:
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver && python /home/kayvan/Repos/custom_backend/etc/clang_format.py format

format: lib/mongo-cxx-driver/CMakeFiles/format
format: lib/mongo-cxx-driver/CMakeFiles/format.dir/build.make

.PHONY : format

# Rule to build all files generated by this target.
lib/mongo-cxx-driver/CMakeFiles/format.dir/build: format

.PHONY : lib/mongo-cxx-driver/CMakeFiles/format.dir/build

lib/mongo-cxx-driver/CMakeFiles/format.dir/clean:
	cd /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver && $(CMAKE_COMMAND) -P CMakeFiles/format.dir/cmake_clean.cmake
.PHONY : lib/mongo-cxx-driver/CMakeFiles/format.dir/clean

lib/mongo-cxx-driver/CMakeFiles/format.dir/depend:
	cd /home/kayvan/Repos/custom_backend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kayvan/Repos/custom_backend /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver /home/kayvan/Repos/custom_backend/build /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/CMakeFiles/format.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/mongo-cxx-driver/CMakeFiles/format.dir/depend
