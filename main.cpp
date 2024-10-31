#include "ListaEnlazada.h"
#include <iostream>
using namespace std;

void menuPrincipal() {
    cout << "\n\tMENU CHRONOS MANAGER ADMINISTRADOR DE TAREAS" << endl;
    cout << "1. Agregar tarea" << endl;
    cout << "2. Mostrar tareas" << endl;
    cout << "3. Ordenar tareas" << endl;
    cout << "4. Filtrar tareas" << endl;
    cout << "5. Buscar tarea" << endl;
    cout << "6. Eliminar tarea" << endl;
    cout << "7. Modificar tarea" << endl;
    cout << "8. Salir" << endl;
    cout << "Elige una opción: ";
}

void menuOrdenar() {
    cout << "\n\tORDENAR TAREAS" << endl;
    cout << "1. Ordenar alfabéticamente" << endl;
    cout << "2. Volver al menú principal" << endl;
    cout << "Elige una opción: ";
}

void menuFiltrar() {
    cout << "\n\tFILTRAR TAREAS" << endl;
    cout << "1. Mostrar tareas activas" << endl;
    cout << "2. Filtrar por tipo" << endl;
    cout << "3. Volver al menú principal" << endl;
    cout << "Elige una opción: ";
}

void menuEliminar() {
    cout << "\n\tELIMINAR TAREAS" << endl;
    cout << "1. Eliminar por título" << endl;
    cout << "2. Eliminar todas las tareas" << endl;
    cout << "3. Volver al menú principal" << endl;
    cout << "Elige una opción: ";
}

void menuBuscar() {
    cout << "\n\tBUSCAR TAREA" << endl;
    cout << "1. Buscar por título" << endl;
    cout << "2. Volver al menú principal" << endl;
    cout << "Elige una opción: ";
}

int main() {
    ListaEnlazada lista;
    char opcion;
    string titulo, descripcion, tipo, estado, fechaInicio;
    bool activo;

    cout << "BIENVENIDO A CHRONOS MANAGER" << endl;

    do {
        menuPrincipal();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case '1':
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

            case '2':
                lista.mostrarTareas();
                break;

            case '3':
                do {
                    menuOrdenar();
                    cin >> opcion;
                    cin.ignore();

                    switch (opcion) {
                        case '1':
                            lista.ordenarTareas();
                            break;
                        case '2':
                            break;
                        default:
                            cout << "Opción no válida." << endl;
                            break;
                    }
                } while (opcion != '2');
                break;

            case '4':
                do {
                    menuFiltrar();
                    cin >> opcion;
                    cin.ignore();

                    switch (opcion) {
                        case '1':
                            lista.mostrarTareasActivas();
                            break;
                        case '2':
                            cout << "Tipo de tarea: ";
                            getline(cin, tipo);
                            lista.filtrarPorTipo(tipo);
                            break;
                        case '3':
                            break;
                        default:
                            cout << "Opción no válida." << endl;
                            break;
                    }
                } while (opcion != '3');
                break;
            case '5':
                do {
                    menuBuscar();
                    cin >> opcion;
                    cin.ignore();

                    switch (opcion) {
                        case '1':
                            cout << "Título de la tarea a buscar: ";
                            getline(cin, titulo);
                            lista.buscarTarea(titulo);
                            break;
                        case '2':
                            break;
                        default:
                            cout << "Opción no válida." << endl;
                            break;
                    }
                } while (opcion != '2');
                break;

            case '6':
                do {
                    menuEliminar();
                    cin >> opcion;
                    cin.ignore();

                    switch (opcion) {
                        case '1':
                            cout << "Título de la tarea a eliminar: ";
                            getline(cin, titulo);
                            lista.eliminarTarea(titulo);
                            break;
                        case '2':
                            lista.limpiarLista();
                            cout << "Todas las tareas han sido eliminadas." << endl;
                            break;
                        case '3':
                            break;
                        default:
                            cout << "Opción no válida." << endl;
                            break;
                    }
                } while (opcion != '3');
                break;

            case '7':
                cout << "Título de la tarea a modificar: ";
                getline(cin, titulo);
                cout << "Nuevo título: ";
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
                lista.modificarTarea(titulo, Tarea(titulo, descripcion, tipo, estado, activo, fechaInicio));
                break;

            case '8':
                cout << "Hasta luego." << endl;
                break;

            default:
                cout << "Opción no válida. Inténtalo de nuevo." << endl;
                break;
        }
    } while (opcion != '8');

    return 0;
}
