#ifndef GESTION_CANCIONES_H
#define GESTION_CANCIONES_H

#include <string>
using namespace std;


//  GestionCanciones.h  –  Cristopher
//  Maneja búsqueda y eliminación con punteros directos al Nodo, sin depender de métodos específicos de ListaCircular.

// NOTA PARA ANDRÉS                                       
// Solo necesito que en ListaCircular declares PUBLIC:    
//      Nodo* cabeza; // primer nodo de la lista        
//      Nodo* actual; // canción en reproducción 


// [ANDRÉS-LINK] Cuando tengas ListaCircular.h listo,
// reemplaza las dos líneas de abajo por:
// #include "ListaCircular.h"
struct Nodo;           // forward declaration temporal
class ListaCircular;   // forward declaration temporal

class GestionCanciones {
public:
    // Busca canción por nombre (insensible a mayúsculas).
    // Si la encuentra posiciona lista.actual ahí y muestra
    // sus datos. Retorna true si tuvo éxito.
    static bool buscarCancion(ListaCircular& lista, const string& nombre);

    // Elimina canción por nombre con confirmación s/n.
    // Reconecta punteros anterior/siguiente internamente y
    // actualiza lista.actual si era el nodo eliminado.
    // Retorna true si se eliminó.
    static bool eliminarCancion(ListaCircular& lista, const string& nombre);

private:
    static string aMinusculas(const string& s);
};

#endif 