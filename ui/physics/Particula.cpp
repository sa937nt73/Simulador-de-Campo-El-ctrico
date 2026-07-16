#include "Particula.h"

Particula::Particula(float carga, glm::vec3 posicion)
    : carga(carga), posicion(posicion), velocidad(0.0f), fuerza(0.0f), masa(1.0f) {}