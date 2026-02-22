# ✅ VERIFICACIÓN PUNTO POR PUNTO – DIVISIÓN DE TAREAS

---

## 📋 TAREAS DE ANDRÉS (Estructura de Datos + Navegación)

| # | Tarea | Estado | Archivo | Notas |
|---|-------|--------|---------|-------|
| 1 | Crear `Cancion.h` con struct | ⏳ PENDIENTE | `src/Cancion.h` | **Andrés debe crear** |
| 2 | Crear Struct `Nodo` | ⏳ PENDIENTE | `src/ListaCircular.h` | **Andrés debe crear en el mismo archivo** |
| 3 | Crear `ListaCircular.h` (firmas) | ⏳ PENDIENTE | `src/ListaCircular.h` | **Andrés debe crear** |
| 4 | Implementar Constructor | ⏳ PENDIENTE | `src/ListaCircular.cpp` | **✅ INSTRUCCIONES LISTAS** |
| 5 | Implementar Destructor | ⏳ PENDIENTE | `src/ListaCircular.cpp` | **✅ INSTRUCCIONES LISTAS** |
| 6 | Implementar `insertarAlFinal()` | ⏳ PENDIENTE | `src/ListaCircular.cpp` | **✅ INSTRUCCIONES LISTAS** |
| 7 | Implementar `estaVacia()` | ⏳ PENDIENTE | `src/ListaCircular.cpp` | **✅ INSTRUCCIONES LISTAS** |
| 8 | Implementar `siguienteCancion()` | ⏳ PENDIENTE | `src/ListaCircular.cpp` | **✅ INSTRUCCIONES LISTAS** |
| 9 | Implementar `anteriorCancion()` | ⏳ PENDIENTE | `src/ListaCircular.cpp` | **✅ INSTRUCCIONES LISTAS** |
| 10 | Implementar `mostrarPlaylist()` | ⏳ PENDIENTE | `src/ListaCircular.cpp` | **✅ INSTRUCCIONES LISTAS** |
| 11 | Implementar `reproducirActual()` | ⏳ PENDIENTE | `src/ListaCircular.cpp` | **✅ INSTRUCCIONES LISTAS** |
| 12 | Implementar `obtenerTodasCanciones()` | ⏳ PENDIENTE | `src/ListaCircular.cpp` | **✅ INSTRUCCIONES LISTAS** |
| 13 | **[EXTRA] Crear `test_persona_a.cpp`** | ❌ FALTA | `src/test_persona_a.cpp` | **Andrés debe crear pruebas** |

---

## 📦 TAREAS DE CHRISTOPHER (Gestión + Persistencia + Integración)

| # | Tarea | Estado | Archivo | Notas |
|---|-------|--------|---------|-------|
| 1 | Crear `GestorArchivos.h` | ✅ HECHO | `src/GestorArchivos.h` | Revisado, está bien |
| 2 | Implementar `GestorArchivos.cpp` | ✅ HECHO | `src/GestorArchivos.cpp` | Revisado, está bien |
| 3 | Crear `GestionCanciones.h` | ✅ HECHO | `src/GestionCanciones.h` | Revisado, está bien |
| 4 | Implementar `GestionCanciones.cpp` | ✅ HECHO | `src/GestionCanciones.cpp` | Revisado, está bien |
| 5 | Implementar `buscarCancion()` | ✅ HECHO | `src/GestionCanciones.cpp` | ✅ Funcional |
| 6 | Implementar `eliminarCancion()` | ✅ HECHO | `src/GestionCanciones.cpp` | ✅ Funcional |
| 7 | Implementar `guardarPlaylist()` | ✅ HECHO | `src/GestorArchivos.cpp` | ✅ Funcional |
| 8 | Implementar `cargarPlaylist()` | ✅ HECHO | `src/GestorArchivos.cpp` | ✅ Funcional |
| 9 | Implementar `cargarLetraDesdeArchivo()` | ✅ HECHO | `src/GestorArchivos.cpp` | ✅ Funcional |
| 10 | Crear Menú Principal interactivo | ✅ HECHO | `src/main.cpp` | **⚠️ Creado por ti**, Christopher lo debe revisar |
| 11 | Validación de entradas del usuario | ✅ HECHO | `src/main.cpp` | ✅ Incluida |
| 12 | Integración final en `main.cpp` | ✅ HECHO | `src/main.cpp` | ✅ Todo integrado |
| 13 | Crear carpeta `letras/` con ejemplos | ✅ HECHO | `letras/` | ✅ 2 canciones de ejemplo |
| 14 | Archivo `playlist.dat` (auto-generado) | ✅ HECHO | `playlist.dat` | ✅ Se genera al guardar |
| 15 | **[EXTRA] Crear `Menu.cpp` separado** | ❌ FALTA | `src/Menu.cpp` | El menú está integrado en main.cpp (no separado) |

---

## 🎯 RESUMEN

### ✅ LO QUE ESTÁ BIEN
- **ListaCircular.cpp**: Vacío con instrucciones detalladas ✅
- **GestorArchivos y GestionCanciones**: Implementados y revisados ✅
- **main.cpp**: Menú funcional con 9 opciones ✅
- **letras/**: Carpeta con ejemplos listos ✅
- **tasks.json**: Compilación configurada ✅

### ⚠️ DISCREPANCIAS / LO QUE DEBERÍA AJUSTARSE
1. **test_persona_a.cpp**
   - NO EXISTE pero está en la división original de Andrés
   - **Andrés debe crear**: Pruebas unitarias para ListaCircular

2. **Menu.cpp**
   - NO EXISTE pero está en la división original de Christopher
   - ESTADO ACTUAL: El menú está integrado en main.cpp (función `mostrarMenu()`)
   - **Opción 1**: Dejarlo así (está funcional)
   - **Opción 2**: Extraer menú a Menu.cpp separado (más modular)

---

## 📌 CONCLUSIÓN

**Lo único que Andrés DEBE implementar ahora es:**
1. ⏳ Crear `src/Cancion.h` (instrucciones en INSTRUCCIONES_ANDRES.md)
2. ⏳ Crear `src/ListaCircular.h` (instrucciones en INSTRUCCIONES_ANDRES.md)
3. ⏳ Implementar los 9 métodos en `src/ListaCircular.cpp` (instrucciones detalladas en ListaCircular.cpp)
4. ⚠️ `test_persona_a.cpp` (opcional, si es parte de requisitos)

**Christopher debe:**
1. ✅ Revisar main.cpp (ya creado) y ajustarlo si necesita cambios
2. ⚠️ Opcionalmente: Extraer menú a Menu.cpp separado si lo requieren

**Todo lo esencial está listo para que el proyecto funcione una vez Andrés termine ListaCircular.cpp.**
