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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/src/character.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/character.cpp.o: src/character.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/character.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/character.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/character.cpp

CMakeFiles/game.dir/src/character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/character.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/character.cpp > CMakeFiles/game.dir/src/character.cpp.i

CMakeFiles/game.dir/src/character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/character.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/character.cpp -o CMakeFiles/game.dir/src/character.cpp.s

CMakeFiles/game.dir/src/character.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/character.cpp.o.requires

CMakeFiles/game.dir/src/character.cpp.o.provides: CMakeFiles/game.dir/src/character.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/character.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/character.cpp.o.provides

CMakeFiles/game.dir/src/character.cpp.o.provides.build: CMakeFiles/game.dir/src/character.cpp.o

CMakeFiles/game.dir/src/environment.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/environment.cpp.o: src/environment.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/environment.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/environment.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/environment.cpp

CMakeFiles/game.dir/src/environment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/environment.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/environment.cpp > CMakeFiles/game.dir/src/environment.cpp.i

CMakeFiles/game.dir/src/environment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/environment.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/environment.cpp -o CMakeFiles/game.dir/src/environment.cpp.s

CMakeFiles/game.dir/src/environment.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/environment.cpp.o.requires

CMakeFiles/game.dir/src/environment.cpp.o.provides: CMakeFiles/game.dir/src/environment.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/environment.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/environment.cpp.o.provides

CMakeFiles/game.dir/src/environment.cpp.o.provides.build: CMakeFiles/game.dir/src/environment.cpp.o

CMakeFiles/game.dir/src/forest.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/forest.cpp.o: src/forest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/forest.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/forest.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/forest.cpp

CMakeFiles/game.dir/src/forest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/forest.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/forest.cpp > CMakeFiles/game.dir/src/forest.cpp.i

CMakeFiles/game.dir/src/forest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/forest.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/forest.cpp -o CMakeFiles/game.dir/src/forest.cpp.s

CMakeFiles/game.dir/src/forest.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/forest.cpp.o.requires

CMakeFiles/game.dir/src/forest.cpp.o.provides: CMakeFiles/game.dir/src/forest.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/forest.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/forest.cpp.o.provides

CMakeFiles/game.dir/src/forest.cpp.o.provides.build: CMakeFiles/game.dir/src/forest.cpp.o

CMakeFiles/game.dir/src/game.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/game.cpp.o: src/game.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/game.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/game.cpp

CMakeFiles/game.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/game.cpp > CMakeFiles/game.dir/src/game.cpp.i

CMakeFiles/game.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/game.cpp -o CMakeFiles/game.dir/src/game.cpp.s

CMakeFiles/game.dir/src/game.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/game.cpp.o.requires

CMakeFiles/game.dir/src/game.cpp.o.provides: CMakeFiles/game.dir/src/game.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/game.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/game.cpp.o.provides

CMakeFiles/game.dir/src/game.cpp.o.provides.build: CMakeFiles/game.dir/src/game.cpp.o

CMakeFiles/game.dir/src/house.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/house.cpp.o: src/house.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/house.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/house.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/house.cpp

CMakeFiles/game.dir/src/house.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/house.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/house.cpp > CMakeFiles/game.dir/src/house.cpp.i

CMakeFiles/game.dir/src/house.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/house.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/house.cpp -o CMakeFiles/game.dir/src/house.cpp.s

CMakeFiles/game.dir/src/house.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/house.cpp.o.requires

CMakeFiles/game.dir/src/house.cpp.o.provides: CMakeFiles/game.dir/src/house.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/house.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/house.cpp.o.provides

CMakeFiles/game.dir/src/house.cpp.o.provides.build: CMakeFiles/game.dir/src/house.cpp.o

CMakeFiles/game.dir/src/human.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/human.cpp.o: src/human.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/human.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/human.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/human.cpp

CMakeFiles/game.dir/src/human.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/human.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/human.cpp > CMakeFiles/game.dir/src/human.cpp.i

CMakeFiles/game.dir/src/human.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/human.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/human.cpp -o CMakeFiles/game.dir/src/human.cpp.s

CMakeFiles/game.dir/src/human.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/human.cpp.o.requires

CMakeFiles/game.dir/src/human.cpp.o.provides: CMakeFiles/game.dir/src/human.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/human.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/human.cpp.o.provides

CMakeFiles/game.dir/src/human.cpp.o.provides.build: CMakeFiles/game.dir/src/human.cpp.o

CMakeFiles/game.dir/src/object.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/object.cpp.o: src/object.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/object.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/object.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/object.cpp

CMakeFiles/game.dir/src/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/object.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/object.cpp > CMakeFiles/game.dir/src/object.cpp.i

CMakeFiles/game.dir/src/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/object.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/object.cpp -o CMakeFiles/game.dir/src/object.cpp.s

CMakeFiles/game.dir/src/object.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/object.cpp.o.requires

CMakeFiles/game.dir/src/object.cpp.o.provides: CMakeFiles/game.dir/src/object.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/object.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/object.cpp.o.provides

CMakeFiles/game.dir/src/object.cpp.o.provides.build: CMakeFiles/game.dir/src/object.cpp.o

CMakeFiles/game.dir/src/parser.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/parser.cpp.o: src/parser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/parser.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/parser.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/parser.cpp

CMakeFiles/game.dir/src/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/parser.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/parser.cpp > CMakeFiles/game.dir/src/parser.cpp.i

CMakeFiles/game.dir/src/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/parser.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/parser.cpp -o CMakeFiles/game.dir/src/parser.cpp.s

CMakeFiles/game.dir/src/parser.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/parser.cpp.o.requires

CMakeFiles/game.dir/src/parser.cpp.o.provides: CMakeFiles/game.dir/src/parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/parser.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/parser.cpp.o.provides

CMakeFiles/game.dir/src/parser.cpp.o.provides.build: CMakeFiles/game.dir/src/parser.cpp.o

CMakeFiles/game.dir/src/boxer.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/boxer.cpp.o: src/boxer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/boxer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/boxer.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/boxer.cpp

CMakeFiles/game.dir/src/boxer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/boxer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/boxer.cpp > CMakeFiles/game.dir/src/boxer.cpp.i

CMakeFiles/game.dir/src/boxer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/boxer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/boxer.cpp -o CMakeFiles/game.dir/src/boxer.cpp.s

CMakeFiles/game.dir/src/boxer.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/boxer.cpp.o.requires

CMakeFiles/game.dir/src/boxer.cpp.o.provides: CMakeFiles/game.dir/src/boxer.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/boxer.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/boxer.cpp.o.provides

CMakeFiles/game.dir/src/boxer.cpp.o.provides.build: CMakeFiles/game.dir/src/boxer.cpp.o

CMakeFiles/game.dir/src/monster.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/monster.cpp.o: src/monster.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/monster.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/monster.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/monster.cpp

CMakeFiles/game.dir/src/monster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/monster.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/monster.cpp > CMakeFiles/game.dir/src/monster.cpp.i

CMakeFiles/game.dir/src/monster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/monster.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/monster.cpp -o CMakeFiles/game.dir/src/monster.cpp.s

CMakeFiles/game.dir/src/monster.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/monster.cpp.o.requires

CMakeFiles/game.dir/src/monster.cpp.o.provides: CMakeFiles/game.dir/src/monster.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/monster.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/monster.cpp.o.provides

CMakeFiles/game.dir/src/monster.cpp.o.provides.build: CMakeFiles/game.dir/src/monster.cpp.o

CMakeFiles/game.dir/src/troll.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/troll.cpp.o: src/troll.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.dir/src/troll.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/troll.cpp.o -c /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/troll.cpp

CMakeFiles/game.dir/src/troll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/troll.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/troll.cpp > CMakeFiles/game.dir/src/troll.cpp.i

CMakeFiles/game.dir/src/troll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/troll.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/src/troll.cpp -o CMakeFiles/game.dir/src/troll.cpp.s

CMakeFiles/game.dir/src/troll.cpp.o.requires:
.PHONY : CMakeFiles/game.dir/src/troll.cpp.o.requires

CMakeFiles/game.dir/src/troll.cpp.o.provides: CMakeFiles/game.dir/src/troll.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/troll.cpp.o.provides.build
.PHONY : CMakeFiles/game.dir/src/troll.cpp.o.provides

CMakeFiles/game.dir/src/troll.cpp.o.provides.build: CMakeFiles/game.dir/src/troll.cpp.o

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/src/character.cpp.o" \
"CMakeFiles/game.dir/src/environment.cpp.o" \
"CMakeFiles/game.dir/src/forest.cpp.o" \
"CMakeFiles/game.dir/src/game.cpp.o" \
"CMakeFiles/game.dir/src/house.cpp.o" \
"CMakeFiles/game.dir/src/human.cpp.o" \
"CMakeFiles/game.dir/src/object.cpp.o" \
"CMakeFiles/game.dir/src/parser.cpp.o" \
"CMakeFiles/game.dir/src/boxer.cpp.o" \
"CMakeFiles/game.dir/src/monster.cpp.o" \
"CMakeFiles/game.dir/src/troll.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/src/character.cpp.o
game: CMakeFiles/game.dir/src/environment.cpp.o
game: CMakeFiles/game.dir/src/forest.cpp.o
game: CMakeFiles/game.dir/src/game.cpp.o
game: CMakeFiles/game.dir/src/house.cpp.o
game: CMakeFiles/game.dir/src/human.cpp.o
game: CMakeFiles/game.dir/src/object.cpp.o
game: CMakeFiles/game.dir/src/parser.cpp.o
game: CMakeFiles/game.dir/src/boxer.cpp.o
game: CMakeFiles/game.dir/src/monster.cpp.o
game: CMakeFiles/game.dir/src/troll.cpp.o
game: CMakeFiles/game.dir/build.make
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game
.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/character.cpp.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/environment.cpp.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/forest.cpp.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/game.cpp.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/house.cpp.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/human.cpp.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/object.cpp.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/parser.cpp.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/boxer.cpp.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/monster.cpp.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/src/troll.cpp.o.requires
.PHONY : CMakeFiles/game.dir/requires

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3 /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3 /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3 /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3 /afs/nada.kth.se/home/z/u1xpi8dz/kurser/cprog12/lab3/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

