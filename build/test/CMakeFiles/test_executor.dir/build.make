# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Programming Studio\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Programming Studio\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build

# Include any dependencies generated for this target.
include test/CMakeFiles/test_executor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_executor.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_executor.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_executor.dir/flags.make

test/CMakeFiles/test_executor.dir/executor_test.cc.obj: test/CMakeFiles/test_executor.dir/flags.make
test/CMakeFiles/test_executor.dir/executor_test.cc.obj: test/CMakeFiles/test_executor.dir/includes_CXX.rsp
test/CMakeFiles/test_executor.dir/executor_test.cc.obj: E:/cpp/git_repository/RepoForCommunication/tyx/cpp/Huawei/executor_bootstrap-master/test/executor_test.cc
test/CMakeFiles/test_executor.dir/executor_test.cc.obj: test/CMakeFiles/test_executor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_executor.dir/executor_test.cc.obj"
	cd /d E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build\test && "E:\Programming Studio\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_executor.dir/executor_test.cc.obj -MF CMakeFiles\test_executor.dir\executor_test.cc.obj.d -o CMakeFiles\test_executor.dir\executor_test.cc.obj -c E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\test\executor_test.cc

test/CMakeFiles/test_executor.dir/executor_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_executor.dir/executor_test.cc.i"
	cd /d E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build\test && "E:\Programming Studio\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\test\executor_test.cc > CMakeFiles\test_executor.dir\executor_test.cc.i

test/CMakeFiles/test_executor.dir/executor_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_executor.dir/executor_test.cc.s"
	cd /d E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build\test && "E:\Programming Studio\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\test\executor_test.cc -o CMakeFiles\test_executor.dir\executor_test.cc.s

# Object files for target test_executor
test_executor_OBJECTS = \
"CMakeFiles/test_executor.dir/executor_test.cc.obj"

# External object files for target test_executor
test_executor_EXTERNAL_OBJECTS =

test/test_executor.exe: test/CMakeFiles/test_executor.dir/executor_test.cc.obj
test/test_executor.exe: test/CMakeFiles/test_executor.dir/build.make
test/test_executor.exe: src/libexecutor.a
test/test_executor.exe: lib/libgtest_main.a
test/test_executor.exe: lib/libgtest.a
test/test_executor.exe: test/CMakeFiles/test_executor.dir/linklibs.rsp
test/test_executor.exe: test/CMakeFiles/test_executor.dir/objects1.rsp
test/test_executor.exe: test/CMakeFiles/test_executor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_executor.exe"
	cd /d E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_executor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_executor.dir/build: test/test_executor.exe
.PHONY : test/CMakeFiles/test_executor.dir/build

test/CMakeFiles/test_executor.dir/clean:
	cd /d E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build\test && $(CMAKE_COMMAND) -P CMakeFiles\test_executor.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/test_executor.dir/clean

test/CMakeFiles/test_executor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\test E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build\test E:\cpp\git_repository\RepoForCommunication\tyx\cpp\Huawei\executor_bootstrap-master\build\test\CMakeFiles\test_executor.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_executor.dir/depend
