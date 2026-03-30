#include "MenuGestorArchivos.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>

using namespace std;

// Imprime la ruta actual al estilo: [/root/Documentos/] $
void mostrarRuta(GestorArbol& arbol) {
    cout << "[" << arbol.getRutaActual() << "] $ ";
}

// Submenú completo del Gestor de Archivos
void menuGestorArchivos(GestorArbol& arbol) {
    bool activo = true;
    string comando;

    cout << "\n=== Gestor de Archivos ===\n";
    cout << "Comandos: ls, ls -R, mkdir, touch, cd, cd .., rm, cat, pwd, salir\n";

    while (activo) {
        mostrarRuta(arbol);
        getline(cin, comando);

        // ---- ls: listar contenido de la carpeta actual ----
        if (comando == "ls") {
            arbol.listarHijos();

        // ---- ls -R: árbol completo desde raíz ----
        } else if (comando == "ls -R") {
            arbol.mostrarArbol();

        // ---- pwd: mostrar ruta actual ----
        } else if (comando == "pwd") {
            cout << arbol.getRutaActual() << "\n";

        // ---- mkdir: crear carpeta ----
        } else if (comando.substr(0, 6) == "mkdir ") {
            string nombre = comando.substr(6);
            if (nombre.empty()) {
                cout << "Error: debes indicar un nombre.\n";
                continue;
            }
            bool existe = arbol.buscarHijo(nombre);

            if (existe) {
                cout << "Error: ya existe '" << nombre << "' en esta carpeta.\n";
            } else {
                arbol.crearCarpeta(nombre);
                cout << "Carpeta '" << nombre << "' creada.\n";
            }

        // ---- touch: crear archivo .txt ----
        } else if (comando.substr(0, 6) == "touch ") {
            string nombre = comando.substr(6);
            if (nombre.empty()) {
                cout << "Error: debes indicar un nombre.\n";
                continue;
            }
            if (nombre.size() < 5 || nombre.substr(nombre.size() - 4) != ".txt") {
                cout << "Error: solo se permiten archivos .txt\n";
                continue;
            }
            bool existe = arbol.buscarHijo(nombre);

            if (existe) {
                cout << "Error: ya existe '" << nombre << "' en esta carpeta.\n";
            } else {
                // Here we could ask for content or just empty
                arbol.crearArchivo(nombre, "Contenido vacio");
                cout << "Archivo '" << nombre << "' creado.\n";
            }

        // ---- cd <nombre>: entrar a una subcarpeta ----
        } else if (comando.substr(0, 3) == "cd " && comando != "cd ..") {
            string nombre = comando.substr(3);
            if (nombre.empty()) {
                cout << "Error: debes indicar una carpeta.\n";
                continue;
            }
            bool existe  = arbol.buscarHijo(nombre);
            bool esCarpeta = arbol.esCarpeta(nombre);

            if (!existe) {
                cout << "Error: no existe '" << nombre << "' en la carpeta actual.\n";
            } else if (!esCarpeta) {
                cout << "Error: '" << nombre << "' es un archivo, no una carpeta.\n";
            } else {
                arbol.entrarCarpeta(nombre);
            }

        // ---- cd ..: subir al padre ----
        } else if (comando == "cd ..") {
            if (!arbol.subirAlPadre()) {
                cout << "Ya estas en el directorio raiz.\n";
            }

        // ---- rm: eliminar archivo o carpeta ----
        } else if (comando.substr(0, 3) == "rm ") {
            string nombre = comando.substr(3);
            if (nombre.empty()) {
                cout << "Error: debes indicar qué eliminar.\n";
                continue;
            }
            bool existe = arbol.buscarHijo(nombre);

            if (!existe) {
                cout << "Error: no existe '" << nombre << "'.\n";
            } else {
                cout << "Seguro que quieres eliminar '" << nombre << "'? (s/n): ";
                string resp;
                getline(cin, resp);
                if (resp == "s" || resp == "S") {
                    arbol.eliminar(nombre);
                    cout << "'" << nombre << "' eliminado.\n";
                } else {
                    cout << "Cancelado.\n";
                }
            }

        // ---- cat: leer contenido de un archivo .txt ----
        } else if (comando.substr(0, 4) == "cat ") {
            string nombre = comando.substr(4);
            if (nombre.empty()) {
                cout << "Error: debes indicar un archivo.\n";
                continue;
            }
            if (nombre.size() < 5 || nombre.substr(nombre.size() - 4) != ".txt") {
                cout << "Error: cat solo funciona con archivos .txt\n";
                continue;
            }
            bool existe = arbol.buscarHijo(nombre);
            bool esCarpeta = arbol.esCarpeta(nombre);

            if (!existe) {
                cout << "Error: no existe '" << nombre << "'.\n";
            } else if (esCarpeta) {
                cout << "Error: '" << nombre << "' es una carpeta, usa 'ls' para ver su contenido.\n";
            } else {
                string contenido = arbol.obtenerContenido(nombre);
                cout << contenido << "\n";
            }

        // ---- salir: volver al menú principal ----
        } else if (comando == "salir") {
            activo = false;

        } else if (comando.empty()) {
            // enter, ignore
        } else {
            cout << "Comando no reconocido: '" << comando << "'\n";
            cout << "Comandos validos: ls, ls -R, mkdir, touch, cd, cd .., rm, cat, pwd, salir\n";
        }
    }
}
