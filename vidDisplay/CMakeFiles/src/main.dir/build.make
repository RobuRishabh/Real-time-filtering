# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay"

# Include any dependencies generated for this target.
include CMakeFiles/src/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/src/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/src/main.dir/flags.make

CMakeFiles/src/main.dir/src/main.cpp.o: CMakeFiles/src/main.dir/flags.make
CMakeFiles/src/main.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/src/main.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src/main.dir/src/main.cpp.o -c "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay/src/main.cpp"

CMakeFiles/src/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src/main.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay/src/main.cpp" > CMakeFiles/src/main.dir/src/main.cpp.i

CMakeFiles/src/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src/main.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay/src/main.cpp" -o CMakeFiles/src/main.dir/src/main.cpp.s

CMakeFiles/src/main.dir/src/filter.cpp.o: CMakeFiles/src/main.dir/flags.make
CMakeFiles/src/main.dir/src/filter.cpp.o: src/filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/src/main.dir/src/filter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src/main.dir/src/filter.cpp.o -c "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay/src/filter.cpp"

CMakeFiles/src/main.dir/src/filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src/main.dir/src/filter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay/src/filter.cpp" > CMakeFiles/src/main.dir/src/filter.cpp.i

CMakeFiles/src/main.dir/src/filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src/main.dir/src/filter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay/src/filter.cpp" -o CMakeFiles/src/main.dir/src/filter.cpp.s

# Object files for target src/main
src/main_OBJECTS = \
"CMakeFiles/src/main.dir/src/main.cpp.o" \
"CMakeFiles/src/main.dir/src/filter.cpp.o"

# External object files for target src/main
src/main_EXTERNAL_OBJECTS =

src/main: CMakeFiles/src/main.dir/src/main.cpp.o
src/main: CMakeFiles/src/main.dir/src/filter.cpp.o
src/main: CMakeFiles/src/main.dir/build.make
src/main: /usr/local/lib/libopencv_gapi.so.4.7.0
src/main: /usr/local/lib/libopencv_highgui.so.4.7.0
src/main: /usr/local/lib/libopencv_ml.so.4.7.0
src/main: /usr/local/lib/libopencv_objdetect.so.4.7.0
src/main: /usr/local/lib/libopencv_photo.so.4.7.0
src/main: /usr/local/lib/libopencv_stitching.so.4.7.0
src/main: /usr/local/lib/libopencv_video.so.4.7.0
src/main: /usr/local/lib/libopencv_videoio.so.4.7.0
src/main: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
src/main: /usr/local/lib/libopencv_dnn.so.4.7.0
src/main: /usr/local/lib/libopencv_calib3d.so.4.7.0
src/main: /usr/local/lib/libopencv_features2d.so.4.7.0
src/main: /usr/local/lib/libopencv_flann.so.4.7.0
src/main: /usr/local/lib/libopencv_imgproc.so.4.7.0
src/main: /usr/local/lib/libopencv_core.so.4.7.0
src/main: CMakeFiles/src/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable src/main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/src/main.dir/build: src/main

.PHONY : CMakeFiles/src/main.dir/build

CMakeFiles/src/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/src/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/src/main.dir/clean

CMakeFiles/src/main.dir/depend:
	cd "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay" "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay" "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay" "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay" "/home/roburishabh/PRCV Projects/P1_Filtering/vidDisplay/CMakeFiles/src/main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/src/main.dir/depend

