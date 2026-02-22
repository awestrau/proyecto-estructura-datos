# 📋 INSTRUCCIONES PARA ANDRÉS – AVANCE 1

## ¿Qué tienes que hacer?

Implementar la **Lista Doblemente Enlazada Circular** para el Reproductor de Música.

---

## 📌 PASO 0: CREA DOS ARCHIVOS ENCABEZADO

### 1. Crea `src/Cancion.h`

```cpp
#ifndef CANCION_H
#define CANCION_H

#include <string>
using namespace std;

struct Cancion {
    string nombreCancion;  // Título de la canción
    string compositor;     // Autor / compositor
    string duracion;       // Formato "mm:ss" o "hh:mm:ss"
    string letra;          // Contenido de la letra (se carga desde .txt)
    string rutaLetra;      // Ruta al archivo .txt de la letra (puede quedar vacía)
};

#endif // CANCION_H
```

### 2. Crea `src/ListaCircular.h`

```cpp
#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "Cancion.h"
#include <vector>
#include <iostream>
using namespace std;

struct Nodo {
    Cancion cancion;
    Nodo* siguiente;
    Nodo* anterior;
};

class ListaCircular {
public:
    Nodo* cabeza;   // Primer nodo; nullptr si vacía
    Nodo* actual;   // Nodo en reproducción; nullptr si no hay canción

    ListaCircular();
    ~ListaCircular();

    bool estaVacia() const;
    void insertarAlFinal(const Cancion &c);
    void siguienteCancion();
    void anteriorCancion();
    void mostrarPlaylist() const;
    void reproducirActual() const;
    vector<Cancion> obtenerTodasCanciones() const;
};

#endif // LISTA_CIRCULAR_H
```

---

## 🎯 PASO 1: Lee los archivos que ya existen

1. **`src/ListaCircular.cpp`** – AQUÍ implementarás los métodos (archivo con instrucciones)

---

## 🎯 PASO 2: Implementa 9 métodos en `src/ListaCircular.cpp`

### 1. Constructor `ListaCircular()`
```cpp
ListaCircular::ListaCircular() {
    cabeza = nullptr;
    actual = nullptr;
}
```

### 2. Destructor `~ListaCircular()`
```cpp
// - Si cabeza == nullptr, retorna (está vacía)
// - Recorre circularmente: cursor->siguiente hasta volver a cabeza
// - Libera TODOS los nodos con delete
// - Pone cabeza = nullptr y actual = nullptr al final
```

### 3. `bool estaVacia() const`
- Retorna `true` si `cabeza == nullptr`, `false` si no

### 4. `void insertarAlFinal(const Cancion &c)`
- Crea nuevo nodo con `new Nodo()`
- **CASO 1**: Si lista vacía (cabeza == nullptr)
  - Conecta el nodo a sí mismo: `nuevo->siguiente = nuevo`, `nuevo->anterior = nuevo`
  - `cabeza = nuevo`, `actual = nuevo`
- **CASO 2**: Si hay elementos
  - Obtener cola: `Nodo *cola = cabeza->anterior`
  - Conectar: `cola->siguiente = nuevo`, `nuevo->anterior = cola`
  - Conectar: `nuevo->siguiente = cabeza`, `cabeza->anterior = nuevo`

### 5. `void siguienteCancion()`
- Si `actual != nullptr`: `actual = actual->siguiente`
- (La circularidad ya existe en los punteros)

### 6. `void anteriorCancion()`
- Si `actual != nullptr`: `actual = actual->anterior`

### 7. `void mostrarPlaylist() const`
- Si `cabeza == nullptr`: imprimir `"[INFO] Playlist vacia.\n"`
- Recorrer con `do-while` desde `cabeza` hasta volver a `cabeza`
- Imprimir: `idx. nombreCancion`
- Si es `actual`, agregar: `" <-- (actual)"`

### 8. `void reproducirActual() const`
- Si `actual == nullptr`: `"[INFO] No hay cancion en reproduccion.\n"`
- Mostrar: `nombreCancion`, `compositor`, `duracion`
- Mostrar letra:
  - Si `letra.empty()` o es `"Letra no disponible"` → imprimir eso
  - Si hay letra → mostrar primeros ~400 caracteres + `"...[truncado]"` si sobra

### 9. `vector<Cancion> obtenerTodasCanciones() const`
- Crear `vector<Cancion> lista` vacío
- Si `cabeza == nullptr`, retornar vector vacío
- Recorrer circularmente desde `cabeza` hasta volver a `cabeza`
- Hacer `push_back()` cada `cancion` al vector
- Retornar vector

---

## ⚠️ RECUERDA

1. **Mantén los nombres de métodos EXACTAMENTE igual** – Christopher y main.cpp dependen
2. **La lista es CIRCULAR**:
   - `cabeza->anterior` apunta al último nodo
   - `último->siguiente` apunta a `cabeza`
3. **Recorridos circulares usan `do-while`**:
   ```cpp
   do {
       // procesar cursor
       cursor = cursor->siguiente;
   } while (cursor != cabeza);
   ```
4. **Los punteros `cabeza` y `actual` son PUBLIC** porque `GestionCanciones.cpp` los accede directamente
5. **Cuidado con memory leaks**: libera TODO en el destructor

---

## 🧪 Prueba tu código

Una vez implementado, compila desde LA RAÍZ DEL REPO:

```bash
g++ -std=c++17 src/ListaCircular.cpp src/GestorArchivos.cpp src/GestionCanciones.cpp src/main.cpp -I src -o output/src/main -Wall -Wextra
./output/src/main
```

O usa la tarea de VS Code: **Ctrl+Shift+B**

---

## ✅ Objetivo Final

Cuando termines, el reproductor debe:
- ✅ Compilar sin errores de vinculación  
- ✅ Cargar canciones (con letras desde archivos .txt)
- ✅ Navegar circular (siguiente/anterior)
- ✅ Mostrar playlist
- ✅ Reproducir (mostrar letra)
- ✅ Guardar en `playlist.dat`

---

**¡Éxito! 🎵**

---

## 🎯 PASO 2: Implementa 9 métodos en `src/ListaCircular.cpp`

### 1. Constructor `ListaCircular()`
```cpp
ListaCircular::ListaCircular() {
    cabeza = nullptr;
    actual = nullptr;
}
```

### 2. Destructor `~ListaCircular()`
```cpp
// - Si cabeza == nullptr, retorna (está vacía)
// - Recorre circularmente: cursor->siguiente hasta volver a cabeza
// - Libera TODOS los nodos con delete
// - Pone cabeza = nullptr y actual = nullptr al final
```

### 3. `bool estaVacia() const`
- Retorna `true` si `cabeza == nullptr`, `false` si no

### 4. `void insertarAlFinal(const Cancion &c)`
- Crea nuevo nodo con `new Nodo()`
- **CASO 1**: Si lista vacía (cabeza == nullptr)
  - Conecta el nodo a sí mismo: `nuevo->siguiente = nuevo`, `nuevo->anterior = nuevo`
  - `cabeza = nuevo`, `actual = nuevo`
- **CASO 2**: Si hay elementos
  - Obtener cola: `Nodo *cola = cabeza->anterior`
  - Conectar: `cola->siguiente = nuevo`, `nuevo->anterior = cola`
  - Conectar: `nuevo->siguiente = cabeza`, `cabeza->anterior = nuevo`

### 5. `void siguienteCancion()`
- Si `actual != nullptr`: `actual = actual->siguiente`
- (La circularidad ya existe en los punteros)

### 6. `void anteriorCancion()`
- Si `actual != nullptr`: `actual = actual->anterior`

### 7. `void mostrarPlaylist() const`
- Si `cabeza == nullptr`: imprimir `"[INFO] Playlist vacia.\n"`
- Recorrer con `do-while` desde `cabeza` hasta volver a `cabeza`
- Imprimir: `idx. nombreCancion`
- Si es `actual`, agregar: `" <-- (actual)"`

### 8. `void reproducirActual() const`
- Si `actual == nullptr`: `"[INFO] No hay cancion en reproduccion.\n"`
- Mostrar: `nombreCancion`, `compositor`, `duracion`
- Mostrar letra:
  - Si `letra.empty()` o es `"Letra no disponible"` → imprimir eso
  - Si hay letra → mostrar primeros ~400 caracteres + `"...[truncado]"` si sobra

### 9. `vector<Cancion> obtenerTodasCanciones() const`
- Crear `vector<Cancion> lista` vacío
- Si `cabeza == nullptr`, retornar vector vacío
- Recorrer circularmente desde `cabeza` hasta volver a `cabeza`
- Hacer `push_back()` cada `cancion` al vector
- Retornar vector

---

## ⚠️ RECUERDA

1. **Mantén los nombres de métodos EXACTAMENTE igual** – Christopher y main.cpp dependen
2. **La lista es CIRCULAR**:
   - `cabeza->anterior` apunta al último nodo
   - `último->siguiente` apunta a `cabeza`
3. **Recorridos circulares usan `do-while`**:
   ```cpp
   do {
       // procesar cursor
       cursor = cursor->siguiente;
   } while (cursor != cabeza);
   ```
4. **Los punteros `cabeza` y `actual` son PUBLIC** porque `GestionCanciones.cpp` los accede directamente
5. **Cuidado con memory leaks**: libera TODO en el destructor

---

## 🧪 Prueba tu código

Una vez implementado, compila desde LA RAÍZ DEL REPO:

```bash
g++ -std=c++17 src/ListaCircular.cpp src/GestorArchivos.cpp src/GestionCanciones.cpp src/main.cpp -I src -o output/src/main -Wall -Wextra
./output/src/main
```

O usa la tarea de VS Code: **Ctrl+Shift+B**

---

## ✅ Objetivo Final

Cuando termines, el reproductor debe:
- ✅ Compilar sin errores de vinculación  
- ✅ Cargar canciones (con letras desde archivos .txt)
- ✅ Navegar circular (siguiente/anterior)
- ✅ Mostrar playlist
- ✅ Reproducir (mostrar letra)
- ✅ Guardar en `playlist.dat`

---

**¡Éxito! 🎵 Si tienes dudas sobre la lógica, mira los comentarios en `ListaCircular.cpp`.**
