#ifndef NODO_HPP
#define NODO_HPP

// Implementar cambiando a template, documentar, etc.
// template<class Clave, class T>
template<class T>
class Nodo {
    T dato;
    Nodo* padre;
    Nodo* hijo_izquierdo;
    Nodo* hijo_derecho;

public:
    Nodo(T dato);

    Nodo(T dato, Nodo* padre, Nodo* hijo_izquierdo, Nodo* hijo_derecho);

    T obtener_dato();

    void cambiar_dato(T dato);

    Nodo* obtener_padre();

    void cambiar_padre(Nodo* padre);

    Nodo* obtener_hijo_izquierdo();

    void cambiar_hijo_izquierdo(Nodo* hijo_izquierdo);

    Nodo* obtener_hijo_derecho();

    void cambiar_hijo_derecho(Nodo* hijo_derecho);

    ~Nodo();
};

template<class T>
Nodo<T>::Nodo(T dato) {
    this->dato = dato;
    padre = nullptr;
    hijo_izquierdo = nullptr;
    hijo_derecho = nullptr;
}

template<class T>
Nodo<T>::Nodo(T dato, Nodo* padre, Nodo* hijo_izquierdo, Nodo* hijo_derecho) {
    this->dato = dato;
    this->padre = padre;
    this->hijo_izquierdo = hijo_izquierdo;
    this->hijo_derecho = hijo_derecho;
}

template<class T>
T Nodo<T>::obtener_dato() {
    return dato;
}

template<class T>
void Nodo<T>::cambiar_dato(T dato) {
    this->dato = dato;
}

template<class T>
Nodo<T>* Nodo<T>::obtener_padre() {
    return padre;
}

template<class T>
void Nodo<T>::cambiar_padre(Nodo* padre) {
    this->padre = padre;
}

template<class T>
Nodo<T>* Nodo<T>::obtener_hijo_izquierdo() {
    return hijo_izquierdo;
}

template<class T>
void Nodo<T>::cambiar_hijo_izquierdo(Nodo* hijo_izquierdo) {
    this->hijo_izquierdo = hijo_izquierdo;
}

template<class T>
Nodo<T>* Nodo<T>::obtener_hijo_derecho() {
    return hijo_derecho;
}

template<class T>
void Nodo<T>::cambiar_hijo_derecho(Nodo* hijo_derecho) {
    this->hijo_derecho = hijo_derecho;
}

template<class T>
Nodo<T>::~Nodo() {
    delete hijo_izquierdo;
    delete hijo_derecho;
}

#endif
