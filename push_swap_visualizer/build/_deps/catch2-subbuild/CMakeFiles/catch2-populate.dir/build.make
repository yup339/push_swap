# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild

# Utility rule file for catch2-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/catch2-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/catch2-populate.dir/progress.make

CMakeFiles/catch2-populate: CMakeFiles/catch2-populate-complete

CMakeFiles/catch2-populate-complete: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-install
CMakeFiles/catch2-populate-complete: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-mkdir
CMakeFiles/catch2-populate-complete: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-download
CMakeFiles/catch2-populate-complete: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-update
CMakeFiles/catch2-populate-complete: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-patch
CMakeFiles/catch2-populate-complete: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-configure
CMakeFiles/catch2-populate-complete: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-build
CMakeFiles/catch2-populate-complete: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-install
CMakeFiles/catch2-populate-complete: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'catch2-populate'"
	/Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E make_directory /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles
	/Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E touch /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles/catch2-populate-complete
	/Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E touch /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-done

catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-update:
.PHONY : catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-update

catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-build: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'catch2-populate'"
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-build && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E echo_append
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-build && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E touch /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-build

catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-configure: catch2-populate-prefix/tmp/catch2-populate-cfgcmd.txt
catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-configure: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'catch2-populate'"
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-build && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E echo_append
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-build && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E touch /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-configure

catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-download: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-gitinfo.txt
catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-download: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'catch2-populate'"
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -P /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/tmp/catch2-populate-gitclone.cmake
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E touch /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-download

catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-install: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'catch2-populate'"
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-build && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E echo_append
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-build && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E touch /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-install

catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'catch2-populate'"
	/Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -Dcfgdir= -P /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/tmp/catch2-populate-mkdirs.cmake
	/Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E touch /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-mkdir

catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-patch: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'catch2-populate'"
	/Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E echo_append
	/Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E touch /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-patch

catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-update:
.PHONY : catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-update

catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-test: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'catch2-populate'"
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-build && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E echo_append
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-build && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -E touch /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-test

catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-update: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'catch2-populate'"
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-src && /Users/pbergero/.brew/Cellar/cmake/3.25.1/bin/cmake -P /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/tmp/catch2-populate-gitupdate.cmake

catch2-populate: CMakeFiles/catch2-populate
catch2-populate: CMakeFiles/catch2-populate-complete
catch2-populate: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-build
catch2-populate: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-configure
catch2-populate: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-download
catch2-populate: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-install
catch2-populate: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-mkdir
catch2-populate: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-patch
catch2-populate: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-test
catch2-populate: catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-update
catch2-populate: CMakeFiles/catch2-populate.dir/build.make
.PHONY : catch2-populate

# Rule to build all files generated by this target.
CMakeFiles/catch2-populate.dir/build: catch2-populate
.PHONY : CMakeFiles/catch2-populate.dir/build

CMakeFiles/catch2-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/catch2-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/catch2-populate.dir/clean

CMakeFiles/catch2-populate.dir/depend:
	cd /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild /Users/pbergero/Desktop/push_swap/build/push_swap_visualizer/build/_deps/catch2-subbuild/CMakeFiles/catch2-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/catch2-populate.dir/depend

