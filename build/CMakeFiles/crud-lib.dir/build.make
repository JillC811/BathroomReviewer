# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/justintsang/CS3307 group project/group11/example-crud-master"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/justintsang/CS3307 group project/group11/build"

# Include any dependencies generated for this target.
include CMakeFiles/crud-lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/crud-lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/crud-lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/crud-lib.dir/flags.make

CMakeFiles/crud-lib.dir/src/Objects/User.cpp.o: CMakeFiles/crud-lib.dir/flags.make
CMakeFiles/crud-lib.dir/src/Objects/User.cpp.o: /Users/justintsang/CS3307\ group\ project/group11/example-crud-master/src/Objects/User.cpp
CMakeFiles/crud-lib.dir/src/Objects/User.cpp.o: CMakeFiles/crud-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/justintsang/CS3307 group project/group11/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/crud-lib.dir/src/Objects/User.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/crud-lib.dir/src/Objects/User.cpp.o -MF CMakeFiles/crud-lib.dir/src/Objects/User.cpp.o.d -o CMakeFiles/crud-lib.dir/src/Objects/User.cpp.o -c "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/Objects/User.cpp"

CMakeFiles/crud-lib.dir/src/Objects/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/crud-lib.dir/src/Objects/User.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/Objects/User.cpp" > CMakeFiles/crud-lib.dir/src/Objects/User.cpp.i

CMakeFiles/crud-lib.dir/src/Objects/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/crud-lib.dir/src/Objects/User.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/Objects/User.cpp" -o CMakeFiles/crud-lib.dir/src/Objects/User.cpp.s

CMakeFiles/crud-lib.dir/src/service/UserService.cpp.o: CMakeFiles/crud-lib.dir/flags.make
CMakeFiles/crud-lib.dir/src/service/UserService.cpp.o: /Users/justintsang/CS3307\ group\ project/group11/example-crud-master/src/service/UserService.cpp
CMakeFiles/crud-lib.dir/src/service/UserService.cpp.o: CMakeFiles/crud-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/justintsang/CS3307 group project/group11/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/crud-lib.dir/src/service/UserService.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/crud-lib.dir/src/service/UserService.cpp.o -MF CMakeFiles/crud-lib.dir/src/service/UserService.cpp.o.d -o CMakeFiles/crud-lib.dir/src/service/UserService.cpp.o -c "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/service/UserService.cpp"

CMakeFiles/crud-lib.dir/src/service/UserService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/crud-lib.dir/src/service/UserService.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/service/UserService.cpp" > CMakeFiles/crud-lib.dir/src/service/UserService.cpp.i

CMakeFiles/crud-lib.dir/src/service/UserService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/crud-lib.dir/src/service/UserService.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/service/UserService.cpp" -o CMakeFiles/crud-lib.dir/src/service/UserService.cpp.s

CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.o: CMakeFiles/crud-lib.dir/flags.make
CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.o: /Users/justintsang/CS3307\ group\ project/group11/example-crud-master/src/service/BathroomService.cpp
CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.o: CMakeFiles/crud-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/justintsang/CS3307 group project/group11/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.o -MF CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.o.d -o CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.o -c "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/service/BathroomService.cpp"

CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/service/BathroomService.cpp" > CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.i

CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/service/BathroomService.cpp" -o CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.s

CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.o: CMakeFiles/crud-lib.dir/flags.make
CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.o: /Users/justintsang/CS3307\ group\ project/group11/example-crud-master/src/service/BuildingService.cpp
CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.o: CMakeFiles/crud-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/justintsang/CS3307 group project/group11/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.o -MF CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.o.d -o CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.o -c "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/service/BuildingService.cpp"

CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/service/BuildingService.cpp" > CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.i

CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/service/BuildingService.cpp" -o CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.s

CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.o: CMakeFiles/crud-lib.dir/flags.make
CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.o: /Users/justintsang/CS3307\ group\ project/group11/example-crud-master/src/ErrorHandler.cpp
CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.o: CMakeFiles/crud-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/justintsang/CS3307 group project/group11/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.o -MF CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.o.d -o CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.o -c "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/ErrorHandler.cpp"

CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/ErrorHandler.cpp" > CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.i

CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/justintsang/CS3307 group project/group11/example-crud-master/src/ErrorHandler.cpp" -o CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.s

# Object files for target crud-lib
crud__lib_OBJECTS = \
"CMakeFiles/crud-lib.dir/src/Objects/User.cpp.o" \
"CMakeFiles/crud-lib.dir/src/service/UserService.cpp.o" \
"CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.o" \
"CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.o" \
"CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.o"

# External object files for target crud-lib
crud__lib_EXTERNAL_OBJECTS =

libcrud-lib.a: CMakeFiles/crud-lib.dir/src/Objects/User.cpp.o
libcrud-lib.a: CMakeFiles/crud-lib.dir/src/service/UserService.cpp.o
libcrud-lib.a: CMakeFiles/crud-lib.dir/src/service/BathroomService.cpp.o
libcrud-lib.a: CMakeFiles/crud-lib.dir/src/service/BuildingService.cpp.o
libcrud-lib.a: CMakeFiles/crud-lib.dir/src/ErrorHandler.cpp.o
libcrud-lib.a: CMakeFiles/crud-lib.dir/build.make
libcrud-lib.a: CMakeFiles/crud-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/justintsang/CS3307 group project/group11/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libcrud-lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/crud-lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/crud-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/crud-lib.dir/build: libcrud-lib.a
.PHONY : CMakeFiles/crud-lib.dir/build

CMakeFiles/crud-lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/crud-lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/crud-lib.dir/clean

CMakeFiles/crud-lib.dir/depend:
	cd "/Users/justintsang/CS3307 group project/group11/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/justintsang/CS3307 group project/group11/example-crud-master" "/Users/justintsang/CS3307 group project/group11/example-crud-master" "/Users/justintsang/CS3307 group project/group11/build" "/Users/justintsang/CS3307 group project/group11/build" "/Users/justintsang/CS3307 group project/group11/build/CMakeFiles/crud-lib.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/crud-lib.dir/depend
