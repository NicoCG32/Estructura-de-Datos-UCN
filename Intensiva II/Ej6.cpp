#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool puedeVisitarTodas(vector<vector<int> > rooms) {
    int n = static_cast<int>(rooms.size());

    if (n == 0) {
        return true;
    }

    vector<int> visitado(n, 0);
    stack<int> pila;

    pila.push(0);
    visitado[0] = 1;

    while (!pila.empty()) {
        int sala = pila.top();
        pila.pop();

        for (int i = 0; i < static_cast<int>(rooms[sala].size()); i++) {
            int llave = rooms[sala][i];

            if (llave >= 0 && llave < n && visitado[llave] == 0) {
                visitado[llave] = 1;
                pila.push(llave);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (visitado[i] == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int> > rooms = {
        {1, 2},
        {3},
        {4},
        {5},
        {},
        {}
    };

    bool respuesta = puedeVisitarTodas(rooms);

    if (respuesta) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
