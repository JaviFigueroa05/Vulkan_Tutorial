cmake_minimum_required(VERSION 3.25)
project(MyRenderer VERSION 0.0.1)
include(GNUInstallDirs)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES *.cpp)
include_directories(
    "${CMAKE_BINARY_DIR}"
    "${CMAKE_SOURCE_DIR}/include"
    )

add_library(MyRenderer SHARED ${SOURCES})
set_target_properties(MyRenderer PROPERTIES 
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER include/MyRenderer.hpp
    )

find_package(Vulkan REQUIRED)
target_link_libraries(MyRenderer Vulkan::Vulkan)

find_package(glfw3 REQUIRED)
target_link_libraries(MyRenderer glfw)

FetchContent_Declare(
    tinyobjloader
    GIT_REPOSITORY https://github.com/tinyobjloader/tinyobjloader.git
    GIT_TAG release
    )
FetchContent_MakeAvailable(tinyobjloader)
target_link_libraries(MyRenderer tinyobjloader)

FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb.git
    GIT_TAG master
    )
FetchContent_MakeAvailable(stb)
target_link_libraries(MyRenderer stb)

configure_file(MyRenderer.pc.in MyRenderer.pc @ONLY)
install(TARGETS MyRenderer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
install(FILES ${CMAKE_BINARY_DIR}/MyRenderer.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
    )