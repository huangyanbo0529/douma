# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/think/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/think/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/workspace/douma-algo/cpp_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/workspace/douma-algo/cpp_code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ArrayUtils.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ArrayUtils.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ArrayUtils.dir/flags.make

CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.o: CMakeFiles/ArrayUtils.dir/flags.make
CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.o: ../line/array/ArrayUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/workspace/douma-algo/cpp_code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.o -c /cygdrive/c/workspace/douma-algo/cpp_code/line/array/ArrayUtils.cpp

CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/workspace/douma-algo/cpp_code/line/array/ArrayUtils.cpp > CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.i

CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/workspace/douma-algo/cpp_code/line/array/ArrayUtils.cpp -o CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.s

CMakeFiles/ArrayUtils.dir/main.cpp.o: CMakeFiles/ArrayUtils.dir/flags.make
CMakeFiles/ArrayUtils.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/workspace/douma-algo/cpp_code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ArrayUtils.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ArrayUtils.dir/main.cpp.o -c /cygdrive/c/workspace/douma-algo/cpp_code/main.cpp

CMakeFiles/ArrayUtils.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ArrayUtils.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/workspace/douma-algo/cpp_code/main.cpp > CMakeFiles/ArrayUtils.dir/main.cpp.i

CMakeFiles/ArrayUtils.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ArrayUtils.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/workspace/douma-algo/cpp_code/main.cpp -o CMakeFiles/ArrayUtils.dir/main.cpp.s

# Object files for target ArrayUtils
ArrayUtils_OBJECTS = \
"CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.o" \
"CMakeFiles/ArrayUtils.dir/main.cpp.o"

# External object files for target ArrayUtils
ArrayUtils_EXTERNAL_OBJECTS =

ArrayUtils.exe: CMakeFiles/ArrayUtils.dir/line/array/ArrayUtils.cpp.o
ArrayUtils.exe: CMakeFiles/ArrayUtils.dir/main.cpp.o
ArrayUtils.exe: CMakeFiles/ArrayUtils.dir/build.make
ArrayUtils.exe: CMakeFiles/ArrayUtils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/workspace/douma-algo/cpp_code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ArrayUtils.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ArrayUtils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ArrayUtils.dir/build: ArrayUtils.exe
.PHONY : CMakeFiles/ArrayUtils.dir/build

CMakeFiles/ArrayUtils.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ArrayUtils.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ArrayUtils.dir/clean

CMakeFiles/ArrayUtils.dir/depend:
	cd /cygdrive/c/workspace/douma-algo/cpp_code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/workspace/douma-algo/cpp_code /cygdrive/c/workspace/douma-algo/cpp_code /cygdrive/c/workspace/douma-algo/cpp_code/cmake-build-debug /cygdrive/c/workspace/douma-algo/cpp_code/cmake-build-debug /cygdrive/c/workspace/douma-algo/cpp_code/cmake-build-debug/CMakeFiles/ArrayUtils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ArrayUtils.dir/depend

