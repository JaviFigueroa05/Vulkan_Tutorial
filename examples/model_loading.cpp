#include <iostream>
#include <stdexcept>
#include <chrono>

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "Renderer/Renderer.hpp"
#include "Renderer/Window.hpp"
#include "Renderer/Camera.hpp"
#include <tuple>

const std::string MODEL_PATH = "../examples/meshes/viking_room.obj";
const std::string TEXTURE_PATH = "../examples/textures/viking_room.png";

const int WIDTH = 1080;
const int HEIGHT = 720;
const float MOVE_SPEED = 1.f;
const float ROTATE_SPEED = .002f;

float deltaTime = 0;

void logger() {
    std::cout << "\rFPS: " << (int)(1/deltaTime);
}

int main() {
    Window window(WIDTH, HEIGHT, "Vulkan");
    Renderer renderer(&window);
    Object viking_room(MODEL_PATH, TEXTURE_PATH);
    Camera camera(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.f), glm::vec3(.0f, .0f, 1.f), 45.f, WIDTH / (float)HEIGHT, .1f, 10.f);

    try {
        renderer.bindObject(&viking_room);
        auto currentTime = std::chrono::high_resolution_clock::now();
        float lastCursorX, lastCursorY;
        std::tie(lastCursorX, lastCursorY) = window.GetCursorPos();
        while (!window.ShouldClose())
        {
            currentTime = std::chrono::high_resolution_clock::now();
            
            window.PollEvents();
            glm::vec3 cameraDirection = glm::vec3(.0f);
            if (window.isKeyPressed(GLFW_KEY_W))
                cameraDirection += glm::vec3(.0f, .0f, MOVE_SPEED);
            if (window.isKeyPressed(GLFW_KEY_A))
                cameraDirection += glm::vec3(-MOVE_SPEED, .0f, .0f);
            if (window.isKeyPressed(GLFW_KEY_S))
                cameraDirection += glm::vec3(.0f, .0f, -MOVE_SPEED);
            if (window.isKeyPressed(GLFW_KEY_D))
                cameraDirection += glm::vec3(MOVE_SPEED, .0f, .0f);
            if (window.isKeyPressed(GLFW_KEY_SPACE))
                cameraDirection += glm::vec3(.0f, MOVE_SPEED, .0f);
            if (window.isKeyPressed(GLFW_KEY_LEFT_SHIFT))
                cameraDirection += glm::vec3(.0f, -MOVE_SPEED, .0f);
            if (window.isKeyPressed(GLFW_KEY_ESCAPE))
                break;
            
            float cursorX, cursorY;
            std::tie(cursorX, cursorY) = window.GetCursorPos();
            float cursorDeltaX = cursorX - lastCursorX;
            float cursorDeltaY = cursorY - lastCursorY;

            lastCursorX = cursorX;
            lastCursorY = cursorY;
            if (cursorDeltaX != 0 || cursorDeltaY != 0)
                camera.rotateCameraSpace(glm::vec3(cursorDeltaX, cursorDeltaY, 1.f), ROTATE_SPEED);
            camera.moveCameraSpace(deltaTime * cameraDirection);
            renderer.bindCamera(&camera);
            renderer.drawFrame();

            deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(std::chrono::high_resolution_clock::now() - currentTime).count();
            logger();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}