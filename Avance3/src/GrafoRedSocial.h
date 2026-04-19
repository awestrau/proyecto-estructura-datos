#ifndef GRAFO_RED_SOCIAL_H
#define GRAFO_RED_SOCIAL_H

#include "UsuarioNodo.h"
#include <string>
#include <vector>

using namespace std;

class GrafoRedSocial {
private:
    vector<UsuarioNodo*> usuarios; // todos los nodos del grafo viven aquí
    int proximoId;                 // se autoincrementa cada vez que se crea un usuario

    // helper interno para buscar sin pasar por la función pública
    // retorna nullptr si no existe
    UsuarioNodo* encontrarNodo(const string& nombre) const;

    // helper recursivo que usa DFS para recorrer el grafo
    // se usa en sonConectados también
    void dfsRecursivo(UsuarioNodo* nodo, vector<int>& visitados) const;

public:
    GrafoRedSocial();
    ~GrafoRedSocial(); // libera toda la memoria de los nodos

    // gestión de usuarios
    bool agregarUsuario(const string& nombre);
    bool eliminarUsuario(const string& nombre);
    UsuarioNodo* buscarUsuario(const string& nombre) const;
    void listarUsuarios() const;

    // amistades (aristas del grafo)
    bool agregarAmistad(const string& nombre1, const string& nombre2);
    bool eliminarAmistad(const string& nombre1, const string& nombre2);
    void mostrarAmigos(const string& nombre) const;

    //recorridos
    void BFS(const string& nombreOrigen) const;
    void DFS(const string& nombreOrigen) const;

    // usa BFS internamente para ver si hay camino entre dos usuarios
    bool sonConectados(const string& nombre1, const string& nombre2) const;

    // para saber si el grafo está vacío antes de operar
    bool estaVacio() const;
};

#endif // GRAFO_RED_SOCIAL_H
