# Plan de Desarrollo — Avance 3: Red Social + Integración Final

## Objetivo
Implementar un módulo de red social basado en grafo no dirigido e integrar los tres módulos
(Reproductor, Gestor de Archivos, Red Social) en un único sistema funcional por consola.

---

## Estructura de carpetas

```
Avance3/src/
├── UsuarioNodo.h          ← struct del nodo de usuario
├── GrafoRedSocial.h       ← declaración de la clase del grafo
├── GrafoRedSocial.cpp     ← implementación del grafo (BFS, DFS, gestión)
├── MenuRedSocial.h        ← declaración del menú de red social
├── MenuRedSocial.cpp      ← implementación del menú de consola
└── main.cpp               ← main final integrado (3 módulos)
```

---

## División de tareas

### Christopher — Estructura del Grafo
**Archivos: `UsuarioNodo.h`, `GrafoRedSocial.h`, `GrafoRedSocial.cpp`**

#### `UsuarioNodo.h`
```cpp
struct UsuarioNodo {
    int id;
    string nombreUsuario;
    vector<UsuarioNodo*> listaAmigos;
};
```

#### Clase `GrafoRedSocial`
Atributos privados:
- `vector<UsuarioNodo*> usuarios`
- `int proximoId`

Métodos a implementar:

| Método | Descripción |
|---|---|
| `agregarUsuario(nombre)` | Crea nodo, asigna id autoincremental, inserta en `usuarios` |
| `eliminarUsuario(nombre)` | Borra nodo y elimina todas sus aristas del grafo |
| `buscarUsuario(nombre)` → `UsuarioNodo*` | Retorna puntero o `nullptr` |
| `listarUsuarios()` | Muestra id + nombre de todos los usuarios |
| `agregarAmistad(nombre1, nombre2)` | Conecta ambos nodos, valida duplicados y existencia |
| `eliminarAmistad(nombre1, nombre2)` | Desconecta ambos nodos |
| `mostrarAmigos(nombre)` | Lista `listaAmigos` del nodo |
| `BFS(nombreOrigen)` | Recorrido por anchura desde un usuario, imprime visitados |
| `DFS(nombreOrigen)` | Recorrido por profundidad desde un usuario, imprime visitados |
| `sonConectados(nombre1, nombre2)` → `bool` | Relación indirecta vía BFS/DFS |
| `~GrafoRedSocial()` | Destructor: libera memoria de todos los nodos |

Validaciones obligatorias dentro de la clase:
- Usuario no encontrado → retornar `false` / `nullptr` con mensaje
- Amistad duplicada → no insertar, notificar
- Grafo vacío al hacer recorrido → notificar
- Eliminar usuario con amistades activas → limpiar aristas antes de borrar nodo

---

### Camila o andres — Menú de Red Social
**Archivos: `MenuRedSocial.h`, `MenuRedSocial.cpp`**

Función principal: `void menuRedSocial(GrafoRedSocial& grafo)`

Menú esperado:
```
=== Red Social ===
1) Crear usuario
2) Eliminar usuario
3) Buscar usuario
4) Listar usuarios
5) Agregar amistad
6) Eliminar amistad
7) Ver amigos de un usuario
8) Recorrido BFS
9) Recorrido DFS
10) Verificar relacion indirecta entre dos usuarios
11) Volver al menu principal
```

Responsabilidades:
- Capturar y validar entrada del usuario (nombres vacíos, opciones fuera de rango)
- Mostrar mensajes claros de éxito y error
- Llamar a los métodos de `GrafoRedSocial` según la opción

---

### Camila o Andrés — Main Final Integrado
**Archivo: `Avance3/src/main.cpp`**

Tomar como base `Avance2/src/main.cpp` y extenderlo:

```cpp
// Incluir todo lo de Avance1 y Avance2 (mismo que antes)
#include "GrafoRedSocial.h"
#include "MenuRedSocial.h"

// En main():
GrafoRedSocial redSocial;

// Menú principal:
1) Reproductor de Musica
2) Gestor de Archivos
3) Red Social          ← nuevo
4) Salir

case 3: menuRedSocial(redSocial); break;
```

Responsabilidades:
- Actualizar rutas relativas a `playlist.dat` y `letras/` (cambian porque ahora compilamos desde `Avance3/src/`)
- Verificar compilación completa con el comando de abajo
- Probar flujo completo: entrar y salir de los 3 módulos sin crash

---

## Comando de compilación final
Desde `Avance3/src/`:
```bash
g++ main.cpp MenuRedSocial.cpp GrafoRedSocial.cpp \
    ../../Avance2/src/GestorArbol.cpp \
    ../../Avance2/src/MenuGestorArchivos.cpp \
    ../../Avance1/src/ListaCircular.cpp \
    ../../Avance1/src/GestionCanciones.cpp \
    ../../Avance1/src/GestorArchivos.cpp \
    -o simulador
./simulador
```

---

## Orden de trabajo recomendado

| Fase | Quién | Qué |
|---|---|---|
| 1 | Christopher | `UsuarioNodo.h` + `GrafoRedSocial.h/cpp` completos |
| 2 | Camila | `MenuRedSocial.h/cpp` (puede usar stubs mientras Christopher termina) |
| 3 | Andrés | `main.cpp` integrado una vez que los dos módulos anteriores estén listos |
| 4 | Todos | Pruebas de integración, validar que los 3 módulos funcionan juntos |

---

## Checklist de entrega

- [ ] `UsuarioNodo.h` — struct definido
- [ ] `GrafoRedSocial.cpp` — todos los métodos implementados
- [ ] BFS y DFS funcionando correctamente
- [ ] `MenuRedSocial.cpp` — menú completo con validaciones
- [ ] `main.cpp` — menú principal con las 4 opciones
- [ ] Compilación limpia sin warnings
- [ ] Prueba: crear usuarios, agregar amistades, recorrer grafo
- [ ] Prueba: acceder a Reproductor y Gestor desde el menú principal
