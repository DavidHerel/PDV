# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/fuji/IDE/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/fuji/IDE/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fuji/PDV/cv2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fuji/PDV/cv2/cmake-build-debug

# Utility rule file for benchmark.

# Include the progress variables for this target.
include CMakeFiles/benchmark.dir/progress.make

CMakeFiles/benchmark: benchmark.bin
	./benchmark.bin

benchmark: CMakeFiles/benchmark
benchmark: CMakeFiles/benchmark.dir/build.make

.PHONY : benchmark

# Rule to build all files generated by this target.
CMakeFiles/benchmark.dir/build: benchmark

.PHONY : CMakeFiles/benchmark.dir/build

CMakeFiles/benchmark.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/benchmark.dir/cmake_clean.cmake
.PHONY : CMakeFiles/benchmark.dir/clean

CMakeFiles/benchmark.dir/depend:
	cd /home/fuji/PDV/cv2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fuji/PDV/cv2 /home/fuji/PDV/cv2 /home/fuji/PDV/cv2/cmake-build-debug /home/fuji/PDV/cv2/cmake-build-debug /home/fuji/PDV/cv2/cmake-build-debug/CMakeFiles/benchmark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/benchmark.dir/depend

