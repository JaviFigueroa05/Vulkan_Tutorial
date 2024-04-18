#include <iostream>

#include "Camera.hpp"

void Camera::print(glm::vec4 vec)
{
    std::cout << std::endl   
              << vec.x << " "
              << vec.y << " "
              << vec.z << " "
              << vec.w << std::endl;
}

void Camera::print(glm::mat3 mat)
{
    std::cout << std::endl
              << mat[0][0] << "\t" << mat[0][1] << "\t" << mat[0][2] << std::endl
              << mat[1][0] << "\t" << mat[1][1] << "\t" << mat[1][2] << std::endl
              << mat[2][0] << "\t" << mat[2][1] << "\t" << mat[2][2] << std::endl
              << std::endl;
}

void Camera::print(glm::mat4 mat)
{
    std::cout << std::endl
              << mat[0][0] << "\t" << mat[0][1] << "\t" << mat[0][2] << "\t" << mat[0][3] << std::endl
              << mat[1][0] << "\t" << mat[1][1] << "\t" << mat[1][2] << "\t" << mat[1][3] << std::endl
              << mat[2][0] << "\t" << mat[2][1] << "\t" << mat[2][2] << "\t" << mat[2][3] << std::endl
              << mat[3][0] << "\t" << mat[3][1] << "\t" << mat[3][2] << "\t" << mat[3][3] << std::endl
              << std::endl;
}

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
