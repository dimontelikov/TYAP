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
include tests/GTest/CMakeFiles/test_ParserLib.dir/depend.make

# Include the progress variables for this target.
include tests/GTest/CMakeFiles/test_ParserLib.dir/progress.make

# Include the compile flags for this target's objects.
include tests/GTest/CMakeFiles/test_ParserLib.dir/flags.make

tests/GTest/CMakeFiles/test_ParserLib.dir/test_pars.cpp.o: tests/GTest/CMakeFiles/test_ParserLib.dir/flags.make
tests/GTest/CMakeFiles/test_ParserLib.dir/test_pars.cpp.o: ../tests/GTest/test_pars.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikita/Study/compilers/For_Dimon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/GTest/CMakeFiles/test_ParserLib.dir/test_pars.cpp.o"
	cd /home/nikita/Study/compilers/For_Dimon/build/tests/GTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_ParserLib.dir/test_pars.cpp.o -c /home/nikita/Study/compilers/For_Dimon/tests/GTest/test_pars.cpp

tests/GTest/CMakeFiles/test_ParserLib.dir/test_pars.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_ParserLib.dir/test_pars.cpp.i"
	cd /home/nikita/Study/compilers/For_Dimon/build/tests/GTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikita/Study/compilers/For_Dimon/tests/GTest/test_pars.cpp > CMakeFiles/test_ParserLib.dir/test_pars.cpp.i

tests/GTest/CMakeFiles/test_ParserLib.dir/test_pars.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_ParserLib.dir/test_pars.cpp.s"
	cd /home/nikita/Study/compilers/For_Dimon/build/tests/GTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikita/Study/compilers/For_Dimon/tests/GTest/test_pars.cpp -o CMakeFiles/test_ParserLib.dir/test_pars.cpp.s

# Object files for target test_ParserLib
test_ParserLib_OBJECTS = \
"CMakeFiles/test_ParserLib.dir/test_pars.cpp.o"

# External object files for target test_ParserLib
test_ParserLib_EXTERNAL_OBJECTS =

tests/GTest/test_ParserLib: tests/GTest/CMakeFiles/test_ParserLib.dir/test_pars.cpp.o
tests/GTest/test_ParserLib: tests/GTest/CMakeFiles/test_ParserLib.dir/build.make
tests/GTest/test_ParserLib: lib/libgtest_main.a
tests/GTest/test_ParserLib: src/parser/libParserLib.a
tests/GTest/test_ParserLib: src/struct/libStructLib.a
tests/GTest/test_ParserLib: lib/libgtest.a
tests/GTest/test_ParserLib: tests/GTest/CMakeFiles/test_ParserLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nikita/Study/compilers/For_Dimon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_ParserLib"
	cd /home/nikita/Study/compilers/For_Dimon/build/tests/GTest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_ParserLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/GTest/CMakeFiles/test_ParserLib.dir/build: tests/GTest/test_ParserLib

.PHONY : tests/GTest/CMakeFiles/test_ParserLib.dir/build

tests/GTest/CMakeFiles/test_ParserLib.dir/clean:
	cd /home/nikita/Study/compilers/For_Dimon/build/tests/GTest && $(CMAKE_COMMAND) -P CMakeFiles/test_ParserLib.dir/cmake_clean.cmake
.PHONY : tests/GTest/CMakeFiles/test_ParserLib.dir/clean

tests/GTest/CMakeFiles/test_ParserLib.dir/depend:
	cd /home/nikita/Study/compilers/For_Dimon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikita/Study/compilers/For_Dimon /home/nikita/Study/compilers/For_Dimon/tests/GTest /home/nikita/Study/compilers/For_Dimon/build /home/nikita/Study/compilers/For_Dimon/build/tests/GTest /home/nikita/Study/compilers/For_Dimon/build/tests/GTest/CMakeFiles/test_ParserLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/GTest/CMakeFiles/test_ParserLib.dir/depend
