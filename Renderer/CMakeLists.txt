add_library(Renderer Renderer.cpp Window.cpp Vertex.cpp Object.cpp)
include_directories("${CMAKE_SOURCE_DIR}/include")

find_package(Vulkan REQUIRED)
target_link_libraries(Renderer Vulkan::Vulkan)

find_package(glfw3 REQUIRED)
target_link_libraries(Renderer glfw)