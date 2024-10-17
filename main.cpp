#include "ListaEnlazada.h"
#include <iostream>
using namespace std;
void menu() {
    cout << "1. Agregar tarea" << endl;
    cout << "2. Mostrar tareas" << endl;
    cout << "3. Eliminar tarea" << endl;
    cout << "4. Salir" << endl;
    cout << "Elige una opción: ";
}
int main() {
    ListaEnlazada lista;
    int opcion;
    string titulo, descripcion, tipo, estado;
    bool activo;
    string fechaInicio;
    do {
        menu();
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                cout << "Título: ";
                getline(cin, titulo);
                cout << "Descripción: ";
                getline(cin, descripcion);
                cout << "Tipo: ";
                getline(cin, tipo);
                cout << "Estado: ";
                getline(cin, estado);
                cout << "Activo (1 para Sí, 0 para No): ";
                cin >> activo;
                cin.ignore();
                cout << "Fecha de inicio: ";
                getline(cin, fechaInicio);
                lista.agregarTarea(Tarea(titulo, descripcion, tipo, estado, activo, fechaInicio));
                break;
            case 2:
                lista.mostrarTareas();
                break;
            case 3:
                cout << "Título de la tarea a eliminar: ";
                getline(cin, titulo);
                lista.eliminarTarea(titulo);
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtalo de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
