cmake_minimum_required(VERSION 3.22)
project(ayed_taller_arboles)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

add_compile_options(-Wall -Werror -Wconversion)

include_directories(include)

set(ARCHIVOS_FUENTE
        src/Alumno.cpp
        include/Alumno.hpp
        include/Nodo.hpp
        include/ArbolAlumnos.hpp
        src/ArbolAlumnos.cpp
)

add_executable(ayed_taller_arboles
        ${ARCHIVOS_FUENTE}
        main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")