#ifndef PANEL_H
#define PANEL_H

#include "../Scene.h"

class Panel {
public:
    // Ahora le pasamos la escena para interactuar con ella directamente
    void render(Scene& scene);
    bool IsSimulating() const { return simulacionActiva; }

private:
    int objetoSeleccionado = -1;
    bool simulacionActiva = false;

    void mostrarPanelPrincipal(Scene& scene);
    void mostrarListaObjetos(Scene& scene);
    void mostrarInspector(Scene& scene);

    // Variables de creación
    float nuevaCarga = 1.0f;
    float nuevaPosX = 0.0f;
    float nuevaPosY = 0.0f;
    float nuevaPosZ = 0.0f;
    float nuevoRadio = 1.0f;
};

#endif