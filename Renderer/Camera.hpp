#pragma once

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
    glm::mat4 view;
    glm::mat4 proj;

public:
    Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up, float fovyDegrees, float aspectRatio, float nearClip, float farClip);
    ~Camera() = default;

    void move(glm::vec3 direction);
    void rotate(float pitch, float yaw);

    glm::mat4 getView();
    glm::mat4 getProj();
};