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
CMAKE_COMMAND = /home/javier/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/javier/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/javier/Documents/Vulkan_Tutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/javier/Documents/Vulkan_Tutorial

# Utility rule file for shaders.

# Include any custom commands dependencies for this target.
include shaders/CMakeFiles/shaders.dir/compiler_depend.make

# Include the progress variables for this target.
include shaders/CMakeFiles/shaders.dir/progress.make

shaders/CMakeFiles/shaders: shaders/shader.frag.spv
shaders/CMakeFiles/shaders: shaders/shader.vert.spv
shaders/CMakeFiles/shaders: shaders/shader_compute.comp.spv
shaders/CMakeFiles/shaders: shaders/shader_compute.frag.spv
shaders/CMakeFiles/shaders: shaders/shader_compute.vert.spv

shaders/shader.frag.spv: shaders/shader.frag
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/javier/Documents/Vulkan_Tutorial/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Compiling shader.frag"
	cd /home/javier/Documents/Vulkan_Tutorial/shaders && glslc /home/javier/Documents/Vulkan_Tutorial/shaders/shader.frag -o shader.frag.spv

shaders/shader.vert.spv: shaders/shader.vert
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/javier/Documents/Vulkan_Tutorial/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Compiling shader.vert"
	cd /home/javier/Documents/Vulkan_Tutorial/shaders && glslc /home/javier/Documents/Vulkan_Tutorial/shaders/shader.vert -o shader.vert.spv

shaders/shader_compute.comp.spv: shaders/shader_compute.comp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/javier/Documents/Vulkan_Tutorial/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Compiling shader_compute.comp"
	cd /home/javier/Documents/Vulkan_Tutorial/shaders && glslc /home/javier/Documents/Vulkan_Tutorial/shaders/shader_compute.comp -o shader_compute.comp.spv

shaders/shader_compute.frag.spv: shaders/shader_compute.frag
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/javier/Documents/Vulkan_Tutorial/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Compiling shader_compute.frag"
	cd /home/javier/Documents/Vulkan_Tutorial/shaders && glslc /home/javier/Documents/Vulkan_Tutorial/shaders/shader_compute.frag -o shader_compute.frag.spv

shaders/shader_compute.vert.spv: shaders/shader_compute.vert
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/javier/Documents/Vulkan_Tutorial/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Compiling shader_compute.vert"
	cd /home/javier/Documents/Vulkan_Tutorial/shaders && glslc /home/javier/Documents/Vulkan_Tutorial/shaders/shader_compute.vert -o shader_compute.vert.spv

shaders: shaders/CMakeFiles/shaders
shaders: shaders/shader.frag.spv
shaders: shaders/shader.vert.spv
shaders: shaders/shader_compute.comp.spv
shaders: shaders/shader_compute.frag.spv
shaders: shaders/shader_compute.vert.spv
shaders: shaders/CMakeFiles/shaders.dir/build.make
.PHONY : shaders

# Rule to build all files generated by this target.
shaders/CMakeFiles/shaders.dir/build: shaders
.PHONY : shaders/CMakeFiles/shaders.dir/build

shaders/CMakeFiles/shaders.dir/clean:
	cd /home/javier/Documents/Vulkan_Tutorial/shaders && $(CMAKE_COMMAND) -P CMakeFiles/shaders.dir/cmake_clean.cmake
.PHONY : shaders/CMakeFiles/shaders.dir/clean

shaders/CMakeFiles/shaders.dir/depend:
	cd /home/javier/Documents/Vulkan_Tutorial && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javier/Documents/Vulkan_Tutorial /home/javier/Documents/Vulkan_Tutorial/shaders /home/javier/Documents/Vulkan_Tutorial /home/javier/Documents/Vulkan_Tutorial/shaders /home/javier/Documents/Vulkan_Tutorial/shaders/CMakeFiles/shaders.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : shaders/CMakeFiles/shaders.dir/depend
