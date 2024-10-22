#include "Alumno.hpp"

Alumno::Alumno() {
    padron = -1;
    nombre = "";
    apellido = "";
}

Alumno::Alumno(int padron, std::string nombre, std::string apellido) {
    this->padron = padron;
    this->nombre = nombre;
    this->apellido = apellido;
}

std::string Alumno::obtener_informacion() {
    return std::to_string(padron) + ", " + nombre + ", " + apellido;
}

bool Alumno::operator<(const Alumno& alumno) {
    return padron < alumno.padron;
}

bool Alumno::operator==(const Alumno& alumno) {
    return padron == alumno.padron;
}

bool Alumno::operator<(int padron) {
    return this->padron < padron;
}

bool Alumno::operator==(int padron) {
    return this->padron == padron;
}
