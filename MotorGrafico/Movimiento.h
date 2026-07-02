#pragma once
#include <GLFW/glfw3.h>
#include "Camera.h"

class Movimiento {
public:
    explicit Movimiento(float speed = 5.0f);
    void Update(Camera& camera, GLFWwindow* window, float deltaTime);

private:
    float speed;
};
