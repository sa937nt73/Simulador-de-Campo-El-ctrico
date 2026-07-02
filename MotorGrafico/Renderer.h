#pragma once
#include "Camera.h"
#include "../Scene.h" // Subimos un nivel para encontrar la escena

class Renderer {
private:
    // Función auxiliar interna para dibujar los ejes de coordenadas
    void DrawAxes(const glm::mat4& view, const glm::mat4& projection);

public:
    Renderer() = default;
    ~Renderer() = default;

    // Inicializa cosas de OpenGL necesarias para el 3D
    void Initialize();

    // El método maestro: renderiza toda la simulación
    void Render(const Scene& scene, const Camera& camera, float windowWidth, float windowHeight);
};