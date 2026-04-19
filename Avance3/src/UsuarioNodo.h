#ifndef USUARIO_NODO_H
#define USUARIO_NODO_H

#include <string>
#include <vector>

using namespace std;

// cada nodo del grafo es un usuario
// listaAmigos guarda punteros a los nodos con los que está conectado
// (grafo no dirigido, así que si A es amigo de B, B también es amigo de A)
struct UsuarioNodo {
    int id;
    string nombreUsuario;
    vector<UsuarioNodo*> listaAmigos;

    // constructor rápido para no estar seteando todo a mano
    UsuarioNodo(int _id, const string& _nombre)
        : id(_id), nombreUsuario(_nombre) {}
};

#endif // USUARIO_NODO_H
