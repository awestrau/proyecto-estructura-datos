#ifndef CANCION_H
#define CANCION_H

#include <string>
using namespace std;

struct Cancion {
    string nombreCancion;
    string compositor;
    string duracion; 
    string letra; 
    string rutaLetra;   

    Cancion() : nombreCancion(""), compositor(""), duracion("00:00"), letra("") {}

    Cancion(string nombre, string comp, string dur, string l = "")
        : nombreCancion(nombre), compositor(comp), duracion(dur), letra(l) {}
};

#endif // CANCION_H
