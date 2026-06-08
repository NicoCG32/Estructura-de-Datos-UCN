# Ayudantía 9

## Contenido

- [Objetivo del bloque](#objetivo-del-bloque)
- [Estructura base](#estructura-base)
- [Árbol de referencia](#árbol-de-referencia)
- [Referencias de práctica](#referencias-de-práctica)
- [Problema 1: valores en rango dentro de un BST](#problema-1-valores-en-rango-dentro-de-un-bst)
- [Problema 2: validar si un árbol binario es BST](#problema-2-validar-si-un-árbol-binario-es-bst)
- [Problema 3: k-ésimo menor elemento en un BST](#problema-3-k-ésimo-menor-elemento-en-un-bst)
- [Problema 4: ancestro común más bajo en un BST](#problema-4-ancestro-común-más-bajo-en-un-bst)
- [Problema 5: recorrido por niveles de un árbol binario](#problema-5-recorrido-por-niveles-de-un-árbol-binario)
- [Problema 6: diámetro de un árbol binario](#problema-6-diámetro-de-un-árbol-binario)
- [Cómo trabajar los ejercicios](#cómo-trabajar-los-ejercicios)
- [Preguntas de control](#preguntas-de-control)
- [Extensiones recomendadas](#extensiones-recomendadas)

Esta ayudantía se centra en problemas clásicos de árboles con formato similar al usado en plataformas como LeetCode y GeeksforGeeks. La idea no es memorizar soluciones, sino identificar qué propiedad del árbol se debe usar, qué recorrido corresponde y qué información auxiliar necesita el algoritmo.

El énfasis está en comparar soluciones recursivas e iterativas. La recursión suele ser más breve, pero la versión iterativa obliga a entender explícitamente qué información se guarda en la pila de llamadas.

## Objetivo del bloque

- leer una firma y traducirla a un contrato preciso;
- distinguir entre árbol binario y árbol binario de búsqueda;
- reconocer cuándo conviene usar DFS, BFS, inorden o postorden;
- aprovechar la propiedad de orden de un BST;
- implementar soluciones recursivas e iterativas;
- justificar correctitud y complejidad con rigor.

## Estructura base

Puedes asumir la siguiente estructura:

```cpp
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};
```

## Árbol de referencia

Para los ejercicios con BST usaremos este árbol:

```text
          8
       /     \
      3       10
     / \        \
    1   6        14
       / \      /
      4   7    13
```

Implementación sugerida para pruebas:

```cpp
TreeNode* crearArbolReferencia() {
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    return root;
}
```

El recorrido inorden del árbol de referencia es:

```text
1, 3, 4, 6, 7, 8, 10, 13, 14
```

## Referencias de práctica

Los ejercicios de esta ayudantía están inspirados en patrones clásicos de entrevistas técnicas y programación competitiva. No son copias literales de los enunciados originales.

- [LeetCode 938 - Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/): problema relacionado con consulta de rango en BST. En esta ayudantía se pide retornar los valores, no la suma.
- [LeetCode 98 - Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/): validación de BST con restricciones globales.
- [LeetCode 230 - Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/): uso de inorden para obtener el k-ésimo menor.
- [LeetCode 235 - Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/): ancestro común más bajo usando la propiedad BST.
- [LeetCode 102 - Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/): recorrido por niveles.
- [LeetCode 543 - Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/): diámetro de un árbol binario.
- [GeeksforGeeks - Binary Search Tree](https://www.geeksforgeeks.org/dsa/binary-search-tree-data-structure/): repaso de la propiedad de orden del BST.
- [GeeksforGeeks - Tree Data Structure](https://www.geeksforgeeks.org/dsa/tree-data-structure/): repaso general de árboles.

---

## Problema 1: valores en rango dentro de un BST

Dado un árbol binario de búsqueda, retorna todos los valores que estén dentro del rango cerrado `[low, high]`, en orden ascendente.

Firma obligatoria:

```cpp
vector<int> valoresEnRangoBST(TreeNode* root, int low, int high);
```

### Contrato de la función

La función debe cumplir lo siguiente:

- si `root == nullptr`, retorna un `vector<int>` vacío;
- si `low > high`, retorna un `vector<int>` vacío;
- si un valor `x` cumple `low <= x <= high`, debe aparecer en la respuesta;
- los valores retornados deben estar en orden ascendente;
- el árbol no debe modificarse;
- no se debe usar `sort`, porque el orden debe venir del recorrido del BST.

Para esta ayudantía asumiremos que el BST no tiene valores repetidos.

### Restricciones

- La solución principal debe ser iterativa.
- Puedes usar `std::stack<TreeNode*>`.
- Puedes usar `std::vector<int>` para la respuesta.
- No uses recursión en la solución principal.
- No recorras subárboles que puedas descartar usando la propiedad BST.

### Ejemplos esperados

| Llamada | Salida esperada |
| --- | --- |
| `valoresEnRangoBST(root, 4, 13)` | `[4, 6, 7, 8, 10, 13]` |
| `valoresEnRangoBST(root, 0, 2)` | `[1]` |
| `valoresEnRangoBST(root, 11, 12)` | `[]` |
| `valoresEnRangoBST(root, 8, 8)` | `[8]` |
| `valoresEnRangoBST(nullptr, 1, 5)` | `[]` |
| `valoresEnRangoBST(root, 9, 4)` | `[]` |

### Cómo pensar el problema

Antes de programar, responde:

1. ¿Qué recorrido entrega valores ordenados en un BST?
2. ¿Qué subárbol puede descartarse si `node->data < low`?
3. ¿Qué ocurre si durante inorden aparece un valor mayor que `high`?
4. ¿Por qué no se debe usar `sort`?
5. ¿Qué información debe guardar la pila para reemplazar la recursión?

---

## Problema 2: validar si un árbol binario es BST

Dado un árbol binario cualquiera, determina si cumple la propiedad de árbol binario de búsqueda.

Firma obligatoria:

```cpp
bool esBST(TreeNode* root);
```

### Contrato de la función

La función debe cumplir lo siguiente:

- si `root == nullptr`, retorna `true`;
- todo valor del subárbol izquierdo de un nodo debe ser estrictamente menor que el valor del nodo;
- todo valor del subárbol derecho de un nodo debe ser estrictamente mayor que el valor del nodo;
- cada subárbol también debe cumplir la propiedad BST;
- no se permiten valores repetidos.

### Restricciones

- No basta con comparar cada nodo solo con sus hijos inmediatos.
- Debes considerar restricciones globales heredadas desde los ancestros.
- Puedes resolverlo recursivamente con límites `min` y `max`.
- Para la versión iterativa puedes usar una pila con tuplas `(nodo, limiteInferior, limiteSuperior)`.

### Ejemplos esperados

Árbol válido:

```text
          8
       /     \
      3       10
     / \        \
    1   6        14
       / \      /
      4   7    13
```

| Llamada | Salida esperada |
| --- | --- |
| `esBST(root)` | `true` |
| `esBST(nullptr)` | `true` |

Árbol inválido:

```text
      5
     / \
    1   4
       / \
      3   6
```

| Llamada | Salida esperada |
| --- | --- |
| `esBST(rootInvalido)` | `false` |

### Cómo pensar el problema

El error frecuente es validar solo esta condición local:

```text
left < root < right
```

Eso no es suficiente. Por ejemplo, en el árbol inválido, el nodo `4` está a la derecha de `5`, por lo que debería ser mayor que `5`, aunque localmente `3 < 4 < 6` parezca correcto.

---

## Problema 3: k-ésimo menor elemento en un BST

Dado un BST y un entero `k`, retorna el k-ésimo menor valor del árbol. El conteo empieza en `1`.

Firma obligatoria:

```cpp
int kEsimoMenorBST(TreeNode* root, int k);
```

### Contrato de la función

La función debe cumplir lo siguiente:

- si `root == nullptr`, se considera entrada inválida;
- si `k <= 0`, se considera entrada inválida;
- si `k` es mayor que la cantidad de nodos, se considera entrada inválida;
- el árbol no debe modificarse;
- no se debe copiar todo el árbol a un vector si se puede detener el recorrido antes.

### Restricciones

- Debes aprovechar que el inorden de un BST entrega valores ascendentes.
- La solución debe detenerse cuando encuentre el k-ésimo valor.
- La solución iterativa puede usar `std::stack<TreeNode*>`.
- La solución recursiva puede usar un contador por referencia.

### Ejemplos esperados

| Llamada | Salida esperada |
| --- | --- |
| `kEsimoMenorBST(root, 1)` | `1` |
| `kEsimoMenorBST(root, 3)` | `4` |
| `kEsimoMenorBST(root, 5)` | `7` |
| `kEsimoMenorBST(root, 9)` | `14` |

### Cómo pensar el problema

El inorden del árbol de referencia es:

```text
1, 3, 4, 6, 7, 8, 10, 13, 14
```

Por lo tanto, el quinto menor valor es `7`.

---

## Problema 4: ancestro común más bajo en un BST

Dado un BST y dos nodos `p` y `q` pertenecientes al árbol, retorna su ancestro común más bajo.

Firma obligatoria:

```cpp
TreeNode* lcaBST(TreeNode* root, TreeNode* p, TreeNode* q);
```

### Contrato de la función

La función debe cumplir lo siguiente:

- si `root == nullptr`, retorna `nullptr`;
- si `p == nullptr` o `q == nullptr`, retorna `nullptr`;
- se asume que `p` y `q` pertenecen al BST;
- si uno de los nodos es ancestro del otro, ese nodo puede ser la respuesta;
- el árbol no debe modificarse.

### Restricciones

- Debes usar la propiedad BST.
- No es necesario recorrer todo el árbol.
- No uses estructuras auxiliares para guardar caminos completos si puedes decidir localmente.
- La solución iterativa debe avanzar hacia la izquierda o derecha según los valores de `p` y `q`.

### Ejemplos esperados

| Nodos | Salida esperada |
| --- | --- |
| `p = 1`, `q = 7` | nodo con valor `3` |
| `p = 4`, `q = 14` | nodo con valor `8` |
| `p = 13`, `q = 14` | nodo con valor `14` |
| `p = 3`, `q = 7` | nodo con valor `3` |

### Cómo pensar el problema

En un BST:

- si `p` y `q` son menores que `root`, la respuesta está a la izquierda;
- si `p` y `q` son mayores que `root`, la respuesta está a la derecha;
- si quedan separados por `root`, entonces `root` es el ancestro común más bajo.

---

## Problema 5: recorrido por niveles de un árbol binario

Dado un árbol binario, retorna sus valores agrupados por nivel, de izquierda a derecha.

Firma obligatoria:

```cpp
vector<vector<int>> recorridoPorNiveles(TreeNode* root);
```

### Contrato de la función

La función debe cumplir lo siguiente:

- si `root == nullptr`, retorna un vector vacío;
- cada subvector representa un nivel;
- los nodos dentro de cada nivel deben aparecer de izquierda a derecha;
- el árbol no debe modificarse.

### Restricciones

- La solución natural es BFS con `std::queue<TreeNode*>`.
- También puede resolverse recursivamente usando la profundidad del nodo.
- Este problema no requiere que el árbol sea BST.

### Ejemplos esperados

Para el árbol de referencia:

```text
          8
       /     \
      3       10
     / \        \
    1   6        14
       / \      /
      4   7    13
```

| Llamada | Salida esperada |
| --- | --- |
| `recorridoPorNiveles(root)` | `[[8], [3, 10], [1, 6, 14], [4, 7, 13]]` |
| `recorridoPorNiveles(nullptr)` | `[]` |

### Cómo pensar el problema

A diferencia del inorden, aquí importa procesar todos los nodos de un nivel antes de pasar al siguiente. Por eso se usa una cola y no una pila.

---

## Problema 6: diámetro de un árbol binario

Dado un árbol binario, retorna su diámetro. El diámetro se define como la cantidad de aristas del camino más largo entre dos nodos del árbol.

Firma obligatoria:

```cpp
int diametroArbolBinario(TreeNode* root);
```

### Contrato de la función

La función debe cumplir lo siguiente:

- si `root == nullptr`, retorna `0`;
- si el árbol tiene un solo nodo, retorna `0`;
- el diámetro se mide en aristas, no en cantidad de nodos;
- el camino más largo puede pasar o no por la raíz;
- el árbol no debe modificarse.

### Restricciones

- Debes calcular alturas de subárboles.
- La solución eficiente debe visitar cada nodo una sola vez.
- La solución recursiva debe usar postorden.
- La solución iterativa puede simular postorden con una pila y un mapa de alturas.

### Ejemplos esperados

Para el árbol de referencia:

```text
          8
       /     \
      3       10
     / \        \
    1   6        14
       / \      /
      4   7    13
```

El camino más largo puede ser:

```text
4 -> 6 -> 3 -> 8 -> 10 -> 14 -> 13
```

Ese camino tiene `6` aristas.

| Llamada | Salida esperada |
| --- | --- |
| `diametroArbolBinario(root)` | `6` |
| `diametroArbolBinario(nullptr)` | `0` |
| `diametroArbolBinario(new TreeNode(5))` | `0` |

### Cómo pensar el problema

En cada nodo, el mejor camino que pasa por ese nodo usa:

```text
altura del subárbol izquierdo + altura del subárbol derecho
```

Por eso conviene un recorrido postorden: primero se calculan las alturas de los hijos y luego se actualiza el diámetro del nodo actual.

---

## Cómo trabajar los ejercicios

Para cada problema, intenta seguir este orden:

1. Identificar si el árbol es binario cualquiera o BST.
2. Determinar si el orden importa.
3. Elegir DFS, BFS, inorden o postorden.
4. Escribir casos base.
5. Definir qué estado auxiliar necesita el algoritmo.
6. Justificar por qué no se pierden respuestas válidas.
7. Calcular complejidad temporal y espacial.

## Preguntas de control

- ¿Por qué el inorden entrega valores ordenados solamente si el árbol es BST?
- ¿Por qué BFS no sirve directamente para obtener valores ascendentes?
- ¿Qué diferencia hay entre altura, profundidad y diámetro?
- ¿Por qué validar un BST requiere límites heredados desde los ancestros?
- ¿Qué problema aparece si el árbol está completamente desbalanceado?
- ¿Cuándo una solución recursiva puede provocar desbordamiento de pila?
- ¿Qué información guarda implícitamente la recursión que debe hacerse explícita en una versión iterativa?

## Extensiones recomendadas

Después de resolver los seis problemas, implementa estas variantes:

1. Retornar la suma de los valores dentro de `[low, high]`.
2. Retornar el k-ésimo mayor valor de un BST.
3. Validar un BST permitiendo repetidos solo a la derecha.
4. Hacer recorrido por niveles en zigzag.
5. Calcular la altura de un árbol de forma iterativa.
6. Encontrar el ancestro común más bajo en un árbol binario que no es BST.
