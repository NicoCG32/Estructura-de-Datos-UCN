#include <iostream>
#include <queue>
#include <stack>
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

vector<int> verticesEnAlgunCamino(const vector<vector<int> >& adj, int src, int dst) {
    vector<int> respuesta;

    int n = adj.size();

    if (src < 0 || src >= n || dst < 0 || dst >= n) {
        return respuesta;
    }

    vector<int> desdeSrc(n, 0);
    queue<int> cola;

    // Basado en BFS: marcar todo lo alcanzable desde src.
    desdeSrc[src] = 1;
    cola.push(src);

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        for (int i = 0; i < (int)adj[actual].size(); i++) {
            int vecino = adj[actual][i];

            if (vecino >= 0 && vecino < n && desdeSrc[vecino] == 0) {
                desdeSrc[vecino] = 1;
                cola.push(vecino);
            }
        }
    }

    vector<vector<int> > invertido(n);

    // Recorrido de lista de adyacencia para construir el grafo invertido.
    for (int u = 0; u < n; u++) {
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];

            if (v >= 0 && v < n) {
                invertido[v].push_back(u);
            }
        }
    }

    vector<int> haciaDst(n, 0);
    stack<int> pila;

    // Basado en DFS sobre el grafo invertido.
    // Si dst llega a v en el invertido, entonces v llega a dst en el original.
    pila.push(dst);

    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (actual < 0 || actual >= n || haciaDst[actual] == 1) {
            continue;
        }

        haciaDst[actual] = 1;

        for (int i = 0; i < (int)invertido[actual].size(); i++) {
            int vecino = invertido[actual][i];

            if (vecino >= 0 && vecino < n && haciaDst[vecino] == 0) {
                pila.push(vecino);
            }
        }
    }

    // Un vértice sirve si src llega a él y él puede llegar a dst.
    for (int v = 0; v < n; v++) {
        if (desdeSrc[v] == 1 && haciaDst[v] == 1) {
            respuesta.push_back(v);
        }
    }

    return respuesta;
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

    cout << "verticesEnAlgunCamino(adj, 2, 3): ";
    imprimirVector(verticesEnAlgunCamino(adj, 2, 3));
    cout << endl;

    cout << "verticesEnAlgunCamino(adj, 5, 6): ";
    imprimirVector(verticesEnAlgunCamino(adj, 5, 6));
    cout << endl;

    cout << "verticesEnAlgunCamino(adj, 6, 0): ";
    imprimirVector(verticesEnAlgunCamino(adj, 6, 0));
    cout << endl;

    cout << "verticesEnAlgunCamino(adj, 0, 6): ";
    imprimirVector(verticesEnAlgunCamino(adj, 0, 6));
    cout << endl;

    return 0;
}
