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
CMAKE_SOURCE_DIR = /home/fuji/PDV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fuji/PDV

# Utility rule file for matrix.

# Include the progress variables for this target.
include CMakeFiles/matrix.dir/progress.make

CMakeFiles/matrix: matrix.bin
	./matrix.bin

matrix: CMakeFiles/matrix
matrix: CMakeFiles/matrix.dir/build.make

.PHONY : matrix

# Rule to build all files generated by this target.
CMakeFiles/matrix.dir/build: matrix

.PHONY : CMakeFiles/matrix.dir/build

CMakeFiles/matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/matrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/matrix.dir/clean

CMakeFiles/matrix.dir/depend:
	cd /home/fuji/PDV && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fuji/PDV /home/fuji/PDV /home/fuji/PDV /home/fuji/PDV /home/fuji/PDV/CMakeFiles/matrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/matrix.dir/depend
