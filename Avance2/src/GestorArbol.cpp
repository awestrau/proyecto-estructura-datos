#include "GestorArbol.h"
#include <iostream>

using namespace std;

GestorArbol::GestorArbol() {
    raiz = new NodoArbol("root", CARPETA);
    actual = raiz;
}

GestorArbol::~GestorArbol() {
    limpiarArbol(raiz);
}

void GestorArbol::limpiarArbol(NodoArbol* nodo) {
    if (nodo == nullptr) return;
    for (NodoArbol* hijo : nodo->hijos) {
        limpiarArbol(hijo);
    }
    delete nodo;
}

std::string GestorArbol::getRutaActual() const {
    string ruta = "";
    NodoArbol* temp = actual;
    while (temp != nullptr) {
        if (ruta.empty()) {
            ruta = temp->nombre;
        } else {
            ruta = temp->nombre + "/" + ruta;
        }
        temp = temp->padre;
    }
    return "/" + ruta + "/";
}

void GestorArbol::listarHijos() const {
    if (actual->hijos.empty()) {
        cout << "(Carpeta vacia)" << endl;
        return;
    }
    for (NodoArbol* hijo : actual->hijos) {
        if (hijo->tipo == CARPETA) {
            cout << "[DIR]  " << hijo->nombre << "/" << endl;
        } else {
            cout << "[FILE] " << hijo->nombre << endl;
        }
    }
}

bool GestorArbol::crearCarpeta(const std::string& nombre) {
    if (buscarHijo(nombre)) return false;
    actual->hijos.push_back(new NodoArbol(nombre, CARPETA, actual));
    return true;
}

bool GestorArbol::crearArchivo(const std::string& nombre, const std::string& contenido) {
    if (buscarHijo(nombre)) return false;
    NodoArbol* nuevo = new NodoArbol(nombre, ARCHIVO, actual);
    nuevo->contenido = contenido;
    actual->hijos.push_back(nuevo);
    return true;
}

bool GestorArbol::entrarCarpeta(const std::string& nombre) {
    for (NodoArbol* hijo : actual->hijos) {
        if (hijo->nombre == nombre && hijo->tipo == CARPETA) {
            actual = hijo;
            return true;
        }
    }
    return false;
}

bool GestorArbol::subirAlPadre() {
    if (actual->padre != nullptr) {
        actual = actual->padre;
        return true;
    }
    return false;
}

bool GestorArbol::eliminar(const std::string& nombre) {
    for (auto it = actual->hijos.begin(); it != actual->hijos.end(); ++it) {
        if ((*it)->nombre == nombre) {
            limpiarArbol(*it);
            actual->hijos.erase(it);
            return true;
        }
    }
    return false;
}

bool GestorArbol::buscarHijo(const std::string& nombre) const {
    for (NodoArbol* hijo : actual->hijos) {
        if (hijo->nombre == nombre) return true;
    }
    return false;
}

std::string GestorArbol::obtenerContenido(const std::string& nombre) const {
    for (NodoArbol* hijo : actual->hijos) {
        if (hijo->nombre == nombre && hijo->tipo == ARCHIVO) {
            return hijo->contenido;
        }
    }
    return "";
}

bool GestorArbol::esCarpeta(const std::string& nombre) const {
    for (NodoArbol* hijo : actual->hijos) {
        if (hijo->nombre == nombre) return hijo->tipo == CARPETA;
    }
    return false;
}

// Helper para preorden
void imprimirNodo(NodoArbol* nodo, string prefijo, bool esUltimo) {
    cout << prefijo;
    cout << (esUltimo ? "└── " : "├── ");
    if (nodo->tipo == CARPETA) cout << "[+] ";
    else cout << "    ";
    cout << nodo->nombre << endl;

    string nuevoPrefijo = prefijo + (esUltimo ? "    " : "│   ");
    for (size_t i = 0; i < nodo->hijos.size(); ++i) {
        imprimirNodo(nodo->hijos[i], nuevoPrefijo, i == (nodo->hijos.size() - 1));
    }
}

void GestorArbol::mostrarArbol() const {
    cout << "root" << endl;
    for (size_t i = 0; i < raiz->hijos.size(); ++i) {
        imprimirNodo(raiz->hijos[i], "", i == (raiz->hijos.size() - 1));
    }
}
