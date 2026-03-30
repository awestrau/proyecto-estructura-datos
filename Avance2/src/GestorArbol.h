#ifndef GESTOR_ARBOL_H
#define GESTOR_ARBOL_H

#include "NodoArbol.h"
#include <string>

class GestorArbol {
private:
    NodoArbol* raiz;    // Nodo raiz del sistema (siempre sera una carpeta)
    NodoArbol* actual;  // Puntero al directorio donde se encuentra el usuario actualmente

    // Metodo privado auxiliar para liberar memoria recursivamente
    void limpiarArbol(NodoArbol* nodo);

public:
    // Constructor: Inicializa la raiz como "/root" y coloca el cursor 'actual' ahi.
    GestorArbol();

    // Destructor: Se encarga de liberar toda la memoria dinamica de los nodos.
    ~GestorArbol();

    // --- Metodos sincronizados con el menu (Persona B) ---

    // Retorna la ruta completa desde la raiz hasta el directorio actual tipo "/root/Docs/"
    std::string getRutaActual() const;

    // Imprime los hijos del nodo actual (comando ls)
    void listarHijos() const;

    // Inserta un nuevo nodo tipo CARPETA en el directorio actual (comando mkdir)
    bool crearCarpeta(const std::string& nombre);

    // Inserta un nuevo nodo tipo ARCHIVO en el directorio actual (comando touch)
    bool crearArchivo(const std::string& nombre, const std::string& contenido = "");

    // Mueve el puntero 'actual' a un hijo que sea carpeta (comando cd <nombre>)
    bool entrarCarpeta(const std::string& nombre);

    // Mueve el puntero 'actual' a su nodo padre (comando cd ..)
    bool subirAlPadre();

    // Elimina un hijo (archivo o carpeta vacia) por su nombre (comando rm)
    bool eliminar(const std::string& nombre);

    // Verifica si existe un hijo (archivo o carpeta) con ese nombre
    bool buscarHijo(const std::string& nombre) const;

    // Retorna el string contenido en un nodo tipo ARCHIVO (comando cat)
    std::string obtenerContenido(const std::string& nombre) const;

    // Determina si un hijo especifico es una CARPETA
    bool esCarpeta(const std::string& nombre) const;

    // Muestra todo el arbol en formato indentado (recorrido preorden)
    void mostrarArbol() const;
};

#endif // GESTOR_ARBOL_H
