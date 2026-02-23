#include "ListaCircular.h"
#include <iostream>

// Mae aqui le pedi a la IA que me escribiera lo que tenias que implementar aqui, 
//tal vez te sirva de guia para implementar el codigo, o al menos para entender lo que se espera de cada metodo.

// ═══════════════════════════════════════════════════════════════════════════
// 📋 TAREAS A IMPLEMENTAR (Copia esta estructura):
// ═══════════════════════════════════════════════════════════════════════════
//
// 1. Constructor ListaCircular()
//    └─ Inicializar cabeza = nullptr y actual = nullptr


//
// 2. Destructor ~ListaCircular()
//    └─ Recorrer circularmente el nodo cabeza->siguiente hasta volver a cabeza
//    └─ Liberar TODOS los nodos con delete
//    └─ Poner cabeza = nullptr y actual = nullptr al final
//
// 3. bool estaVacia() const
//    └─ Retorna true si cabeza == nullptr, false si no
//
// 4. void insertarAlFinal(const Cancion &c)
//    └─ Crear nuevo Nodo con new, copiar canción a nuevo->cancion
//    └─ CASO 1: Si lista vacía (cabeza == nullptr)
//       └─ nuevo->siguiente = nuevo, nuevo->anterior = nuevo
//       └─ cabeza = nuevo, actual = nuevo
//    └─ CASO 2: Si hay elementos
//       └─ Obtener cola = cabeza->anterior (último nodo)
//       └─ Conectar: cola->siguiente = nuevo, nuevo->anterior = cola
//       └─ Conectar: nuevo->siguiente = cabeza, cabeza->anterior = nuevo
//
// 5. void siguienteCancion()
//    └─ Si actual != nullptr: actual = actual->siguiente
//    └─ (la circularidad ya está en los punteros)
//
// 6. void anteriorCancion()
//    └─ Si actual != nullptr: actual = actual->anterior
//
// 7. void mostrarPlaylist() const
//    └─ Si cabeza == nullptr: imprimir "[INFO] Playlist vacia.\n"
//    └─ Recorrer desde cabeza hasta volver a cabeza (do-while)
//    └─ Imprimir idx. nombreCancion
//    └─ Si es actual, agregar " <-- (actual)"
//
// 8. void reproducirActual() const
//    └─ Si actual == nullptr: imprimir "[INFO] No hay cancion en reproduccion.\n"
//    └─ Mostrar: nombreCancion, compositor, duracion
//    └─ Si letra.empty() o es "Letra no disponible": mostrar "Letra no disponible"
//    └─ Si hay letra: mostrar primeros ~400 caracteres + "[truncado]" si sobra
//
// 9. vector<Cancion> obtenerTodasCanciones() const
//    └─ Crear vector<Cancion> vacío
//    └─ Si cabeza == nullptr: retornar vector vacío
//    └─ Recorrer circularmente desde cabeza hasta volver a cabeza
//    └─ push_back() cada canción al vector
//    └─ Retornar vector lleno
//
// ═══════════════════════════════════════════════════════════════════════════
// 📌 NOTAS IMPORTANTES:
// ═══════════════════════════════════════════════════════════════════════════
// - Usa #include "ListaCircular.h" al inicio
// - Usa #include <iostream> para cout
// - La lista es DOBLEMENTE ENLAZADA y CIRCULAR:
//   * cabeza->anterior apunta al último nodo
//   * último nodo->siguiente apunta a cabeza
// - CUIDADO con recorridos circulares: usa do-while (cursor != cabeza)
// - Los recorridos SIEMPRE empiezan en cabeza
// - RECUERDA: cuando recorres, terminas cuando vuelves a cabeza
//
// ═══════════════════════════════════════════════════════════════════════════
// 🔗 REFERENCIAS DEL PROYECTO:
// ═══════════════════════════════════════════════════════════════════════════
// - GestionCanciones.cpp accede a lista.cabeza y lista.actual directamente
// - main.cpp usa TODOS tus métodos, así que NO cambies las firmas
// - Si tienes dudas de cómo usar los punteros, ver Cancion.h y Nodo struct
//
// ¡Buena suerte! 🎵

ListaCircular::ListaCircular() {
    cabeza = nullptr;
    actual = nullptr;
}

ListaCircular::~ListaCircular() {
    if (cabeza == nullptr) return;
    Nodo* temp = cabeza->siguiente;
    while (temp != cabeza) {
        Nodo* a_borrar = temp;
        temp = temp->siguiente;
        delete a_borrar;
    }
    delete cabeza;
    cabeza = nullptr;
    actual = nullptr;
}

bool ListaCircular::estaVacia() const {
    return cabeza == nullptr;
}

void ListaCircular::insertarAlFinal(const Cancion& c) {
    Nodo* nuevo = new Nodo(c);
    if (cabeza == nullptr) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        cabeza = nuevo;
        actual = nuevo;
    } else {
        Nodo* cola = cabeza->anterior;
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
    }
}

void ListaCircular::siguienteCancion() {
    if (actual != nullptr) {
        cout << "[INFO] Avanzando a la siguiente cancion...\n";
        actual = actual->siguiente;
    } else {
        cout << "[INFO] No hay cancion en reproduccion.\n";
    }
}

void ListaCircular::anteriorCancion() {
    if (actual != nullptr) {
        cout << "[INFO] Retrocediendo a la cancion anterior...\n";
        actual = actual->anterior;
    } else {
        cout << "[INFO] No hay cancion en reproduccion.\n";
    }
}

void ListaCircular::mostrarPlaylist() const {
    if (cabeza == nullptr) {
        cout << "[INFO] Playlist vacia.\n";
        return;
    }
    Nodo* temp = cabeza;
    int idx = 1;
    do {
        cout << idx << ". " << temp->cancion.nombreCancion;
        if (temp == actual) {
            cout << " <-- (actual)";
        }
        cout << "\n";
        temp = temp->siguiente;
        idx++;
    } while (temp != cabeza);
}

void ListaCircular::reproducirActual() const {
    if (actual == nullptr) {
        cout << "[INFO] No hay cancion en reproduccion.\n";
        return;
    }
    cout << "════════════════════════════════════════════════════\n";
    cout << "🎵 REPRODUCIENDO 🎵\n";
    cout << "════════════════════════════════════════════════════\n";
    cout << "Nombre: " << actual->cancion.nombreCancion << "\n";
    cout << "Compositor: " << actual->cancion.compositor << "\n";
    cout << "Duracion: " << actual->cancion.duracion << "\n";
    cout << "────────────────────────────────────────────────────\n";
    
    if (actual->cancion.letra.empty() || actual->cancion.letra == "Letra no disponible") {
        cout << "Letra no disponible\n";
    } else {
        if (actual->cancion.letra.length() > 400) {
            cout << actual->cancion.letra.substr(0, 400) << "... [truncado]\n";
        } else {
            cout << actual->cancion.letra << "\n";
        }
    }
    cout << "════════════════════════════════════════════════════\n";
}

vector<Cancion> ListaCircular::obtenerTodasCanciones() const {
    vector<Cancion> canciones;
    if (cabeza == nullptr) return canciones;
    
    Nodo* temp = cabeza;
    do {
        canciones.push_back(temp->cancion);
        temp = temp->siguiente;
    } while (temp != cabeza);
    
    return canciones;
}
