#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "Nodo.h"

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada();

    void agregarTarea(Tarea tarea);
    void mostrarTareas() const;
    void eliminarTarea(string titulo);
};

#endif
