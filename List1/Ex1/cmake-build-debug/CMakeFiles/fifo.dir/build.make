# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fifo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fifo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fifo.dir/flags.make

CMakeFiles/fifo.dir/fifo.c.obj: CMakeFiles/fifo.dir/flags.make
CMakeFiles/fifo.dir/fifo.c.obj: ../fifo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fifo.dir/fifo.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\fifo.dir\fifo.c.obj   -c C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1\fifo.c

CMakeFiles/fifo.dir/fifo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fifo.dir/fifo.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1\fifo.c > CMakeFiles\fifo.dir\fifo.c.i

CMakeFiles/fifo.dir/fifo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fifo.dir/fifo.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1\fifo.c -o CMakeFiles\fifo.dir\fifo.c.s

CMakeFiles/fifo.dir/fifo.c.obj.requires:

.PHONY : CMakeFiles/fifo.dir/fifo.c.obj.requires

CMakeFiles/fifo.dir/fifo.c.obj.provides: CMakeFiles/fifo.dir/fifo.c.obj.requires
	$(MAKE) -f CMakeFiles\fifo.dir\build.make CMakeFiles/fifo.dir/fifo.c.obj.provides.build
.PHONY : CMakeFiles/fifo.dir/fifo.c.obj.provides

CMakeFiles/fifo.dir/fifo.c.obj.provides.build: CMakeFiles/fifo.dir/fifo.c.obj


# Object files for target fifo
fifo_OBJECTS = \
"CMakeFiles/fifo.dir/fifo.c.obj"

# External object files for target fifo
fifo_EXTERNAL_OBJECTS =

fifo.exe: CMakeFiles/fifo.dir/fifo.c.obj
fifo.exe: CMakeFiles/fifo.dir/build.make
fifo.exe: CMakeFiles/fifo.dir/linklibs.rsp
fifo.exe: CMakeFiles/fifo.dir/objects1.rsp
fifo.exe: CMakeFiles/fifo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fifo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\fifo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fifo.dir/build: fifo.exe

.PHONY : CMakeFiles/fifo.dir/build

CMakeFiles/fifo.dir/requires: CMakeFiles/fifo.dir/fifo.c.obj.requires

.PHONY : CMakeFiles/fifo.dir/requires

CMakeFiles/fifo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\fifo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/fifo.dir/clean

CMakeFiles/fifo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1 C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1 C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1\cmake-build-debug C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1\cmake-build-debug C:\Users\Krzysztof\Desktop\AiSD\List1\Ex1\cmake-build-debug\CMakeFiles\fifo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fifo.dir/depend
