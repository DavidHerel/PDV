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

# Include any dependencies generated for this target.
include CMakeFiles/benchmark.bin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/benchmark.bin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/benchmark.bin.dir/flags.make

CMakeFiles/benchmark.bin.dir/benchmark.cpp.o: CMakeFiles/benchmark.bin.dir/flags.make
CMakeFiles/benchmark.bin.dir/benchmark.cpp.o: ../benchmark.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fuji/PDV/cv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/benchmark.bin.dir/benchmark.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark.bin.dir/benchmark.cpp.o -c /home/fuji/PDV/cv2/benchmark.cpp

CMakeFiles/benchmark.bin.dir/benchmark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark.bin.dir/benchmark.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fuji/PDV/cv2/benchmark.cpp > CMakeFiles/benchmark.bin.dir/benchmark.cpp.i

CMakeFiles/benchmark.bin.dir/benchmark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark.bin.dir/benchmark.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fuji/PDV/cv2/benchmark.cpp -o CMakeFiles/benchmark.bin.dir/benchmark.cpp.s

CMakeFiles/benchmark.bin.dir/decryption.cpp.o: CMakeFiles/benchmark.bin.dir/flags.make
CMakeFiles/benchmark.bin.dir/decryption.cpp.o: ../decryption.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fuji/PDV/cv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/benchmark.bin.dir/decryption.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark.bin.dir/decryption.cpp.o -c /home/fuji/PDV/cv2/decryption.cpp

CMakeFiles/benchmark.bin.dir/decryption.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark.bin.dir/decryption.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fuji/PDV/cv2/decryption.cpp > CMakeFiles/benchmark.bin.dir/decryption.cpp.i

CMakeFiles/benchmark.bin.dir/decryption.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark.bin.dir/decryption.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fuji/PDV/cv2/decryption.cpp -o CMakeFiles/benchmark.bin.dir/decryption.cpp.s

CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.o: CMakeFiles/benchmark.bin.dir/flags.make
CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.o: ../PDVCrypt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fuji/PDV/cv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.o -c /home/fuji/PDV/cv2/PDVCrypt.cpp

CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fuji/PDV/cv2/PDVCrypt.cpp > CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.i

CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fuji/PDV/cv2/PDVCrypt.cpp -o CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.s

# Object files for target benchmark.bin
benchmark_bin_OBJECTS = \
"CMakeFiles/benchmark.bin.dir/benchmark.cpp.o" \
"CMakeFiles/benchmark.bin.dir/decryption.cpp.o" \
"CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.o"

# External object files for target benchmark.bin
benchmark_bin_EXTERNAL_OBJECTS =

benchmark.bin: CMakeFiles/benchmark.bin.dir/benchmark.cpp.o
benchmark.bin: CMakeFiles/benchmark.bin.dir/decryption.cpp.o
benchmark.bin: CMakeFiles/benchmark.bin.dir/PDVCrypt.cpp.o
benchmark.bin: CMakeFiles/benchmark.bin.dir/build.make
benchmark.bin: CMakeFiles/benchmark.bin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fuji/PDV/cv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable benchmark.bin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark.bin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/benchmark.bin.dir/build: benchmark.bin

.PHONY : CMakeFiles/benchmark.bin.dir/build

CMakeFiles/benchmark.bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/benchmark.bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/benchmark.bin.dir/clean

CMakeFiles/benchmark.bin.dir/depend:
	cd /home/fuji/PDV/cv2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fuji/PDV/cv2 /home/fuji/PDV/cv2 /home/fuji/PDV/cv2/cmake-build-debug /home/fuji/PDV/cv2/cmake-build-debug /home/fuji/PDV/cv2/cmake-build-debug/CMakeFiles/benchmark.bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/benchmark.bin.dir/depend

