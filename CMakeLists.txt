cmake_minimum_required(VERSION 3.25)

project(RendererDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Renderer)

add_executable(RendererDemo main.cpp)
target_link_libraries(RendererDemo PUBLIC Renderer)

target_include_directories(RendererDemo PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/Renderer"
                           )