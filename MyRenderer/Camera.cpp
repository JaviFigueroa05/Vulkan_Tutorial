#include <iostream>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "include/MyRenderer.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up, float fovyDegrees, float aspectRatio, float nearClip, float farClip)
{
    view = glm::lookAt(position, front, up);
    proj = glm::perspective(glm::radians(fovyDegrees), aspectRatio, nearClip, farClip);
    proj[1][1] *= -1;
}

void Camera::moveCameraSpace(glm::vec3 cameraSpaceDirection)
{
    cameraSpaceDirection[2] *= -1;
    view = glm::translate(glm::mat4(1.f), -cameraSpaceDirection) * view;
}

void Camera::rotateCameraSpace(glm::vec3 deltaCursor, float rotationSpeed)
{
    deltaCursor = glm::normalize(deltaCursor);
    glm::vec3 axis = glm::cross(glm::vec3(0.f, 0.f, 1.f), deltaCursor);
    axis[0] *= -1;
    axis[2] = 0.f;
    axis = glm::normalize(axis);
    float angle = rotationSpeed * glm::acos(glm::dot(glm::vec3(0.f, 0.f, 1.f), deltaCursor));

    view = glm::rotate(glm::mat4(1.f), angle, axis) * view;
}

void Camera::moveGlobalSpace(glm::vec3 direction)
{
    view = glm::translate(view, direction);
}

glm::mat4 Camera::getView() { return view; }

glm::mat4 Camera::getProj() { return proj; }
