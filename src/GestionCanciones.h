#ifndef GESTION_CANCIONES_H
#define GESTION_CANCIONES_H

#include <string>
using namespace std;


//  GestionCanciones.h  Cristopher
//  este .H maneja búsqueda y eliminación con punteros directos al Nodo, sin depender de métodos específicos de ListaCircular.


#include "ListaCircular.h"

class GestionCanciones {
public:
    // Busca canción por nombre (insensible a mayúsculas). Si la encuentra posiciona lista.actual ahí y muestra sus datos. esto retorna true si pasa con exito lfgo.
    static bool buscarCancion(ListaCircular& lista, const string& nombre);
    // Elimina canción por nombre con confirmación s/n.
    // Reconecta punteros anterior/siguiente internamente y actualiza lista.actual si era el nodo eliminado.
    // Retorna true si se eliminó.
    static bool eliminarCancion(ListaCircular& lista, const string& nombre);

private:
    static string aMinusculas(const string& s);
};

#endif 