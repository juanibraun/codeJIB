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
CMAKE_SOURCE_DIR = /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree/build

# Include any dependencies generated for this target.
include CMakeFiles/adjMat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/adjMat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/adjMat.dir/flags.make

CMakeFiles/adjMat.dir/adjMat.c.o: CMakeFiles/adjMat.dir/flags.make
CMakeFiles/adjMat.dir/adjMat.c.o: ../adjMat.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/adjMat.dir/adjMat.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/adjMat.dir/adjMat.c.o   -c /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree/adjMat.c

CMakeFiles/adjMat.dir/adjMat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/adjMat.dir/adjMat.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree/adjMat.c > CMakeFiles/adjMat.dir/adjMat.c.i

CMakeFiles/adjMat.dir/adjMat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/adjMat.dir/adjMat.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree/adjMat.c -o CMakeFiles/adjMat.dir/adjMat.c.s

CMakeFiles/adjMat.dir/adjMat.c.o.requires:
.PHONY : CMakeFiles/adjMat.dir/adjMat.c.o.requires

CMakeFiles/adjMat.dir/adjMat.c.o.provides: CMakeFiles/adjMat.dir/adjMat.c.o.requires
	$(MAKE) -f CMakeFiles/adjMat.dir/build.make CMakeFiles/adjMat.dir/adjMat.c.o.provides.build
.PHONY : CMakeFiles/adjMat.dir/adjMat.c.o.provides

CMakeFiles/adjMat.dir/adjMat.c.o.provides.build: CMakeFiles/adjMat.dir/adjMat.c.o

# Object files for target adjMat
adjMat_OBJECTS = \
"CMakeFiles/adjMat.dir/adjMat.c.o"

# External object files for target adjMat
adjMat_EXTERNAL_OBJECTS =

adjMat: CMakeFiles/adjMat.dir/adjMat.c.o
adjMat: CMakeFiles/adjMat.dir/build.make
adjMat: CMakeFiles/adjMat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable adjMat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/adjMat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/adjMat.dir/build: adjMat
.PHONY : CMakeFiles/adjMat.dir/build

CMakeFiles/adjMat.dir/requires: CMakeFiles/adjMat.dir/adjMat.c.o.requires
.PHONY : CMakeFiles/adjMat.dir/requires

CMakeFiles/adjMat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/adjMat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/adjMat.dir/clean

CMakeFiles/adjMat.dir/depend:
	cd /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree/build /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree/build /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/test_tree/build/CMakeFiles/adjMat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/adjMat.dir/depend

