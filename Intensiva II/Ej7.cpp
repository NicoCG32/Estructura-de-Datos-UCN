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

vector<int> caminoListaArcos(EdgeNode* head, int n, int origen, int destino) {
    vector<int> camino;

    if (n <= 0 || origen < 0 || origen >= n || destino < 0 || destino >= n) {
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

        EdgeNode* cursor = head;

        while (cursor != nullptr) {
            int vecino = -1;

            if (cursor->source == actual) {
                vecino = cursor->destination;
            } else if (cursor->destination == actual) {
                vecino = cursor->source;
            }

            if (vecino >= 0 && vecino < n && visitado[vecino] == 0) {
                visitado[vecino] = 1;
                padre[vecino] = actual;
                cola.push(vecino);
            }

            cursor = cursor->next;
        }
    }

    if (visitado[destino] == 0) {
        return camino;
    }

    int cursorCamino = destino;

    while (cursorCamino != -1) {
        camino.push_back(cursorCamino);
        cursorCamino = padre[cursorCamino];
    }

    vector<int> caminoOrdenado;

    for (int i = static_cast<int>(camino.size()) - 1; i >= 0; i--) {
        caminoOrdenado.push_back(camino[i]);
    }

    return caminoOrdenado;
}

int main() {
    EdgeNode* head = nullptr;

    agregarArco(head, 0, 1);
    agregarArco(head, 0, 2);
    agregarArco(head, 1, 4);
    agregarArco(head, 2, 3);
    agregarArco(head, 3, 5);
    agregarArco(head, 4, 5);

    int n = 6;
    int origen = 0;
    int destino = 5;

    vector<int> camino = caminoListaArcos(head, n, origen, destino);

    if (camino.size() == 0) {
        cout << "Existe camino:" << endl;
        cout << "false" << endl;
    } else {
        cout << "Existe camino:" << endl;
        cout << "true" << endl;

        cout << "Camino:" << endl;

        for (int i = 0; i < camino.size(); i++) {
            cout << camino[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
