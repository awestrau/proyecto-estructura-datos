#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "Cancion.h"
#include <vector>
#include <iostream>
using namespace std;

// ═══════════════════════════════════════════════════════════════════════════
// ListaCircular.h – ANDRÉS: ESTRUCTURA DE DATOS
// ═══════════════════════════════════════════════════════════════════════════
// INSTRUCCIONES:
// 1. Los struct Nodo y class ListaCircular YA están definidos aquí (no cambies)
// 2. VE A ListaCircular.cpp e IMPLEMENTA TODOS LOS MÉTODOS que ves abajo
// 3. Lee los comentarios en ListaCircular.cpp para detalles de cada método
// 4. IMPORTANTE: mantén los nombres exactos (Christopher y main.cpp dependen)
//
// NOTAS IMPORTANTES:
// - cabeza y actual son PUBLIC porque GestionCanciones les accede
// - La lista es DOBLEMENTE ENLAZADA y CIRCULAR
// - VER EJEMPLOS DE RECORRIDO CIRCULAR: en GestionCanciones.cpp
// ═══════════════════════════════════════════════════════════════════════════

struct Nodo {
    Cancion cancion;   // Datos de la canción
    Nodo* siguiente;   // Puntero al siguiente nodo (circular)
    Nodo* anterior;    // Puntero al nodo anterior (circular)
};

class ListaCircular {
public:
    // ESTOS son públicos porque GestionCanciones los necesita
    Nodo* cabeza;      // Primer nodo; nullptr si vacía
    Nodo* actual;      // Nodo en reproducción; nullptr si no hay canción

    // ANDRÉS: IMPLEMENTA ESTOS MÉTODOS EN ListaCircular.cpp
    // Ver comentarios detallados en ListaCircular.cpp
    
    // Constructor: inicializa cabeza y actual a nullptr
    ListaCircular();
    
    // Destructor: libera todos los nodos circularmente
    ~ListaCircular();

    // Verifica si la lista está vacía
    bool estaVacia() const;
    
    // Inserta una canción al final (mantiene circularidad)
    // CASO 1: Si vacía, crea primer nodo
    // CASO 2: Si hay elementos, inserta antes de cabeza
    void insertarAlFinal(const Cancion &c);
    
    // Avanza al siguiente nodo circularmente
    // Si estabas en el último, vuelves al primero
    void siguienteCancion();
    
    // Retrocede al nodo anterior circularmente
    // Si estabas en el primero, vas al último
    void anteriorCancion();
    
    // Muestra todas las canciones en orden
    // Marca con "<-- (actual)" la canción en reproducción
    void mostrarPlaylist() const;
    
    // Muestra datos de la canción actual + fragmento de letra
    void reproducirActual() const;

    // Devuelve todas las canciones en un vector
    // Útil para que GestorArchivos guarde en playlist.dat
    vector<Cancion> obtenerTodasCanciones() const;
};

#endif // LISTA_CIRCULAR_H
