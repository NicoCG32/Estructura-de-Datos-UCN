#include <iostream>
#include <vector>
using namespace std;

bool existeArcoMatriz(const vector<vector<int> >& matrix, int u, int v) {
    int n = matrix.size();

    if (u < 0 || u >= n || v < 0 || v >= n) {
        return false;
    }

    // En matriz de adyacencia, matrix[u][v] representa el arco u -> v.
    return matrix[u][v] != 0;
}

int gradoSalidaMatriz(const vector<vector<int> >& matrix, int v) {
    int n = matrix.size();

    if (v < 0 || v >= n) {
        return 0;
    }

    int grado = 0;

    // Grado de salida: se recorre la fila del vértice.
    for (int j = 0; j < n; j++) {
        if (matrix[v][j] != 0) {
            grado++;
        }
    }

    return grado;
}

int gradoEntradaMatriz(const vector<vector<int> >& matrix, int v) {
    int n = matrix.size();

    if (v < 0 || v >= n) {
        return 0;
    }

    int grado = 0;

    // Grado de entrada: se recorre la columna del vértice.
    for (int i = 0; i < n; i++) {
        if (matrix[i][v] != 0) {
            grado++;
        }
    }

    return grado;
}

vector<int> vecinosSalidaMatriz(const vector<vector<int> >& matrix, int v) {
    vector<int> vecinos;

    int n = matrix.size();

    if (v < 0 || v >= n) {
        return vecinos;
    }

    // Vecinos de salida: posiciones j donde existe v -> j.
    for (int j = 0; j < n; j++) {
        if (matrix[v][j] != 0) {
            vecinos.push_back(j);
        }
    }

    return vecinos;
}

void imprimirVector(vector<int> valores) {
    cout << "[";

    for (int i = 0; i < (int)valores.size(); i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << valores[i];
    }

    cout << "]";
}

int main() {
    vector<vector<int> > matrix = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0}
    };

    cout << boolalpha;

    cout << "existeArcoMatriz(matrix, 2, 5): ";
    cout << existeArcoMatriz(matrix, 2, 5) << endl;

    cout << "existeArcoMatriz(matrix, 5, 2): ";
    cout << existeArcoMatriz(matrix, 5, 2) << endl;

    cout << "gradoSalidaMatriz(matrix, 4): ";
    cout << gradoSalidaMatriz(matrix, 4) << endl;

    cout << "gradoEntradaMatriz(matrix, 4): ";
    cout << gradoEntradaMatriz(matrix, 4) << endl;

    cout << "gradoEntradaMatriz(matrix, 6): ";
    cout << gradoEntradaMatriz(matrix, 6) << endl;

    cout << "vecinosSalidaMatriz(matrix, 1): ";
    imprimirVector(vecinosSalidaMatriz(matrix, 1));
    cout << endl;

    return 0;
}
