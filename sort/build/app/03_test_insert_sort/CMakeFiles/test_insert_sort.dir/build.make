# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build

# Include any dependencies generated for this target.
include app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/compiler_depend.make

# Include the progress variables for this target.
include app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/progress.make

# Include the compile flags for this target's objects.
include app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/flags.make

app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/main.cpp.o: app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/flags.make
app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/main.cpp.o: ../app/03_test_insert_sort/main.cpp
app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/main.cpp.o: app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/main.cpp.o"
	cd /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build/app/03_test_insert_sort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/main.cpp.o -MF CMakeFiles/test_insert_sort.dir/main.cpp.o.d -o CMakeFiles/test_insert_sort.dir/main.cpp.o -c /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/app/03_test_insert_sort/main.cpp

app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_insert_sort.dir/main.cpp.i"
	cd /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build/app/03_test_insert_sort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/app/03_test_insert_sort/main.cpp > CMakeFiles/test_insert_sort.dir/main.cpp.i

app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_insert_sort.dir/main.cpp.s"
	cd /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build/app/03_test_insert_sort && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/app/03_test_insert_sort/main.cpp -o CMakeFiles/test_insert_sort.dir/main.cpp.s

# Object files for target test_insert_sort
test_insert_sort_OBJECTS = \
"CMakeFiles/test_insert_sort.dir/main.cpp.o"

# External object files for target test_insert_sort
test_insert_sort_EXTERNAL_OBJECTS =

../app/03_test_insert_sort/bin/test_insert_sort: app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/main.cpp.o
../app/03_test_insert_sort/bin/test_insert_sort: app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/build.make
../app/03_test_insert_sort/bin/test_insert_sort: src/libSORT_UTILS.a
../app/03_test_insert_sort/bin/test_insert_sort: app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../app/03_test_insert_sort/bin/test_insert_sort"
	cd /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build/app/03_test_insert_sort && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_insert_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/build: ../app/03_test_insert_sort/bin/test_insert_sort
.PHONY : app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/build

app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/clean:
	cd /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build/app/03_test_insert_sort && $(CMAKE_COMMAND) -P CMakeFiles/test_insert_sort.dir/cmake_clean.cmake
.PHONY : app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/clean

app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/depend:
	cd /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/app/03_test_insert_sort /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build/app/03_test_insert_sort /home/ctrtemp/Documents/VS_Code_Prj/Learning/LeetCode/02__230514/leetcode_on_the_way/sort/build/app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/03_test_insert_sort/CMakeFiles/test_insert_sort.dir/depend
