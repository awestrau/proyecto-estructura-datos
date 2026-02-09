# proyecto-estructura-datos

## Avance 1: Implementar un simulador de reproductor de música utilizando una lista doblemente enlazada circular, que permita agregar, eliminar, buscar y navegar canciones hacia adelante y hacia atrás, simulando reproducción continua.

### El simulador de Reproductor de Música: 

1. Registro (struct) sugerido 
   * Cada nodo de la lista contiene una canción: o nombreCancion (string) o compositor (string) o duracion (string, formato “mm:ss” o #“hh:mm:ss”) o letra (string) ← se carga leyendo un .txt externo o Punteros: anterior y siguiente 
2. IMPORTANTE: la lista es doblemente enlazada y circular: nodo-> siguiente; nodo -> anterior; 

3. y se mantiene un puntero del nodo actual para la canción “en reproducción”.
4. Operaciones mínimas (lo que sí o sí deberían #implementar) a. Gestión de canciones 

   * Agregar canción al final. Estas canciones se irán guardando en un archivo

   * Eliminar canción por nombre. Recuerde confirmar la eliminación.
   * Buscar canción por nombre (y posicionar el nodo “actual” ahí). 
   * Mostrar playlist (mostrar las canciones con indicador de la canción actual). 

5. Reproducción / navegación
   * Reproducir canción actual (mostrar datos + opcional: un fragmento de letra).
   * Siguiente canción (actual = #actual->next).

   * Canción anterior (actual = actual->prev). c. Archivo de letra

   * Cargar letra desde archivo: dada una ruta (ej: letras/BohemianRhapsody.txt) leer todo el contenido al string letra.

   * Si el archivo no existe: guardar un mensaje tipo “Letra no disponible”. 4. Entrega de archivo RAR: En un único archivo .RAR, incluya obligatoriamente: a. Todos los archivos .cpp y.h (si aplica) 

   * El ejecutable .exe (compilado y funcional). 

7. La carpeta o archivos .txt que contienen las letras utilizadas en la demo (para que pueda probarse).
