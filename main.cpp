#include "ListaEnlazada.h"
#include <iostream>
using namespace std;

char revisar(string x) {
    char y;
    if (x.length() != 1) {
        y='9';
    } else {
        y=x[0];
    }
    return y;
}

void menuPrincipal() {
    cout << "|-------------------------------------------------------|" << endl;
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

void menuAgregar() {
    cout << "|-------------------------------------------------------|" << endl;
    cout << "\n\tAGREGAR TAREAS" << endl;
    cout << "1. Agregar una tarea" << endl;
    cout << "2. Agregar varias tareas" << endl;
    cout << "3. Volver al menú principal" << endl;
    cout << "Elige una opción: ";
}

void menuOrdenar() {
    cout << "|-------------------------------------------------------|" << endl;
    cout << "\n\tORDENAR TAREAS" << endl;
    cout << "1. Ordenar alfabéticamente" << endl;
    cout << "2. Ordenar por fecha de creación" << endl;
    cout << "3. Volver al menú principal" << endl;
    cout << "Elige una opción: ";
}

void menuFiltrar() {
    cout << "|-------------------------------------------------------|" << endl;
    cout << "\n\tFILTRAR TAREAS" << endl;
    cout << "1. Mostrar tareas activas" << endl;
    cout << "2. Filtrar por tipo" << endl;
    cout << "3. Volver al menú principal" << endl;
    cout << "Elige una opción: ";
}

void menuEliminar() {
    cout << "|-------------------------------------------------------|" << endl;
    cout << "\n\tELIMINAR TAREAS" << endl;
    cout << "1. Eliminar por título" << endl;
    cout << "2. Eliminar todas las tareas" << endl;
    cout << "3. Volver al menú principal" << endl;
    cout << "Elige una opción: ";
}

void menuBuscar() {
    cout << "|-------------------------------------------------------|" << endl;
    cout << "\n\tBUSCAR TAREA" << endl;
    cout << "1. Buscar por título" << endl;
    cout << "2. Volver al menú principal" << endl;
    cout << "Elige una opción: ";
}

int main() {
    ListaEnlazada lista;
    char opcion;
    string x, viejo, titulo, descripcion, tipo, estado, fechaInicio;
    bool activo;
    lista.agregarTarea(Tarea("funcion agregar", "agregar la funcion de agregar a ListaEnlazada.cpp", "codigo", "pendiente", true, "13-10-24"));
    lista.agregarTarea(Tarea("objetivos generales y especificos", "terminar el apartado objetivos del documento", "documentacion", "en progeso", true, "12-10-24"));
    lista.agregarTarea(Tarea("investigar estructuras de datos", "investigar las estructuras de datos existentes", "investigacion", "terminado", false, "10-10-24"));
                            
    cout << "BIENVENIDO A CHRONOS MANAGER" << endl;

    do {
        menuPrincipal();
        cin >> x;
        opcion=revisar(x);
        cin.ignore();

        switch (opcion) {
            case '1':
                do {
                    menuAgregar();
                    cin >> x;
                    opcion=revisar(x);
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
                            cout << "Activo (1 es Sí, 0 es No :3): ";
                            cin >> activo;
                            cin.ignore();
                            cout << "Fecha de inicio: ";
                            getline(cin, fechaInicio);
                            lista.agregarTarea(Tarea(titulo, descripcion, tipo, estado, activo, fechaInicio));
                            break;
                        case '2':
                            int z;
                            cout << "cuantas?: ";
                            cin >> z;
                            while (z>0) {
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
                                z--;
                            }
                            break;
                        case '3':

                            break;
                        default:
                            cout << "Opción no válida." << endl;
                            break;
                        }
                    } while (opcion != '3');
                    break;
                break;

            case '2':
                cout << "|-------------------------------------------------------|" << endl;
                lista.mostrarTareas();
                break;

            case '3':
                do {
                    menuOrdenar();
                    cin >> x;
                    opcion=revisar(x);
                    cin.ignore();
                    cout << "|-------------------------------------------------------|" << endl;
                    switch (opcion) {
                        case '1':
                            lista.ordenarTareas();
                            break;
                        case '2':
                            lista.ordenarPorFecha();
                            break;
                        case '3':
                            break;
                        default:
                            cout << "Opción no válida." << endl;
                            break;
                    }
                } while (opcion != '3');
                break;

            case '4':
                do {
                    menuFiltrar();
                    cin >> x;
                    opcion=revisar(x);
                    cin.ignore();
                    cout << "|-------------------------------------------------------|" << endl;
                    
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
                    cin >> x;
                    opcion=revisar(x);
                    cin.ignore();
                    cout << "|-------------------------------------------------------|" << endl;
                    
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
                    cin >> x;
                    opcion=revisar(x);
                    cin.ignore();
                    cout << "|-------------------------------------------------------|" << endl;
                    
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
                cout << "|-------------------------------------------------------|" << endl;
                
                cout << "Título de la tarea a modificar: ";
                getline(cin, viejo);
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
                lista.modificarTarea(viejo, Tarea(titulo, descripcion, tipo, estado, activo, fechaInicio));
                break;

            case '8':
                cout << "|-------------------------------------------------------|" << endl;
                
                cout << "Hasta luego." << endl;
                break;

            default:
                cout << "|-------------------------------------------------------|" << endl;
                
                cout << "Opción no válida. Inténtalo de nuevo." << endl;
                break;
        }
    } while (opcion != '8');

    return 0;
}
