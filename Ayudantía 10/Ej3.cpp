#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int> > crearGrafoDirigidoReferencia() {
    vector<vector<int> > adj(8);

    adj[0] = {1, 2};
    adj[1] = {3, 4};
    adj[2] = {4, 5};
    adj[3] = {6};
    adj[4] = {3, 6, 7};
    adj[5] = {4, 7};
    adj[6] = {};
    adj[7] = {6};

    return adj;
}

vector<int> bfsOrden(const vector<vector<int> >& adj, int start) {
    vector<int> orden;

    int n = adj.size();

    if (start < 0 || start >= n) {
        return orden;
    }

    vector<int> visitado(n, 0);
    queue<int> cola;

    // Basado en BFS: se usa queue para recorrer por capas.
    visitado[start] = 1;
    cola.push(start);

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        orden.push_back(actual);

        for (int i = 0; i < (int)adj[actual].size(); i++) {
            int vecino = adj[actual][i];

            if (vecino >= 0 && vecino < n && visitado[vecino] == 0) {
                visitado[vecino] = 1;
                cola.push(vecino);
            }
        }
    }

    return orden;
}

vector<int> distanciasBFS(const vector<vector<int> >& adj, int start) {
    vector<int> dist(adj.size(), -1);

    int n = adj.size();

    if (start < 0 || start >= n) {
        return dist;
    }

    queue<int> cola;

    // Basado en BFS: la primera vez que llego a un vértice,
    // llego con la menor cantidad de arcos.
    dist[start] = 0;
    cola.push(start);

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        for (int i = 0; i < (int)adj[actual].size(); i++) {
            int vecino = adj[actual][i];

            if (vecino >= 0 && vecino < n && dist[vecino] == -1) {
                dist[vecino] = dist[actual] + 1;
                cola.push(vecino);
            }
        }
    }

    return dist;
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
    vector<vector<int> > adj = crearGrafoDirigidoReferencia();

    cout << "bfsOrden(adj, 0): ";
    imprimirVector(bfsOrden(adj, 0));
    cout << endl;

    cout << "distanciasBFS(adj, 0): ";
    imprimirVector(distanciasBFS(adj, 0));
    cout << endl;

    cout << "distanciasBFS(adj, 6): ";
    imprimirVector(distanciasBFS(adj, 6));
    cout << endl;

    cout << "bfsOrden(adj, 20): ";
    imprimirVector(bfsOrden(adj, 20));
    cout << endl;

    return 0;
}
