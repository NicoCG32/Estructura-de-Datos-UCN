#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct EdgeNode {
    int source;
    int destination;
    EdgeNode* next;

    EdgeNode(int source, int destination) {
        this->source = source;
        this->destination = destination;
        this->next = nullptr;
    }
};

void agregarArco(EdgeNode*& head, int source, int destination) {
    EdgeNode* nuevo = new EdgeNode(source, destination);

    if (head == nullptr) {
        head = nuevo;
        return;
    }

    EdgeNode* actual = head;

    while (actual->next != nullptr) {
        actual = actual->next;
    }

    actual->next = nuevo;
}

EdgeNode* crearListaArcosReferencia() {
    EdgeNode* head = nullptr;

    agregarArco(head, 0, 1);
    agregarArco(head, 0, 2);
    agregarArco(head, 1, 3);
    agregarArco(head, 1, 4);
    agregarArco(head, 2, 4);
    agregarArco(head, 2, 5);
    agregarArco(head, 3, 6);
    agregarArco(head, 4, 3);
    agregarArco(head, 4, 6);
    agregarArco(head, 4, 7);
    agregarArco(head, 5, 4);
    agregarArco(head, 5, 7);
    agregarArco(head, 7, 6);

    return head;
}

vector<vector<int> > construirListaAdy(EdgeNode* edges, int n, bool directed) {
    vector<vector<int> > adj;

    if (n <= 0) {
        return adj;
    }

    adj.resize(n);

    // Recorrido de LinkedList de arcos.
    // Cada nodo de la lista representa un arco source -> destination.
    EdgeNode* actual = edges;

    while (actual != nullptr) {
        int u = actual->source;
        int v = actual->destination;

        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);

            // Si el grafo no es dirigido, el arco también sirve al revés.
            if (!directed) {
                adj[v].push_back(u);
            }
        }

        actual = actual->next;
    }

    // Se ordena cada lista de vecinos para recorrer en orden ascendente.
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    return adj;
}

vector<vector<int> > construirMatrizAdy(EdgeNode* edges, int n, bool directed) {
    vector<vector<int> > matrix;

    if (n <= 0) {
        return matrix;
    }

    matrix.resize(n, vector<int>(n, 0));

    // Recorrido de LinkedList de arcos.
    // En matriz, matrix[u][v] indica si existe el arco u -> v.
    EdgeNode* actual = edges;

    while (actual != nullptr) {
        int u = actual->source;
        int v = actual->destination;

        if (u >= 0 && u < n && v >= 0 && v < n) {
            matrix[u][v] = 1;

            // Si el grafo no es dirigido, se marca también v -> u.
            if (!directed) {
                matrix[v][u] = 1;
            }
        }

        actual = actual->next;
    }

    return matrix;
}

void imprimirListaAdy(vector<vector<int> > adj) {
    for (int i = 0; i < (int)adj.size(); i++) {
        cout << i << ": ";

        for (int j = 0; j < (int)adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }
}

void imprimirMatriz(vector<vector<int> > matrix) {
    for (int i = 0; i < (int)matrix.size(); i++) {
        for (int j = 0; j < (int)matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    int n = 8;
    bool directed = true;
    EdgeNode* edges = crearListaArcosReferencia();

    vector<vector<int> > lista = construirListaAdy(edges, n, directed);
    vector<vector<int> > matriz = construirMatrizAdy(edges, n, directed);

    cout << "Lista de adyacencia:" << endl;
    imprimirListaAdy(lista);

    cout << endl;
    cout << "Matriz de adyacencia:" << endl;
    imprimirMatriz(matriz);

    return 0;
}
