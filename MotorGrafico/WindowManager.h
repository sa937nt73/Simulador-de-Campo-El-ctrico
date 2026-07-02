#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class WindowManager{
    private:
    GLFWwindow* window;
    int width;
    int height;
    std::string title;


    public:
    // Constructor para el tamáño y títulod e la ventana
    WindowManager(int width, int height, const std::string& title);

    // Destructor: Limpia GLFW al cerrar el programa
    ~WindowManager();

    // Inicializa GLFW y GLAD. Devuelve true si todo salió bien.
    bool Initialize();

    // Nos dice si el usuario le dio clic a la "X" de cerrar
    bool ShouldClose() const;

    // Intercambia los buffers (actualiza la imagen) y procesa eventos
    void Update();

    // Limpia la pantalla con un color de fondo
    void Clear(float r, float g, float b, float a);

    // Devuelve el puntero nativo de GLFW por si ImGui lo necesita después
    GLFWwindow* GetNativeWindow() const { return window; }
};