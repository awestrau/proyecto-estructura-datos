# Proyecto Estructura de Datos

Este repositorio contiene la implementación paso a paso de un proyecto final para la clase de Estructura de Datos, dividido en tres avances principales que culminan en un sistema integrado.

---

## Avance 1: Reproductor de Música (Lista Doblemente Enlazada Circular)

Implementación de un simulador de reproductor de música. 
* **Estructura base:** Lista doblemente enlazada circular para simular una reproducción continua.
* **Funcionalidades:**
  * Agregar canciones (título, compositor, duración, y ruta de la letra).
  * Eliminar y buscar canciones por nombre.
  * Navegar hacia adelante y hacia atrás en la playlist (`siguiente`, `anterior`).
  * Mostrar playlist con indicador de canción actual.
  * Reproducir canción (mostrar datos y opcionalmente cargar la letra desde un archivo `.txt`).
  * Guardado persistente de la playlist en un archivo `.dat`.

---

## Avance 2: Gestor de Archivos (Árbol General)

Implementación de un sistema de archivos jerárquico.
* **Estructura base:** Árbol General compuesto por nodos que representan carpetas o archivos.
* **Funcionalidades:**
  * Operaciones CRUD (Crear, Leer, Actualizar, Eliminar) para carpetas y archivos `.txt`.
  * Navegación dinámica entre niveles (entrar a carpetas, regresar al directorio padre).
  * Mostrar ruta actual (ej: `/root/Documentos/`).
  * Visualización en cascada/indentada del árbol de directorios.
  * Validación contra nombres duplicados en el mismo directorio.

---

## Avance 3: Red Social y Proyecto Integrado (Grafo No Dirigido)

Implementación de un módulo de red social y la integración de los tres avances en un menú principal unificado.
* **Estructura base:** Grafo no dirigido para representar a los usuarios y sus relaciones de amistad.
* **Funcionalidades:**
  * Crear, buscar, eliminar y listar usuarios.
  * Agregar y eliminar amistades (aristas).
  * Visualizar lista de amigos de un usuario.
  * Recorridos BFS (Anchura) y DFS (Profundidad).
  * Verificar conexiones indirectas entre usuarios utilizando recorridos del grafo.
* **Integración Final:** Menú de consola que permite acceder a los 3 submódulos sin perder la persistencia de datos durante la ejecución.

---

## Compilación y Ejecución del Proyecto Integrado

El proyecto incluye un menú principal unificado que permite acceder al **Reproductor de Música**, al **Gestor de Archivos** y a la **Red Social**. 

### Requisitos
- Compilador de C++ (por ejemplo, `g++`).

### Instrucciones

1. Abrir la terminal y ubicarse en el directorio raíz del proyecto (`proyecto-estructura-datos`).
2. Ejecutar el siguiente comando para compilar todos los archivos fuente juntos:

```bash
g++ main.cpp Avance3/src/MenuRedSocial.cpp Avance3/src/GrafoRedSocial.cpp Avance2/src/GestorArbol.cpp Avance2/src/MenuGestorArchivos.cpp Avance1/src/ListaCircular.cpp Avance1/src/GestionCanciones.cpp Avance1/src/GestorArchivos.cpp -o simulador
```

3. Ejecutar el programa compilado:

En Linux o macOS:
```bash
./simulador
```

En Windows:
```bash
simulador.exe
```
