#include "Panel.h"
#include <imgui.h>
#include <iostream>
#include <string>

void Panel::render(Scene& scene) {
    mostrarPanelPrincipal(scene);
    mostrarListaObjetos(scene);
    mostrarInspector(scene);
}

void Panel::mostrarPanelPrincipal(Scene& scene) {
    ImGui::Begin("Panel de Control");
    ImGui::Text("Simulador de Campo Electrico");
    ImGui::Separator();

    ImGui::Text("Crear Particula");
    ImGui::SliderFloat("Carga (C)", &nuevaCarga, -10.0f, 10.0f);
    ImGui::SliderFloat("Pos X", &nuevaPosX, -10.0f, 10.0f);
    ImGui::SliderFloat("Pos Y", &nuevaPosY, -10.0f, 10.0f);
    ImGui::SliderFloat("Pos Z", &nuevaPosZ, -10.0f, 10.0f);

    if (ImGui::Button("Crear Particula")) {
        scene.AddObject(Particula(nuevaCarga, glm::vec3(nuevaPosX, nuevaPosY, nuevaPosZ)));
    }

    ImGui::Separator();
    ImGui::Text("Crear Esfera");
    ImGui::SliderFloat("Radio", &nuevoRadio, 0.1f, 5.0f);

    if (ImGui::Button("Crear Esfera")) {
        scene.AddObject(Esfera(nuevaCarga, glm::vec3(nuevaPosX, nuevaPosY, nuevaPosZ), nuevoRadio));
    }

    ImGui::Separator();

    if (ImGui::Button("Iniciar"))  simulacionActiva = true;
    ImGui::SameLine();
    if (ImGui::Button("Pausar"))   simulacionActiva = false;
    ImGui::SameLine();
    if (ImGui::Button("Reiniciar")) {
        scene.ClearScene();
        objetoSeleccionado = -1;
        simulacionActiva = false;
    }

    ImGui::End();
}

void Panel::mostrarListaObjetos(Scene& scene) {
    ImGui::Begin("Lista de Objetos");
    auto& objetos = scene.GetObjects();

    for (size_t i = 0; i < objetos.size(); ++i) {
        std::string label = std::holds_alternative<Particula>(objetos[i]) 
            ? "Particula " + std::to_string(i) 
            : "Esfera " + std::to_string(i);

        if (ImGui::Selectable(label.c_str(), objetoSeleccionado == (int)i)) {
            objetoSeleccionado = (int)i;
        }
    }

    if (ImGui::Button("Eliminar seleccionado") && objetoSeleccionado >= 0 && objetoSeleccionado < (int)objetos.size()) {
        objetos.erase(objetos.begin() + objetoSeleccionado);
        objetoSeleccionado = -1;
    }
    ImGui::End();
}

void Panel::mostrarInspector(Scene& scene) {
    auto& objetos = scene.GetObjects();
    if (objetoSeleccionado < 0 || objetoSeleccionado >= (int)objetos.size()) return;

    ImGui::Begin("Inspector");
    auto& obj = objetos[objetoSeleccionado];

    if (std::holds_alternative<Particula>(obj)) {
        auto& p = std::get<Particula>(obj);
        ImGui::Text("Tipo: Particula");
        ImGui::SliderFloat("Carga", &p.carga, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos X", &p.posicion.x, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos Y", &p.posicion.y, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos Z", &p.posicion.z, -10.0f, 10.0f);
    } else {
        auto& e = std::get<Esfera>(obj);
        ImGui::Text("Tipo: Esfera");
        ImGui::SliderFloat("Carga", &e.carga, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos X", &e.posicion.x, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos Y", &e.posicion.y, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos Z", &e.posicion.z, -10.0f, 10.0f);
        ImGui::SliderFloat("Radio", &e.radio, 0.1f, 5.0f);
    }
    ImGui::End();
}