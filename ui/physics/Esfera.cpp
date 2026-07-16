#include "Esfera.h"

Esfera::Esfera(float carga, glm::vec3 posicion, float radio)
    : carga(carga), posicion(posicion), radio(radio), velocidad(0.0f), fuerza(0.0f), masa(10.0f) {}