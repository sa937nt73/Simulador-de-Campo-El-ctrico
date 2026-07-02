#pragma once
#include <vector>
#include <glm/glm.hpp>

// Estructura temporal para cuando la física envíe datos más adelante
struct ChargeData {
    glm::vec3 position;
    float chargeValue;
};

class Scene {
private:
    // Aquí se guardarán las cargas en el futuro
    std::vector<ChargeData> charges;

public:
    Scene() = default;
    ~Scene() = default;

    // Métodos limpios para que la física o la interfaz metan/saquen datos después
    void AddCharge(glm::vec3 pos, float value) {
        charges.push_back({pos, value});
    }

    const std::vector<ChargeData>& GetCharges() const {
        return charges;
    }

    void ClearScene() {
        charges.clear();
    }
};