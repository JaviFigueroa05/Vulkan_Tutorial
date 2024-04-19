cmake_minimum_required(VERSION 3.25)
include(FetchContent)

project(RendererDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(MyRenderer)
add_subdirectory(shaders)

add_executable(RendererDemo main.cpp)
target_link_libraries(RendererDemo PUBLIC MyRenderer)
add_dependencies(RendererDemo shaders)

target_include_directories(RendererDemo PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/MyRenderer"
                           )

