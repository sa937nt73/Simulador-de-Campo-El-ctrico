#ifndef OBJETO_COMPARTIDO_H
#define OBJETO_COMPARTIDO_H

#include "Particula.h"
#include "Esfera.h"
#include <variant>

using Objeto = std::variant<Particula, Esfera>;

#endif