#include "Camera.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up, float fovyDegrees, float aspectRatio, float nearClip, float farClip)
{
    view = glm::lookAt(position, front, up);
    proj = glm::perspective(glm::radians(fovyDegrees), aspectRatio, nearClip, farClip);
    proj[1][1] *= -1;
}

void Camera::move(glm::vec3 direction)
{
    view = glm::translate(view, direction);
}

void Camera::rotate(float pitch, float yaw)
{
    
}

glm::mat4 Camera::getView()
{
    return view;
}

glm::mat4 Camera::getProj()
{
    return proj;
}
