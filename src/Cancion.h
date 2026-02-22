#ifndef CANCION_H
#define CANCION_H

#include <string>
using namespace std;

// Cancion.h
// Estructura de datos que representa una canción. Andrés: asegúrate de
// mantener los nombres de campo exactamente como están aquí porque
// otros módulos (GestorArchivos, GestionCanciones) dependen de ellos.

struct Cancion {
    string nombreCancion; // Título de la canción
    string compositor;    // Autor / compositor
    string duracion;      // Formato "mm:ss" o "hh:mm:ss"
    string letra;         // Contenido de la letra (se carga desde .txt)
    string rutaLetra;     // Ruta al archivo .txt de la letra (puede quedar vacía)
};

#endif // CANCION_H
