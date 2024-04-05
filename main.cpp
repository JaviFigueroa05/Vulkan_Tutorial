#include <iostream>
#include <stdexcept>

#include "Graphics.hpp"
#include "Window.hpp"

int main() {
    Window* window = new Window(1920, 1080, "Vulkan");
    HelloTriangleApplication app(window);

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}