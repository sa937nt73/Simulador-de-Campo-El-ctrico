#ifndef ESFERA_H
#define ESFERA_H

#include <glm/glm.hpp>

class Esfera {
public:
    float carga;
    glm::vec3 posicion;
    float radio;
    glm::vec3 velocidad{0.0f};
    glm::vec3 fuerza{0.0f};
    float masa = 10.0f; // Más pesada que la partícula

    Esfera(float carga = 1.0f, glm::vec3 posicion = glm::vec3(0.0f), float radio = 1.0f);
};

#endif