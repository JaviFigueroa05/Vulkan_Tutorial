#include <iostream>
#include <stdexcept>
#include <chrono>

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "_deps/tracy-src/public/tracy/Tracy.hpp"

#include "Renderer/Renderer.hpp"
#include "Renderer/Window.hpp"
#include "Renderer/Camera.hpp"

const std::string MODEL_PATH = "../meshes/viking_room.obj";
const std::string TEXTURE_PATH = "../textures/viking_room.png";

const int WIDTH = 1080;
const int HEIGHT = 720;

int main() {
    Window window(WIDTH, HEIGHT, "Vulkan");
    Renderer renderer(&window);
    Object viking_room(MODEL_PATH, TEXTURE_PATH);
    Camera camera(glm::vec3(2.f, .0f, 2.f), glm::vec3(.0f, .0f, .0f), glm::vec3(.0f, .0f, 1.f), 45.f, WIDTH / (float)HEIGHT, .1f, 10.f);

    try {
        renderer.bindObject(&viking_room);
        auto currentTime = std::chrono::high_resolution_clock::now();
        while (!window.ShouldClose())
        {
            float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(std::chrono::high_resolution_clock::now() - currentTime).count();
            currentTime = std::chrono::high_resolution_clock::now();
            
            glm::vec3 cameraDirection = glm::vec3(.0f, .0f, .0f);

            window.PollEvents();
            if (window.isKeyPressed(GLFW_KEY_W))
                cameraDirection += glm::vec3(-1.f, .0f, .0f);
            if (window.isKeyPressed(GLFW_KEY_A))
                cameraDirection += glm::vec3(.0f, -1.f, .0f);
            if (window.isKeyPressed(GLFW_KEY_S))
                cameraDirection += glm::vec3(1.f, .0f, .0f);
            if (window.isKeyPressed(GLFW_KEY_D))
                cameraDirection += glm::vec3(0.f, 1.f, .0f);

            camera.move(deltaTime * cameraDirection);
            renderer.bindCamera(&camera);
            renderer.drawFrame();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}