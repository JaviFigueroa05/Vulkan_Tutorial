#pragma once 

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

class Window
{
    public:
    Window(int width, int height, const char* title);
    ~Window();
    bool ShouldClose();
    void PollEvents();
    void WaitEvents();
    std::pair<int, int> GetFrameBufferSize();
    VkResult CreateSurface(VkInstance instance, VkSurfaceKHR* surface);    
    std::vector<const char*> GetRequiredExtensions();
    
    private:
    GLFWwindow* window;
};