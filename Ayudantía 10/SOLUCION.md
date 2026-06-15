# Ayudantía 10: Soluciones

Este archivo contiene soluciones para los ejercicios de grafos propuestos en `README.md`.

El énfasis está en tres ideas:

- elegir una representación coherente con la operación requerida;
- controlar vértices visitados para que los recorridos terminen;
- justificar por qué BFS, DFS o una combinación de ambos resuelve el problema.

## Código base común

```cpp
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct EdgeNode {
    int source;
    int destination;
    EdgeNode* next;

    EdgeNode(int source, int destination)
        : source(source), destination(destination), next(nullptr) {}
};

bool verticeValido(int v, int n) {
    return 0 <= v && v < n;
}

bool matrizCuadrada(const vector<vector<int>>& matrix) {
    int n = static_cast<int>(matrix.size());

    for (const vector<int>& row : matrix) {
        if (static_cast<int>(row.size()) != n) {
            return false;
        }
    }

    return true;
}
```

---

# Problema 1: lista de arcos hacia lista y matriz de adyacencia

## Idea

Una lista de arcos permite recorrer todos los arcos de forma directa. Por eso sirve bien como entrada para construir otras representaciones.

Para cada arco `(u, v)`:

- en grafo dirigido, se agrega solo `u -> v`;
- en grafo no dirigido, se agregan `u -> v` y `v -> u`;
- si el arco tiene extremos inválidos, se ignora.

## Solución

```cpp
vector<vector<int>> construirListaAdy(EdgeNode* edges, int n, bool directed) {
    if (n <= 0) {
        return {};
    }

    vector<vector<int>> adj(n);

    EdgeNode* current = edges;
    while (current != nullptr) {
        int u = current->source;
        int v = current->destination;

        if (verticeValido(u, n) && verticeValido(v, n)) {
            adj[u].push_back(v);

            if (!directed && u != v) {
                adj[v].push_back(u);
            }
        }

        current = current->next;
    }

    for (vector<int>& vecinos : adj) {
        sort(vecinos.begin(), vecinos.end());
        vecinos.erase(unique(vecinos.begin(), vecinos.end()), vecinos.end());
    }

    return adj;
}

vector<vector<int>> construirMatrizAdy(EdgeNode* edges, int n, bool directed) {
    if (n <= 0) {
        return {};
    }

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    EdgeNode* current = edges;
    while (current != nullptr) {
        int u = current->source;
        int v = current->destination;

        if (verticeValido(u, n) && verticeValido(v, n)) {
            matrix[u][v] = 1;

            if (!directed) {
                matrix[v][u] = 1;
            }
        }

        current = current->next;
    }

    return matrix;
}
```

## Correctitud

Cada nodo de la lista enlazada representa exactamente un arco. El algoritmo recorre todos esos nodos una vez.

Si el grafo es dirigido, insertar solo `u -> v` conserva la orientación original del arco. Si el grafo es no dirigido, agregar también `v -> u` representa correctamente que la arista puede recorrerse en ambos sentidos.

La matriz queda correcta porque `matrix[u][v] = 1` se asigna exactamente cuando existe el arco `u -> v`. La lista de adyacencia queda correcta porque cada vecino `v` se inserta en la lista de vecinos de `u`.

El ordenamiento final no cambia el conjunto de vecinos; solo fija el orden ascendente pedido por la convención.

## Complejidad

Sea `V = n` y `E` la cantidad de nodos en la lista de arcos.

- Construir la matriz cuesta `O(V^2 + E)`, porque se inicializa una matriz `V x V`.
- Construir la lista cuesta `O(V + E + S)`, donde `S` es el costo de ordenar las listas de vecinos.
- En total, `S <= O(E log E)` como cota simple.
- Espacio de matriz: `O(V^2)`.
- Espacio de lista de adyacencia: `O(V + E)`.

---

# Problema 2: consultas y grados con matriz de adyacencia

## Idea

En una matriz de adyacencia dirigida:

- `matrix[u][v]` indica si existe el arco `u -> v`;
- la fila `u` contiene los arcos que salen de `u`;
- la columna `v` contiene los arcos que entran a `v`.

## Solución

```cpp
bool existeArcoMatriz(const vector<vector<int>>& matrix, int u, int v) {
    int n = static_cast<int>(matrix.size());

    if (!matrizCuadrada(matrix) || !verticeValido(u, n) || !verticeValido(v, n)) {
        return false;
    }

    return matrix[u][v] != 0;
}

int gradoSalidaMatriz(const vector<vector<int>>& matrix, int v) {
    int n = static_cast<int>(matrix.size());

    if (!matrizCuadrada(matrix) || !verticeValido(v, n)) {
        return 0;
    }

    int grado = 0;
    for (int j = 0; j < n; j++) {
        if (matrix[v][j] != 0) {
            grado++;
        }
    }

    return grado;
}

int gradoEntradaMatriz(const vector<vector<int>>& matrix, int v) {
    int n = static_cast<int>(matrix.size());

    if (!matrizCuadrada(matrix) || !verticeValido(v, n)) {
        return 0;
    }

    int grado = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[i][v] != 0) {
            grado++;
        }
    }

    return grado;
}

vector<int> vecinosSalidaMatriz(const vector<vector<int>>& matrix, int v) {
    int n = static_cast<int>(matrix.size());
    vector<int> vecinos;

    if (!matrizCuadrada(matrix) || !verticeValido(v, n)) {
        return vecinos;
    }

    for (int j = 0; j < n; j++) {
        if (matrix[v][j] != 0) {
            vecinos.push_back(j);
        }
    }

    return vecinos;
}
```

## Correctitud

Por definición de matriz de adyacencia, existe un arco `u -> v` si y solo si la celda `matrix[u][v]` es distinta de cero. Por eso `existeArcoMatriz` revisa exactamente esa celda.

El grado de salida de `v` cuenta los arcos que salen desde `v`; esos arcos están en la fila `v`. El grado de entrada cuenta los arcos que llegan hacia `v`; esos arcos están en la columna `v`.

`vecinosSalidaMatriz` recorre la fila `v` de izquierda a derecha. Por eso retorna los vecinos en orden ascendente.

## Complejidad

- `existeArcoMatriz`: `O(1)` si no contamos la validación de matriz cuadrada.
- `gradoSalidaMatriz`: `O(V)`.
- `gradoEntradaMatriz`: `O(V)`.
- `vecinosSalidaMatriz`: `O(V)`.
- La matriz ocupa `O(V^2)` memoria.

Si se valida que la matriz sea cuadrada en cada llamada, esa validación cuesta `O(V)`. En una implementación de producción, esa validación podría hacerse una sola vez antes de realizar muchas consultas.

---

# Problema 3: BFS y distancias mínimas en grafos no ponderados

## Idea

BFS usa una cola. Primero procesa el origen, luego todos los vértices a distancia `1`, luego todos los vértices a distancia `2`, y así sucesivamente.

Por eso, cuando BFS descubre un vértice por primera vez, la distancia registrada es mínima en cantidad de arcos.

## Solución

```cpp
vector<int> bfsOrden(const vector<vector<int>>& adj, int start) {
    int n = static_cast<int>(adj.size());
    vector<int> order;

    if (!verticeValido(start, n)) {
        return order;
    }

    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u);

        for (int v : adj[u]) {
            if (verticeValido(v, n) && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return order;
}

vector<int> distanciasBFS(const vector<vector<int>>& adj, int start) {
    int n = static_cast<int>(adj.size());
    vector<int> dist(n, -1);

    if (!verticeValido(start, n)) {
        return dist;
    }

    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (verticeValido(v, n) && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}
```

## Correctitud

La cola mantiene el orden de descubrimiento. Cuando un vértice `u` con distancia `d` se procesa, sus vecinos no visitados reciben distancia `d + 1`.

BFS procesa todos los vértices de distancia `d` antes de procesar cualquier vértice de distancia `d + 1`. Por tanto, si un vértice `v` se descubre por primera vez con distancia `k`, no puede existir un camino más corto hacia `v`; de existir, BFS lo habría descubierto en una capa anterior.

Así, `distanciasBFS` asigna a cada vértice alcanzable su distancia mínima y deja en `-1` a los no alcanzables.

## Complejidad

Sea `V` la cantidad de vértices y `E` la cantidad de arcos.

- Tiempo: `O(V + E)`, porque cada vértice se encola a lo más una vez y cada arco se revisa al recorrer la lista de vecinos.
- Espacio adicional: `O(V)` por el vector de visitados o distancias y la cola.

---

# Problema 4: DFS recursivo, DFS iterativo y alcanzabilidad

## Idea

DFS profundiza por un vecino antes de volver a intentar el siguiente. En la versión recursiva, el lenguaje administra el retroceso con la pila de llamadas. En la versión iterativa, se usa `std::stack<int>`.

Para que la versión iterativa respete el mismo orden que la recursiva, se apilan los vecinos en orden inverso. Como la pila es LIFO, el vecino menor queda arriba y se procesa primero.

## Solución recursiva

```cpp
void dfsRecAux(const vector<vector<int>>& adj,
               int u,
               vector<bool>& visited,
               vector<int>& order) {
    int n = static_cast<int>(adj.size());

    if (!verticeValido(u, n) || visited[u]) {
        return;
    }

    visited[u] = true;
    order.push_back(u);

    for (int v : adj[u]) {
        if (verticeValido(v, n) && !visited[v]) {
            dfsRecAux(adj, v, visited, order);
        }
    }
}

vector<int> dfsRecursivo(const vector<vector<int>>& adj, int start) {
    int n = static_cast<int>(adj.size());
    vector<int> order;

    if (!verticeValido(start, n)) {
        return order;
    }

    vector<bool> visited(n, false);
    dfsRecAux(adj, start, visited, order);

    return order;
}
```

## Solución iterativa

```cpp
vector<int> dfsIterativo(const vector<vector<int>>& adj, int start) {
    int n = static_cast<int>(adj.size());
    vector<int> order;

    if (!verticeValido(start, n)) {
        return order;
    }

    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!verticeValido(u, n) || visited[u]) {
            continue;
        }

        visited[u] = true;
        order.push_back(u);

        for (int i = static_cast<int>(adj[u].size()) - 1; i >= 0; i--) {
            int v = adj[u][i];

            if (verticeValido(v, n) && !visited[v]) {
                st.push(v);
            }
        }
    }

    return order;
}
```

## Alcanzabilidad con DFS

```cpp
bool existeCaminoDFS(const vector<vector<int>>& adj, int src, int dst) {
    int n = static_cast<int>(adj.size());

    if (!verticeValido(src, n) || !verticeValido(dst, n)) {
        return false;
    }

    if (src == dst) {
        return true;
    }

    vector<bool> visited(n, false);
    stack<int> st;

    st.push(src);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!verticeValido(u, n) || visited[u]) {
            continue;
        }

        if (u == dst) {
            return true;
        }

        visited[u] = true;

        for (int i = static_cast<int>(adj[u].size()) - 1; i >= 0; i--) {
            int v = adj[u][i];

            if (verticeValido(v, n) && !visited[v]) {
                st.push(v);
            }
        }
    }

    return false;
}
```

## Correctitud

En la versión recursiva, cada llamada procesa un vértice no visitado, lo marca y luego explora sus vecinos. Por inducción sobre la profundidad de la recursión, se visitan exactamente los vértices alcanzables desde `start`.

En la versión iterativa, la pila almacena vértices pendientes de explorar. Al desapilar un vértice ya visitado, se ignora; al desapilar uno no visitado, se procesa y se agregan sus vecinos pendientes. Apilar en orden inverso reproduce la prioridad de vecinos ascendentes.

`existeCaminoDFS` retorna `true` si llega a desapilar `dst`. Eso ocurre exactamente cuando `dst` es alcanzable desde `src`, porque la pila solo recibe vértices descubiertos desde vértices ya alcanzables.

## Complejidad

- Tiempo: `O(V + E)`.
- Espacio recursivo: `O(V)` en el peor caso por la pila de llamadas.
- Espacio iterativo: `O(V)` en el peor caso por la pila explícita.

---

# Problema 5: componentes conexas y ciclos en grafos no dirigidos

## Idea

Para contar componentes, se recorre todo el conjunto de vértices. Cada vez que aparece un vértice no visitado, se inicia un DFS nuevo. Ese DFS marca exactamente una componente.

Para detectar ciclos en grafos no dirigidos, no basta con encontrar un vecino visitado. El vecino visitado puede ser el padre inmediato. Solo hay ciclo si se encuentra un vecino visitado que no es el padre.

## Solución

```cpp
int contarComponentes(const vector<vector<int>>& adj) {
    int n = static_cast<int>(adj.size());
    vector<bool> visited(n, false);
    int componentes = 0;

    for (int start = 0; start < n; start++) {
        if (visited[start]) {
            continue;
        }

        componentes++;

        stack<int> st;
        st.push(start);
        visited[start] = true;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            for (int v : adj[u]) {
                if (verticeValido(v, n) && !visited[v]) {
                    visited[v] = true;
                    st.push(v);
                }
            }
        }
    }

    return componentes;
}

bool tieneCicloNoDirigido(const vector<vector<int>>& adj) {
    int n = static_cast<int>(adj.size());
    vector<bool> visited(n, false);

    for (int start = 0; start < n; start++) {
        if (visited[start]) {
            continue;
        }

        stack<pair<int, int>> st;
        st.push({start, -1});
        visited[start] = true;

        while (!st.empty()) {
            int u = st.top().first;
            int parent = st.top().second;
            st.pop();

            for (int v : adj[u]) {
                if (!verticeValido(v, n)) {
                    continue;
                }

                if (!visited[v]) {
                    visited[v] = true;
                    st.push({v, u});
                } else if (v != parent) {
                    return true;
                }
            }
        }
    }

    return false;
}
```

## Correctitud

Para componentes conexas, si `start` no está visitado, ningún vértice ya procesado puede alcanzarlo; de lo contrario, habría sido marcado durante un recorrido anterior. El DFS iniciado en `start` marca todos los vértices alcanzables desde él, es decir, toda su componente. Por tanto, cada incremento de `componentes` corresponde a una componente distinta.

Para ciclos, cuando se explora una arista no dirigida `{u, v}`, puede ocurrir que `v` sea el padre de `u`; eso solo representa volver por la misma arista. Si `v` ya fue visitado y `v != parent`, entonces existe una ruta previa desde el inicio de la componente hasta `v`, además del camino actual hasta `u` y la arista `{u, v}`. Eso forma un ciclo.

## Complejidad

- Tiempo: `O(V + E)`.
- Espacio adicional: `O(V)`.

En un grafo no dirigido representado por lista de adyacencia, cada arista aparece dos veces en las listas, pero eso sigue siendo proporcional a `E`.

---

# Problema 6: vértices que pertenecen a algún camino usando BFS y DFS

## Idea

Un vértice `v` pertenece a algún camino desde `src` hasta `dst` si cumple simultáneamente:

```text
src puede llegar a v
v puede llegar a dst
```

La primera condición se obtiene con BFS desde `src`.

Para la segunda condición, se invierten todos los arcos. Entonces:

```text
v puede llegar a dst en el grafo original
```

es equivalente a:

```text
dst puede llegar a v en el grafo invertido
```

Esa segunda marca se obtiene con DFS desde `dst` sobre el grafo invertido.

## Solución

```cpp
vector<bool> alcanzablesBFS(const vector<vector<int>>& adj, int start) {
    int n = static_cast<int>(adj.size());
    vector<bool> visited(n, false);

    if (!verticeValido(start, n)) {
        return visited;
    }

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (verticeValido(v, n) && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return visited;
}

vector<vector<int>> invertirGrafo(const vector<vector<int>>& adj) {
    int n = static_cast<int>(adj.size());
    vector<vector<int>> reversed(n);

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (verticeValido(v, n)) {
                reversed[v].push_back(u);
            }
        }
    }

    for (vector<int>& vecinos : reversed) {
        sort(vecinos.begin(), vecinos.end());
        vecinos.erase(unique(vecinos.begin(), vecinos.end()), vecinos.end());
    }

    return reversed;
}

vector<bool> alcanzablesDFS(const vector<vector<int>>& adj, int start) {
    int n = static_cast<int>(adj.size());
    vector<bool> visited(n, false);

    if (!verticeValido(start, n)) {
        return visited;
    }

    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!verticeValido(u, n) || visited[u]) {
            continue;
        }

        visited[u] = true;

        for (int i = static_cast<int>(adj[u].size()) - 1; i >= 0; i--) {
            int v = adj[u][i];

            if (verticeValido(v, n) && !visited[v]) {
                st.push(v);
            }
        }
    }

    return visited;
}

vector<int> verticesEnAlgunCamino(const vector<vector<int>>& adj, int src, int dst) {
    int n = static_cast<int>(adj.size());
    vector<int> result;

    if (!verticeValido(src, n) || !verticeValido(dst, n)) {
        return result;
    }

    vector<bool> desdeSrc = alcanzablesBFS(adj, src);
    vector<vector<int>> reversed = invertirGrafo(adj);
    vector<bool> haciaDst = alcanzablesDFS(reversed, dst);

    for (int v = 0; v < n; v++) {
        if (desdeSrc[v] && haciaDst[v]) {
            result.push_back(v);
        }
    }

    return result;
}
```

## Correctitud

Primero, `alcanzablesBFS(adj, src)` marca exactamente los vértices alcanzables desde `src`, por la correctitud de BFS.

Luego, `invertirGrafo` cambia cada arco `u -> v` por `v -> u`. Por tanto, existe un camino `v -> ... -> dst` en el grafo original si y solo si existe un camino `dst -> ... -> v` en el grafo invertido. Entonces `alcanzablesDFS(reversed, dst)` marca exactamente los vértices que pueden llegar a `dst` en el grafo original.

Un vértice `v` pertenece a algún camino desde `src` hasta `dst` si y solo si ambas condiciones son verdaderas:

- `src` puede llegar a `v`;
- `v` puede llegar a `dst`.

El algoritmo agrega exactamente los vértices que cumplen ambas condiciones, por lo que la respuesta es correcta.

## Complejidad

- BFS desde `src`: `O(V + E)`.
- Construcción del grafo invertido: `O(V + E)`, más el ordenamiento de vecinos si se requiere orden fijo.
- DFS desde `dst` en el grafo invertido: `O(V + E)`.
- Intersección de marcas: `O(V)`.

Sin contar el ordenamiento opcional de vecinos, la complejidad temporal total es `O(V + E)`.

El espacio auxiliar es `O(V + E)` por el grafo invertido y los vectores de visitados.

---

# Resumen comparativo

| Problema | Representación principal | Recorrido | Estructura auxiliar | Complejidad temporal |
| --- | --- | --- | --- | --- |
| Convertir lista de arcos | Lista de arcos | Recorrido de arcos | `vector<vector<int>>` | `O(V^2 + E)` para matriz |
| Consultas en matriz | Matriz de adyacencia | Fila o columna | ninguna relevante | `O(1)` arco, `O(V)` grado |
| BFS y distancias | Lista de adyacencia | BFS | `queue` | `O(V + E)` |
| DFS y camino | Lista de adyacencia | DFS | recursión o `stack` | `O(V + E)` |
| Componentes y ciclos | Lista de adyacencia | DFS | `stack`, padre | `O(V + E)` |
| Vértices en algún camino | Lista de adyacencia e inversa | BFS + DFS | `queue`, `stack` | `O(V + E)` |

# Errores frecuentes

- Confundir lista de arcos con lista de adyacencia.
- Tratar un grafo dirigido como si fuera no dirigido.
- Olvidar que en matriz `matrix[u][v]` y `matrix[v][u]` pueden ser distintos.
- Marcar visitado demasiado tarde en BFS y encolar muchas copias del mismo vértice.
- Usar DFS para distancia mínima en grafo no ponderado.
- En un grafo no dirigido, considerar al padre como si fuera un ciclo.
- Enumerar todos los caminos cuando solo se necesita saber alcanzabilidad.
- Olvidar casos inválidos como vértices fuera de rango o grafo vacío.
