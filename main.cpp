// main.cpp — Archivo principal integrado
// Main Final Integrado: Reproductor, Gestor de Archivos y Red Social
// Compilar desde la raíz del proyecto

#include <iostream>
#include <string>
#include <vector>
#include <limits>

// --- Avance 1 (Reproductor) ---
#include "Avance1/src/Cancion.h"
#include "Avance1/src/ListaCircular.h"
#include "Avance1/src/GestorArchivos.h"
#include "Avance1/src/GestionCanciones.h"

// --- Avance 2 (Gestor de Archivos - árbol) ---
#include "Avance2/src/NodoArbol.h"
#include "Avance2/src/GestorArbol.h"
#include "Avance2/src/MenuGestorArchivos.h"

// --- Avance 3 (Red Social - grafo) ---
#include "Avance3/src/GrafoRedSocial.h"
#include "Avance3/src/MenuRedSocial.h"

using namespace std;

// Menú del Reproductor
void menuReproductor(ListaCircular& lista) {
    bool activo = true;
    while (activo) {
        cout << "\n=== Reproductor de Musica ===\n";
        cout << "1) Agregar cancion\n";
        cout << "2) Eliminar cancion\n";
        cout << "3) Buscar cancion\n";
        cout << "4) Siguiente cancion\n";
        cout << "5) Cancion anterior\n";
        cout << "6) Reproducir actual\n";
        cout << "7) Mostrar playlist\n";
        cout << "8) Guardar playlist\n";
        cout << "9) Volver al menu principal\n";
        cout << "Opcion: ";

        int op;
        if (!(cin >> op)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }
        cin.ignore();

        switch (op) {
        case 1: {
            Cancion c;
            cout << "Titulo: ";       getline(cin, c.nombreCancion);
            cout << "Compositor: ";   getline(cin, c.compositor);
            cout << "Duracion (mm:ss): "; getline(cin, c.duracion);
            cout << "Ruta a letra (o Enter para omitir): ";
            getline(cin, c.rutaLetra);
            if (!c.rutaLetra.empty())
                c.letra = GestorArchivos::cargarLetraDesdeArchivo(c.rutaLetra);
            else
                c.letra = "Letra no disponible";
            lista.insertarAlFinal(c);
            cout << "[OK] Cancion agregada.\n";
            break;
        }
        case 2: {
            string nombre;
            cout << "Cancion a eliminar: "; getline(cin, nombre);
            GestionCanciones::eliminarCancion(lista, nombre);
            break;
        }
        case 3: {
            string nombre;
            cout << "Cancion a buscar: "; getline(cin, nombre);
            GestionCanciones::buscarCancion(lista, nombre);
            break;
        }
        case 4: lista.siguienteCancion(); lista.reproducirActual(); break;
        case 5: lista.anteriorCancion();  lista.reproducirActual(); break;
        case 6: lista.reproducirActual(); break;
        case 7: lista.mostrarPlaylist();  break;
        case 8: {
            vector<Cancion> todas = lista.obtenerTodasCanciones();
            GestorArchivos::guardarPlaylist(todas, "Avance1/src/playlist.dat");
            cout << "[OK] Playlist guardada.\n";
            break;
        }
        case 9: activo = false; break;
        default: cout << "Opcion no valida.\n";
        }
    }
}

// Menú principal del programa
int main() {
    // Cargar playlist del Avance 1
    ListaCircular lista;
    vector<Cancion> cargadas = GestorArchivos::cargarPlaylist("Avance1/src/playlist.dat");
    for (const Cancion& c : cargadas)
        lista.insertarAlFinal(c);

    // Instanciar GestorArbol
    GestorArbol arbol;

    // Instanciar GrafoRedSocial
    GrafoRedSocial redSocial;

    bool corriendo = true;
    while (corriendo) {
        cout << "\n========================================\n";
        cout << "       PROYECTO ESTRUCTURA DE DATOS     \n";
        cout << "========================================\n";
        cout << "1) Reproductor de Musica\n";
        cout << "2) Gestor de Archivos\n";
        cout << "3) Red Social\n";
        cout << "4) Salir\n";
        cout << "Opcion: ";

        int op;
        if (!(cin >> op)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }
        cin.ignore();

        switch (op) {
        case 1:
            menuReproductor(lista);
            break;
        case 2:
            menuGestorArchivos(arbol);
            break;
        case 3:
            menuRedSocial(redSocial);
            break;
        case 4:
            // Guardar playlist antes de salir
            {
                vector<Cancion> todas = lista.obtenerTodasCanciones();
                GestorArchivos::guardarPlaylist(todas, "Avance1/src/playlist.dat");
            }
            corriendo = false;
            break;
        default:
            cout << "Opcion no valida.\n";
        }
    }

    cout << "Hasta luego!\n";
    return 0;
}
