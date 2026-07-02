// Camera.h
#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
    private:
        glm::vec3 position;
        glm::vec3 target;
        glm::vec3 up;

        // Coordenadas esféricas para la orbita (yaw (tetha), pitch (psi), radius (r))
        float yaw; // Giro horizontal (izquierda/derecha)
        float pitch; // Giro verticas (arriba/abajo)
        float radius; // Distancia al centro (zoom)

        // Funcion interna para recalcular position a partir de yaw, pitch y radius
        void UpdateCameraVectors();

    public:
        Camera(glm::vec3 startPosition);

        glm::mat4 GetViewMatrix() const;
        glm::mat4 GetProjectionMatrix(float width, float height) const;
        glm::vec3 GetPosition() const;
        void SetPosition(const glm::vec3& newPosition);
        glm::vec3 GetTarget() const;
        void SetTarget(const glm::vec3& newTarget);

        // Metodos que llamará el sistema de eventos
        void ProcessMouseScroll(float yOffset);
        void ProcessMouseMovement(float xOffset, float yOffset);

};