#include <iostream>
#include <stdexcept>

#include "Renderer/Renderer.hpp"
#include "Renderer/Window.hpp"

const std::string MODEL_PATH = "../meshes/viking_room.obj";
const std::string TEXTURE_PATH = "../textures/viking_room.png";

int main() {
    Object viking_room(MODEL_PATH, TEXTURE_PATH);
    Window window(1080, 720, "Vulkan");
    Renderer renderer(&window);

    try {
        renderer.bindObject(&viking_room);
        renderer.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}