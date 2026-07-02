#include "WindowManager.h"
#include <iostream>

namespace {
    void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }
}

WindowManager::WindowManager(int width, int height, const std::string& title)
    : window(nullptr), width(width), height(height), title(title) {}

WindowManager::~WindowManager(){
    if (window){
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

bool WindowManager::Initialize(){
    // 1. Inicio GLFW
    if (!glfwInit()){
        std::cerr << "Error al inicializar GLFW, Te jodiste bro :c" << std::endl;
        return false;
    }

// Configurar un contexto de OpenGL compatible con el renderizado clásico
// usado por glBegin/glEnd y las matrices fijas de la escena.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    // 2. Crear la ventana
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        std::cerr << "Error al crear la ventana GLFW" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    // 3. Inicializar GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Error al inicializar GLAD" << std::endl;
        return false;
    }

    // Configurar el viewport (área de dibujo)
    glViewport(0, 0, width, height);

    return true;
}

bool WindowManager::ShouldClose() const {
    return glfwWindowShouldClose(window);
}

void WindowManager::Update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void WindowManager::Clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Añadimos Depth Buffer para el 3D posterior
}