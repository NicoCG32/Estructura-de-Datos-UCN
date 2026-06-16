#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int> > crearGrafoNoDirigidoReferencia() {
    vector<vector<int> > adj(9);

    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2};
    adj[4] = {5};
    adj[5] = {4, 6};
    adj[6] = {5};
    adj[7] = {8};
    adj[8] = {7};

    return adj;
}

int contarComponentes(const vector<vector<int> >& adj) {
    int n = adj.size();
    vector<int> visitado(n, 0);
    int componentes = 0;

    for (int inicio = 0; inicio < n; inicio++) {
        if (visitado[inicio] == 1) {
            continue;
        }

        componentes++;

        stack<int> pila;
        pila.push(inicio);
        visitado[inicio] = 1;

        // Basado en DFS: cada recorrido marca una componente completa.
        while (!pila.empty()) {
            int actual = pila.top();
            pila.pop();

            for (int i = 0; i < (int)adj[actual].size(); i++) {
                int vecino = adj[actual][i];

                if (vecino >= 0 && vecino < n && visitado[vecino] == 0) {
                    visitado[vecino] = 1;
                    pila.push(vecino);
                }
            }
        }
    }

    return componentes;
}

bool tieneCicloNoDirigido(const vector<vector<int> >& adj) {
    int n = adj.size();
    vector<int> visitado(n, 0);

    for (int inicio = 0; inicio < n; inicio++) {
        if (visitado[inicio] == 1) {
            continue;
        }

        stack<int> pilaNodo;
        stack<int> pilaPadre;

        pilaNodo.push(inicio);
        pilaPadre.push(-1);
        visitado[inicio] = 1;

        // Basado en DFS para grafo no dirigido.
        // Hay ciclo si encuentro un visitado que no es mi padre.
        while (!pilaNodo.empty()) {
            int actual = pilaNodo.top();
            int padre = pilaPadre.top();

            pilaNodo.pop();
            pilaPadre.pop();

            for (int i = 0; i < (int)adj[actual].size(); i++) {
                int vecino = adj[actual][i];

                if (vecino < 0 || vecino >= n) {
                    continue;
                }

                if (visitado[vecino] == 0) {
                    visitado[vecino] = 1;
                    pilaNodo.push(vecino);
                    pilaPadre.push(actual);
                } else if (vecino != padre) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int> > adjNoDirigido = crearGrafoNoDirigidoReferencia();

    cout << boolalpha;

    cout << "contarComponentes(adjNoDirigido): ";
    cout << contarComponentes(adjNoDirigido) << endl;

    cout << "tieneCicloNoDirigido(adjNoDirigido): ";
    cout << tieneCicloNoDirigido(adjNoDirigido) << endl;

    vector<vector<int> > path(4);
    path[0] = {1};
    path[1] = {0, 2};
    path[2] = {1, 3};
    path[3] = {2};

    cout << "contarComponentes(path): ";
    cout << contarComponentes(path) << endl;

    cout << "tieneCicloNoDirigido(path): ";
    cout << tieneCicloNoDirigido(path) << endl;

    return 0;
}
