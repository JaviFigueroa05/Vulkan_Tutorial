cmake_minimum_required(VERSION 3.25)

project(VulkanRenderer VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(VulkanRenderer main.cpp Graphics.hpp Window.cpp)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

find_package(Vulkan REQUIRED)
target_link_libraries(VulkanRenderer Vulkan::Vulkan)

find_package(glfw3 REQUIRED)
target_link_libraries(VulkanRenderer glfw)