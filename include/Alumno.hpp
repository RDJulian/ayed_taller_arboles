#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <string>

class Alumno {
private:
    int padron;
    std::string nombre;
    std::string apellido;

public:
    Alumno();

    Alumno(int padron, std::string nombre, std::string apellido);

    std::string obtener_informacion();

    bool operator<(const Alumno& alumno);

    bool operator==(const Alumno& alumno);

    bool operator<(int padron);

    bool operator==(int padron);
};

#endif
