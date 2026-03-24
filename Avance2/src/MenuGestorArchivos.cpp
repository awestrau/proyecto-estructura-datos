// MenuGestorArchivos.cpp — Persona B osea Cris
// Lógica del menú de comandos para el Gestor de Archivos (árbol general).
// Aquí va todo lo que es interfaz: imprimir, pedir input, validar, llamar al árbol.

#include "MenuGestorArchivos.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>   // para leer archivos .txt con 'cat'

using namespace std;


// ANDRES: estas son las operaciones que necesito de GestorArbol.
// Te las listo para que sepas qué métodos implementar (o cómo los llamarías tú):
//
//   arbol.getRutaActual()            string con la ruta tipo "/root/Docs/"
//   arbol.listarHijos()              imprime los hijos del nodo actual (ls)
//   arbol.crearCarpeta(nombre)       inserta nodo tipo CARPETA en actual
//   arbol.crearArchivo(nombre)       inserta nodo tipo ARCHIVO (.txt) en actual
//   arbol.entrarCarpeta(nombre)      mueve actual al hijo con ese nombre (cd)
//   arbol.subirAlPadre()             mueve actual al padre (cd ..)
//   arbol.eliminar(nombre)           borra hijo con ese nombre (rm)
//   arbol.buscarHijo(nombre)         bool, dice si existe un hijo con ese nombre
//   arbol.obtenerContenido(nombre)   string con el texto del archivo (cat)
//   arbol.esCarpeta(nombre)          bool, dice si el hijo es CARPETA o ARCHIVO
//   arbol.mostrarArbol()             recorrido preorden con indentación (ls -R)
//
// Si los nombres que usaste son distintos, dímelos y ajusto aquí sin problema.

// Imprime la ruta actual al estilo: [/root/Documentos/]
void mostrarRuta(/* GestorArbol& arbol */) {
    // ANDRES: descomente y ajuste esto cuando tengas getRutaActual():
    // cout << "[" << arbol.getRutaActual() << "] $ ";

    // Stub temporal para que compile solo
    cout << "[/root/] $ ";
}


// Submenú completo del Gestor de Archivos
void menuGestorArchivos(/* GestorArbol& arbol */) {
    bool activo = true;
    string comando;

    cout << "\n=== Gestor de Archivos ===\n";
    cout << "Comandos: ls, ls -R, mkdir, touch, cd, cd .., rm, cat, pwd, salir\n";

    while (activo) {
        mostrarRuta(/* arbol */);
        getline(cin, comando);

        // ---- ls: listar contenido de la carpeta actual ----
        if (comando == "ls") {
            // ANDRES: cambie esto por: arbol.listarHijos();
            cout << "[stub] ls: aqui van los hijos del nodo actual\n";

        // ---- ls -R: árbol completo desde raíz ----
        } else if (comando == "ls -R") {
            // ANDRES: cambie esto por: arbol.mostrarArbol();
            cout << "[stub] ls -R: aqui va el recorrido preorden completo\n";

        // ---- pwd: mostrar ruta actual ----
        } else if (comando == "pwd") {
            // ANDRES: cambie esto por: cout << arbol.getRutaActual() << "\n";
            cout << "[stub] /root/\n";

        // ---- mkdir: crear carpeta ----
        } else if (comando.substr(0, 6) == "mkdir ") {
            string nombre = comando.substr(6);
            if (nombre.empty()) {
                cout << "Error: debes indicar un nombre.\n";
                continue;
            }
            // ANDRES: aquí llamo buscarHijo para validar duplicados antes de insertar.
            // bool existe = arbol.buscarHijo(nombre);
            bool existe = false; // stub temporal

            if (existe) {
                cout << "Error: ya existe '" << nombre << "' en esta carpeta.\n";
            } else {
                // arbol.crearCarpeta(nombre);
                cout << "[stub] Carpeta '" << nombre << "' creada.\n";
            }

        // ---- touch: crear archivo .txt ----
        } else if (comando.substr(0, 6) == "touch ") {
            string nombre = comando.substr(6);
            if (nombre.empty()) {
                cout << "Error: debes indicar un nombre.\n";
                continue;
            }
            // Validar que sea .txt
            if (nombre.size() < 5 || nombre.substr(nombre.size() - 4) != ".txt") {
                cout << "Error: solo se permiten archivos .txt\n";
                continue;
            }
            // ANDRES: aquí también valido duplicados antes de insertar.
            // bool existe = arbol.buscarHijo(nombre);
            bool existe = false; // stub temporal

            if (existe) {
                cout << "Error: ya existe '" << nombre << "' en esta carpeta.\n";
            } else {
                // arbol.crearArchivo(nombre);
                cout << "[stub] Archivo '" << nombre << "' creado.\n";
            }

        // ---- cd <nombre>: entrar a una subcarpeta ----
        } else if (comando.substr(0, 3) == "cd " && comando != "cd ..") {
            string nombre = comando.substr(3);
            if (nombre.empty()) {
                cout << "Error: debes indicar una carpeta.\n";
                continue;
            }
            // ANDRES: necesito buscarHijo y saber si es carpeta o archivo.
            // bool existe  = arbol.buscarHijo(nombre);
            // bool esCarpeta = arbol.esCarpeta(nombre);
            bool existe    = false; // stub
            bool esCarpeta = false; // stub

            if (!existe) {
                cout << "Error: no existe '" << nombre << "' en la carpeta actual.\n";
            } else if (!esCarpeta) {
                cout << "Error: '" << nombre << "' es un archivo, no una carpeta.\n";
            } else {
                // arbol.entrarCarpeta(nombre);
                cout << "[stub] Entrando a '" << nombre << "'...\n";
            }

        // ---- cd ..: subir al padre ----
        } else if (comando == "cd ..") {
            // ANDRES: necesito saber si ya estoy en la raíz para no subir más.
            // Asumo que subirAlPadre() no hace nada si ya está en raíz,
            // o devuelve bool, lo que prefieras.
            // arbol.subirAlPadre();
            cout << "[stub] Subiendo al directorio padre...\n";

        // ---- rm: eliminar archivo o carpeta ----
        } else if (comando.substr(0, 3) == "rm ") {
            string nombre = comando.substr(3);
            if (nombre.empty()) {
                cout << "Error: debes indicar qué eliminar.\n";
                continue;
            }
            // ANDRES: si eliminar una carpeta con hijos requiere confirmación,
            // implementa esa validación en GestorArbol::eliminar() o digame y lo pongo aquí.
            // bool existe = arbol.buscarHijo(nombre);
            bool existe = false; // stub

            if (!existe) {
                cout << "Error: no existe '" << nombre << "'.\n";
            } else {
                cout << "Seguro que quieres eliminar '" << nombre << "'? (s/n): ";
                string resp;
                getline(cin, resp);
                if (resp == "s" || resp == "S") {
                    // arbol.eliminar(nombre);
                    cout << "[stub] '" << nombre << "' eliminado.\n";
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
            // ANDRES: necesito obtenerContenido(nombre) que devuelva un string.
            // Si guardas el contenido directamente en el nodo, perfecto.
            // string contenido = arbol.obtenerContenido(nombre);
            // cout << contenido << "\n";
            cout << "[stub] (contenido de " << nombre << " iria aqui)\n";

        // ---- salir: volver al menú principal ----
        } else if (comando == "salir") {
            activo = false;

        } else if (comando.empty()) {
            // solo presionó enter, no hacer nada

        } else {
            cout << "Comando no reconocido: '" << comando << "'\n";
            cout << "Comandos validos: ls, ls -R, mkdir, touch, cd, cd .., rm, cat, pwd, salir\n";
        }
    }
}
