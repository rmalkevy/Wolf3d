# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Henprokuror/CLionProjects/Wolfenstain

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Henprokuror/CLionProjects/Wolfenstain/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Wolfenstain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Wolfenstain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wolfenstain.dir/flags.make

CMakeFiles/Wolfenstain.dir/main.c.o: CMakeFiles/Wolfenstain.dir/flags.make
CMakeFiles/Wolfenstain.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Henprokuror/CLionProjects/Wolfenstain/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Wolfenstain.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolfenstain.dir/main.c.o   -c /Users/Henprokuror/CLionProjects/Wolfenstain/main.c

CMakeFiles/Wolfenstain.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolfenstain.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Henprokuror/CLionProjects/Wolfenstain/main.c > CMakeFiles/Wolfenstain.dir/main.c.i

CMakeFiles/Wolfenstain.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolfenstain.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Henprokuror/CLionProjects/Wolfenstain/main.c -o CMakeFiles/Wolfenstain.dir/main.c.s

CMakeFiles/Wolfenstain.dir/main.c.o.requires:

.PHONY : CMakeFiles/Wolfenstain.dir/main.c.o.requires

CMakeFiles/Wolfenstain.dir/main.c.o.provides: CMakeFiles/Wolfenstain.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Wolfenstain.dir/build.make CMakeFiles/Wolfenstain.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Wolfenstain.dir/main.c.o.provides

CMakeFiles/Wolfenstain.dir/main.c.o.provides.build: CMakeFiles/Wolfenstain.dir/main.c.o


CMakeFiles/Wolfenstain.dir/draw.c.o: CMakeFiles/Wolfenstain.dir/flags.make
CMakeFiles/Wolfenstain.dir/draw.c.o: ../draw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Henprokuror/CLionProjects/Wolfenstain/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Wolfenstain.dir/draw.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolfenstain.dir/draw.c.o   -c /Users/Henprokuror/CLionProjects/Wolfenstain/draw.c

CMakeFiles/Wolfenstain.dir/draw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolfenstain.dir/draw.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Henprokuror/CLionProjects/Wolfenstain/draw.c > CMakeFiles/Wolfenstain.dir/draw.c.i

CMakeFiles/Wolfenstain.dir/draw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolfenstain.dir/draw.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Henprokuror/CLionProjects/Wolfenstain/draw.c -o CMakeFiles/Wolfenstain.dir/draw.c.s

CMakeFiles/Wolfenstain.dir/draw.c.o.requires:

.PHONY : CMakeFiles/Wolfenstain.dir/draw.c.o.requires

CMakeFiles/Wolfenstain.dir/draw.c.o.provides: CMakeFiles/Wolfenstain.dir/draw.c.o.requires
	$(MAKE) -f CMakeFiles/Wolfenstain.dir/build.make CMakeFiles/Wolfenstain.dir/draw.c.o.provides.build
.PHONY : CMakeFiles/Wolfenstain.dir/draw.c.o.provides

CMakeFiles/Wolfenstain.dir/draw.c.o.provides.build: CMakeFiles/Wolfenstain.dir/draw.c.o


CMakeFiles/Wolfenstain.dir/key.c.o: CMakeFiles/Wolfenstain.dir/flags.make
CMakeFiles/Wolfenstain.dir/key.c.o: ../key.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Henprokuror/CLionProjects/Wolfenstain/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Wolfenstain.dir/key.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolfenstain.dir/key.c.o   -c /Users/Henprokuror/CLionProjects/Wolfenstain/key.c

CMakeFiles/Wolfenstain.dir/key.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolfenstain.dir/key.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Henprokuror/CLionProjects/Wolfenstain/key.c > CMakeFiles/Wolfenstain.dir/key.c.i

CMakeFiles/Wolfenstain.dir/key.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolfenstain.dir/key.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Henprokuror/CLionProjects/Wolfenstain/key.c -o CMakeFiles/Wolfenstain.dir/key.c.s

CMakeFiles/Wolfenstain.dir/key.c.o.requires:

.PHONY : CMakeFiles/Wolfenstain.dir/key.c.o.requires

CMakeFiles/Wolfenstain.dir/key.c.o.provides: CMakeFiles/Wolfenstain.dir/key.c.o.requires
	$(MAKE) -f CMakeFiles/Wolfenstain.dir/build.make CMakeFiles/Wolfenstain.dir/key.c.o.provides.build
.PHONY : CMakeFiles/Wolfenstain.dir/key.c.o.provides

CMakeFiles/Wolfenstain.dir/key.c.o.provides.build: CMakeFiles/Wolfenstain.dir/key.c.o


CMakeFiles/Wolfenstain.dir/window.c.o: CMakeFiles/Wolfenstain.dir/flags.make
CMakeFiles/Wolfenstain.dir/window.c.o: ../window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Henprokuror/CLionProjects/Wolfenstain/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Wolfenstain.dir/window.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolfenstain.dir/window.c.o   -c /Users/Henprokuror/CLionProjects/Wolfenstain/window.c

CMakeFiles/Wolfenstain.dir/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolfenstain.dir/window.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Henprokuror/CLionProjects/Wolfenstain/window.c > CMakeFiles/Wolfenstain.dir/window.c.i

CMakeFiles/Wolfenstain.dir/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolfenstain.dir/window.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Henprokuror/CLionProjects/Wolfenstain/window.c -o CMakeFiles/Wolfenstain.dir/window.c.s

CMakeFiles/Wolfenstain.dir/window.c.o.requires:

.PHONY : CMakeFiles/Wolfenstain.dir/window.c.o.requires

CMakeFiles/Wolfenstain.dir/window.c.o.provides: CMakeFiles/Wolfenstain.dir/window.c.o.requires
	$(MAKE) -f CMakeFiles/Wolfenstain.dir/build.make CMakeFiles/Wolfenstain.dir/window.c.o.provides.build
.PHONY : CMakeFiles/Wolfenstain.dir/window.c.o.provides

CMakeFiles/Wolfenstain.dir/window.c.o.provides.build: CMakeFiles/Wolfenstain.dir/window.c.o


# Object files for target Wolfenstain
Wolfenstain_OBJECTS = \
"CMakeFiles/Wolfenstain.dir/main.c.o" \
"CMakeFiles/Wolfenstain.dir/draw.c.o" \
"CMakeFiles/Wolfenstain.dir/key.c.o" \
"CMakeFiles/Wolfenstain.dir/window.c.o"

# External object files for target Wolfenstain
Wolfenstain_EXTERNAL_OBJECTS =

Wolfenstain: CMakeFiles/Wolfenstain.dir/main.c.o
Wolfenstain: CMakeFiles/Wolfenstain.dir/draw.c.o
Wolfenstain: CMakeFiles/Wolfenstain.dir/key.c.o
Wolfenstain: CMakeFiles/Wolfenstain.dir/window.c.o
Wolfenstain: CMakeFiles/Wolfenstain.dir/build.make
Wolfenstain: CMakeFiles/Wolfenstain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Henprokuror/CLionProjects/Wolfenstain/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Wolfenstain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Wolfenstain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wolfenstain.dir/build: Wolfenstain

.PHONY : CMakeFiles/Wolfenstain.dir/build

CMakeFiles/Wolfenstain.dir/requires: CMakeFiles/Wolfenstain.dir/main.c.o.requires
CMakeFiles/Wolfenstain.dir/requires: CMakeFiles/Wolfenstain.dir/draw.c.o.requires
CMakeFiles/Wolfenstain.dir/requires: CMakeFiles/Wolfenstain.dir/key.c.o.requires
CMakeFiles/Wolfenstain.dir/requires: CMakeFiles/Wolfenstain.dir/window.c.o.requires

.PHONY : CMakeFiles/Wolfenstain.dir/requires

CMakeFiles/Wolfenstain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Wolfenstain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Wolfenstain.dir/clean

CMakeFiles/Wolfenstain.dir/depend:
	cd /Users/Henprokuror/CLionProjects/Wolfenstain/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Henprokuror/CLionProjects/Wolfenstain /Users/Henprokuror/CLionProjects/Wolfenstain /Users/Henprokuror/CLionProjects/Wolfenstain/cmake-build-debug /Users/Henprokuror/CLionProjects/Wolfenstain/cmake-build-debug /Users/Henprokuror/CLionProjects/Wolfenstain/cmake-build-debug/CMakeFiles/Wolfenstain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Wolfenstain.dir/depend

