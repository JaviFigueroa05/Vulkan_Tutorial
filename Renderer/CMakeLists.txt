set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES *.cpp)
add_library(Renderer ${SOURCES})
include_directories(
    "${CMAKE_BINARY_DIR}"
    "${CMAKE_SOURCE_DIR}/include"
    )

find_package(Vulkan REQUIRED)
target_link_libraries(Renderer Vulkan::Vulkan)

find_package(glfw3 REQUIRED)
target_link_libraries(Renderer glfw)