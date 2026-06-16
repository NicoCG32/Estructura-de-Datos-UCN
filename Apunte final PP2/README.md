# Apunte final PP2

Este apunte resume las implementaciones genéricas de recorridos que más se repiten en PP2:

- DFS inorden en árboles binarios;
- BFS en árboles binarios;
- DFS y BFS en grafos representados como lista de arcos;
- DFS y BFS en grafos representados como lista de adyacencia;
- DFS y BFS en grafos representados como matriz de adyacencia.

La implementación completa se encuentra en [recorridos_genericos.cpp](recorridos_genericos.cpp).

## Idea central

Un recorrido no depende solo del algoritmo, sino también de la representación.

| Estructura | Recorrido | Estructura auxiliar | Uso típico |
| --- | --- | --- | --- |
| Árbol binario | DFS inorden | recursión | visitar izquierda, raíz, derecha |
| Árbol binario | BFS | `queue` | recorrer por niveles |
| Grafo | DFS | `stack` | explorar en profundidad |
| Grafo | BFS | `queue` | recorrer por capas o distancia mínima no ponderada |

## Árboles

### DFS inorden

El inorden es un recorrido DFS porque baja por una rama antes de volver:

```txt
izquierdo -> nodo actual -> derecho
```

En un ABB, este recorrido entrega los valores en orden ascendente.

### BFS en árbol

BFS usa una cola:

```txt
raíz -> nivel 1 -> nivel 2 -> nivel 3 -> ...
```

Sirve cuando el problema habla de niveles, profundidad mínima o recorrido por capas.

## Grafos

En grafos siempre se necesita un vector de visitados. Sin visitados, un ciclo puede hacer que el algoritmo repita vértices indefinidamente.

### EdgeList

Una lista de arcos guarda arcos, no vecinos directos:

```txt
(0,1) -> (0,2) -> (1,3) -> nullptr
```

Para conocer los vecinos de `u`, se debe recorrer toda la lista de arcos.

### AdyList

Una lista de adyacencia guarda vecinos directos:

```txt
0: 1, 2
1: 3, 4
```

Es la representación más cómoda para DFS y BFS.

### AdyMat / AdtMat

Una matriz de adyacencia usa:

```txt
matrix[u][v] != 0
```

para indicar que existe el arco `u -> v`.

Para encontrar vecinos de `u`, se recorre la fila completa `matrix[u]`.

## Regla rápida

- Usa **DFS** si quieres explorar profundidad, subárboles, componentes o existencia de camino.
- Usa **BFS** si quieres niveles, capas o menor cantidad de arcos en grafo no ponderado.
- En árboles, `queue` casi siempre significa recorrido por niveles.
- En grafos, `visited` es obligatorio salvo que tengas garantía formal de que no hay ciclos.
