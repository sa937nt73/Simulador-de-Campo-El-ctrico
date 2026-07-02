#include "Movimiento.h"

Movimiento::Movimiento(float speed) : speed(speed) {}

void Movimiento::Update(Camera& camera, GLFWwindow* window, float deltaTime) {
    if (window == nullptr) {
        return;
    }

    glm::vec3 position = camera.GetPosition();
    glm::vec3 target = camera.GetTarget();
    glm::vec3 forward = glm::normalize(target - position);
    glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    float move = speed * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        position -= right * move;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        position += right * move;
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        position += forward * move;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        position -= forward * move;
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        position += up * move;
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        position -= up * move;
    }

    camera.SetPosition(position);
}
