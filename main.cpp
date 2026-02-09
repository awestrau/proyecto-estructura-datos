#include <iostream>;
#include <string>;
using namespace std;

struct Cancion {
    string titulo;
    string artista;
    int duracion; // Duración en segundos
    string letra;
    Cancion *siguiente; // Puntero al siguiente nodo
    Cancion *anterior; // Puntero al nodo anterior
};

int main() {

    return 0;
}