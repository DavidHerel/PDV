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
CMAKE_SOURCE_DIR = /home/fuji/PDV/cv4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fuji/PDV/cv4/cmake-build-debug

# Utility rule file for main.

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

CMakeFiles/main: main.bin
	./main.bin

main: CMakeFiles/main
main: CMakeFiles/main.dir/build.make

.PHONY : main

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/fuji/PDV/cv4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fuji/PDV/cv4 /home/fuji/PDV/cv4 /home/fuji/PDV/cv4/cmake-build-debug /home/fuji/PDV/cv4/cmake-build-debug /home/fuji/PDV/cv4/cmake-build-debug/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

