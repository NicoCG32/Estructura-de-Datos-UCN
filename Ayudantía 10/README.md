# Ayudantía 10

## Contenido

- [Objetivo del bloque](#objetivo-del-bloque)
- [Convenciones](#convenciones)
- [Estructuras base](#estructuras-base)
- [Grafo dirigido de referencia](#grafo-dirigido-de-referencia)
- [Grafo no dirigido de referencia](#grafo-no-dirigido-de-referencia)
- [Referencias de práctica](#referencias-de-práctica)
- [Problema 1: lista de arcos hacia lista y matriz de adyacencia](#problema-1-lista-de-arcos-hacia-lista-y-matriz-de-adyacencia)
- [Problema 2: consultas y grados con matriz de adyacencia](#problema-2-consultas-y-grados-con-matriz-de-adyacencia)
- [Problema 3: BFS y distancias mínimas en grafos no ponderados](#problema-3-bfs-y-distancias-mínimas-en-grafos-no-ponderados)
- [Problema 4: DFS recursivo, DFS iterativo y alcanzabilidad](#problema-4-dfs-recursivo-dfs-iterativo-y-alcanzabilidad)
- [Problema 5: componentes conexas y ciclos en grafos no dirigidos](#problema-5-componentes-conexas-y-ciclos-en-grafos-no-dirigidos)
- [Problema 6: vértices que pertenecen a algún camino usando BFS y DFS](#problema-6-vértices-que-pertenecen-a-algún-camino-usando-bfs-y-dfs)
- [Cómo trabajar los ejercicios](#cómo-trabajar-los-ejercicios)
- [Preguntas de control](#preguntas-de-control)
- [Extensiones recomendadas](#extensiones-recomendadas)

Esta ayudantía cierra el bloque de estructuras no lineales con grafos. El objetivo no es solo implementar recorridos, sino entender qué representación conviene según la operación que se quiere realizar.

Trabajaremos con tres representaciones:

- lista de arcos;
- lista de adyacencia;
- matriz de adyacencia.

También compararemos BFS y DFS. Ambos recorren grafos, pero resuelven problemas distintos: BFS procesa por capas y sirve naturalmente para distancias mínimas en grafos no ponderados; DFS profundiza por ramas y sirve para explorar estructura, detectar ciclos y razonar sobre caminos.

## Objetivo del bloque

- representar grafos dirigidos y no dirigidos en C++;
- convertir entre lista de arcos, lista de adyacencia y matriz de adyacencia;
- calcular grados de entrada y salida;
- implementar BFS con `queue`;
- implementar DFS recursivo e iterativo con `stack`;
- controlar vértices visitados para evitar ciclos infinitos;
- resolver un problema integrador usando BFS y DFS en conjunto;
- justificar correctitud y complejidad de cada solución.

## Convenciones

En todos los ejercicios:

- los vértices se identifican con enteros `0..n-1`;
- si hay que escoger entre varios vecinos, se visitan en orden numérico ascendente;
- un arco dirigido `u -> v` permite moverse desde `u` hacia `v`, pero no necesariamente desde `v` hacia `u`;
- una arista no dirigida `{u, v}` se representa como dos adyacencias: `u` contiene a `v` y `v` contiene a `u`;
- una matriz de adyacencia usa `matrix[u][v] != 0` para indicar que existe el arco `u -> v`;
- salvo que el enunciado indique lo contrario, se asume grafo simple: sin arcos duplicados.

## Estructuras base

Para los ejercicios con lista de arcos, puedes asumir esta estructura:

```cpp
struct EdgeNode {
    int source;
    int destination;
    EdgeNode* next;

    EdgeNode(int source, int destination)
        : source(source), destination(destination), next(nullptr) {}
};
```

Una lista de arcos enlazada representa un conjunto de arcos:

```text
(0, 1) -> (0, 2) -> (1, 3) -> ... -> nullptr
```

Cada nodo de la lista almacena un arco, no un vértice.

## Grafo dirigido de referencia

Usaremos el siguiente grafo dirigido en los problemas 1, 2, 3, 4 y 6:

```text
0 -> 1, 2
1 -> 3, 4
2 -> 4, 5
3 -> 6
4 -> 3, 6, 7
5 -> 4, 7
6 -> -
7 -> 6
```

Lista de arcos equivalente:

```text
(0,1), (0,2), (1,3), (1,4), (2,4), (2,5),
(3,6), (4,3), (4,6), (4,7), (5,4), (5,7), (7,6)
```

Matriz de adyacencia equivalente:

```text
    0 1 2 3 4 5 6 7
0 | 0 1 1 0 0 0 0 0
1 | 0 0 0 1 1 0 0 0
2 | 0 0 0 0 1 1 0 0
3 | 0 0 0 0 0 0 1 0
4 | 0 0 0 1 0 0 1 1
5 | 0 0 0 0 1 0 0 1
6 | 0 0 0 0 0 0 0 0
7 | 0 0 0 0 0 0 1 0
```

## Grafo no dirigido de referencia

Usaremos este grafo no dirigido en el problema 5:

```text
0 -- 1
|  /
| /
2 -- 3

4 -- 5 -- 6

7 -- 8
```

Lista de aristas:

```text
{0,1}, {0,2}, {1,2}, {2,3}, {4,5}, {5,6}, {7,8}
```

Tiene tres componentes conexas:

```text
{0,1,2,3}, {4,5,6}, {7,8}
```

Además, contiene un ciclo en la primera componente:

```text
0 -> 1 -> 2 -> 0
```

## Referencias de práctica

Los ejercicios están inspirados en patrones clásicos de grafos. No son copias literales de los enunciados originales.

- [LeetCode 1971 - Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/): alcanzabilidad en grafo no dirigido.
- [LeetCode 547 - Number of Provinces](https://leetcode.com/problems/number-of-provinces/): componentes conexas usando matriz de adyacencia.
- [LeetCode 797 - All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/): recorridos DFS sobre caminos.
- [GeeksforGeeks - Breadth First Search or BFS for a Graph](https://www.geeksforgeeks.org/dsa/breadth-first-search-or-bfs-for-a-graph/): repaso de BFS.
- [GeeksforGeeks - Depth First Search or DFS for a Graph](https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/): repaso de DFS.
- [GeeksforGeeks - Graph and its representations](https://www.geeksforgeeks.org/dsa/graph-and-its-representations/): comparación de representaciones.

---

## Problema 1: lista de arcos hacia lista y matriz de adyacencia

Dado un grafo representado mediante lista de arcos enlazada, construye:

1. su lista de adyacencia;
2. su matriz de adyacencia.

Firmas obligatorias:

```cpp
vector<vector<int>> construirListaAdy(EdgeNode* edges, int n, bool directed);
vector<vector<int>> construirMatrizAdy(EdgeNode* edges, int n, bool directed);
```

### Contrato de las funciones

Las funciones deben cumplir lo siguiente:

- si `n <= 0`, retornan un `vector<vector<int>>` vacío;
- si `edges == nullptr`, retornan una representación con `n` vértices y sin arcos;
- si `directed == true`, cada arco `(u, v)` se agrega solo como `u -> v`;
- si `directed == false`, cada arco `(u, v)` se agrega como `u -> v` y `v -> u`;
- si aparece un arco con extremos fuera de `0..n-1`, debe ignorarse;
- en la lista de adyacencia, los vecinos de cada vértice deben quedar en orden ascendente;
- en la matriz de adyacencia, `matrix[u][v]` debe ser `1` si existe el arco `u -> v`, y `0` en caso contrario.

### Restricciones

- No modifiques la lista enlazada original.
- No uses variables globales.
- Para la lista de adyacencia puedes usar `vector<vector<int>>`.
- Para la matriz de adyacencia debes usar `vector<vector<int>>`.
- La conversión debe recorrer la lista de arcos una sola vez, además del ordenamiento final de vecinos si corresponde.

### Ejemplos esperados

Usando el grafo dirigido de referencia con `n = 8`:

| Consulta | Salida esperada |
| --- | --- |
| `lista[0]` | `[1, 2]` |
| `lista[4]` | `[3, 6, 7]` |
| `lista[6]` | `[]` |
| `matrix[0][2]` | `1` |
| `matrix[2][0]` | `0` |
| `matrix[7][6]` | `1` |

### Cómo pensar el problema

Antes de programar, responde:

1. ¿Qué almacena un nodo de la lista de arcos?
2. ¿Por qué una lista de adyacencia permite recorrer vecinos de forma eficiente?
3. ¿Qué costo en memoria tiene una matriz de adyacencia?
4. ¿Qué cambia entre un grafo dirigido y uno no dirigido al construir la representación?
5. ¿Qué representa exactamente `matrix[u][v]`?

---

## Problema 2: consultas y grados con matriz de adyacencia

Dada una matriz de adyacencia de un grafo dirigido, implementa funciones para consultar arcos, grados y vecinos de salida.

Firmas obligatorias:

```cpp
bool existeArcoMatriz(const vector<vector<int>>& matrix, int u, int v);
int gradoSalidaMatriz(const vector<vector<int>>& matrix, int v);
int gradoEntradaMatriz(const vector<vector<int>>& matrix, int v);
vector<int> vecinosSalidaMatriz(const vector<vector<int>>& matrix, int v);
```

### Contrato de las funciones

Las funciones deben cumplir lo siguiente:

- si la matriz no es cuadrada, se considera inválida;
- si un vértice está fuera de rango, se retorna `false`, `0` o vector vacío según corresponda;
- `existeArcoMatriz(matrix, u, v)` retorna `true` si `matrix[u][v] != 0`;
- `gradoSalidaMatriz(matrix, v)` cuenta cuántos arcos salen desde `v`;
- `gradoEntradaMatriz(matrix, v)` cuenta cuántos arcos llegan hacia `v`;
- `vecinosSalidaMatriz(matrix, v)` retorna los vértices `x` tales que existe `v -> x`, en orden ascendente.

### Restricciones

- No conviertas la matriz a lista de adyacencia para resolver este problema.
- Debes recorrer filas o columnas según corresponda.
- Asume que cualquier valor distinto de cero indica existencia de arco.

### Ejemplos esperados

Usando la matriz del grafo dirigido de referencia:

| Llamada | Salida esperada |
| --- | --- |
| `existeArcoMatriz(matrix, 2, 5)` | `true` |
| `existeArcoMatriz(matrix, 5, 2)` | `false` |
| `gradoSalidaMatriz(matrix, 4)` | `3` |
| `gradoEntradaMatriz(matrix, 4)` | `3` |
| `gradoEntradaMatriz(matrix, 6)` | `3` |
| `vecinosSalidaMatriz(matrix, 1)` | `[3, 4]` |

### Cómo pensar el problema

En una matriz de adyacencia dirigida:

- la fila `u` describe los arcos que salen desde `u`;
- la columna `v` describe los arcos que llegan hacia `v`;
- consultar un arco puntual cuesta `O(1)`;
- listar todos los vecinos de un vértice cuesta `O(n)`, incluso si tiene pocos vecinos.

---

## Problema 3: BFS y distancias mínimas en grafos no ponderados

Dado un grafo representado por lista de adyacencia, implementa BFS desde un vértice inicial. Además, calcula la distancia mínima en cantidad de arcos desde el origen hacia cada vértice.

Firmas obligatorias:

```cpp
vector<int> bfsOrden(const vector<vector<int>>& adj, int start);
vector<int> distanciasBFS(const vector<vector<int>>& adj, int start);
```

### Contrato de las funciones

Las funciones deben cumplir lo siguiente:

- si `start` está fuera de rango, `bfsOrden` retorna un vector vacío;
- si `start` está fuera de rango, `distanciasBFS` retorna un vector de tamaño `n` lleno de `-1`;
- si un vértice no es alcanzable desde `start`, su distancia debe ser `-1`;
- la distancia de `start` hacia sí mismo es `0`;
- los vecinos deben procesarse en orden ascendente;
- un vértice debe marcarse como visitado al descubrirse, no después de repetirlo muchas veces en la cola.

### Restricciones

- Debes usar `std::queue<int>`.
- No uses recursión.
- No uses `priority_queue`; el grafo no tiene pesos.
- No modifiques `adj`.

### Ejemplos esperados

Usando la lista de adyacencia del grafo dirigido de referencia:

| Llamada | Salida esperada |
| --- | --- |
| `bfsOrden(adj, 0)` | `[0, 1, 2, 3, 4, 5, 6, 7]` |
| `distanciasBFS(adj, 0)` | `[0, 1, 1, 2, 2, 2, 3, 3]` |
| `distanciasBFS(adj, 6)` | `[-1, -1, -1, -1, -1, -1, 0, -1]` |
| `bfsOrden(adj, 20)` | `[]` |

### Cómo pensar el problema

BFS procesa el grafo por capas:

```text
distancia 0: start
distancia 1: vecinos directos
distancia 2: vecinos de los vecinos no visitados
...
```

Por eso, en un grafo no ponderado, la primera vez que BFS descubre un vértice ya encontró una ruta con la mínima cantidad de arcos.

---

## Problema 4: DFS recursivo, DFS iterativo y alcanzabilidad

Dado un grafo representado por lista de adyacencia, implementa DFS desde un vértice inicial en dos versiones: recursiva e iterativa. Además, implementa una función que determine si existe camino desde `src` hasta `dst`.

Firmas obligatorias:

```cpp
vector<int> dfsRecursivo(const vector<vector<int>>& adj, int start);
vector<int> dfsIterativo(const vector<vector<int>>& adj, int start);
bool existeCaminoDFS(const vector<vector<int>>& adj, int src, int dst);
```

### Contrato de las funciones

Las funciones deben cumplir lo siguiente:

- si `start`, `src` o `dst` están fuera de rango, se retorna vector vacío o `false`;
- si `src == dst` y el vértice es válido, `existeCaminoDFS` retorna `true`;
- cada vértice debe aparecer a lo más una vez en el recorrido;
- los vecinos deben considerarse en orden ascendente;
- `dfsIterativo` debe producir el mismo orden que `dfsRecursivo` bajo la convención de vecinos ascendentes.

### Restricciones

- La versión recursiva debe usar una función auxiliar.
- La versión iterativa debe usar `std::stack<int>`.
- En la versión iterativa, si apilas vecinos, debes razonar en qué orden se apilan para respetar el orden de visita.
- No modifiques `adj`.

### Ejemplos esperados

Usando la lista de adyacencia del grafo dirigido de referencia:

| Llamada | Salida esperada |
| --- | --- |
| `dfsRecursivo(adj, 0)` | `[0, 1, 3, 6, 4, 7, 2, 5]` |
| `dfsIterativo(adj, 0)` | `[0, 1, 3, 6, 4, 7, 2, 5]` |
| `existeCaminoDFS(adj, 2, 6)` | `true` |
| `existeCaminoDFS(adj, 6, 0)` | `false` |
| `existeCaminoDFS(adj, 4, 4)` | `true` |

### Cómo pensar el problema

DFS sigue una rama hasta donde puede antes de retroceder. En la versión recursiva, el retroceso lo administra la pila de llamadas. En la versión iterativa, debes administrar explícitamente esa pila con `std::stack`.

El detalle crítico es el orden: como la pila es LIFO, si quieres visitar primero el vecino menor, debes apilar los vecinos desde el mayor hacia el menor.

---

## Problema 5: componentes conexas y ciclos en grafos no dirigidos

Dado un grafo no dirigido representado por lista de adyacencia, implementa:

1. una función que cuente componentes conexas;
2. una función que detecte si existe al menos un ciclo.

Firmas obligatorias:

```cpp
int contarComponentes(const vector<vector<int>>& adj);
bool tieneCicloNoDirigido(const vector<vector<int>>& adj);
```

### Contrato de las funciones

Las funciones deben cumplir lo siguiente:

- el grafo se considera no dirigido;
- `adj[u]` contiene los vecinos de `u`;
- si `n == 0`, `contarComponentes` retorna `0` y `tieneCicloNoDirigido` retorna `false`;
- una componente conexa es un conjunto maximal de vértices alcanzables entre sí;
- `tieneCicloNoDirigido` debe distinguir entre volver al padre inmediato y encontrar un ciclo real.

### Restricciones

- Puedes usar DFS recursivo o iterativo.
- Debes usar un vector de visitados.
- Para detectar ciclos en grafo no dirigido, debes recordar el padre del vértice actual.
- No basta con decir "si veo un visitado hay ciclo", porque en grafos no dirigidos siempre se ve el padre.

### Ejemplos esperados

Usando el grafo no dirigido de referencia:

| Llamada | Salida esperada |
| --- | --- |
| `contarComponentes(adjNoDirigido)` | `3` |
| `tieneCicloNoDirigido(adjNoDirigido)` | `true` |

Para el grafo:

```text
0 -- 1 -- 2 -- 3
```

| Llamada | Salida esperada |
| --- | --- |
| `contarComponentes(path)` | `1` |
| `tieneCicloNoDirigido(path)` | `false` |

### Cómo pensar el problema

Para contar componentes, cada vez que encuentras un vértice no visitado, inicias un recorrido desde él. Ese recorrido marca toda su componente. Por tanto, la cantidad de veces que inicias un recorrido nuevo corresponde a la cantidad de componentes.

Para detectar ciclos en un grafo no dirigido, si desde `u` visitas a `v`, entonces `u` es el padre de `v`. Más adelante, que `v` vea de vuelta a `u` no constituye ciclo; es simplemente la misma arista mirada en sentido contrario.

---

## Problema 6: vértices que pertenecen a algún camino usando BFS y DFS

Dado un grafo dirigido, un origen `src` y un destino `dst`, retorna todos los vértices que pertenecen a al menos un camino dirigido desde `src` hasta `dst`.

Firma obligatoria:

```cpp
vector<int> verticesEnAlgunCamino(const vector<vector<int>>& adj, int src, int dst);
```

### Contrato de la función

La función debe cumplir lo siguiente:

- si `src` o `dst` están fuera de rango, retorna un vector vacío;
- un vértice `v` pertenece a la respuesta si existe un camino `src -> ... -> v -> ... -> dst`;
- la respuesta debe quedar en orden ascendente;
- si no existe camino desde `src` hasta `dst`, retorna un vector vacío;
- el grafo no debe modificarse.

### Restricciones

- Debes usar BFS para marcar los vértices alcanzables desde `src`.
- Debes usar DFS sobre el grafo invertido para marcar los vértices que pueden llegar a `dst`.
- Debes construir el grafo invertido en `O(V + E)`.
- No enumeres todos los caminos simples, porque pueden ser exponenciales.

### Ejemplos esperados

Usando el grafo dirigido de referencia:

| Llamada | Salida esperada |
| --- | --- |
| `verticesEnAlgunCamino(adj, 2, 3)` | `[2, 3, 4, 5]` |
| `verticesEnAlgunCamino(adj, 5, 6)` | `[3, 4, 5, 6, 7]` |
| `verticesEnAlgunCamino(adj, 6, 0)` | `[]` |
| `verticesEnAlgunCamino(adj, 0, 6)` | `[0, 1, 2, 3, 4, 5, 6, 7]` |

### Cómo pensar el problema

Un vértice `v` está en algún camino desde `src` hasta `dst` si y solo si cumple dos condiciones:

```text
src puede llegar a v
v puede llegar a dst
```

La primera condición se obtiene con BFS desde `src`.

La segunda condición puede verse al revés: si invertimos todos los arcos, entonces `v` puede llegar a `dst` en el grafo original si y solo si `dst` puede llegar a `v` en el grafo invertido. Esa segunda marca se puede hacer con DFS.

---

## Cómo trabajar los ejercicios

Para cada problema, intenta seguir este orden:

1. Identificar si el grafo es dirigido o no dirigido.
2. Identificar la representación inicial.
3. Determinar si necesitas recorrer vecinos, consultar arcos puntuales o recorrer todos los arcos.
4. Elegir BFS, DFS o conversión de representación.
5. Definir cuándo se marca un vértice como visitado.
6. Escribir casos inválidos.
7. Justificar correctitud con una idea clara, no solo con intuición.
8. Calcular complejidad en términos de `V` vértices y `E` arcos.

## Preguntas de control

- ¿Cuál es la diferencia entre lista de arcos y lista de adyacencia?
- ¿Por qué una matriz de adyacencia ocupa `O(V^2)` memoria?
- ¿Cuándo conviene una matriz de adyacencia por sobre una lista de adyacencia?
- ¿Por qué BFS entrega distancias mínimas en grafos no ponderados?
- ¿Por qué DFS no garantiza distancia mínima?
- ¿Qué ocurre si no marcas vértices visitados en un grafo con ciclos?
- En un grafo no dirigido, ¿por qué ver al padre no significa encontrar un ciclo?
- ¿Qué cambia al invertir todos los arcos de un grafo dirigido?
- ¿Por qué enumerar todos los caminos puede ser mucho más costoso que razonar con alcanzabilidad?

## Extensiones recomendadas

Después de resolver los seis problemas, implementa estas variantes:

1. Convertir una matriz de adyacencia a lista de arcos enlazada.
2. Calcular grados de entrada y salida desde una lista de adyacencia.
3. Recuperar explícitamente un camino mínimo usando BFS y vector de padres.
4. Detectar ciclos en un grafo dirigido usando colores: blanco, gris y negro.
5. Determinar si un grafo no dirigido es árbol.
6. Contar cuántos vértices son alcanzables desde cada vértice.
7. Implementar BFS usando matriz de adyacencia y comparar su complejidad con BFS sobre lista de adyacencia.
