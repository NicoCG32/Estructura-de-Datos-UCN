# Ayudantia 7: Soluciones

Esta carpeta contiene las soluciones paso a paso de los ejercicios planteados en la [Ayudantia 7](README.md).

La idea es mantener separado:

- el bloque de enunciados, notas y consideraciones, en `README.md`;
- el bloque de resoluciones desarrolladas, en este archivo.

## Ejercicio 1: leer un heap con indexacion 0-based

Arreglo dado:

```cpp
int a[] = {19, 11, 17, 8, 10, 13, 15};
```

### Paso 1: aplicar las formulas `0-based`

- `parent(i) = (i - 1) / 2` para `i > 0`;
- `left(i) = 2 * i + 1`;
- `right(i) = 2 * i + 2`.

### Paso 2: identificar el arbol

```text
                        19
                  11          17
                8   10      13   15
```

### Paso 3: verificar la propiedad de max-heap

- `19 >= 11` y `19 >= 17`;
- `11 >= 8` y `11 >= 10`;
- `17 >= 13` y `17 >= 15`.

### Conclusion

El arreglo si representa un `max-heap`.

## Ejercicio 2: leer un heap con indexacion 1-based

Arreglo dado:

```cpp
int b[] = {0, 20, 14, 18, 9, 12, 16, 17};
```

La posicion `0` queda vacia para trabajar con indices desde `1`.

### Paso 1: aplicar las formulas `1-based`

- `parent(i) = i / 2`;
- `left(i) = 2 * i`;
- `right(i) = 2 * i + 1`.

### Paso 2: identificar el arbol

```text
                        20
                  14          18
                9   12      16   17
```

### Paso 3: verificar la propiedad de max-heap

- `20 >= 14` y `20 >= 18`;
- `14 >= 9` y `14 >= 12`;
- `18 >= 16` y `18 >= 17`.

### Conclusion

El arreglo si representa un `max-heap`.

## Ejercicio 3: HeapSort paso a paso con indexacion 0-based

Arreglo inicial:

```cpp
int a[] = {4, 10, 3, 5, 1};
```

### 1. Construccion del max-heap

Partimos del arreglo original:

```text
[4, 10, 3, 5, 1]
```

El ultimo nodo padre esta en `i = 1`.

Aplicamos `heapify-down` desde `i = 1` y luego desde `i = 0`:

```text
[10, 5, 3, 4, 1]
```

### 2. Primera extraccion

Intercambiamos la raiz con el ultimo elemento del heap activo:

```text
[1, 5, 3, 4, 10]
```

`heapify-down`:

```text
[5, 4, 3, 1, 10]
```

### 3. Segunda extraccion

```text
[1, 4, 3, 5, 10]
```

Heap activo de tamano `3`.

`heapify-down`:

```text
[4, 1, 3, 5, 10]
```

### 4. Tercera extraccion

```text
[3, 1, 4, 5, 10]
```

Heap activo de tamano `2`.

### 5. Resultado final

```text
[1, 3, 4, 5, 10]
```

## Ejercicio 4: HeapSort paso a paso con indexacion 1-based

Arreglo dado:

```cpp
int b[] = {0, 8, 3, 7, 1, 6, 4};
```

Indices utiles: `1` a `6`.

### 1. Construccion del max-heap

Arreglo original en la parte util:

```text
[8, 3, 7, 1, 6, 4]
```

Heap construido:

```text
[8, 6, 7, 1, 3, 4]
```

### 2. Primera extraccion

```text
[4, 6, 7, 1, 3, 8]
```

```text
[7, 6, 4, 1, 3, 8]
```

### 3. Segunda extraccion

```text
[3, 6, 4, 1, 7, 8]
```

```text
[6, 3, 4, 1, 7, 8]
```

### 4. Tercera extraccion

```text
[1, 3, 4, 6, 7, 8]
```

```text
[4, 3, 1, 6, 7, 8]
```

### 5. Cuarta extraccion

```text
[1, 3, 4, 6, 7, 8]
```

```text
[3, 1, 4, 6, 7, 8]
```

### 6. Resultado final

```text
[1, 3, 4, 6, 7, 8]
```

## Ejercicio 5: HeapSort paso a paso con un arreglo un poco mas grande

Arreglo dado:

```cpp
int c[] = {12, 11, 13, 5, 6, 7, 9, 25, 31, 26, 17, 14};
```

### 1. Construccion del max-heap

Partimos del arreglo original:

```text
[12, 11, 13, 5, 6, 7, 9, 25, 31, 26, 17, 14]
```

Aplicando `heapify-down` desde el ultimo padre hasta la raiz, se obtiene:

```text
[31, 26, 14, 25, 17, 13, 9, 11, 5, 6, 12, 7]
```

### 2. Primera extraccion

```text
[7, 26, 14, 25, 17, 13, 9, 11, 5, 6, 12, 31]
```

```text
[26, 25, 14, 11, 17, 13, 9, 7, 5, 6, 12, 31]
```

### 3. Segunda extraccion

```text
[12, 25, 14, 11, 17, 13, 9, 7, 5, 6, 26, 31]
```

```text
[25, 17, 14, 11, 12, 13, 9, 7, 5, 6, 26, 31]
```

### 4. Tercera extraccion

```text
[6, 17, 14, 11, 12, 13, 9, 7, 5, 25, 26, 31]
```

```text
[17, 12, 14, 11, 6, 13, 9, 7, 5, 25, 26, 31]
```

### 5. Cuarta extraccion

```text
[5, 12, 14, 11, 6, 13, 9, 7, 17, 25, 26, 31]
```

```text
[14, 12, 13, 11, 6, 5, 9, 7, 17, 25, 26, 31]
```

### 6. Quinta extraccion

```text
[7, 12, 13, 11, 6, 5, 9, 14, 17, 25, 26, 31]
```

```text
[13, 12, 9, 11, 6, 5, 7, 14, 17, 25, 26, 31]
```

### 7. Sexta extraccion

```text
[7, 12, 9, 11, 6, 5, 13, 14, 17, 25, 26, 31]
```

```text
[12, 11, 9, 7, 6, 5, 13, 14, 17, 25, 26, 31]
```

### 8. Septima extraccion

```text
[5, 11, 9, 7, 6, 12, 13, 14, 17, 25, 26, 31]
```

```text
[11, 7, 9, 5, 6, 12, 13, 14, 17, 25, 26, 31]
```

### 9. Octava extraccion

```text
[6, 7, 9, 5, 11, 12, 13, 14, 17, 25, 26, 31]
```

```text
[9, 7, 6, 5, 11, 12, 13, 14, 17, 25, 26, 31]
```

### 10. Novena extraccion

```text
[5, 7, 6, 9, 11, 12, 13, 14, 17, 25, 26, 31]
```

```text
[7, 5, 6, 9, 11, 12, 13, 14, 17, 25, 26, 31]
```

### 11. Decima extraccion

```text
[6, 5, 7, 9, 11, 12, 13, 14, 17, 25, 26, 31]
```

### 12. Resultado final

```text
[5, 6, 7, 9, 11, 12, 13, 14, 17, 25, 26, 31]
```