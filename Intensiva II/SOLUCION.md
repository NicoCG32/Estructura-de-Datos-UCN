# SOLUCIÓN - Intensiva II

Este archivo contiene el desarrollo de los ejercicios propuestos en `README.md`.

La pauta está escrita para que no solo se vea el resultado final, sino también el tipo de recorrido o estrategia que justifica cada solución. Esto es importante porque en PP2 aparecen recorridos tanto en árboles como en grafos:

- en árboles, DFS aparece como preorden, inorden, postorden o como recorrido con pila explícita;
- en árboles, BFS aparece como recorrido por niveles usando cola;
- en grafos, DFS se usa para exploración profunda y alcanzabilidad;
- en grafos, BFS se usa para exploración por capas, caminos mínimos no ponderados y orden topológico con cola.

## Mapa de recorridos usados

| Ejercicio | Estructura | Recorrido o estrategia | Estructura auxiliar principal |
| --- | --- | --- | --- |
| 1 | Heap | Heapify manual | Arreglo |
| 2 | AVL | Rebalanceo por alturas | Rotaciones |
| 3 | ABB | DFS iterativo con poda | `stack` |
| 4 | Árbol binario | BFS por niveles + impresión zigzag | `queue` |
| 5 | Grafo con matriz | BFS con padres | `queue` |
| 6 | Grafo con lista de adyacencia | DFS iterativo | `stack` |
| 7 | Grafo con lista de arcos | BFS con padres | `queue` |
| 8 | Grafo dirigido | BFS topológico, algoritmo de Kahn | `queue` |

---

# Ejercicio 1 - HeapSort manual

Arreglo inicial:

```txt
[16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
```

Se trabajará con indexación desde 1:

```txt
i:   1   2   3   4   5   6   7   8   9   10
A: [16,  4, 10, 14,  7,  9,  3,  2,  8,  1]
```

Para un heap indexado desde 1:

```txt
hijo izquierdo = 2i
hijo derecho   = 2i + 1
padre          = i / 2
```

Como `n = 10`, la construcción del heap inicia en:

```txt
n/2 = 5
```

## Construcción del Max-Heap

### heapify(5)

Nodo actual: `7`.

Hijo izquierdo: `1`.

Como `7 > 1`, no se intercambia.

```txt
[16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
```

### heapify(4)

Nodo actual: `14`.

Hijos: `2` y `8`.

Como `14` es mayor que ambos, no se intercambia.

```txt
[16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
```

### heapify(3)

Nodo actual: `10`.

Hijos: `9` y `3`.

Como `10` es mayor que ambos, no se intercambia.

```txt
[16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
```

### heapify(2)

Nodo actual: `4`.

Hijos: `14` y `7`.

El mayor es `14`, por lo tanto se intercambia `4` con `14`.

```txt
[16, 14, 10, 4, 7, 9, 3, 2, 8, 1]
```

Ahora el `4` quedó en la posición 4.

Sus hijos son `2` y `8`.

El mayor es `8`, por lo tanto se intercambia `4` con `8`.

```txt
[16, 14, 10, 8, 7, 9, 3, 2, 4, 1]
```

### heapify(1)

Nodo actual: `16`.

Hijos: `14` y `10`.

Como `16` es mayor que ambos, no se intercambia.

Max-Heap construido:

```txt
[16, 14, 10, 8, 7, 9, 3, 2, 4, 1]
```

---

## Extracciones

En cada extracción se intercambia la raíz con el último elemento del heap activo.

### Extracción 1

Se intercambia `16` con `1`.

```txt
[1, 14, 10, 8, 7, 9, 3, 2, 4, 16]
```

Se aplica `heapify` sobre los primeros 9 elementos:

```txt
1 < 14  -> intercambio
[14, 1, 10, 8, 7, 9, 3, 2, 4, 16]

1 < 8   -> intercambio
[14, 8, 10, 1, 7, 9, 3, 2, 4, 16]

1 < 4   -> intercambio
[14, 8, 10, 4, 7, 9, 3, 2, 1, 16]
```

### Extracción 2

Se intercambia `14` con `1`.

```txt
[1, 8, 10, 4, 7, 9, 3, 2, 14, 16]
```

Heapify sobre 8 elementos:

```txt
1 < 10  -> intercambio
[10, 8, 1, 4, 7, 9, 3, 2, 14, 16]

1 < 9   -> intercambio
[10, 8, 9, 4, 7, 1, 3, 2, 14, 16]
```

### Extracción 3

Se intercambia `10` con `2`.

```txt
[2, 8, 9, 4, 7, 1, 3, 10, 14, 16]
```

Heapify sobre 7 elementos:

```txt
2 < 9   -> intercambio
[9, 8, 2, 4, 7, 1, 3, 10, 14, 16]

2 < 3   -> intercambio
[9, 8, 3, 4, 7, 1, 2, 10, 14, 16]
```

### Extracción 4

Se intercambia `9` con `2`.

```txt
[2, 8, 3, 4, 7, 1, 9, 10, 14, 16]
```

Heapify sobre 6 elementos:

```txt
2 < 8   -> intercambio
[8, 2, 3, 4, 7, 1, 9, 10, 14, 16]

2 < 7   -> intercambio
[8, 7, 3, 4, 2, 1, 9, 10, 14, 16]
```

### Extracción 5

Se intercambia `8` con `1`.

```txt
[1, 7, 3, 4, 2, 8, 9, 10, 14, 16]
```

Heapify sobre 5 elementos:

```txt
1 < 7   -> intercambio
[7, 1, 3, 4, 2, 8, 9, 10, 14, 16]

1 < 4   -> intercambio
[7, 4, 3, 1, 2, 8, 9, 10, 14, 16]
```

### Extracción 6

Se intercambia `7` con `2`.

```txt
[2, 4, 3, 1, 7, 8, 9, 10, 14, 16]
```

Heapify sobre 4 elementos:

```txt
2 < 4   -> intercambio
[4, 2, 3, 1, 7, 8, 9, 10, 14, 16]
```

### Extracción 7

Se intercambia `4` con `1`.

```txt
[1, 2, 3, 4, 7, 8, 9, 10, 14, 16]
```

Heapify sobre 3 elementos:

```txt
1 < 3   -> intercambio
[3, 2, 1, 4, 7, 8, 9, 10, 14, 16]
```

### Extracción 8

Se intercambia `3` con `1`.

```txt
[1, 2, 3, 4, 7, 8, 9, 10, 14, 16]
```

Heapify sobre 2 elementos:

```txt
1 < 2   -> intercambio
[2, 1, 3, 4, 7, 8, 9, 10, 14, 16]
```

### Extracción 9

Se intercambia `2` con `1`.

```txt
[1, 2, 3, 4, 7, 8, 9, 10, 14, 16]
```

Resultado final:

```txt
[1, 2, 3, 4, 7, 8, 9, 10, 14, 16]
```

## Complejidad

```txt
Construcción del heap: O(n)
Extracciones:          O(n log n)
Total:                 O(n log n)
Espacio extra:         O(1)
```

---

# Ejercicio 2 - AVL manual

Convención:

```txt
FB(nodo) = altura(izquierdo) - altura(derecho)
```

Un nodo está balanceado si:

```txt
FB = -1, 0 o 1
```

---

## Inserciones

### Insertar 50

```txt
50
```

### Insertar 30

```txt
   50
  /
30
```

### Insertar 70

```txt
   50
  /  \
30    70
```

### Insertar 20

```txt
      50
     /  \
   30    70
  /
20
```

Sigue balanceado.

### Insertar 40

```txt
      50
     /  \
   30    70
  /  \
20   40
```

Sigue balanceado.

### Insertar 35

El `35` entra como hijo izquierdo de `40`.

```txt
        50
       /  \
     30    70
    /  \
  20    40
        /
       35
```

El primer nodo desbalanceado es `50`.

```txt
FB(50) = 2
FB(30) = -1
```

Caso:

```txt
Izquierda - Derecha
LR
```

Se aplica:

1. Rotación izquierda sobre `30`.
2. Rotación derecha sobre `50`.

Árbol después de la rotación LR:

```txt
        40
       /  \
     30    50
    / \     \
  20  35     70
```

### Insertar 45

```txt
        40
       /  \
     30    50
    / \   /  \
  20  35 45   70
```

Sigue balanceado.

### Insertar 80

```txt
        40
       /  \
     30    50
    / \   /  \
  20  35 45   70
                 \
                  80
```

Sigue balanceado.

### Insertar 75

El `75` entra como hijo izquierdo de `80`.

```txt
        40
       /  \
     30    50
    / \   /  \
  20  35 45   70
                 \
                  80
                 /
                75
```

El primer nodo desbalanceado es `70`.

```txt
FB(70) = -2
FB(80) = 1
```

Caso:

```txt
Derecha - Izquierda
RL
```

Se aplica:

1. Rotación derecha sobre `80`.
2. Rotación izquierda sobre `70`.

Árbol después de la rotación RL:

```txt
        40
       /  \
     30    50
    / \   /  \
  20  35 45   75
              /  \
             70   80
```

---

## Eliminaciones

Árbol antes de eliminar:

```txt
        40
       /  \
     30    50
    / \   /  \
  20  35 45   75
              /  \
             70   80
```

### Eliminar 20

El `20` es hoja.

```txt
        40
       /  \
     30    50
       \   /  \
       35 45   75
              /  \
             70   80
```

No se requiere rotación.

### Eliminar 70

El `70` es hoja.

```txt
        40
       /  \
     30    50
       \   /  \
       35 45   75
                    \
                     80
```

No se requiere rotación.

### Eliminar 30

El `30` posee solo hijo derecho `35`, por lo tanto se reemplaza directamente por `35`.

Árbol temporal:

```txt
        40
       /  \
     35    50
           /  \
          45   75
                 \
                  80
```

Ahora el nodo `40` queda desbalanceado:

```txt
FB(40) = -2
FB(50) = -1
```

Caso:

```txt
Derecha - Derecha
RR
```

Se aplica rotación izquierda sobre `40`.

Árbol final:

```txt
        50
       /  \
     40    75
    /  \     \
   35  45     80
```

---

# Ejercicio 3 - ABB: suma condicionada en rango

Árbol:

```txt
          10
        /    \
       5      15
      / \    /  \
     3   7  13   18
        /     \
       6       14
```

Rango:

```txt
[6, 15]
```

Valores dentro del rango:

```txt
6, 7, 10, 13, 14, 15
```

Se excluyen múltiplos de 5:

```txt
10, 15
```

Suma:

```txt
6 + 7 + 13 + 14 = 40
```

## Recorrido utilizado

La solución principal usa **DFS iterativo con `stack`**.

No se necesita BFS porque no interesa procesar por niveles ni encontrar distancia mínima. Lo importante es visitar nodos candidatos del ABB y descartar subárboles completos usando la propiedad de orden:

- si `actual->val <= low`, el subárbol izquierdo no puede aportar valores mayores o iguales a `low`;
- si `actual->val >= high`, el subárbol derecho no puede aportar valores menores o iguales a `high`;
- si el valor está dentro del rango y no es múltiplo de `5`, se suma.

## Estructura del nodo

```cpp
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~TreeNode() {}
};
```

## Solución iterativa: DFS con pila y poda ABB

```cpp
#include <iostream>
#include <stack>
using namespace std;

int sumaRangoABB(TreeNode* root, int low, int high) {
    if (root == nullptr || low > high) {
        return 0;
    }

    stack<TreeNode*> pila;
    pila.push(root);

    int suma = 0;

    while (!pila.empty()) {
        TreeNode* actual = pila.top();
        pila.pop();

        if (actual->val >= low && actual->val <= high && actual->val % 5 != 0) {
            suma = suma + actual->val;
        }

        if (actual->left != nullptr && actual->val > low) {
            pila.push(actual->left);
        }

        if (actual->right != nullptr && actual->val < high) {
            pila.push(actual->right);
        }
    }

    return suma;
}
```

## Solución recursiva alternativa

```cpp
int sumaRangoABBRec(TreeNode* root, int low, int high) {
    if (root == nullptr || low > high) {
        return 0;
    }

    if (root->val < low) {
        return sumaRangoABBRec(root->right, low, high);
    }

    if (root->val > high) {
        return sumaRangoABBRec(root->left, low, high);
    }

    int suma = 0;

    if (root->val % 5 != 0) {
        suma = root->val;
    }

    suma = suma + sumaRangoABBRec(root->left, low, high);
    suma = suma + sumaRangoABBRec(root->right, low, high);

    return suma;
}
```

La versión recursiva también es DFS. La diferencia es que la pila no aparece escrita en el código, porque la maneja internamente la recursión.

## Complejidad

```txt
Tiempo:  O(n) en el peor caso
Espacio: O(h) por pila o recursión
```

Donde `h` es la altura del árbol.

---

# Ejercicio 4 - Árbol binario: recorrido zigzag con suma por nivel

Árbol:

```txt
          8
        /   \
       3     10
      / \      \
     1   6      14
        / \    /
       4   7  13
```

Recorrido esperado:

```txt
Nivel 1: 8
Nivel 2: 10 3
Nivel 3: 1 6 14
Nivel 4: 13 7 4
```

Sumas:

```txt
Nivel 1: 8
Nivel 2: 13
Nivel 3: 21
Nivel 4: 24
```

Por lo tanto:

```txt
Nivel con mayor suma: 4
Mayor suma: 24
```

## Recorrido utilizado

La solución usa **BFS en árbol**, también llamado **recorrido por niveles**.

La cola mantiene el orden natural de los niveles: primero se procesan los nodos del nivel actual y, mientras se procesan, se encolan los hijos que formarán el nivel siguiente. El zigzag no cambia el recorrido base; solo cambia el orden en que se imprime el vector de valores de cada nivel.

## Solución iterativa: BFS por niveles con queue

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void zigzagConSuma(TreeNode* root) {
    if (root == nullptr) {
        cout << "Arbol vacio" << endl;
        return;
    }

    queue<TreeNode*> cola;
    cola.push(root);

    bool izquierdaDerecha = true;
    int numeroNivel = 1;

    int mayorSuma = 0;
    int nivelMayorSuma = 1;
    bool primeraSuma = true;

    while (!cola.empty()) {
        int cantidad = static_cast<int>(cola.size());
        vector<int> nivel;
        int sumaNivel = 0;

        for (int i = 0; i < cantidad; i++) {
            TreeNode* actual = cola.front();
            cola.pop();

            nivel.push_back(actual->val);
            sumaNivel = sumaNivel + actual->val;

            if (actual->left != nullptr) {
                cola.push(actual->left);
            }

            if (actual->right != nullptr) {
                cola.push(actual->right);
            }
        }

        cout << "Nivel " << numeroNivel << ": ";

        if (izquierdaDerecha) {
            for (int i = 0; i < (int)nivel.size(); i++) {
                cout << nivel[i] << " ";
            }
        } else {
            for (int i = (int)nivel.size() - 1; i >= 0; i--) {
                cout << nivel[i] << " ";
            }
        }

        cout << "| suma = " << sumaNivel << endl;

        if (primeraSuma || sumaNivel > mayorSuma) {
            mayorSuma = sumaNivel;
            nivelMayorSuma = numeroNivel;
            primeraSuma = false;
        }

        izquierdaDerecha = !izquierdaDerecha;
        numeroNivel++;
    }

    cout << "Nivel con mayor suma: " << nivelMayorSuma << endl;
    cout << "Mayor suma: " << mayorSuma << endl;
}
```

## Complejidad

```txt
Tiempo:  O(n)
Espacio: O(n)
```

---

# Ejercicio 5 - Matriz de adyacencia: BFS con vértice bloqueado

Vértices:

```txt
A=0, B=1, C=2, D=3, E=4, F=5, G=6, H=7
```

Vértice bloqueado:

```txt
E = 4
```

BFS desde `A` hasta `H` evitando `E`.

Un camino mínimo válido es:

```txt
A -> B -> D -> F -> G -> H
```

Distancia:

```txt
5 arcos
```

## Recorrido utilizado

La solución usa **BFS en grafo no ponderado**.

La razón es que se pide el camino con menor cantidad de arcos. BFS visita primero los vértices a distancia `1`, luego los de distancia `2`, luego los de distancia `3`, y así sucesivamente. Por eso, la primera vez que se descubre `H`, el camino reconstruido con el vector `padre` tiene distancia mínima.

La matriz de adyacencia cambia la forma de buscar vecinos: para saber a qué vértices se puede mover desde `actual`, se recorre toda la fila `matriz[actual]`.

## Solución: BFS con matriz de adyacencia

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> caminoBFSMatriz(vector<vector<int> > matriz, int origen, int destino, int bloqueado) {
    int n = matriz.size();

    vector<int> visitado(n, 0);
    vector<int> padre(n, -1);
    vector<int> camino;

    if (origen < 0 || origen >= n || destino < 0 || destino >= n) {
        return camino;
    }

    if (origen == bloqueado || destino == bloqueado) {
        return camino;
    }

    queue<int> cola;
    cola.push(origen);
    visitado[origen] = 1;

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        if (actual == destino) {
            break;
        }

        for (int vecino = 0; vecino < n; vecino++) {
            if (matriz[actual][vecino] == 1 &&
                visitado[vecino] == 0 &&
                vecino != bloqueado) {

                visitado[vecino] = 1;
                padre[vecino] = actual;
                cola.push(vecino);
            }
        }
    }

    if (visitado[destino] == 0) {
        return camino;
    }

    int cursor = destino;

    while (cursor != -1) {
        camino.push_back(cursor);
        cursor = padre[cursor];
    }

    vector<int> caminoOrdenado;

    for (int i = (int)camino.size() - 1; i >= 0; i--) {
        caminoOrdenado.push_back(camino[i]);
    }

    return caminoOrdenado;
}
```

## Ruteo resumido

Inicio:

```txt
cola = [A]
visitados = A
```

Desde `A` se descubren:

```txt
B, C
```

Desde `B` se descubre:

```txt
D
```

Desde `C` no se puede usar `E`, porque está bloqueado.

Desde `D` se descubre:

```txt
F
```

Desde `F` se descubre:

```txt
G
```

Desde `G` se descubre:

```txt
H
```

Camino reconstruido:

```txt
A -> B -> D -> F -> G -> H
```

## Complejidad

Con matriz de adyacencia:

```txt
Tiempo:  O(n^2)
Espacio: O(n)
```

---

# Ejercicio 6 - Lista de adyacencia: DFS iterativo con llaves

Lista de adyacencia:

```txt
0: 1, 2
1: 3
2: 4
3: 5
4:
5:
```

Desde la sala `0` sí se pueden visitar todas las salas.

## Recorrido utilizado

La solución usa **DFS iterativo en grafo dirigido**.

Cada sala es un vértice y cada llave representa un arco dirigido hacia otra sala. Se usa una pila porque basta con explorar profundamente las salas alcanzables desde la sala `0`; no se necesita distancia mínima. BFS también serviría para decidir alcanzabilidad, pero aquí se practica explícitamente DFS con `stack`.

## Solución: DFS iterativo con lista de adyacencia

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool puedeVisitarTodas(vector<vector<int> > rooms) {
    int n = rooms.size();

    if (n == 0) {
        return true;
    }

    vector<int> visitado(n, 0);
    stack<int> pila;

    pila.push(0);
    visitado[0] = 1;

    while (!pila.empty()) {
        int sala = pila.top();
        pila.pop();

        for (int i = 0; i < (int)rooms[sala].size(); i++) {
            int llave = rooms[sala][i];

            if (llave >= 0 && llave < n && visitado[llave] == 0) {
                visitado[llave] = 1;
                pila.push(llave);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (visitado[i] == 0) {
            return false;
        }
    }

    return true;
}
```

## Ruteo posible

Dependiendo del orden de la pila, un recorrido posible es:

```txt
0, 2, 4, 1, 3, 5
```

Todas las salas quedan visitadas, por lo tanto:

```txt
true
```

## Complejidad

```txt
Tiempo:  O(V + E)
Espacio: O(V)
```

Donde:

```txt
V = cantidad de salas
E = cantidad de llaves
```

---

# Ejercicio 7 - Lista de arcos: existencia de camino

Lista de arcos no dirigida:

```txt
0 - 1
0 - 2
1 - 4
2 - 3
3 - 5
4 - 5
```

Se busca camino desde:

```txt
origen = 0
destino = 5
```

Un camino válido es:

```txt
0 -> 1 -> 4 -> 5
```

## Recorrido utilizado

La solución usa **BFS en grafo no dirigido no ponderado**.

Aunque el enunciado pide existencia de camino, se pide además reconstruir un camino válido. BFS permite guardar un vector `padre` y reconstruir el camino desde el destino hacia el origen. Además, como el grafo no tiene pesos, el camino que entrega BFS tiene mínima cantidad de aristas.

La representación por lista de arcos no entrega directamente los vecinos de un vértice. Por eso, cada vez que se procesa un vértice, se recorre la lista completa de arcos para encontrar los arcos incidentes.

## Clase del arco

```cpp
class EdgeNode {
public:
    int source;
    int destination;
    EdgeNode* next;

    EdgeNode(int source, int destination) {
        this->source = source;
        this->destination = destination;
        this->next = nullptr;
    }

    ~EdgeNode() {}
};
```

## Solución con BFS recorriendo lista de arcos

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> caminoListaArcos(EdgeNode* head, int n, int origen, int destino) {
    vector<int> visitado(n, 0);
    vector<int> padre(n, -1);
    vector<int> camino;

    if (n <= 0 || origen < 0 || origen >= n || destino < 0 || destino >= n) {
        return camino;
    }

    if (origen == destino) {
        camino.push_back(origen);
        return camino;
    }

    queue<int> cola;
    cola.push(origen);
    visitado[origen] = 1;

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        if (actual == destino) {
            break;
        }

        EdgeNode* cursor = head;

        while (cursor != nullptr) {
            int vecino = -1;

            if (cursor->source == actual) {
                vecino = cursor->destination;
            } else if (cursor->destination == actual) {
                vecino = cursor->source;
            }

            if (vecino >= 0 && vecino < n && visitado[vecino] == 0) {
                visitado[vecino] = 1;
                padre[vecino] = actual;
                cola.push(vecino);
            }

            cursor = cursor->next;
        }
    }

    if (visitado[destino] == 0) {
        return camino;
    }

    int cursorCamino = destino;

    while (cursorCamino != -1) {
        camino.push_back(cursorCamino);
        cursorCamino = padre[cursorCamino];
    }

    vector<int> caminoOrdenado;

    for (int i = (int)camino.size() - 1; i >= 0; i--) {
        caminoOrdenado.push_back(camino[i]);
    }

    return caminoOrdenado;
}
```

## Ruteo resumido

```txt
Inicio: 0
Desde 0 se descubren 1 y 2.
Desde 1 se descubre 4.
Desde 2 se descubre 3.
Desde 4 se descubre 5.
```

Camino reconstruido:

```txt
0 -> 1 -> 4 -> 5
```

## Complejidad

Como se recorre la lista de arcos cada vez que se procesa un nodo:

```txt
Tiempo:  O(V * E) en el peor caso
Espacio: O(V)
```

Esta complejidad es aceptable para el objetivo del ejercicio, porque busca practicar explícitamente la representación por lista de arcos.

---

# Ejercicio 8 - Orden de cursos con dependencias

Arcos dirigidos:

```txt
0 -> 1
0 -> 2
1 -> 3
2 -> 3
3 -> 4
4 -> 5
```

Interpretación:

```txt
Para tomar el curso destino, primero se debe tomar el curso origen.
```

Como no existe ciclo, sí es posible completar todos los cursos.

Un orden válido es:

```txt
0, 1, 2, 3, 4, 5
```

## Recorrido utilizado

La solución usa **BFS topológico**, conocido como **algoritmo de Kahn**.

La cola no representa distancia mínima, sino cursos disponibles: primero entran los cursos con grado de entrada `0`, es decir, cursos sin prerrequisitos pendientes. Cada vez que se procesa un curso, se "liberan" los cursos que dependían de él reduciendo su grado de entrada.

Si al final no se procesan todos los cursos, entonces algunos quedaron atrapados en un ciclo de dependencias.

## Clase del arco dirigido

Se puede usar la misma clase `EdgeNode`, interpretando:

```txt
source      = prerrequisito
destination = curso desbloqueado
```

```cpp
class EdgeNode {
public:
    int source;
    int destination;
    EdgeNode* next;

    EdgeNode(int source, int destination) {
        this->source = source;
        this->destination = destination;
        this->next = nullptr;
    }

    ~EdgeNode() {}
};
```

## Solución con lista de arcos + lista de adyacencia + BFS

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool ordenCursos(EdgeNode* head, int numCursos, vector<int>& orden) {
    orden.clear();

    if (numCursos < 0) {
        return false;
    }

    vector<vector<int> > adyacencia(numCursos);
    vector<int> gradoEntrada(numCursos, 0);

    EdgeNode* cursor = head;

    while (cursor != nullptr) {
        int origen = cursor->source;
        int destino = cursor->destination;

        if (origen >= 0 && origen < numCursos && destino >= 0 && destino < numCursos) {
            adyacencia[origen].push_back(destino);
            gradoEntrada[destino]++;
        }

        cursor = cursor->next;
    }

    queue<int> cola;

    for (int i = 0; i < numCursos; i++) {
        if (gradoEntrada[i] == 0) {
            cola.push(i);
        }
    }

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        orden.push_back(actual);

        for (int i = 0; i < (int)adyacencia[actual].size(); i++) {
            int vecino = adyacencia[actual][i];
            gradoEntrada[vecino]--;

            if (gradoEntrada[vecino] == 0) {
                cola.push(vecino);
            }
        }
    }

    if ((int)orden.size() == numCursos) {
        return true;
    }

    return false;
}
```

## Ruteo resumido

Grados de entrada iniciales:

```txt
curso 0: 0
curso 1: 1
curso 2: 1
curso 3: 2
curso 4: 1
curso 5: 1
```

Cola inicial:

```txt
[0]
```

Proceso:

```txt
Sale 0 -> libera 1 y 2
Sale 1 -> reduce grado de 3
Sale 2 -> libera 3
Sale 3 -> libera 4
Sale 4 -> libera 5
Sale 5 -> fin
```

Orden:

```txt
0 1 2 3 4 5
```

Como se procesaron los 6 cursos:

```txt
true
```

## Caso con ciclo

Si los arcos fueran:

```txt
0 -> 1
1 -> 2
2 -> 0
```

Todos los nodos tienen grado de entrada mayor que 0.

No habría nodo inicial para la cola.

Resultado:

```txt
false
```

## Complejidad

```txt
Tiempo:  O(V + E)
Espacio: O(V + E)
```

---

# Cierre técnico

Esta Intensiva II queda organizada de la siguiente forma:

```txt
HeapSort: manual.
AVL: manual.
Árboles: DFS con stack y BFS por niveles con queue.
Grafos: BFS, DFS y BFS topológico sobre matriz, lista de adyacencia y lista de arcos.
```

La intención no es memorizar código, sino reconocer:

1. Qué estructura representa el problema.
2. Qué recorrido corresponde.
3. Por qué ese recorrido corresponde.
4. Qué datos auxiliares son estrictamente necesarios.
5. Cuándo se usa `queue`, cuándo `stack` y cuándo basta recorrer una lista de arcos.
6. Cómo justificar la complejidad.

Regla de decisión rápida:

- usa **BFS** si el problema habla de niveles, capas o menor cantidad de arcos;
- usa **DFS** si el problema habla de explorar alcanzabilidad, subárboles o caminos sin exigir distancia mínima;
- usa **BFS topológico** si el problema habla de prerrequisitos y dependencias;
- usa la representación del enunciado, pero convierte a otra solo cuando el costo de hacerlo simplifica el algoritmo.
