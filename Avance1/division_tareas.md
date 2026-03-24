# 🎯 DIVISIÓN DEL TRABAJO - AVANCE 1

## ANDRES : Estructura de Datos + Navegación

### 📌 Tareas Específicas:

#### 1. Definir estructuras base

✅ Crear Cancion.h con el struct:

```cpp
struct Cancion {
      string nombreCancion;
      string compositor;
      string duracion;
      string letra;
  };
```

✅ Crear Nodo para la lista doblemente enlazada:

```cpp  
struct Nodo {
      Cancion cancion;
      Nodo* siguiente;
      Nodo* anterior;
};
```

#### **2. Implementar ListaCircular básica**
- ✅ Constructor y destructor
- ✅ `insertarAlFinal(Cancion c)` - agregar canciones
- ✅ `estaVacia()` - verificar si hay canciones

#### **3. Sistema de navegación circular**
- ✅ `siguienteCancion()` - avanzar (actual = actual->siguiente)
- ✅ `anteriorCancion()` - retroceder (actual = actual->anterior)
- ✅ Mantener correctamente el puntero `actual`

#### **4. Visualización**
- ✅ `mostrarPlaylist()` - listar todas las canciones con indicador de actual
- ✅ `reproducirActual()` - mostrar datos de la canción en reproducción

#### **5. Archivos a entregar:**

- Cancion.h
- ListaCircular.h
- ListaCircular.cpp
- test_persona_a.cpp (archivo de pruebas)


---

## **CHRISTOPHER: Gestión + Persistencia + Integración**

### 📌 **Tareas Específicas:**

#### **1. Operaciones de gestión avanzada**
- ✅ `buscarCancion(string nombre)` - localizar y posicionar actual
- ✅ `eliminarCancion(string nombre)` - con confirmación del usuario
- ✅ Validaciones y manejo de errores

#### **2. Sistema completo de archivos**
- ✅ `guardarPlaylist()` - persistir canciones en archivo
- ✅ `cargarPlaylist()` - recuperar canciones al iniciar
- ✅ `cargarLetraDesdeArchivo(string ruta)` - leer .txt de letras
- ✅ Manejo de errores (archivo no existe, etc.)

#### **3. Menú principal interactivo**
- ✅ Crear menú con todas las opciones:
  - Agregar canción
  - Eliminar canción
  - Buscar canción
  - Siguiente/Anterior
  - Reproducir actual
  - Mostrar playlist
  - Salir
- ✅ Validación de entradas del usuario

#### **4. Integración final**
- ✅ Combinar todo en `main.cpp`
- ✅ Crear carpeta `letras/` con archivos .txt de ejemplo
- ✅ Compilar y generar `.exe`
- ✅ Preparar el archivo .RAR completo

#### **5. Archivos a entregar:**

- GestorArchivos.h
- GestorArchivos.cpp
- Menu.cpp
- main.cpp (programa final)
- letras/ (carpeta con .txt)
- playlist.dat (generado automáticamente).