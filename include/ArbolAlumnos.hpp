#ifndef ABB_HPP
#define ABB_HPP

#include <cstddef>
#include <stdexcept>
#include <vector>
#include "Nodo.hpp"
#include "Alumno.hpp"

class ExcepcionABB : public std::runtime_error {
public:
    ExcepcionABB(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionABB(): runtime_error("") {
    }
};

// Implementar cambiando a template, documentar, etc.
// template<class Clave, class T>
class ArbolAlumnos {
    Nodo<Alumno>* raiz;
    std::size_t cantidad_datos;

    void alta_recursivo(Nodo<Alumno>* actual, Alumno alumno);

    void inorder_recursivo(Nodo<Alumno>* nodo, std::vector<Alumno>& vector);

    Alumno obtener_recursivo(Nodo<Alumno>* nodo, int padron);

public:
    ArbolAlumnos();

    void alta(Alumno alumno);

    std::vector<Alumno> inorder();

    Alumno obtener_alumno(int padron);

    std::vector<Alumno> ancho();

    ~ArbolAlumnos();
};

#endif
