#include "Renderer.h"
#include <glad/glad.h>

void Renderer::Initialize() {
    // Activamos la prueba de profundidad (Depth Test)
    // Esto hace que lo que está adelante tape correctamente a lo que está atrás en 3D
    glEnable(GL_DEPTH_TEST);
}

void Renderer::Render(const Scene& scene, const Camera& camera, float windowWidth, float windowHeight) {
    // 1. Obtener las matrices de la cámara
    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 projection = camera.GetProjectionMatrix(windowWidth, windowHeight);

    // 2. Dibujar los ejes de coordenadas base
    DrawAxes(view, projection);

    // [Aquí en el futuro leeremos 'scene.GetCharges()' con un ciclo for para dibujar las esferas]
}

void Renderer::DrawAxes(const glm::mat4& view, const glm::mat4& projection) {
    // Avisamos a OpenGL clásico qué matrices usar (Vista y Proyección)
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(&projection[0][0]);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(&view[0][0]);

    // Empezamos a dibujar líneas crudas en el espacio 3D
    glBegin(GL_LINES);

    // --- EJE X: ROJO ---
    glColor3f(1.0f, 0.0f, 0.0f); // Color Rojo
    glVertex3f(-10.0f, 0.0f, 0.0f); // Punto de inicio
    glVertex3f(10.0f, 0.0f, 0.0f);  // Punto final

    // --- EJE Y: VERDE ---
    glColor3f(0.0f, 1.0f, 0.0f); // Color Verde
    glVertex3f(0.0f, -10.0f, 0.0f);
    glVertex3f(0.0f, 10.0f, 0.0f);

    // --- EJE Z: AZUL ---
    glColor3f(0.0f, 0.0f, 1.0f); // Color Azul
    glVertex3f(0.0f, 0.0f, -10.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);

    glEnd();
}