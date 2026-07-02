#include "Camera.h"
#include <cmath>

Camera::Camera(glm::vec3 startPosition) {
    target = glm::vec3(0.0f, 0.0f, 0.0f); // Orbitamos alrededor del origen
    up = glm::vec3(0.0f, 1.0f, 0.0f);     // El eje Y es "arriba"
    
    // Calculamos el radio inicial basado en la posición de inicio
    radius = glm::length(startPosition - target);
    
    // Ángulos iniciales por defecto para mirar hacia el centro
    yaw = -90.0f;
    pitch = 20.0f; // Un pequeño ángulo hacia arriba para no empezar totalmente planos
    
    // Calculamos la posición real inicial
    UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() const {
    return glm::lookAt(position, target, up);
}

glm::vec3 Camera::GetPosition() const {
    return position;
}

void Camera::SetPosition(const glm::vec3& newPosition) {
    position = newPosition;
}

glm::vec3 Camera::GetTarget() const {
    return target;
}

void Camera::SetTarget(const glm::vec3& newTarget) {
    target = newTarget;
}

glm::mat4 Camera::GetProjectionMatrix(float width, float height) const {
    float aspectRatio = (height > 0) ? (width / height) : 1.0f;
    return glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);
}

void Camera::ProcessMouseScroll(float yOffset) {
    // El zoom modifica el radio (distancia al centro)
    radius -= yOffset * 0.5f; // El 0.5f es para modular la velocidad del zoom
    if (radius < 1.0f) radius = 1.0f;   // Límite para no traspasar el origen
    if (radius > 50.0f) radius = 50.0f; // Límite para no alejarnos infinitamente
    
    UpdateCameraVectors();
}

void Camera::ProcessMouseMovement(float xOffset, float yOffset) {
    // Sensibilidad del mouse para que no gire caóticamente
    float sensitivity = 0.1f;
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    // LIMITACIÓN CRÍTICA: Evitamos que la cámara se invierta (pasar de 90 grados)
    if (pitch > 89.0f)  pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    UpdateCameraVectors();
}

// LA FUNCIÓN MATEMÁTICA: Traduce ángulos a coordenadas X, Y, Z
void Camera::UpdateCameraVectors() {
    // Conversión de coordenadas esféricas a cartesianas usando radianes
    position.x = target.x + radius * cos(glm::radians(pitch)) * sin(glm::radians(yaw));
    position.y = target.y + radius * sin(glm::radians(pitch));
    position.z = target.z + radius * cos(glm::radians(pitch)) * cos(glm::radians(yaw));
}

