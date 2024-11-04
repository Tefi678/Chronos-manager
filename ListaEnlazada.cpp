#include "ListaEnlazada.h"
#include <iostream>
#include <algorithm>
#include <vector>

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

void ListaEnlazada::eliminarTarea(std::string titulo) {
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

void ListaEnlazada::buscarTarea(std::string titulo) const {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->tarea.getTitulo() == titulo) {
            std::cout << "Tarea encontrada: " << std::endl;
            actual->tarea.mostrarTarea();
            return;
        }
        actual = actual->siguiente;
    }

    std::cout << "Tarea con título '" << titulo << "' no encontrada." << std::endl;
}

void ListaEnlazada::ordenarTareas() {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) return;

    std::vector<Tarea> tareasVec;
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        tareasVec.push_back(actual->tarea);
        actual = actual->siguiente;
    }

    std::sort(tareasVec.begin(), tareasVec.end(), [](const Tarea& t1, const Tarea& t2) {
        return t1.getTitulo() < t2.getTitulo();
    });

    actual = cabeza;
    for (const auto& tarea : tareasVec) {
        actual->tarea = tarea;
        actual = actual->siguiente;
    }

    std::cout << "Las tareas han sido ordenadas alfabéticamente." << std::endl;
}

void ListaEnlazada::ordenarPorFecha() {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) return;

    std::vector<Tarea> tareasVec;
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        tareasVec.push_back(actual->tarea);
        actual = actual->siguiente;
    }

    std::sort(tareasVec.begin(), tareasVec.end(), [](const Tarea& t1, const Tarea& t2) {
        return t1.getFechaInicio() < t2.getFechaInicio();
    });

    actual = cabeza;
    for (const auto& tarea : tareasVec) {
        actual->tarea = tarea;
        actual = actual->siguiente;
    }

    std::cout << "Las tareas han sido ordenadas por fecha de inicio." << std::endl;
}

void ListaEnlazada::modificarTarea(std::string titulo, const Tarea& nuevaTarea) {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->tarea.getTitulo() == titulo) {
            actual->tarea = nuevaTarea;
            std::cout << "Tarea modificada correctamente." << std::endl;
            return;
        }
        actual = actual->siguiente;
    }

    std::cout << "Tarea con título '" << titulo << "' no encontrada." << std::endl;
}

void ListaEnlazada::mostrarTareasActivas() const {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    bool hayActivas = false;

    while (actual != nullptr) {
        if (actual->tarea.isActivo()) {
            actual->tarea.mostrarTarea();
            std::cout << "-------------------------" << std::endl;
            hayActivas = true;
        }
        actual = actual->siguiente;
    }

    if (!hayActivas) {
        std::cout << "No hay tareas activas." << std::endl;
    }
}

Tarea* ListaEnlazada::obtenerTareaPorIndice(int indice) const {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return nullptr;
    }

    Nodo* actual = cabeza;
    int contador = 0;
    while (actual != nullptr) {
        if (contador == indice) {
            return &actual->tarea;
        }
        contador++;
        actual = actual->siguiente;
    }

    std::cout << "Índice fuera de rango." << std::endl;
    return nullptr;
}

void ListaEnlazada::limpiarLista() {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    std::cout << "La lista ha sido limpiada." << std::endl;
}

void ListaEnlazada::filtrarPorTipo(std::string tipo) const {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    bool hayCoincidencias = false;

    while (actual != nullptr) {
        if (actual->tarea.getTipo() == tipo) {
            actual->tarea.mostrarTarea();
            std::cout << "-------------------------" << std::endl;
            hayCoincidencias = true;
        }
        actual = actual->siguiente;
    }

    if (!hayCoincidencias) {
        std::cout << "No hay tareas de tipo '" << tipo << "'." << std::endl;
    }
}

int ListaEnlazada::contarTareas() const {
    int contador = 0;
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
}

void ListaEnlazada::completarTarea(std::string titulo) {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->tarea.getTitulo() == titulo) {
            actual->tarea.setActivo(false);
            std::cout << "Tarea '" << titulo << "' ha sido marcada como completada." << std::endl;
            return;
        }
        actual = actual->siguiente;
    }

    std::cout << "Tarea con título '" << titulo << "' no encontrada." << std::endl;
}

