#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>

#include "Window.hpp"
#include <vector>

Window::Window(int width, int height, const char* title)
{
    if (!glfwInit()) 
        std::runtime_error("Failed to initialize GLFW");
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::runtime_error("Failed to create window");
    }
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(window);
}   

void Window::PollEvents()
{
    glfwPollEvents();
}

std::pair<int, int> Window::GetFrameBufferSize()
{
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    return {width, height};
}

VkResult Window::CreateSurface(VkInstance instance, VkSurfaceKHR *surface)
{
    return glfwCreateWindowSurface(instance, window, nullptr, surface);
}

std::vector<const char *> Window::GetRequiredExtensions()
{
    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char *> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);
    return extensions;
}

void Window::WaitEvents()
{
    glfwWaitEvents();
}

