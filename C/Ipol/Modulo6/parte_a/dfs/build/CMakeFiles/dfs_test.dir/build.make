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
CMAKE_SOURCE_DIR = /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs/build

# Include any dependencies generated for this target.
include CMakeFiles/dfs_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dfs_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dfs_test.dir/flags.make

CMakeFiles/dfs_test.dir/main.c.o: CMakeFiles/dfs_test.dir/flags.make
CMakeFiles/dfs_test.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/dfs_test.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/dfs_test.dir/main.c.o   -c /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs/main.c

CMakeFiles/dfs_test.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dfs_test.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs/main.c > CMakeFiles/dfs_test.dir/main.c.i

CMakeFiles/dfs_test.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dfs_test.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs/main.c -o CMakeFiles/dfs_test.dir/main.c.s

CMakeFiles/dfs_test.dir/main.c.o.requires:
.PHONY : CMakeFiles/dfs_test.dir/main.c.o.requires

CMakeFiles/dfs_test.dir/main.c.o.provides: CMakeFiles/dfs_test.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/dfs_test.dir/build.make CMakeFiles/dfs_test.dir/main.c.o.provides.build
.PHONY : CMakeFiles/dfs_test.dir/main.c.o.provides

CMakeFiles/dfs_test.dir/main.c.o.provides.build: CMakeFiles/dfs_test.dir/main.c.o

# Object files for target dfs_test
dfs_test_OBJECTS = \
"CMakeFiles/dfs_test.dir/main.c.o"

# External object files for target dfs_test
dfs_test_EXTERNAL_OBJECTS =

dfs_test: CMakeFiles/dfs_test.dir/main.c.o
dfs_test: CMakeFiles/dfs_test.dir/build.make
dfs_test: libdfs.a
dfs_test: libtree.a
dfs_test: CMakeFiles/dfs_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable dfs_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dfs_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dfs_test.dir/build: dfs_test
.PHONY : CMakeFiles/dfs_test.dir/build

CMakeFiles/dfs_test.dir/requires: CMakeFiles/dfs_test.dir/main.c.o.requires
.PHONY : CMakeFiles/dfs_test.dir/requires

CMakeFiles/dfs_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dfs_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dfs_test.dir/clean

CMakeFiles/dfs_test.dir/depend:
	cd /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs/build /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs/build /Users/juanignaciobraun/codeJIB/C/Ipol/Modulo6/entrega/dfs/build/CMakeFiles/dfs_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dfs_test.dir/depend

