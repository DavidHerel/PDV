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

# Include any dependencies generated for this target.
include CMakeFiles/magic.bin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/magic.bin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/magic.bin.dir/flags.make

CMakeFiles/magic.bin.dir/magic.cpp.o: CMakeFiles/magic.bin.dir/flags.make
CMakeFiles/magic.bin.dir/magic.cpp.o: magic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fuji/PDV/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/magic.bin.dir/magic.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/magic.bin.dir/magic.cpp.o -c /home/fuji/PDV/magic.cpp

CMakeFiles/magic.bin.dir/magic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/magic.bin.dir/magic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fuji/PDV/magic.cpp > CMakeFiles/magic.bin.dir/magic.cpp.i

CMakeFiles/magic.bin.dir/magic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/magic.bin.dir/magic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fuji/PDV/magic.cpp -o CMakeFiles/magic.bin.dir/magic.cpp.s

CMakeFiles/magic.bin.dir/magic.cpp.o.requires:

.PHONY : CMakeFiles/magic.bin.dir/magic.cpp.o.requires

CMakeFiles/magic.bin.dir/magic.cpp.o.provides: CMakeFiles/magic.bin.dir/magic.cpp.o.requires
	$(MAKE) -f CMakeFiles/magic.bin.dir/build.make CMakeFiles/magic.bin.dir/magic.cpp.o.provides.build
.PHONY : CMakeFiles/magic.bin.dir/magic.cpp.o.provides

CMakeFiles/magic.bin.dir/magic.cpp.o.provides.build: CMakeFiles/magic.bin.dir/magic.cpp.o


CMakeFiles/magic.bin.dir/cpu_info.cpp.o: CMakeFiles/magic.bin.dir/flags.make
CMakeFiles/magic.bin.dir/cpu_info.cpp.o: cpu_info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fuji/PDV/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/magic.bin.dir/cpu_info.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/magic.bin.dir/cpu_info.cpp.o -c /home/fuji/PDV/cpu_info.cpp

CMakeFiles/magic.bin.dir/cpu_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/magic.bin.dir/cpu_info.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fuji/PDV/cpu_info.cpp > CMakeFiles/magic.bin.dir/cpu_info.cpp.i

CMakeFiles/magic.bin.dir/cpu_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/magic.bin.dir/cpu_info.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fuji/PDV/cpu_info.cpp -o CMakeFiles/magic.bin.dir/cpu_info.cpp.s

CMakeFiles/magic.bin.dir/cpu_info.cpp.o.requires:

.PHONY : CMakeFiles/magic.bin.dir/cpu_info.cpp.o.requires

CMakeFiles/magic.bin.dir/cpu_info.cpp.o.provides: CMakeFiles/magic.bin.dir/cpu_info.cpp.o.requires
	$(MAKE) -f CMakeFiles/magic.bin.dir/build.make CMakeFiles/magic.bin.dir/cpu_info.cpp.o.provides.build
.PHONY : CMakeFiles/magic.bin.dir/cpu_info.cpp.o.provides

CMakeFiles/magic.bin.dir/cpu_info.cpp.o.provides.build: CMakeFiles/magic.bin.dir/cpu_info.cpp.o


# Object files for target magic.bin
magic_bin_OBJECTS = \
"CMakeFiles/magic.bin.dir/magic.cpp.o" \
"CMakeFiles/magic.bin.dir/cpu_info.cpp.o"

# External object files for target magic.bin
magic_bin_EXTERNAL_OBJECTS =

magic.bin: CMakeFiles/magic.bin.dir/magic.cpp.o
magic.bin: CMakeFiles/magic.bin.dir/cpu_info.cpp.o
magic.bin: CMakeFiles/magic.bin.dir/build.make
magic.bin: CMakeFiles/magic.bin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fuji/PDV/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable magic.bin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/magic.bin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/magic.bin.dir/build: magic.bin

.PHONY : CMakeFiles/magic.bin.dir/build

CMakeFiles/magic.bin.dir/requires: CMakeFiles/magic.bin.dir/magic.cpp.o.requires
CMakeFiles/magic.bin.dir/requires: CMakeFiles/magic.bin.dir/cpu_info.cpp.o.requires

.PHONY : CMakeFiles/magic.bin.dir/requires

CMakeFiles/magic.bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/magic.bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/magic.bin.dir/clean

CMakeFiles/magic.bin.dir/depend:
	cd /home/fuji/PDV && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fuji/PDV /home/fuji/PDV /home/fuji/PDV /home/fuji/PDV /home/fuji/PDV/CMakeFiles/magic.bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/magic.bin.dir/depend

