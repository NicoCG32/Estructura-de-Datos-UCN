#include <iostream>
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

void dfsRecAux(const vector<vector<int> >& adj,
               int actual,
               vector<int>& visitado,
               vector<int>& orden) {
    int n = adj.size();

    if (actual < 0 || actual >= n || visitado[actual] == 1) {
        return;
    }

    // Basado en DFS recursivo: se baja por una rama antes de retroceder.
    visitado[actual] = 1;
    orden.push_back(actual);

    for (int i = 0; i < (int)adj[actual].size(); i++) {
        int vecino = adj[actual][i];

        if (vecino >= 0 && vecino < n && visitado[vecino] == 0) {
            dfsRecAux(adj, vecino, visitado, orden);
        }
    }
}

vector<int> dfsRecursivo(const vector<vector<int> >& adj, int start) {
    vector<int> orden;

    int n = adj.size();

    if (start < 0 || start >= n) {
        return orden;
    }

    vector<int> visitado(n, 0);
    dfsRecAux(adj, start, visitado, orden);

    return orden;
}

vector<int> dfsIterativo(const vector<vector<int> >& adj, int start) {
    vector<int> orden;

    int n = adj.size();

    if (start < 0 || start >= n) {
        return orden;
    }

    vector<int> visitado(n, 0);
    stack<int> pila;

    // Basado en DFS iterativo: se usa stack explícito.
    pila.push(start);

    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (actual < 0 || actual >= n || visitado[actual] == 1) {
            continue;
        }

        visitado[actual] = 1;
        orden.push_back(actual);

        // Se apila al revés para que el vecino menor salga primero.
        for (int i = (int)adj[actual].size() - 1; i >= 0; i--) {
            int vecino = adj[actual][i];

            if (vecino >= 0 && vecino < n && visitado[vecino] == 0) {
                pila.push(vecino);
            }
        }
    }

    return orden;
}

bool existeCaminoDFS(const vector<vector<int> >& adj, int src, int dst) {
    int n = adj.size();

    if (src < 0 || src >= n || dst < 0 || dst >= n) {
        return false;
    }

    vector<int> visitado(n, 0);
    stack<int> pila;

    // Basado en DFS: si logro visitar dst, existe camino.
    pila.push(src);

    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (actual < 0 || actual >= n || visitado[actual] == 1) {
            continue;
        }

        if (actual == dst) {
            return true;
        }

        visitado[actual] = 1;

        for (int i = (int)adj[actual].size() - 1; i >= 0; i--) {
            int vecino = adj[actual][i];

            if (vecino >= 0 && vecino < n && visitado[vecino] == 0) {
                pila.push(vecino);
            }
        }
    }

    return false;
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

    cout << "dfsRecursivo(adj, 0): ";
    imprimirVector(dfsRecursivo(adj, 0));
    cout << endl;

    cout << "dfsIterativo(adj, 0): ";
    imprimirVector(dfsIterativo(adj, 0));
    cout << endl;

    cout << boolalpha;

    cout << "existeCaminoDFS(adj, 2, 6): ";
    cout << existeCaminoDFS(adj, 2, 6) << endl;

    cout << "existeCaminoDFS(adj, 6, 0): ";
    cout << existeCaminoDFS(adj, 6, 0) << endl;

    cout << "existeCaminoDFS(adj, 4, 4): ";
    cout << existeCaminoDFS(adj, 4, 4) << endl;

    return 0;
}
