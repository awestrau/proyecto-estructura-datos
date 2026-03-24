#ifndef MENU_GESTOR_ARCHIVOS_H
#define MENU_GESTOR_ARCHIVOS_H

// MenuGestorArchivos.h — Persona B osea Cristopher
// Declaración del menú de comandos del Gestor de Archivos.
//
// ANDRES: cuando GestorArbol esté listo, cambie la firma de menuGestorArchivos
// para que reciba una referencia: menuGestorArchivos(GestorArbol& arbol)
// y descomenta el #include de GestorArbol.h aqui y en el .cpp

// #include "GestorArbol.h"

// Muestra la ruta actual estilo /root/Carpeta/Subcarpeta/
// ANDRES: internamente llama arbol.getRutaActual() o como lo hayas nombrado,
// avísame el nombre exacto del método para conectarlo bien.
void mostrarRuta(/* GestorArbol& arbol */);

// Submenú principal del gestor (mkdir, cd, ls, touch, rm, cat, etc.)
void menuGestorArchivos(/* GestorArbol& arbol */);

#endif // MENU_GESTOR_ARCHIVOS_H
