#include "MenuRedSocial.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;


string limpiar(const string& input){ //funcion para limpiar espacios al inicio y al final del nombre
    size_t start = input.find_first_not_of(" \t\n\r\f\v"); // primer carácter válido
    size_t end = input.find_last_not_of(" \t\n\r\f\v");    // último carácter válido
    if (start == string::npos || end == string::npos){ //esto evita strings vacíos o solo espacios
        return ""; // Si la cadena es completamente espacios, devuelve una cadena vacía
    }

    return input.substr(start, end - start + 1); //devuelve texto limpio sin espacios al inicio ni al final
}

void menuRedSocial(GrafoRedSocial& grafo) { //funcion del submenu de red social
    bool activo = true;
    int opcion;

    while (activo) {
        cout<< "\n=== Red Social ===\n";
        cout<< "1. Crear usuario\n";
        cout<< "2. Eliminar usuario\n";
        cout<< "3. Buscar usuario\n";
        cout<< "4. Listar usuarios\n";
        cout<< "5. Agregar amistad\n";
        cout<< "6. Eliminar amistad\n";
        cout<< "7. Ver amigos de un usuario\n";
        cout<< "8. Recorrido BFS\n";
        cout<< "9. Recorrido DFS\n";
        cout<< "10. Verificar relacion indirecta entre dos usuarios\n";
        cout<< "11. Volver al menu principal\n";
        cout<< "Opcion: ";

        if(!(cin>>opcion)){ //validar de que si se digite un numero
           cin.clear();   //limpia error de entrada
           cin.ignore(numeric_limits<streamsize>::max(), '\n'); //elimina lo que el usuario
           cout<< "Opcion invalida. Ingrese un numero.\n";
           continue;
        }
        cin.ignore();
        string nombre, nombre2;

        if(opcion == 1){
            cout<< "Nombre del usuario: ";
            getline(cin, nombre);
            nombre = limpiar(nombre); // limpiar el nombre

            if(nombre.empty()){ //validar que no este vacio
                cout<< "[!] El nombre no puede estar vacio.\n";
            }else{
            grafo.agregarUsuario(nombre);
            }
        }else if(opcion == 2){
            cout<< "Usuario a eliminar: ";
            getline(cin, nombre);
            nombre = limpiar(nombre); // limpiar el nombre
            if (nombre.empty()){
                cout << "[!] Debe ingresar un nombre.\n";
            }else{
                grafo.eliminarUsuario(nombre);
            }
        
        }else if(opcion == 3){
            cout<< "Usuario a buscar: ";
            getline(cin, nombre);
            nombre = limpiar(nombre); // limpiar el nombre
            if (nombre.empty()){
                cout << "[!] Debe ingresar un nombre.\n";
            }else{
                grafo.buscarUsuario(nombre);
            }
         
        }else if(opcion == 4){
            grafo.listarUsuarios(); //muestra todos los usuarios registrados

        }else if(opcion == 5){
            cout<< "Usuario 1: ";
            getline(cin, nombre);
            nombre = limpiar(nombre); // limpiar el nombre
            cout<< "Usuario 2: ";
            getline(cin,nombre2);
            nombre2 = limpiar(nombre2); // limpiar el nombre
            
            if(nombre.empty() || nombre2.empty()){
                cout << "[!] Debe ingresar ambos nombres.\n";
            }else{
                grafo.agregarAmistad(nombre, nombre2);
            }

        }else if(opcion == 6){
            cout<< "Usuario 1: ";
            getline(cin, nombre);
            nombre = limpiar(nombre); // limpiar el nombre
            cout<< "Usuario 2: ";
            getline(cin, nombre2);
            nombre2 = limpiar(nombre2); // limpiar el nombre
             if(nombre.empty() || nombre2.empty()){
                cout << "[!] Debe ingresar ambos nombres.\n";
            }else{
                grafo.eliminarAmistad(nombre, nombre2);
            }

        }else if(opcion ==7){
            cout<< "Usuario: ";
            getline(cin,nombre);
            nombre = limpiar(nombre); // limpiar el nombre
            if(nombre.empty()) {
                cout << "[!] Debe ingresar un nombre.\n";
            }else{
                grafo.mostrarAmigos(nombre);
            }

        }else if (opcion ==8){
            cout<< "Usuario de origen: ";
            getline(cin, nombre);
            nombre = limpiar(nombre); // limpiar el nombre
              if(nombre.empty()) {
                cout << "[!] Debe ingresar un nombre.\n";
            }else{
                grafo.BFS(nombre); //recorrido BFS 
            }

        }else if (opcion ==9){
            cout<< "Usuario de origen: ";
            getline(cin, nombre);
            nombre = limpiar(nombre); // limpiar el nombre
             if(nombre.empty()){
                cout << "[!] Debe ingresar un nombre.\n";
            }else{
                grafo.DFS(nombre); //recorrido DFS
            }

        }else if(opcion ==10){
            cout<< "Usuario 1: ";
            getline(cin, nombre);
            nombre = limpiar(nombre); // limpiar el nombre
            cout<< "Usuario 2: ";
            getline(cin, nombre2);
            nombre2 = limpiar(nombre2); // limpiar el nombre

                if(nombre.empty() || nombre2.empty()){
                    cout << "[!] Debe ingresar ambos nombres.\n";
                }else{
                    if(grafo.sonConectados(nombre, nombre2)){
                        cout<< "[OK] Los usuarios estan conectados.\n";
                    }else{
                        cout<< "[!] Los usuarios no estan conectados.\n";
                    }
                }

        }else if(opcion ==11){
            activo = false;
        }else{
            cout<< "[!] Opcion invalida. Intente de nuevo.\n";
        }
    }
}
    