#ifndef PARTICULA_H
#define PARTICULA_H

#include <glm/glm.hpp>

class Particula {
public:
    float carga;
    glm::vec3 posicion;
    glm::vec3 velocidad{0.0f}; // Requerido para que se mueva
    glm::vec3 fuerza{0.0f};    // Fuerza neta acumulada
    float masa = 1.0f;         // f = m * a -> a = f / m

    Particula(float carga = 1.0f, glm::vec3 posicion = glm::vec3(0.0f));
};

#endif