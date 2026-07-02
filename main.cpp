#include "MotorGrafico/WindowManager.h"
#include "MotorGrafico/Camera.h"
#include "MotorGrafico/Renderer.h"
#include "MotorGrafico/Movimiento.h"
#include "Scene.h"
#include <iostream>

int main() {
    // 1. Inicializar la Ventana (Ancho: 800, Alto: 600)
    WindowManager appWindow(800, 600, "Simulador de Campo Electrico 3D");
    if (!appWindow.Initialize()) {
        std::cerr << "Fallo critico al iniciar la ventana." << std::endl;
        return -1;
    }

    // 2. Crear los componentes centrales (Nuestra Arquitectura Modular)
    Scene scene;       // El cerebro que guarda los datos
    Renderer renderer; // El pintor encargado de OpenGL
    Movimiento movimiento;
    
    // Inicializar configuraciones de OpenGL (como el Depth Test)
    renderer.Initialize();

    // 3. Crear la Camara apuntando al origen desde una distancia inicial
    // La colocamos en la posicion (X=0, Y=5, Z=10) para ver el mundo desde arriba y lejos
    Camera camera(glm::vec3(0.0f, 5.0f, 10.0f));

    double lastTime = glfwGetTime();

    // ==========================================
    // BUCLE PRINCIPAL DE LA SIMULACION
    // ==========================================
    while (!appWindow.ShouldClose()) {
        double currentTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime);
        lastTime = currentTime;

        // A. Limpiar la pantalla con un fondo gris oscuro
        appWindow.Clear(0.1f, 0.1f, 0.1f, 1.0f);

        movimiento.Update(camera, appWindow.GetNativeWindow(), deltaTime);

        // B. EL METODO MAESTRO: Le pasamos la escena y la camara al pintor
        // Le pasamos el ancho y alto (800x600) fijas por ahora para la proyeccion
        renderer.Render(scene, camera, 800.0f, 600.0f);

        // C. Intercambiar buffers y procesar eventos de la ventana
        appWindow.Update();
    }

    return 0;
}