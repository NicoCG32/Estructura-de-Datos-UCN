#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> caminoBFSMatriz(vector<vector<int> > matriz, int origen, int destino, int bloqueado) {
    int n = static_cast<int>(matriz.size());
    vector<int> camino;

    if (n == 0 || origen < 0 || origen >= n || destino < 0 || destino >= n) {
        return camino;
    }

    for (int i = 0; i < n; i++) {
        if (static_cast<int>(matriz[i].size()) != n) {
            return camino;
        }
    }

    if (origen == bloqueado || destino == bloqueado) {
        return camino;
    }

    if (origen == destino) {
        camino.push_back(origen);
        return camino;
    }

    vector<int> visitado(n, 0);
    vector<int> padre(n, -1);
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
            if (matriz[actual][vecino] != 0 &&
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

    for (int i = static_cast<int>(camino.size()) - 1; i >= 0; i--) {
        caminoOrdenado.push_back(camino[i]);
    }

    return caminoOrdenado;
}

void imprimirCamino(vector<int> camino) {
    char nombres[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    for (int i = 0; i < camino.size(); i++) {
        cout << nombres[camino[i]] << " ";
    }

    cout << endl;
}

int main() {
    vector<vector<int> > matriz = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
    };

    int origen = 0;    // A
    int destino = 7;   // H
    int bloqueado = 4; // E

    vector<int> camino = caminoBFSMatriz(matriz, origen, destino, bloqueado);

    cout << "Camino:" << endl;
    imprimirCamino(camino);

    cout << "Distancia:" << endl;

    if (camino.size() == 0) {
        cout << -1 << endl;
    } else {
        cout << camino.size() - 1 << endl;
    }

    return 0;
}
