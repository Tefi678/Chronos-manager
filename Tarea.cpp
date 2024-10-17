#include "Tarea.h"
#include <iostream>

Tarea::Tarea(string titulo, string descripcion, string tipo, string estado, bool activo, string fechaInicio)
    : titulo(titulo), descripcion(descripcion), tipo(tipo), estado(estado), activo(activo), fechaInicio(fechaInicio), fechaFin("") {}

string Tarea::getTitulo() const { return titulo; }

void Tarea::mostrarTarea() const {
    cout << "Título: " << titulo << endl;
    cout << "Descripción: " << descripcion << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Estado: " << estado << endl;
    cout << "Activo: " << (activo ? "Sí" : "No") << endl;
    cout << "Fecha de inicio: " << fechaInicio << endl;
    cout << "Fecha de fin: " << fechaFin << endl;
}
