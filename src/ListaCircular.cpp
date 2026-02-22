// ListaCircular.cpp
// ANDRÉS: Implementa AQUÍ todos los métodos de la clase ListaCircular.
// Este archivo está VACÍO intencionalmente para que lo completes tú.
//
// ═══════════════════════════════════════════════════════════════════════════
// 📋 TAREAS A IMPLEMENTAR (Copia esta estructura):
// ═══════════════════════════════════════════════════════════════════════════
//
// 1. Constructor ListaCircular()
//    └─ Inicializar cabeza = nullptr y actual = nullptr
//
// 2. Destructor ~ListaCircular()
//    └─ Recorrer circularmente el nodo cabeza->siguiente hasta volver a cabeza
//    └─ Liberar TODOS los nodos con delete
//    └─ Poner cabeza = nullptr y actual = nullptr al final
//
// 3. bool estaVacia() const
//    └─ Retorna true si cabeza == nullptr, false si no
//
// 4. void insertarAlFinal(const Cancion &c)
//    └─ Crear nuevo Nodo con new, copiar canción a nuevo->cancion
//    └─ CASO 1: Si lista vacía (cabeza == nullptr)
//       └─ nuevo->siguiente = nuevo, nuevo->anterior = nuevo
//       └─ cabeza = nuevo, actual = nuevo
//    └─ CASO 2: Si hay elementos
//       └─ Obtener cola = cabeza->anterior (último nodo)
//       └─ Conectar: cola->siguiente = nuevo, nuevo->anterior = cola
//       └─ Conectar: nuevo->siguiente = cabeza, cabeza->anterior = nuevo
//
// 5. void siguienteCancion()
//    └─ Si actual != nullptr: actual = actual->siguiente
//    └─ (la circularidad ya está en los punteros)
//
// 6. void anteriorCancion()
//    └─ Si actual != nullptr: actual = actual->anterior
//
// 7. void mostrarPlaylist() const
//    └─ Si cabeza == nullptr: imprimir "[INFO] Playlist vacia.\n"
//    └─ Recorrer desde cabeza hasta volver a cabeza (do-while)
//    └─ Imprimir idx. nombreCancion
//    └─ Si es actual, agregar " <-- (actual)"
//
// 8. void reproducirActual() const
//    └─ Si actual == nullptr: imprimir "[INFO] No hay cancion en reproduccion.\n"
//    └─ Mostrar: nombreCancion, compositor, duracion
//    └─ Si letra.empty() o es "Letra no disponible": mostrar "Letra no disponible"
//    └─ Si hay letra: mostrar primeros ~400 caracteres + "[truncado]" si sobra
//
// 9. vector<Cancion> obtenerTodasCanciones() const
//    └─ Crear vector<Cancion> vacío
//    └─ Si cabeza == nullptr: retornar vector vacío
//    └─ Recorrer circularmente desde cabeza hasta volver a cabeza
//    └─ push_back() cada canción al vector
//    └─ Retornar vector lleno
//
// ═══════════════════════════════════════════════════════════════════════════
// 📌 NOTAS IMPORTANTES:
// ═══════════════════════════════════════════════════════════════════════════
// - Usa #include "ListaCircular.h" al inicio
// - Usa #include <iostream> para cout
// - La lista es DOBLEMENTE ENLAZADA y CIRCULAR:
//   * cabeza->anterior apunta al último nodo
//   * último nodo->siguiente apunta a cabeza
// - CUIDADO con recorridos circulares: usa do-while (cursor != cabeza)
// - Los recorridos SIEMPRE empiezan en cabeza
// - RECUERDA: cuando recorres, terminas cuando vuelves a cabeza
//
// ═══════════════════════════════════════════════════════════════════════════
// 🔗 REFERENCIAS DEL PROYECTO:
// ═══════════════════════════════════════════════════════════════════════════
// - GestionCanciones.cpp accede a lista.cabeza y lista.actual directamente
// - main.cpp usa TODOS tus métodos, así que NO cambies las firmas
// - Si tienes dudas de cómo usar los punteros, ver Cancion.h y Nodo struct
//
// ¡Buena suerte! 🎵
