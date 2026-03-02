#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <string>
#include "Cancion.h"
#include <vector>
using namespace std;

//  ListaCircular.h  Andrés
//  Este .H define la estructura de Nodo y la clase ListaCircular con métodos básicos de
//  manejo de la lista circular, sin incluir lógica de búsqueda o eliminación específica.

struct Nodo {
    Cancion cancion; 
    Nodo* siguiente; 
    Nodo* anterior;  

    Nodo(const Cancion& c) : cancion(c), siguiente(nullptr), anterior(nullptr) {}
};

class ListaCircular {
public:
    Nodo* cabeza;
    Nodo* actual;

    ListaCircular();
    ~ListaCircular();

    bool estaVacia() const;
    void insertarAlFinal(const Cancion& c);
    void siguienteCancion();
    void anteriorCancion();
    void mostrarPlaylist() const;
    void reproducirActual() const;
    vector<Cancion> obtenerTodasCanciones() const;
};
#endif