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
CMAKE_SOURCE_DIR = /home/nikita/Study/compilers/For_Dimon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikita/Study/compilers/For_Dimon/build

# Include any dependencies generated for this target.
include extern/cxxopts/test/CMakeFiles/link_test.dir/depend.make

# Include the progress variables for this target.
include extern/cxxopts/test/CMakeFiles/link_test.dir/progress.make

# Include the compile flags for this target's objects.
include extern/cxxopts/test/CMakeFiles/link_test.dir/flags.make

extern/cxxopts/test/CMakeFiles/link_test.dir/link_a.cpp.o: extern/cxxopts/test/CMakeFiles/link_test.dir/flags.make
extern/cxxopts/test/CMakeFiles/link_test.dir/link_a.cpp.o: ../extern/cxxopts/test/link_a.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikita/Study/compilers/For_Dimon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object extern/cxxopts/test/CMakeFiles/link_test.dir/link_a.cpp.o"
	cd /home/nikita/Study/compilers/For_Dimon/build/extern/cxxopts/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/link_test.dir/link_a.cpp.o -c /home/nikita/Study/compilers/For_Dimon/extern/cxxopts/test/link_a.cpp

extern/cxxopts/test/CMakeFiles/link_test.dir/link_a.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/link_test.dir/link_a.cpp.i"
	cd /home/nikita/Study/compilers/For_Dimon/build/extern/cxxopts/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikita/Study/compilers/For_Dimon/extern/cxxopts/test/link_a.cpp > CMakeFiles/link_test.dir/link_a.cpp.i

extern/cxxopts/test/CMakeFiles/link_test.dir/link_a.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/link_test.dir/link_a.cpp.s"
	cd /home/nikita/Study/compilers/For_Dimon/build/extern/cxxopts/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikita/Study/compilers/For_Dimon/extern/cxxopts/test/link_a.cpp -o CMakeFiles/link_test.dir/link_a.cpp.s

extern/cxxopts/test/CMakeFiles/link_test.dir/link_b.cpp.o: extern/cxxopts/test/CMakeFiles/link_test.dir/flags.make
extern/cxxopts/test/CMakeFiles/link_test.dir/link_b.cpp.o: ../extern/cxxopts/test/link_b.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikita/Study/compilers/For_Dimon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object extern/cxxopts/test/CMakeFiles/link_test.dir/link_b.cpp.o"
	cd /home/nikita/Study/compilers/For_Dimon/build/extern/cxxopts/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/link_test.dir/link_b.cpp.o -c /home/nikita/Study/compilers/For_Dimon/extern/cxxopts/test/link_b.cpp

extern/cxxopts/test/CMakeFiles/link_test.dir/link_b.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/link_test.dir/link_b.cpp.i"
	cd /home/nikita/Study/compilers/For_Dimon/build/extern/cxxopts/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikita/Study/compilers/For_Dimon/extern/cxxopts/test/link_b.cpp > CMakeFiles/link_test.dir/link_b.cpp.i

extern/cxxopts/test/CMakeFiles/link_test.dir/link_b.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/link_test.dir/link_b.cpp.s"
	cd /home/nikita/Study/compilers/For_Dimon/build/extern/cxxopts/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikita/Study/compilers/For_Dimon/extern/cxxopts/test/link_b.cpp -o CMakeFiles/link_test.dir/link_b.cpp.s

# Object files for target link_test
link_test_OBJECTS = \
"CMakeFiles/link_test.dir/link_a.cpp.o" \
"CMakeFiles/link_test.dir/link_b.cpp.o"

# External object files for target link_test
link_test_EXTERNAL_OBJECTS =

extern/cxxopts/test/link_test: extern/cxxopts/test/CMakeFiles/link_test.dir/link_a.cpp.o
extern/cxxopts/test/link_test: extern/cxxopts/test/CMakeFiles/link_test.dir/link_b.cpp.o
extern/cxxopts/test/link_test: extern/cxxopts/test/CMakeFiles/link_test.dir/build.make
extern/cxxopts/test/link_test: extern/cxxopts/test/CMakeFiles/link_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nikita/Study/compilers/For_Dimon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable link_test"
	cd /home/nikita/Study/compilers/For_Dimon/build/extern/cxxopts/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/link_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extern/cxxopts/test/CMakeFiles/link_test.dir/build: extern/cxxopts/test/link_test

.PHONY : extern/cxxopts/test/CMakeFiles/link_test.dir/build

extern/cxxopts/test/CMakeFiles/link_test.dir/clean:
	cd /home/nikita/Study/compilers/For_Dimon/build/extern/cxxopts/test && $(CMAKE_COMMAND) -P CMakeFiles/link_test.dir/cmake_clean.cmake
.PHONY : extern/cxxopts/test/CMakeFiles/link_test.dir/clean

extern/cxxopts/test/CMakeFiles/link_test.dir/depend:
	cd /home/nikita/Study/compilers/For_Dimon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikita/Study/compilers/For_Dimon /home/nikita/Study/compilers/For_Dimon/extern/cxxopts/test /home/nikita/Study/compilers/For_Dimon/build /home/nikita/Study/compilers/For_Dimon/build/extern/cxxopts/test /home/nikita/Study/compilers/For_Dimon/build/extern/cxxopts/test/CMakeFiles/link_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : extern/cxxopts/test/CMakeFiles/link_test.dir/depend
