#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class EdgeNode {
public:
    int source;
    int destination;
    EdgeNode* next;

    EdgeNode(int source, int destination) {
        this->source = source;
        this->destination = destination;
        this->next = nullptr;
    }

    ~EdgeNode() {}
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

bool ordenCursos(EdgeNode* head, int numCursos, vector<int>& orden) {
    orden.clear();

    if (numCursos < 0) {
        return false;
    }

    vector<vector<int> > adyacencia(numCursos);
    vector<int> gradoEntrada(numCursos, 0);

    EdgeNode* cursor = head;

    while (cursor != nullptr) {
        int origen = cursor->source;
        int destino = cursor->destination;

        if (origen >= 0 && origen < numCursos && destino >= 0 && destino < numCursos) {
            adyacencia[origen].push_back(destino);
            gradoEntrada[destino]++;
        }

        cursor = cursor->next;
    }

    queue<int> cola;

    for (int i = 0; i < numCursos; i++) {
        if (gradoEntrada[i] == 0) {
            cola.push(i);
        }
    }

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        orden.push_back(actual);

        for (int i = 0; i < static_cast<int>(adyacencia[actual].size()); i++) {
            int vecino = adyacencia[actual][i];
            gradoEntrada[vecino]--;

            if (gradoEntrada[vecino] == 0) {
                cola.push(vecino);
            }
        }
    }

    return static_cast<int>(orden.size()) == numCursos;
}

int main() {
    EdgeNode* head = nullptr;

    agregarArco(head, 0, 1);
    agregarArco(head, 0, 2);
    agregarArco(head, 1, 3);
    agregarArco(head, 2, 3);
    agregarArco(head, 3, 4);
    agregarArco(head, 4, 5);

    int numCursos = 6;
    vector<int> orden;

    bool posible = ordenCursos(head, numCursos, orden);

    if (posible) {
        cout << "true" << endl;
        cout << "Orden posible:" << endl;

        for (int i = 0; i < orden.size(); i++) {
            cout << orden[i] << " ";
        }

        cout << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
