#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "Cancion.h"
#include "ListaCircular.h"
#include "GestorArchivos.h"
#include "GestionCanciones.h"

using namespace std;

// main.cpp - Menú interactivo que integra ListaCircular, GestorArchivos y GestionCanciones
// Notas para Andrés:
// - Este archivo usa las funciones ya implementadas por Christopher.
// - Si cambias nombres de métodos en ListaCircular o Cancion, actualiza aquí.

void mostrarMenu()
{
    cout << "\n=== Reproductor (simulador) ===\n";
    cout << "1) Agregar cancion\n";
    cout << "2) Eliminar cancion\n";
    cout << "3) Buscar cancion\n";
    cout << "4) Siguiente cancion\n";
    cout << "5) Cancion anterior\n";
    cout << "6) Reproducir actual\n";
    cout << "7) Mostrar playlist\n";
    cout << "8) Guardar playlist\n";
    cout << "9) Salir\n";
    cout << "Selecciona una opcion: ";
}

int main()
{
    ListaCircular lista;

    // Cargar playlist desde disco usando GestorArchivos
    vector<Cancion> cargadas = GestorArchivos::cargarPlaylist("playlist.dat");
    for (const Cancion &c : cargadas)
    {
        lista.insertarAlFinal(c);
    }

    bool running = true;
    while (running)
    {
        mostrarMenu();
        int opcion;
        if (!(cin >> opcion))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Intenta de nuevo.\n";
            continue;
        }
        cin.ignore(); // limpiar newline

        switch (opcion)
        {
        case 1: {
            Cancion c;
            cout << "Titulo: ";
            getline(cin, c.nombreCancion);
            cout << "Compositor: ";
            getline(cin, c.compositor);
            cout << "Duracion (mm:ss): ";
            getline(cin, c.duracion);
            cout << "Ruta a archivo de letra (ej: letras/miCancion.txt) o deja vacío: ";
            getline(cin, c.rutaLetra);

            // Cargar letra inmediatamente si se proporcionó ruta
            if (!c.rutaLetra.empty())
            {
                c.letra = GestorArchivos::cargarLetraDesdeArchivo(c.rutaLetra);
            }
            else
            {
                c.letra = "Letra no disponible";
            }

            lista.insertarAlFinal(c);
            cout << "[OK] Cancion agregada.\n";
            break;
        }
        case 2: {
            cout << "Nombre de la cancion a eliminar: ";
            string nombre;
            getline(cin, nombre);
            GestionCanciones::eliminarCancion(lista, nombre);
            break;
        }
        case 3: {
            cout << "Nombre de la cancion a buscar: ";
            string nombre;
            getline(cin, nombre);
            GestionCanciones::buscarCancion(lista, nombre);
            break;
        }
        case 4:
            lista.siguienteCancion();
            lista.reproducirActual();
            break;
        case 5:
            lista.anteriorCancion();
            lista.reproducirActual();
            break;
        case 6:
            lista.reproducirActual();
            break;
        case 7:
            lista.mostrarPlaylist();
            break;
        case 8: {
            vector<Cancion> todas = lista.obtenerTodasCanciones();
            GestorArchivos::guardarPlaylist(todas, "playlist.dat");
            break;
        }
        case 9:
            // Guardar automáticamente antes de salir
            {
                vector<Cancion> todas = lista.obtenerTodasCanciones();
                GestorArchivos::guardarPlaylist(todas, "playlist.dat");
            }
            running = false;
            break;
        default:
            cout << "Opcion no valida.\n";
            break;
        }
    }

    cout << "Saliendo...\n";
    return 0;
}
