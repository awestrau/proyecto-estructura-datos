#ifndef MENU_GESTOR_ARCHIVOS_H
#define MENU_GESTOR_ARCHIVOS_H

#include "GestorArbol.h"

// Muestra la ruta actual estilo /root/Carpeta/Subcarpeta/
void mostrarRuta(GestorArbol& arbol);

// Submenú principal del gestor (mkdir, cd, ls, touch, rm, cat, etc.)
void menuGestorArchivos(GestorArbol& arbol);

#endif // MENU_GESTOR_ARCHIVOS_H
