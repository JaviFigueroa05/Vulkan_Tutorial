#include <iostream>
#include <stdexcept>

#include "Renderer/Renderer.hpp"
#include "Renderer/Window.hpp"

int main() {
    Window window(1080, 720, "Vulkan");
    Renderer renderer(&window);

    try {
        renderer.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}