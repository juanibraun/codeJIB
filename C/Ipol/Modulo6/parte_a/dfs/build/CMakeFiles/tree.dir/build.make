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
CMAKE_SOURCE_DIR = /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs/build

# Include any dependencies generated for this target.
include CMakeFiles/tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tree.dir/flags.make

CMakeFiles/tree.dir/tree.c.o: CMakeFiles/tree.dir/flags.make
CMakeFiles/tree.dir/tree.c.o: ../tree.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/tree.dir/tree.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tree.dir/tree.c.o   -c /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs/tree.c

CMakeFiles/tree.dir/tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tree.dir/tree.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs/tree.c > CMakeFiles/tree.dir/tree.c.i

CMakeFiles/tree.dir/tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tree.dir/tree.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs/tree.c -o CMakeFiles/tree.dir/tree.c.s

CMakeFiles/tree.dir/tree.c.o.requires:
.PHONY : CMakeFiles/tree.dir/tree.c.o.requires

CMakeFiles/tree.dir/tree.c.o.provides: CMakeFiles/tree.dir/tree.c.o.requires
	$(MAKE) -f CMakeFiles/tree.dir/build.make CMakeFiles/tree.dir/tree.c.o.provides.build
.PHONY : CMakeFiles/tree.dir/tree.c.o.provides

CMakeFiles/tree.dir/tree.c.o.provides.build: CMakeFiles/tree.dir/tree.c.o

# Object files for target tree
tree_OBJECTS = \
"CMakeFiles/tree.dir/tree.c.o"

# External object files for target tree
tree_EXTERNAL_OBJECTS =

libtree.a: CMakeFiles/tree.dir/tree.c.o
libtree.a: CMakeFiles/tree.dir/build.make
libtree.a: CMakeFiles/tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libtree.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tree.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tree.dir/build: libtree.a
.PHONY : CMakeFiles/tree.dir/build

CMakeFiles/tree.dir/requires: CMakeFiles/tree.dir/tree.c.o.requires
.PHONY : CMakeFiles/tree.dir/requires

CMakeFiles/tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tree.dir/clean

CMakeFiles/tree.dir/depend:
	cd /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs/build /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs/build /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/parte_a/entrega/dfs/build/CMakeFiles/tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tree.dir/depend

