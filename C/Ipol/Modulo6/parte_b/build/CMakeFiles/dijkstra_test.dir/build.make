# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /opt/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build

# Include any dependencies generated for this target.
include CMakeFiles/dijkstra_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dijkstra_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dijkstra_test.dir/flags.make

CMakeFiles/dijkstra_test.dir/main.c.o: CMakeFiles/dijkstra_test.dir/flags.make
CMakeFiles/dijkstra_test.dir/main.c.o: /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/dijkstra_test.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/dijkstra_test.dir/main.c.o   -c /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src/main.c

CMakeFiles/dijkstra_test.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dijkstra_test.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src/main.c > CMakeFiles/dijkstra_test.dir/main.c.i

CMakeFiles/dijkstra_test.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dijkstra_test.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src/main.c -o CMakeFiles/dijkstra_test.dir/main.c.s

CMakeFiles/dijkstra_test.dir/main.c.o.requires:
.PHONY : CMakeFiles/dijkstra_test.dir/main.c.o.requires

CMakeFiles/dijkstra_test.dir/main.c.o.provides: CMakeFiles/dijkstra_test.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/dijkstra_test.dir/build.make CMakeFiles/dijkstra_test.dir/main.c.o.provides.build
.PHONY : CMakeFiles/dijkstra_test.dir/main.c.o.provides

CMakeFiles/dijkstra_test.dir/main.c.o.provides.build: CMakeFiles/dijkstra_test.dir/main.c.o

# Object files for target dijkstra_test
dijkstra_test_OBJECTS = \
"CMakeFiles/dijkstra_test.dir/main.c.o"

# External object files for target dijkstra_test
dijkstra_test_EXTERNAL_OBJECTS =

dijkstra_test: CMakeFiles/dijkstra_test.dir/main.c.o
dijkstra_test: CMakeFiles/dijkstra_test.dir/build.make
dijkstra_test: libheap.a
dijkstra_test: libdijkstra.a
dijkstra_test: CMakeFiles/dijkstra_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable dijkstra_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dijkstra_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dijkstra_test.dir/build: dijkstra_test
.PHONY : CMakeFiles/dijkstra_test.dir/build

CMakeFiles/dijkstra_test.dir/requires: CMakeFiles/dijkstra_test.dir/main.c.o.requires
.PHONY : CMakeFiles/dijkstra_test.dir/requires

CMakeFiles/dijkstra_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dijkstra_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dijkstra_test.dir/clean

CMakeFiles/dijkstra_test.dir/depend:
	cd /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build/CMakeFiles/dijkstra_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dijkstra_test.dir/depend

