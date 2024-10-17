#ifndef NODO_H
#define NODO_H

#include "Tarea.h"

class Nodo {
public:
    Tarea tarea;
    Nodo* siguiente;

    Nodo(Tarea tarea);
};

#endif
