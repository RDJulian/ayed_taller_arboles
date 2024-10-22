#include <iostream>
#include "ArbolAlumnos.hpp"
#include "Alumno.hpp"

int main() {
    ArbolAlumnos arbol;

    // Super original
    arbol.alta({108410, "Julian", "Ruiz Diaz"});
    arbol.alta({108411, "Julian", "Ruiz Diaz"});
    arbol.alta({108419, "Julian", "Ruiz Diaz"});
    arbol.alta({108412, "Julian", "Ruiz Diaz"});
    arbol.alta({108420, "Julian", "Ruiz Diaz"});
    arbol.alta({108401, "Julian", "Ruiz Diaz"});

    for (Alumno& alumno: arbol.inorder()) {
        std::cout << alumno.obtener_informacion() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "BUSQUEDA" << std::endl;
    Alumno alumno = arbol.obtener_alumno(108401);
    std::cout << alumno.obtener_informacion();

    return 0;
}
