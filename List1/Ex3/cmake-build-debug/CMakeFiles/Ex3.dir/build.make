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
CMAKE_SOURCE_DIR = C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ex3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ex3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ex3.dir/flags.make

CMakeFiles/Ex3.dir/main.c.obj: CMakeFiles/Ex3.dir/flags.make
CMakeFiles/Ex3.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Ex3.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Ex3.dir\main.c.obj   -c C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3\main.c

CMakeFiles/Ex3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex3.dir/main.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3\main.c > CMakeFiles\Ex3.dir\main.c.i

CMakeFiles/Ex3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex3.dir/main.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3\main.c -o CMakeFiles\Ex3.dir\main.c.s

CMakeFiles/Ex3.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Ex3.dir/main.c.obj.requires

CMakeFiles/Ex3.dir/main.c.obj.provides: CMakeFiles/Ex3.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Ex3.dir\build.make CMakeFiles/Ex3.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Ex3.dir/main.c.obj.provides

CMakeFiles/Ex3.dir/main.c.obj.provides.build: CMakeFiles/Ex3.dir/main.c.obj


# Object files for target Ex3
Ex3_OBJECTS = \
"CMakeFiles/Ex3.dir/main.c.obj"

# External object files for target Ex3
Ex3_EXTERNAL_OBJECTS =

Ex3.exe: CMakeFiles/Ex3.dir/main.c.obj
Ex3.exe: CMakeFiles/Ex3.dir/build.make
Ex3.exe: CMakeFiles/Ex3.dir/linklibs.rsp
Ex3.exe: CMakeFiles/Ex3.dir/objects1.rsp
Ex3.exe: CMakeFiles/Ex3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Ex3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ex3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ex3.dir/build: Ex3.exe

.PHONY : CMakeFiles/Ex3.dir/build

CMakeFiles/Ex3.dir/requires: CMakeFiles/Ex3.dir/main.c.obj.requires

.PHONY : CMakeFiles/Ex3.dir/requires

CMakeFiles/Ex3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ex3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ex3.dir/clean

CMakeFiles/Ex3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3 C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3 C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3\cmake-build-debug C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3\cmake-build-debug C:\Users\Krzysztof\Desktop\AiSD\List1\Ex3\cmake-build-debug\CMakeFiles\Ex3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ex3.dir/depend

