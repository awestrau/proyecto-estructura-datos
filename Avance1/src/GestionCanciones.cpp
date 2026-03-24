
//  GestionCanciones.cpp  Cristopher >:)
#include "GestionCanciones.h"

#include "ListaCircular.h"

#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

// aMinusculas – transforma a mayúsculas a minúsculas
///esto crea una copia local de s. Trabajamos sobre la copia para no tocar el original (por eso el parámetro era const).
string GestionCanciones::aMinusculas(const string &s)
{
    string r = s;
    transform(r.begin(), r.end(), r.begin(),
              [](unsigned char c)
              { return tolower(c); }); 
    return r;
}
//Esto es una **lambda** una función anónima que se define en el momento. Por cada carácter `c` del string, llama a `tolower(c)` que lo convierte a minúscula.
//Se usa `unsigned char` y no `char` porque `tolower` tiene comportamiento indefinido con `char` si el valor es negativo (como caracteres especiales). `unsigned char` lo evita

// esto es lo que hace buscarCancion
//   punteros directos:
//    1. Guarda la posición de cabeza.
//    2. Recorre nodo a nodo comparando nombres (sin mayús.).
//    3. Al dar la vuelta completa (llegamos a cabeza de nuevo) para el ciclo.
//    4. Si encontró: mueve lista.actual al nodo y muestra info.
//    5. Si no encontró: informa al usuario.

bool GestionCanciones::buscarCancion(ListaCircular &lista, const string &nombre)
{
    // Verificar lista vacía accediendo directamente a cabeza
    if (lista.cabeza == nullptr)
    {
        cout << "[INFO] La playlist esta vacia. No hay nada que buscar.\n";
        return false;
    }

    string nombreBuscado = aMinusculas(nombre);
    Nodo *cursor = lista.cabeza;

    // Recorrido circular: paramos cuando volvamos a cabeza para el ciclo
    do
    {
        string nombreActual = aMinusculas(cursor->cancion.nombreCancion);

        if (nombreActual == nombreBuscado)
        {
            // ✅ Encontrada: posicionar actual aquí
            lista.actual = cursor;

            cout << "\n[OK] Cancion encontrada y seleccionada como actual:\n";
            cout << "---------------------------------------------\n";
            cout << "  Titulo    : " << cursor->cancion.nombreCancion << "\n";
            cout << "  Compositor: " << cursor->cancion.compositor << "\n";
            cout << "  Duracion  : " << cursor->cancion.duracion << "\n";
            cout << "---------------------------------------------\n";
            return true;
        }

        cursor = cursor->siguiente;

    } while (cursor != lista.cabeza);

    // No se encontró
    cout << "[INFO] No se encontro ninguna cancion con el nombre \""
         << nombre << "\".\n";
    cout << "       Verifica la ortografia e intenta de nuevo.\n";
    return false;
}

// esto es lo que hace eliminarCancion
//    1. Busca el nodo a eliminar recorriendo la lista.
//    2. Pide confirmación s/n.
//    3. Reconecta: nodoAnterior->siguiente = nodoSiguiente nodoSiguiente->anterior = nodoAnterior
//    4. Casos especiales:
//       a) Lista con un solo nodo  -> cabeza = actual = nullptr
//       b) El nodo a eliminar ES cabeza -> mover cabeza al sig.
//       c) El nodo a eliminar ES actual -> mover actual al sig.
//    5. Liberar memoria con delete.

bool GestionCanciones::eliminarCancion(ListaCircular &lista, const string &nombre)
{
    if (lista.cabeza == nullptr)
    {
        cout << "[INFO] La playlist esta vacia. No hay nada que eliminar.\n";
        return false;
    }

    string nombreBuscado = aMinusculas(nombre);
    Nodo *cursor = lista.cabeza;
    Nodo *objetivo = nullptr;

    //Paso 1: busca el nodo 
    do
    {
        if (aMinusculas(cursor->cancion.nombreCancion) == nombreBuscado)
        {
            objetivo = cursor;
            break;
        }
        cursor = cursor->siguiente;
    } while (cursor != lista.cabeza);

    if (objetivo == nullptr)
    {
        cout << "[INFO] No se encontro ninguna cancion con el nombre \""
             << nombre << "\".\n";
        return false;
    }

    //Paso 2: muestra y confirmar 
    cout << "\nSe eliminara la siguiente cancion:\n";
    cout << "---------------------------------------------\n";
    cout << "  Titulo    : " << objetivo->cancion.nombreCancion << "\n";
    cout << "  Compositor: " << objetivo->cancion.compositor << "\n";
    cout << "  Duracion  : " << objetivo->cancion.duracion << "\n";
    cout << "---------------------------------------------\n";

    cout << "¿Estas seguro de que deseas eliminarla? (s/n): ";
    char respuesta;
    cin >> respuesta;
    cin.ignore();

    if (tolower(respuesta) != 's')
    {
        cout << "[INFO] Eliminacion cancelada.\n";
        return false;
    }

    //Paso 3: caso lista con UN solo nodo
    if (objetivo->siguiente == objetivo)
    {
        // Es el único nodo; la lista queda vacía
        delete objetivo;
        lista.cabeza = nullptr;
        lista.actual = nullptr;
        cout << "[OK] Cancion eliminada. La playlist quedo vacia.\n";
        return true;
    }

    //  Paso 4: reconecta los punteros
    Nodo *anteriorNodo = objetivo->anterior;
    Nodo *siguienteNodo = objetivo->siguiente;

    anteriorNodo->siguiente = siguienteNodo;
    siguienteNodo->anterior = anteriorNodo;

    // Paso 5: actualiza cabeza si era la cabeza
    if (objetivo == lista.cabeza)
    {
        lista.cabeza = siguienteNodo;
    }

    // Paso 6: actualiza actual si era el nodo actual
    if (objetivo == lista.actual)
    {
        // Movemos actual al siguiente para no dejar puntero colgante y el usuario sigue escuchando la próxima.
        lista.actual = siguienteNodo;
        cout << "[INFO] La cancion en reproduccion fue eliminada. "
             << "Ahora suena: \""
             << lista.actual->cancion.nombreCancion << "\".\n";
    }

    // Paso 7: liberar memoria
    delete objetivo;

    cout << "[OK] La cancion \"" << nombre
         << "\" fue eliminada de la playlist.\n";
    return true;
}