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
include CMakeFiles/dijkstra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dijkstra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dijkstra.dir/flags.make

CMakeFiles/dijkstra.dir/dijkstra.c.o: CMakeFiles/dijkstra.dir/flags.make
CMakeFiles/dijkstra.dir/dijkstra.c.o: /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src/dijkstra.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/dijkstra.dir/dijkstra.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/dijkstra.dir/dijkstra.c.o   -c /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src/dijkstra.c

CMakeFiles/dijkstra.dir/dijkstra.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dijkstra.dir/dijkstra.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src/dijkstra.c > CMakeFiles/dijkstra.dir/dijkstra.c.i

CMakeFiles/dijkstra.dir/dijkstra.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dijkstra.dir/dijkstra.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src/dijkstra.c -o CMakeFiles/dijkstra.dir/dijkstra.c.s

CMakeFiles/dijkstra.dir/dijkstra.c.o.requires:
.PHONY : CMakeFiles/dijkstra.dir/dijkstra.c.o.requires

CMakeFiles/dijkstra.dir/dijkstra.c.o.provides: CMakeFiles/dijkstra.dir/dijkstra.c.o.requires
	$(MAKE) -f CMakeFiles/dijkstra.dir/build.make CMakeFiles/dijkstra.dir/dijkstra.c.o.provides.build
.PHONY : CMakeFiles/dijkstra.dir/dijkstra.c.o.provides

CMakeFiles/dijkstra.dir/dijkstra.c.o.provides.build: CMakeFiles/dijkstra.dir/dijkstra.c.o

# Object files for target dijkstra
dijkstra_OBJECTS = \
"CMakeFiles/dijkstra.dir/dijkstra.c.o"

# External object files for target dijkstra
dijkstra_EXTERNAL_OBJECTS =

libdijkstra.a: CMakeFiles/dijkstra.dir/dijkstra.c.o
libdijkstra.a: CMakeFiles/dijkstra.dir/build.make
libdijkstra.a: CMakeFiles/dijkstra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libdijkstra.a"
	$(CMAKE_COMMAND) -P CMakeFiles/dijkstra.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dijkstra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dijkstra.dir/build: libdijkstra.a
.PHONY : CMakeFiles/dijkstra.dir/build

CMakeFiles/dijkstra.dir/requires: CMakeFiles/dijkstra.dir/dijkstra.c.o.requires
.PHONY : CMakeFiles/dijkstra.dir/requires

CMakeFiles/dijkstra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dijkstra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dijkstra.dir/clean

CMakeFiles/dijkstra.dir/depend:
	cd /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/src /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_b/build/CMakeFiles/dijkstra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dijkstra.dir/depend

