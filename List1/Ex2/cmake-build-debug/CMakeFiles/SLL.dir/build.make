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
CMAKE_SOURCE_DIR = C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SLL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SLL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SLL.dir/flags.make

CMakeFiles/SLL.dir/singlyLinkedList.c.obj: CMakeFiles/SLL.dir/flags.make
CMakeFiles/SLL.dir/singlyLinkedList.c.obj: ../singlyLinkedList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SLL.dir/singlyLinkedList.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SLL.dir\singlyLinkedList.c.obj   -c C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2\singlyLinkedList.c

CMakeFiles/SLL.dir/singlyLinkedList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SLL.dir/singlyLinkedList.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2\singlyLinkedList.c > CMakeFiles\SLL.dir\singlyLinkedList.c.i

CMakeFiles/SLL.dir/singlyLinkedList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SLL.dir/singlyLinkedList.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2\singlyLinkedList.c -o CMakeFiles\SLL.dir\singlyLinkedList.c.s

CMakeFiles/SLL.dir/singlyLinkedList.c.obj.requires:

.PHONY : CMakeFiles/SLL.dir/singlyLinkedList.c.obj.requires

CMakeFiles/SLL.dir/singlyLinkedList.c.obj.provides: CMakeFiles/SLL.dir/singlyLinkedList.c.obj.requires
	$(MAKE) -f CMakeFiles\SLL.dir\build.make CMakeFiles/SLL.dir/singlyLinkedList.c.obj.provides.build
.PHONY : CMakeFiles/SLL.dir/singlyLinkedList.c.obj.provides

CMakeFiles/SLL.dir/singlyLinkedList.c.obj.provides.build: CMakeFiles/SLL.dir/singlyLinkedList.c.obj


# Object files for target SLL
SLL_OBJECTS = \
"CMakeFiles/SLL.dir/singlyLinkedList.c.obj"

# External object files for target SLL
SLL_EXTERNAL_OBJECTS =

SLL.exe: CMakeFiles/SLL.dir/singlyLinkedList.c.obj
SLL.exe: CMakeFiles/SLL.dir/build.make
SLL.exe: CMakeFiles/SLL.dir/linklibs.rsp
SLL.exe: CMakeFiles/SLL.dir/objects1.rsp
SLL.exe: CMakeFiles/SLL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SLL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SLL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SLL.dir/build: SLL.exe

.PHONY : CMakeFiles/SLL.dir/build

CMakeFiles/SLL.dir/requires: CMakeFiles/SLL.dir/singlyLinkedList.c.obj.requires

.PHONY : CMakeFiles/SLL.dir/requires

CMakeFiles/SLL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SLL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SLL.dir/clean

CMakeFiles/SLL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2 C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2 C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2\cmake-build-debug C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2\cmake-build-debug C:\Users\Krzysztof\Desktop\AiSD\List1\Ex2\cmake-build-debug\CMakeFiles\SLL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SLL.dir/depend
