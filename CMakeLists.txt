cmake_minimum_required(VERSION 3.25)
include(FetchContent)

project(RendererDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

FetchContent_Declare(
    tracy
    GIT_REPOSITORY https://github.com/wolfpld/tracy.git
    GIT_TAG v0.10
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(tracy)

add_subdirectory(Renderer)
add_subdirectory(shaders)

option(TRACY_ENABLE "" ON)
option(TRACY_ON_DEMAND "" ON)
option(TRACY_NO_SAMPLING "" ON)

add_executable(RendererDemo main.cpp)
target_link_libraries(RendererDemo PUBLIC Renderer)
target_link_libraries(RendererDemo PUBLIC Tracy::TracyClient)
add_dependencies(RendererDemo shaders)

target_include_directories(RendererDemo PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/Renderer"
                           )

