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
CMAKE_SOURCE_DIR = /root/CodeField_C/tlpi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/CodeField_C/tlpi

# Include any dependencies generated for this target.
include signals/CMakeFiles/signal_functions.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include signals/CMakeFiles/signal_functions.dir/compiler_depend.make

# Include the progress variables for this target.
include signals/CMakeFiles/signal_functions.dir/progress.make

# Include the compile flags for this target's objects.
include signals/CMakeFiles/signal_functions.dir/flags.make

signals/CMakeFiles/signal_functions.dir/signal_functions.c.o: signals/CMakeFiles/signal_functions.dir/flags.make
signals/CMakeFiles/signal_functions.dir/signal_functions.c.o: signals/signal_functions.c
signals/CMakeFiles/signal_functions.dir/signal_functions.c.o: signals/CMakeFiles/signal_functions.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CodeField_C/tlpi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object signals/CMakeFiles/signal_functions.dir/signal_functions.c.o"
	cd /root/CodeField_C/tlpi/signals && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT signals/CMakeFiles/signal_functions.dir/signal_functions.c.o -MF CMakeFiles/signal_functions.dir/signal_functions.c.o.d -o CMakeFiles/signal_functions.dir/signal_functions.c.o -c /root/CodeField_C/tlpi/signals/signal_functions.c

signals/CMakeFiles/signal_functions.dir/signal_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/signal_functions.dir/signal_functions.c.i"
	cd /root/CodeField_C/tlpi/signals && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/CodeField_C/tlpi/signals/signal_functions.c > CMakeFiles/signal_functions.dir/signal_functions.c.i

signals/CMakeFiles/signal_functions.dir/signal_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/signal_functions.dir/signal_functions.c.s"
	cd /root/CodeField_C/tlpi/signals && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/CodeField_C/tlpi/signals/signal_functions.c -o CMakeFiles/signal_functions.dir/signal_functions.c.s

# Object files for target signal_functions
signal_functions_OBJECTS = \
"CMakeFiles/signal_functions.dir/signal_functions.c.o"

# External object files for target signal_functions
signal_functions_EXTERNAL_OBJECTS =

signals/libsignal_functions.a: signals/CMakeFiles/signal_functions.dir/signal_functions.c.o
signals/libsignal_functions.a: signals/CMakeFiles/signal_functions.dir/build.make
signals/libsignal_functions.a: signals/CMakeFiles/signal_functions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/CodeField_C/tlpi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libsignal_functions.a"
	cd /root/CodeField_C/tlpi/signals && $(CMAKE_COMMAND) -P CMakeFiles/signal_functions.dir/cmake_clean_target.cmake
	cd /root/CodeField_C/tlpi/signals && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/signal_functions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
signals/CMakeFiles/signal_functions.dir/build: signals/libsignal_functions.a
.PHONY : signals/CMakeFiles/signal_functions.dir/build

signals/CMakeFiles/signal_functions.dir/clean:
	cd /root/CodeField_C/tlpi/signals && $(CMAKE_COMMAND) -P CMakeFiles/signal_functions.dir/cmake_clean.cmake
.PHONY : signals/CMakeFiles/signal_functions.dir/clean

signals/CMakeFiles/signal_functions.dir/depend:
	cd /root/CodeField_C/tlpi && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/CodeField_C/tlpi /root/CodeField_C/tlpi/signals /root/CodeField_C/tlpi /root/CodeField_C/tlpi/signals /root/CodeField_C/tlpi/signals/CMakeFiles/signal_functions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : signals/CMakeFiles/signal_functions.dir/depend

