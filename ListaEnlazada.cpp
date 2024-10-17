#include "ListaEnlazada.h"
#include <iostream>

ListaEnlazada::ListaEnlazada() : cabeza(nullptr) {}

void ListaEnlazada::agregarTarea(Tarea tarea) {
    Nodo* nuevoNodo = new Nodo(tarea);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void ListaEnlazada::mostrarTareas() const {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        actual->tarea.mostrarTarea();
        std::cout << "-------------------------" << std::endl;
        actual = actual->siguiente;
    }
}

void ListaEnlazada::eliminarTarea(string titulo) {
    if (cabeza == nullptr) return;

    if (cabeza->tarea.getTitulo() == titulo) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->tarea.getTitulo() != titulo) {
            actual = actual->siguiente;
        }
        if (actual->siguiente != nullptr) {
            Nodo* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
        }
    }
}
