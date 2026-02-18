#include "GestorArchivos.h"
#include "Cancion.h" // [ANDRÉS-LINK] necesito Cancion.h

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// trim: elimina espacios y tabulaciones al inicio y al final
string GestorArchivos::trim(const string &s)
{
    size_t inicio = s.find_first_not_of(" \t\r\n");
    if (inicio == string::npos)
        return "";
    size_t fin = s.find_last_not_of(" \t\r\n");
    return s.substr(inicio, fin - inicio + 1);
}

// cargarLetraDesdeArchivo
//   Abre el archivo en `ruta`, lee todo su contenido y lo devuelve como un único string.  Si no se puede abrir,devuelve "Letra no disponible".
string GestorArchivos::cargarLetraDesdeArchivo(const string &ruta)
{
    ifstream archivo(ruta);

    if (!archivo.is_open())
    {
        // El archivo no existe o no se tiene permiso de lectura
        return "Letra no disponible";
    }

    // Leee todo el contenido de una sola vez
    ostringstream contenido;
    contenido << archivo.rdbuf();
    archivo.close();

    string letra = contenido.str();
    if (trim(letra).empty())
    {
        return "Letra no disponible";
    }
    return letra;
}

// guardarPlaylist
//   aqui guarda las canciones en `archivoPlaylist` (por defecto "playlist.dat").

//   Formato por línea: nombreCancion|compositor|duracion|rutaLetra

//   La letra completa NO se guarda; sólo la ruta al .txt para poder recargarla después.  Si la canción no tiene ruta asociada, se guarda un string vacío en ese campo.

//   NOTA: para guardar la ruta necesitamos que el struct Cancion incluya un campo `rutaLetra` (string).

//   [ANDRÉS-LINK] Agregue `string rutaLetra;` a Cancion.h si aún no lo tiene.  importante

void GestorArchivos::guardarPlaylist(const vector<Cancion> &canciones, const string &archivoPlaylist)
{
    ofstream archivo(archivoPlaylist);

    if (!archivo.is_open())
    {
        cerr << "[ERROR] No se pudo abrir \"" << archivoPlaylist
             << "\" para escritura.\n";
        return;
    }

    for (const Cancion &c : canciones)
    {
        // Usamos '|' como delimitador porque es poco común en títulos o nombres de artistas
        archivo << c.nombreCancion << "|"
                << c.compositor << "|"
                << c.duracion << "|"
                << c.rutaLetra << "\n";
        // [ANDRÉS-LINK] c.rutaLetra debe existir en su struct Cancion
    }

    archivo.close();
    cout << "[OK] Playlist guardada en \"" << archivoPlaylist << "\".\n";
}

// cargarPlaylist
//Lee `archivoPlaylist` línea a línea, reconstruye cada Cancion y carga su letra desde el .txt correspondiente. Si el archivo no existe, devuelve un vector vacío 
//(el programa arranca "en blanco".

vector<Cancion> GestorArchivos::cargarPlaylist(const string &archivoPlaylist)
{
    vector<Cancion> canciones;
    ifstream archivo(archivoPlaylist);

    if (!archivo.is_open())
    {
        // Primera ejecución: no hay playlist guardada todavía
        cout << "[INFO] No se encontro \"" << archivoPlaylist
             << "\". Se iniciara con la playlist vacia.\n";
        return canciones;
    }

    string linea;
    int numeroLinea = 0;

    while (getline(archivo, linea))
    {
        numeroLinea++;
        linea = trim(linea);
        if (linea.empty())
            continue; // ignorar líneas en blanco

        // Separar los 4 campos por '|'
        istringstream ss(linea);
        string campos[4];
        int i = 0;

        while (i < 4 && getline(ss, campos[i], '|'))
        {
            campos[i] = trim(campos[i]);
            i++;
        }

        if (i < 4)
        {
            cerr << "[ADVERTENCIA] Linea " << numeroLinea
                 << " tiene formato incorrecto, se omite.\n";
            continue;
        }

        Cancion c;
        c.nombreCancion = campos[0];
        c.compositor = campos[1];
        c.duracion = campos[2];
        c.rutaLetra = campos[3];
        // [ANDRÉS-LINK] c.rutaLetra debe existir en su struct

        // Cargar letra desde el .txt (si hay ruta)
        if (!c.rutaLetra.empty())
        {
            c.letra = cargarLetraDesdeArchivo(c.rutaLetra);
        }
        else
        {
            c.letra = "Letra no disponible";
        }

        canciones.push_back(c);
    }

    archivo.close();
    cout << "[OK] Playlist cargada: " << canciones.size()
         << " cancion(es) encontradas.\n";
    return canciones;
}