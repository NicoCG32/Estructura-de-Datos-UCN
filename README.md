# Ayudantía Estructura de Datos

**Profesor de Cátedra:** Bastián Ruiz

**Ayudante:** Pablo Guzmán

**Período:** 2026 - I

## Contenido

- [Introducción](#introduccion)
- [¿Qué son "Data Structures and Algorithms"?](#que-son-data-structures-and-algorithms)
- [Desafíos para Nuevos Programadores](#desafios-para-nuevos-programadores)
- [C++ y su Importancia en Programación](#c-y-su-importancia-en-programacion)
- [📚 Ayudantías](#-ayudantias)
  - [PP1](#pp1)
  - [PP2](#pp2)
- [Temario](#temario)
  - [Conceptos Fundamentales](#conceptos-fundamentales)
  - [Estructuras de Datos](#estructuras-de-datos)
- [Nota Importante: Transición desde Java](#nota-importante-transicion-desde-java)
  - [Memoria local, global y heap (aclaración clave)](#memoria-local-global-y-heap-aclaracion-clave)

## Drive complementario de recopilación

- [Drive Estructura de Datos UCN](https://drive.google.com/drive/u/1/folders/1FYQ9pW4oi6wDTOiPmnqvGxrakmT2eb6Y)

## Introducción

Bienvenido a las ayudantías de Estructura de Datos del semestre 2026-I. Este curso es fundamental en tu formación como programador, combinando teoría algorítmica con implementación práctica en C++. Las estructuras de datos son la base sobre la cual se construyen soluciones eficientes y escalables.

## ¿Qué son "Data Structures and Algorithms"?

Las estructuras de datos y algoritmos forman el corazón de la informática. Una **estructura de datos** es una forma de organizar información en memoria para que sea accesible y modificable de manera eficiente, mientras que un **algoritmo** es un procedimiento paso a paso para resolver un problema o realizar una tarea computacional. Juntas, determinan la velocidad, eficiencia en memoria y viabilidad de cualquier solución de software.

## Desafíos para Nuevos Programadores

- **Pensamiento abstracto:** Visualizar cómo los datos se organizan en memoria no es trivial
- **Análisis de complejidad:** Aprender a evaluar la eficiencia de soluciones (Big O)
- **Trade-offs de diseño:** Entender cuándo usar qué estructura según el contexto
- **Transición desde Java:** Los estudiantes de este curso ya dominan POO en Java, pero deben adaptarse a C++ con gestión manual de memoria y mayor control del sistema

## C++ y su Importancia en Programación

C++ es un lenguaje robusto, eficiente y ampliamente usado en sistemas de alto rendimiento, juegos, bases de datos y aplicaciones críticas. Su acceso directo a la memoria mediante punteros, compilación a código nativo y control fino de recursos lo hacen ideal para aprender estructuras de datos. Aunque Java abstrae muchos conceptos, **C++ te obliga a entender realmente cómo funcionan las cosas**, lo que profundiza tu comprensión fundamental de la programación.

---

## 📚 Ayudantías

Las ayudantías del semestre se encuentran organizadas en las siguientes carpetas:

### Compendio

- **[Compendio](Compendio/README.md)** - Banco de ejercicios por temas y soluciones para la PP1 y PP2

### PP1

- **[Ayudantía 1](Ayudantía%201/README.md)** - Introducción a C++ y punteros
- **[Ayudantía 2](Ayudantía%202/README.md)** - POO en C++, herencia y polimorfismo
- **[Ayudantía 3](Ayudantía%203/README.md)** - Organización de archivos, Listas enlazadas y Stack 
- **[Ayudantía 4](Ayudantía%204/README.md)** - Complejidad algorítmica, listas, pilas y colas
- **[Ayudantía 5](Ayudantía%205/README.md)** - Repaso final antes de la PP1
- **[Intensiva I](Intensiva%20I/README.md)** - Ruta seleccionada para la intensiva PP1

### PP2

- **[Ayudantí­a 6](Ayudantía%206/README.md)** - Recorridos de árboles binarios
- **[Ayudantía 7](Ayudantía%207/README.md)** - Heaps y HeapSort
- **[Ayudantía 8](Ayudantía%208/README.md)** - Árboles AVL
- **[Ayudantía 9](Ayudantía%209/README.md)** - Algoritmos recursivos e iterativos con árboles
- **[Ayudantía 10](Ayudantía%2010/README.md)** - Grafos: representaciones, BFS y DFS
- **[Intensiva II](Intensiva%20II/README.md)** - Ruta seleccionada para la intensiva PP2
- **[Apunte final PP2](Apunte%20final%20PP2/README.md)** - Recorridos genéricos en árboles y grafos

## Temario

### Conceptos Fundamentales

#### 1. **Programación en C++**
Sintaxis básica, tipos de datos, funciones, y estructura general de un programa C++.

#### 2. **Punteros**
Entender qué son los punteros, gestión de memoria (new/delete), y por qué son cruciales para estructuras de datos dinámicas.

#### 3. **Programación Orientada a Objetos (POO) en C++**
Clases, herencia, encapsulación y polimorfismo. Adaptación desde Java a C++, incluyendo destructores, constructores de copia y el concepto de *this*.

#### 4. **Librería STD y Documentación**
La Standard Template Library (STL) proporciona implementaciones eficientes de estructuras de datos comunes:
- `vector<T>` - arreglos dinámicos.
Comunes: `push_back` (agrega al final), `pop_back` (elimina el último), `size` (cantidad de elementos), `operator[]` (acceso por índice sin verificación), `at` (acceso por índice con verificación), `front` (primer elemento), `back` (último elemento), `begin` (iterador al inicio), `end` (iterador al final).
	- Documentación: <https://en.cppreference.com/w/cpp/container/vector>

- `pair<T1,T2>` - par de valores.
Comunes: `first` (accede al primer valor), `second` (accede al segundo valor), `make_pair` (crea un `pair` deduciendo tipos).
	- Documentación: <https://en.cppreference.com/w/cpp/utility/pair>

- `list<T>` - lista doblemente enlazada.
Comunes: `push_back` (agrega al final), `push_front` (agrega al inicio), `pop_back` (elimina el último), `pop_front` (elimina el primero), `insert` (inserta en posición dada por iterador), `erase` (elimina en posición dada por iterador), `front` (primer elemento), `back` (último elemento).
	- Documentación: <https://en.cppreference.com/w/cpp/container/list>

- `stack<T>` - pila (LIFO).
Comunes: `push` (apila un elemento), `pop` (desapila el tope), `top` (consulta el tope), `empty` (verifica si está vacía), `size` (cantidad de elementos).
	- Documentación: <https://en.cppreference.com/w/cpp/container/stack>

- `queue<T>` - cola (FIFO).
Comunes: `push` (encola al final), `pop` (desencola el primero), `front` (consulta el primero), `back` (consulta el último), `empty` (verifica si está vacía), `size` (cantidad de elementos).
	- Documentación: <https://en.cppreference.com/w/cpp/container/queue>

- `map<K,V>` - diccionario ordenado por clave (árbol balanceado).
Comunes: `insert` (inserta clave-valor), `erase` (elimina por clave/iterador), `find` (busca una clave), `count` (indica si existe la clave), `operator[]` (accede o crea valor por clave), `at` (accede con verificación de existencia).
	- Documentación: <https://en.cppreference.com/w/cpp/container/map>

- `unordered_map<K,V>` - tabla hash.
Comunes: `insert` (inserta clave-valor), `erase` (elimina por clave/iterador), `find` (busca una clave), `count` (indica si existe la clave), `operator[]` (accede o crea valor por clave), `at` (accede con verificación de existencia), `bucket_count` (cantidad de buckets), `load_factor` (factor de carga actual).
	- Documentación: <https://en.cppreference.com/w/cpp/container/unordered_map>

- `set<T>` - conjunto de claves únicas (ordenado).
Comunes: `insert` (agrega un valor único), `erase` (elimina un valor), `find` (busca un valor), `count` (indica si existe el valor), `contains` (verifica pertenencia de forma directa).
	- Documentación: <https://en.cppreference.com/w/cpp/container/set>

- Algoritmos: `sort()` (ordena un rango), `find()` (busca un valor en un rango), `reverse()` (invierte el orden de un rango), etc.

---

### Estructuras de Datos

#### 1. **Vectores**
Arreglos dinámicos que crecen bajo demanda. Entender la **indexación por memoria**: cómo acceder a elementos en O(1) usando aritmética de direcciones, por qué son eficientes en lectura pero costosos en inserciones.

#### 2. **Listas Enlazadas (LinkedList)**
Estructuras flexibles donde cada elemento (nodo) apunta al siguiente. Complejas en memoria pero eficientes para inserciones y eliminaciones. Incluye variantes como listas doblemente enlazadas y listas circulares.

#### 3. **Pilas (Stacks) y Colas (Queues)**
- **Pilas (LIFO):** Último en entrar, primero en salir. Aplicación crítica: **pila de recursión** - entender cómo funciona la recursión internamente
- **Colas (FIFO):** Primero en entrar, primero en salir. Útiles en procesamiento de tareas y simulaciones.

#### 4. **Matriz poco poblada (SparseMatrix)**
Representación eficiente de matrices con gran cantidad de ceros, almacenando solo los elementos no nulos para optimizar memoria y operaciones relevantes.

#### 5. **Tablas Hash**
Estructura basada en función hash para acceso promedio en tiempo constante. Se estudian colisiones, encadenamiento y sondeo, además de casos de uso como diccionarios y conteo de frecuencias. Equivalente al diccionario en python.

#### 6. **Árboles**
Estructuras jerárquicas con un nodo raíz y múltiples ramas. Incluye:
- Árboles binarios y búsqueda binaria (BST)
- **Heaps (pilas binarias):** Árboles especiales para colas de prioridad, ordenamiento eficiente (HeapSort)
- Árboles balanceados (AVL, Red-Black)

#### 7. **Árboles B***
Árboles de búsqueda multi-ramificados optimizados para acceso a disco. Fundamentales en bases de datos e indexación de archivos.

#### 8. **Grafos**
Estructuras generales que conectan múltiples nodos. El porqué de dos algoritmos clave:
- **DFS (Depth-First Search):** Exploración en profundidad - útil para detectar ciclos, componentes conexas, ordenamiento topológico (Se hace con un Stack).
- **BFS (Breadth-First Search):** Exploración en amplitud - útil para caminos más cortos, nivel de profundidad (Se hace con una Queue).

---

## Nota Importante: Transición desde Java

Muchos de ustedes ya tienen experiencia con POO en Java. Recuerden:
- **No hay recolección automática de basura:** Deben gestionar memoria manualmente (new/delete)
- **Punteros vs referencias:** Java tiene referencias manejadas; C++ tiene punteros explícitos
- **Compilación:** C++ compila a código nativo, no a bytecode
- **Control de memoria:** Mayor poder, pero también mayor responsabilidad

### Memoria local, global y heap (aclaración clave)

En C++ no toda la memoria es igual. Es importante distinguir:

- **Memoria local (automática, stack):** Variables declaradas dentro de funciones o bloques (por ejemplo `int x = 5;`). Se crean al entrar al bloque y se destruyen automáticamente al salir. **No usan `new` ni requieren `delete`.**
- **Memoria global/estática:** Variables globales o `static`. Existen durante toda la ejecución del programa y el sistema las libera al terminar. **Tampoco se manejan con `new/delete`.**
- **Memoria dinámica (heap):** Se reserva manualmente con `new` o `new[]` y vive hasta que se libere con `delete` o `delete[]`.

Regla práctica:

- Si usaste `new`, debes usar `delete`.
- Si usaste `new[]`, debes usar `delete[]`.

Si no se libera memoria dinámica, ocurre una **fuga de memoria** (memory leak): el programa pierde acceso a ese bloque y no puede reutilizarlo.

Errores típicos al comenzar:

- Hacer `delete` dos veces al mismo puntero (double delete).
- Usar un puntero después de liberar su memoria (dangling pointer).
- Olvidar liberar en todos los caminos posibles del programa (por ejemplo, en retornos tempranos).

Buenas prácticas recomendadas para el curso y proyectos reales:

- Preferir contenedores de la STL (`vector`, `string`, etc.) cuando sea posible.
- En código moderno, preferir punteros inteligentes (`unique_ptr`, `shared_ptr`) para reducir errores manuales.

Esta transición las hará mejores programadores al obligarlos a entender qué sucede realmente "bajo el capó".

---

**¡Bienvenidos al fascinante mundo de las estructuras de datos!**
