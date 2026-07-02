cmake_minimum_required(VERSION 3.15)
project(SimuladorCampos3D CXX)

# Forzar a usar C++17 o superior
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscar las librerías que pusimos en el vcpkg.json
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# El archivo ejecutable principal (crearemos el main.cpp ahora)
add_executable(Simulador 
    main.cpp 
    Scene.h
    MotorGrafico/WindowManager.h
    MotorGrafico/WindowManager.cpp
    MotorGrafico/Camera.h
    MotorGrafico/Camera.cpp
    MotorGrafico/Renderer.h
    MotorGrafico/Renderer.cpp
    MotorGrafico/Movimiento.h
    MotorGrafico/Movimiento.cpp
)
# Enlazar las librerías a nuestro ejecutable
target_link_libraries(Simulador PRIVATE glfw glad::glad glm::glm)