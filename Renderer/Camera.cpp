#include <iostream>

#include "Camera.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up, float fovyDegrees, float aspectRatio, float nearClip, float farClip)
{
    this->position = position;
    this->front = front;
    this->up = up;

    view = glm::lookAt(position, front, up);
    proj = glm::perspective(glm::radians(fovyDegrees), aspectRatio, nearClip, farClip);
    proj[1][1] *= -1;
}

void Camera::updatePosition(glm::vec3 position, glm::vec3 front, glm::vec3 up)
{
    view = glm::lookAt(position, front, up);
}

void Camera::move(glm::vec3 direction)
{
    position += direction;
    front += direction;
    view = glm::lookAt(position, front, up);
}

glm::mat4 Camera::getView()
{
    return view;
}

glm::mat4 Camera::getProj()
{
    return proj;
}
