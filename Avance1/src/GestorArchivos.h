#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H

#include <string>
#include <vector>
using namespace std;

//  GestorArchivos.h  Cristopher

// esto maneja toda la persistencia: playlist.dat y letras/*.txt

// NOTA PARA ANDRÉS:
//Este header NO depende de ListaCircular directamente para evitar dependencias circulares.Las funciones que reciben o devuelven la lista usan un puntero genérico void* quemain.cpp casteara al tipo correcto, O puedes incluir
//"ListaCircular.h" aquí cuando ya lo tengas listo y reemplazar los comentarios marcados con [ANDRÉS-LINK].

//   Lo único que necesito aqui es:
//     1. Que `Cancion` esté definida en "Cancion.h" con los campos: nombreCancion, compositor, duracion, letra.
//     2. Que `ListaCircular` exponga:
//           - insertarAlFinal(Cancion c)
//           - obtenerTodasCanciones() -> vector<Cancion>
//        (o el equivalente que use para iterar la lista).
//   Aviseme si cambia algún nombre de campo/método.

class GestorArchivos
{
public:
    // ---------- Letras ----------

    // Lee el contenido de `ruta` y lo retorna como string.
    // Si el archivo no existe o no se puede abrir, retorna "Letra no disponible".
    static string cargarLetraDesdeArchivo(const string &ruta);

    // ---------- Playlist ----------

    // Guarda todas las canciones en "playlist.dat".
    // Formato de cada línea:
    // nombreCancion|compositor|duracion|rutaLetra. La letra NO se guarda en el .dat; se recarga desde el.txt al cargar la playlist.

    // [ANDRÉS-LINK] puede reemplazar el vector<Cancion> por laestructura que uses para obtener las canciones.
    static void guardarPlaylist(const vector<struct Cancion> &canciones, const string &archivoPlaylist = "playlist.dat");

    // Lee "playlist.dat" y devuelve un vector de Cancion con la letra ya cargada (llama internamente a cargarLetraDesdeArchivo).
    // cargarLetraDesdeArchivo).
    static vector<struct Cancion> cargarPlaylist(const string &archivoPlaylist = "playlist.dat");

private:
    // Quita espacios/tabs al inicio y final de un string.
    static string trim(const string &s);
};

#endif 