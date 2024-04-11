#pragma once

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;

    glm::mat4 view;
    glm::mat4 proj;

public:
    Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up, float fovyDegrees, float aspectRatio, float nearClip, float farClip);
    ~Camera() = default;

    void updatePosition(glm::vec3 position, glm::vec3 front, glm::vec3 up);
    void move(glm::vec3 position);

    glm::mat4 getView();
    glm::mat4 getProj();
};