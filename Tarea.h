#ifndef TAREA_H
#define TAREA_H

#include <string>
using namespace std;

class Tarea {
private:
    string titulo;
    string descripcion;
    string tipo;
    string estado;
    bool activo;
    string fechaInicio;
    string fechaFin;

public:
    Tarea(string titulo, string descripcion, string tipo, string estado, bool activo, string fechaInicio);

    string getTitulo() const;
    bool isActivo() const;

    void mostrarTarea() const;
};

#endif
