#include "ArbolAlumnos.hpp"
#include <queue>

ArbolAlumnos::ArbolAlumnos() {
    raiz = nullptr;
    cantidad_datos = 0;
}

void ArbolAlumnos::alta_recursivo(Nodo<Alumno>* actual, Alumno alumno) {
    if (alumno == actual->obtener_dato()) {
        throw ExcepcionABB("No se puede agregar un dato repetido.");
    }
    if (alumno < actual->obtener_dato()) {
        // Caso izquierdo
        if (!actual->obtener_hijo_izquierdo()) {
            actual->cambiar_hijo_izquierdo(new Nodo<Alumno>(alumno, actual, nullptr, nullptr));
        } else {
            alta_recursivo(actual->obtener_hijo_izquierdo(), alumno);
        }
    } else {
        // Caso derecho
        if (!actual->obtener_hijo_derecho()) {
            actual->cambiar_hijo_derecho(new Nodo<Alumno>(alumno, actual, nullptr, nullptr));
        } else {
            alta_recursivo(actual->obtener_hijo_derecho(), alumno);
        }
    }
}

void ArbolAlumnos::alta(Alumno alumno) {
    if (!raiz) {
        raiz = new Nodo(alumno);
    } else {
        alta_recursivo(raiz, alumno);
    }
    cantidad_datos++;
}

void ArbolAlumnos::inorder_recursivo(Nodo<Alumno>* nodo, std::vector<Alumno>& vector) {
    if (nodo->obtener_hijo_izquierdo()) {
        inorder_recursivo(nodo->obtener_hijo_izquierdo(), vector);
    }
    vector.push_back(nodo->obtener_dato());
    if (nodo->obtener_hijo_derecho()) {
        inorder_recursivo(nodo->obtener_hijo_derecho(), vector);
    }
}

std::vector<Alumno> ArbolAlumnos::inorder() {
    std::vector<Alumno> recorrido;
    if (raiz) {
        inorder_recursivo(raiz, recorrido);
    }
    return recorrido;
}

Alumno ArbolAlumnos::obtener_recursivo(Nodo<Alumno>* nodo, int padron) {
    if (nodo->obtener_dato() == padron) {
        return nodo->obtener_dato();
    }
    // Caso derecho
    if (nodo->obtener_dato() < padron) {
        if (!nodo->obtener_hijo_derecho()) {
            throw ExcepcionABB("El dato no se encontró en el arbol.");
        }
        return obtener_recursivo(nodo->obtener_hijo_derecho(), padron);
    }
    // Caso izquierdo
    if (!nodo->obtener_hijo_izquierdo()) {
        throw ExcepcionABB("El dato no se encontró en el arbol.");
    }
    return obtener_recursivo(nodo->obtener_hijo_izquierdo(), padron);
}

Alumno ArbolAlumnos::obtener_alumno(int padron) {
    if (raiz) {
        return obtener_recursivo(raiz, padron);
    }
    throw ExcepcionABB("El dato no se encontró en el arbol.");
}

std::vector<Alumno> ArbolAlumnos::ancho() {
    std::vector<Alumno> recorrido;
    std::queue<Nodo<Alumno> *> nodos;
    if (raiz) {
        nodos.push(raiz);
    }
    while (!nodos.empty()) {
        // El primer nodo de la cola agrega a sus hijos,
        // luego se quita y agrega su dato al vector.
        // Iterar hasta que no queden nodos.
        Nodo<Alumno>* nodo_actual = nodos.front();
        nodos.pop();
        if (nodo_actual->obtener_hijo_izquierdo()) {
            nodos.push(nodo_actual->obtener_hijo_izquierdo());
        }
        if (nodo_actual->obtener_hijo_derecho()) {
            nodos.push(nodo_actual->obtener_hijo_derecho());
        }
        recorrido.push_back(nodo_actual->obtener_dato());
    }
    return recorrido;
}

ArbolAlumnos::~ArbolAlumnos() {
    delete raiz;
}
