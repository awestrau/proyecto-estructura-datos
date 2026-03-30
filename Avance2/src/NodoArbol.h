#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H

using namespace std;

#include <string>
#include <vector>

// Enumeracion para distinguir entre carpetas y archivos segun el plan de desarrollo
enum TipoNodo {
    CARPETA,
    ARCHIVO
};

struct NodoArbol {
    string nombre;
    TipoNodo tipo;
    string contenido;           // Solo para archivos (.txt)
    vector<NodoArbol*> hijos;   // Lista de nodos hijos (Arbol General)
    NodoArbol* padre;                // Puntero al padre para navegacion ascendente

    // Constructor de conveniencia
    NodoArbol(std::string _nombre, TipoNodo _tipo, NodoArbol* _padre = nullptr)
        : nombre(_nombre), tipo(_tipo), padre(_padre), contenido("") {}
};


#endif // NODO_ARBOL_H


