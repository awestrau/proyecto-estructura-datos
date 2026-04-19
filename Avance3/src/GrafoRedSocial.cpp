#include "GrafoRedSocial.h"
#include <iostream>
#include <queue>    // para el BFS
#include <algorithm> // para find y remove en vectores

using namespace std;

// Constructor / Destructor

GrafoRedSocial::GrafoRedSocial() : proximoId(1) {}

GrafoRedSocial::~GrafoRedSocial() {
    // borramos todos los nodos que creamos con new
    for (UsuarioNodo* u : usuarios)
        delete u;
    usuarios.clear();
}

// Helpers privados

// busca por nombre, retorna nullptr si no existe
UsuarioNodo* GrafoRedSocial::encontrarNodo(const string& nombre) const {
    for (UsuarioNodo* u : usuarios) {
        if (u->nombreUsuario == nombre)
            return u;
    }
    return nullptr;
}

// recorrido DFS recursivo, guarda los ids ya visitados para no ciclar
void GrafoRedSocial::dfsRecursivo(UsuarioNodo* nodo, vector<int>& visitados) const {
    visitados.push_back(nodo->id);
    cout << "  -> " << nodo->nombreUsuario << " (id: " << nodo->id << ")\n";

    for (UsuarioNodo* amigo : nodo->listaAmigos) {
        // si el amigo no está en visitados, seguimos por ahí
        if (find(visitados.begin(), visitados.end(), amigo->id) == visitados.end())
            dfsRecursivo(amigo, visitados);
    }
}

// Gestión de usuarios

bool GrafoRedSocial::agregarUsuario(const string& nombre) {
    if (nombre.empty()) {
        cout << "[!] El nombre no puede estar vacio.\n";
        return false;
    }

    // no queremos duplicados
    if (encontrarNodo(nombre) != nullptr) {
        cout << "[!] Ya existe un usuario con ese nombre.\n";
        return false;
    }

    UsuarioNodo* nuevo = new UsuarioNodo(proximoId++, nombre);
    usuarios.push_back(nuevo);
    cout << "[OK] Usuario '" << nombre << "' creado con id " << nuevo->id << ".\n";
    return true;
}

bool GrafoRedSocial::eliminarUsuario(const string& nombre) {
    UsuarioNodo* objetivo = encontrarNodo(nombre);
    if (objetivo == nullptr) {
        cout << "[!] Usuario '" << nombre << "' no encontrado.\n";
        return false;
    }

    // primero quitamos al usuario de la lista de amigos de cada uno de sus amigos
    // si no hacemos esto quedan punteros colgantes por todo el grafo
    for (UsuarioNodo* amigo : objetivo->listaAmigos) {
        auto& lista = amigo->listaAmigos;
        lista.erase(remove(lista.begin(), lista.end(), objetivo), lista.end());
    }

    // ahora sí lo sacamos del vector principal y liberamos memoria
    usuarios.erase(remove(usuarios.begin(), usuarios.end(), objetivo), usuarios.end());
    delete objetivo;

    cout << "[OK] Usuario '" << nombre << "' eliminado junto con sus amistades.\n";
    return true;
}

UsuarioNodo* GrafoRedSocial::buscarUsuario(const string& nombre) const {
    UsuarioNodo* u = encontrarNodo(nombre);
    if (u == nullptr) {
        cout << "[!] Usuario '" << nombre << "' no encontrado.\n";
        return nullptr;
    }
    cout << "[OK] Usuario encontrado -> id: " << u->id
         << ", nombre: " << u->nombreUsuario
         << ", amigos: " << u->listaAmigos.size() << "\n";
    return u;
}

void GrafoRedSocial::listarUsuarios() const {
    if (usuarios.empty()) {
        cout << "[!] No hay usuarios registrados.\n";
        return;
    }
    cout << "\n--- Usuarios registrados (" << usuarios.size() << ") ---\n";
    for (UsuarioNodo* u : usuarios)
        cout << "  [" << u->id << "] " << u->nombreUsuario
             << "  (" << u->listaAmigos.size() << " amigos)\n";
}

bool GrafoRedSocial::estaVacio() const {
    return usuarios.empty();
}

// Amistades (aristas)

bool GrafoRedSocial::agregarAmistad(const string& nombre1, const string& nombre2) {
    if (nombre1 == nombre2) {
        cout << "[!] Un usuario no puede ser amigo de si mismo.\n";
        return false;
    }

    UsuarioNodo* u1 = encontrarNodo(nombre1);
    UsuarioNodo* u2 = encontrarNodo(nombre2);

    if (u1 == nullptr) { cout << "[!] Usuario '" << nombre1 << "' no encontrado.\n"; return false; }
    if (u2 == nullptr) { cout << "[!] Usuario '" << nombre2 << "' no encontrado.\n"; return false; }

    // revisar si ya son amigos (evitar duplicar la arista)
    for (UsuarioNodo* a : u1->listaAmigos) {
        if (a == u2) {
            cout << "[!] " << nombre1 << " y " << nombre2 << " ya son amigos.\n";
            return false;
        }
    }

    // grafo no dirigido: la conexión va en los dos sentidos
    u1->listaAmigos.push_back(u2);
    u2->listaAmigos.push_back(u1);

    cout << "[OK] Amistad agregada entre '" << nombre1 << "' y '" << nombre2 << "'.\n";
    return true;
}

bool GrafoRedSocial::eliminarAmistad(const string& nombre1, const string& nombre2) {
    UsuarioNodo* u1 = encontrarNodo(nombre1);
    UsuarioNodo* u2 = encontrarNodo(nombre2);

    if (u1 == nullptr) { cout << "[!] Usuario '" << nombre1 << "' no encontrado.\n"; return false; }
    if (u2 == nullptr) { cout << "[!] Usuario '" << nombre2 << "' no encontrado.\n"; return false; }

    // ver si realmente son amigos antes de intentar borrar
    bool eranAmigos = false;
    for (UsuarioNodo* a : u1->listaAmigos) {
        if (a == u2) { eranAmigos = true; break; }
    }

    if (!eranAmigos) {
        cout << "[!] " << nombre1 << " y " << nombre2 << " no son amigos.\n";
        return false;
    }

    // sacar de los dos lados
    auto& lista1 = u1->listaAmigos;
    lista1.erase(remove(lista1.begin(), lista1.end(), u2), lista1.end());

    auto& lista2 = u2->listaAmigos;
    lista2.erase(remove(lista2.begin(), lista2.end(), u1), lista2.end());

    cout << "[OK] Amistad eliminada entre '" << nombre1 << "' y '" << nombre2 << "'.\n";
    return true;
}

void GrafoRedSocial::mostrarAmigos(const string& nombre) const {
    UsuarioNodo* u = encontrarNodo(nombre);
    if (u == nullptr) {
        cout << "[!] Usuario '" << nombre << "' no encontrado.\n";
        return;
    }

    if (u->listaAmigos.empty()) {
        cout << "[!] '" << nombre << "' no tiene amigos aun.\n";
        return;
    }

    cout << "\n--- Amigos de " << nombre << " (" << u->listaAmigos.size() << ") ---\n";
    for (UsuarioNodo* a : u->listaAmigos)
        cout << "  [" << a->id << "] " << a->nombreUsuario << "\n";
}

// Recorridos del grafo

// BFS: recorre nivel por nivel usando una cola
// sirve para ver todos los usuarios alcanzables desde uno y a qué "distancia" están
void GrafoRedSocial::BFS(const string& nombreOrigen) const {
    if (estaVacio()) {
        cout << "[!] El grafo esta vacio.\n";
        return;
    }

    UsuarioNodo* origen = encontrarNodo(nombreOrigen);
    if (origen == nullptr) {
        cout << "[!] Usuario '" << nombreOrigen << "' no encontrado.\n";
        return;
    }

    vector<int> visitados;
    queue<UsuarioNodo*> cola;

    cola.push(origen);
    visitados.push_back(origen->id);

    cout << "\n--- BFS desde '" << nombreOrigen << "' ---\n";

    while (!cola.empty()) {
        UsuarioNodo* actual = cola.front();
        cola.pop();

        cout << "  -> " << actual->nombreUsuario << " (id: " << actual->id << ")\n";

        for (UsuarioNodo* vecino : actual->listaAmigos) {
            if (find(visitados.begin(), visitados.end(), vecino->id) == visitados.end()) {
                visitados.push_back(vecino->id);
                cola.push(vecino);
            }
        }
    }
}

// DFS: recorre por profundidad (va lo más lejos posible antes de retroceder)
// usa el helper recursivo de arriba
void GrafoRedSocial::DFS(const string& nombreOrigen) const {
    if (estaVacio()) {
        cout << "[!] El grafo esta vacio.\n";
        return;
    }

    UsuarioNodo* origen = encontrarNodo(nombreOrigen);
    if (origen == nullptr) {
        cout << "[!] Usuario '" << nombreOrigen << "' no encontrado.\n";
        return;
    }

    vector<int> visitados;
    cout << "\n--- DFS desde '" << nombreOrigen << "' ---\n";
    dfsRecursivo(origen, visitados);
}

// verifica si hay algún camino entre dos usuarios (relación indirecta)
// reutiliza la lógica de BFS pero en vez de imprimir, solo busca el destino
bool GrafoRedSocial::sonConectados(const string& nombre1, const string& nombre2) const {
    UsuarioNodo* u1 = encontrarNodo(nombre1);
    UsuarioNodo* u2 = encontrarNodo(nombre2);

    if (u1 == nullptr) { cout << "[!] Usuario '" << nombre1 << "' no encontrado.\n"; return false; }
    if (u2 == nullptr) { cout << "[!] Usuario '" << nombre2 << "' no encontrado.\n"; return false; }

    if (u1 == u2) return true; // mismo nodo, trivialmente conectado

    // BFS interno sin prints
    vector<int> visitados;
    queue<UsuarioNodo*> cola;

    cola.push(u1);
    visitados.push_back(u1->id);

    while (!cola.empty()) {
        UsuarioNodo* actual = cola.front();
        cola.pop();

        for (UsuarioNodo* vecino : actual->listaAmigos) {
            if (vecino == u2) return true; // encontramos el destino

            if (find(visitados.begin(), visitados.end(), vecino->id) == visitados.end()) {
                visitados.push_back(vecino->id);
                cola.push(vecino);
            }
        }
    }

    return false; // no hay camino
}
