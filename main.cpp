#include "ListaEnlazada.h"
#include <iostream>
using namespace std;

void menu() {
    cout << "\tMENU CHRONOS MANAGES" << endl;
    cout << "1. Agregar tarea" << endl;
    cout << "2. Mostrar tareas" << endl;
    cout << "3. Eliminar tarea" << endl;
    cout << "4. Buscar tarea" << endl;
    cout << "5. Ordenar tareas" << endl;
    cout << "6. Modificar tarea" << endl;
    cout << "7. Tarea por posición" << endl;
    cout << "8. Filtrar tareas activas" << endl;
    cout << "9. Eliminar todas las tareas" << endl;
    cout << "10. Filtrar por tipo" << endl;
    cout << "11. Cantidad de tareas actuales" << endl;
    cout << "12. Completar tarea" << endl;
    cout << "13. Salir" << endl;
    cout << "Elige una opción: ";
}

int main() {
    ListaEnlazada lista;
    int opcion;
    string titulo1, titulo, descripcion, tipo, estado;
    bool activo;
    string fechaInicio;
    cout << "BIENVENIDO A CHRONOS MANAGEr" << endl;

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
                cout << "Título de la tarea a buscar: ";
                getline(cin, titulo);
                lista.buscarTarea(titulo);
                break;

            case 5:
                lista.ordenarTareas();
                break;

            case 6:
                cout << "Bye bye :3" << endl;
                break;
            
            case 7:
                cout << "dame el nombre de la tarea a modificar: ";
                getline(cin, titulo1);
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
                lista.modificarTarea(titulo1, Tarea(titulo, descripcion, tipo, estado, activo, fechaInicio));
                break;

            case 8:
                lista.mostrarTareasActivas();
                break;

            default:
                cout << "Opción no válida. Inténtalo de nuevo." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
