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
    void eliminarTarea(std::string titulo);
    void buscarTarea(std::string titulo) const;
    void ordenarTareas();
    void modificarTarea(std::string titulo, const Tarea& nuevaTarea);
    void mostrarTareasActivas() const;
    Tarea* obtenerTareaPorIndice(int indice) const;
    void limpiarLista();
    void filtrarPorTipo(std::string tipo) const;
    int contarTareas() const;
    void completarTarea(std::string titulo);
};

#endif
