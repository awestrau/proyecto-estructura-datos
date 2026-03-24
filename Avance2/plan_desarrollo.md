# Plan de Desarrollo - Avance 2: Gestor de Archivos

Este documento detalla la estrategia de desarrollo y división de tareas para la implementación del módulo de Gestor de Archivos mediante una estructura de datos de Árbol.

## 1. Objetivos del Avance
*   Implementar un sistema de archivos jerárquico utilizando un Árbol General.
*   Permitir operaciones CRUD de carpetas y archivos (.txt).
*   Navegación dinámica entre niveles (subir/bajar).
*   Integración con el módulo de Reproductor de Música (Avance 1).

## 2. División de Tareas (2 Personas)

### Persona A: Especialista en Estructura de Datos (Core Logic)
**Responsabilidades:** Implementación de la lógica del árbol y manipulación de nodos.

1.  **Definición de Estructura:**
    *   Crear `NodoArbol.h`: Definir el struct con `nombre`, `tipo` (enum), `contenido`, lista de `hijos` y puntero al `padre`.
    *   Diseñar la clase `GestorArbol`: Manejar el nodo `raiz` y el nodo `actual` (cursor de navegación).
2.  **Operaciones de Estructura:**
    *   Implementar métodos para insertar nodos (distinguiendo entre carpeta y archivo).
    *   Implementar eliminación de nodos (validando si la carpeta está vacía o con confirmación).
    *   Implementar la lógica de búsqueda de hijos por nombre.
3.  **Visualización:**
    *   Implementar al menos un recorrido (ej. Preorden) para mostrar la estructura completa en forma de cascada/indentada.

### Persona B: Especialista en Interfaz e Integración (UX & Flow)
**Responsabilidades:** Menú de consola, validaciones y unión con el Avance 1.

1.  **Interfaz de Consola:**
    *   Crear un menú principal que permita elegir entre "Reproductor de Música" y "Gestor de Archivos".
    *   Implementar el submenú de comandos para el Gestor de Archivos (ej: `mkdir`, `cd`, `ls`, `touch`, `rm`).
2.  **Lógica de Navegación:**
    *   Implementar la función para "entrar" a carpetas y "regresar" al padre, actualizando el "path" actual.
    *   Mostrar la ruta actual de forma amigable (ej: `/root/Documentos/`).
3.  **Robustez y Validaciones:**
    *   Validar que no se creen archivos duplicados con el mismo nombre en la misma carpeta.
    *   Manejar errores: intentar entrar a carpetas inexistentes o leer archivos que no son .txt.
    *   Asegurar que la integración con el Avance 1 no rompa la funcionalidad previa del reproductor.

## 3. Cronograma Sugerido

| Día | Tarea Persona A | Tarea Persona B |
| :--- | :--- | :--- |
| 1 | Diseño de `NodoArbol` y `GestorArbol`. | Refactorización de `main.cpp` para menú dual. |
| 2 | Métodos `insertar` y `eliminar`. | Implementación de `ls` y `pwd` (ruta actual). |
| 3 | Lógica de recorridos (visualización jerárquica). | Lógica de navegación `cd` y `cd ..`. |
| 4 | Pruebas unitarias de la estructura. | Manejo de errores y lectura de archivos .txt. |
| 5 | Integración final y revisión de punteros. | Preparación del ejecutable y empaquetado .RAR. |

## 4. Estándares de Entrega
*   **Código:** Comentado, con nombres de variables descriptivos.
*   **Compilación:** Debe generar un único `.exe` funcional.
*   **Archivos:** Incluir todas las letras de canciones (`.txt`) y el archivo de datos del avance anterior.
