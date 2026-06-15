#include <iostream>
#include <stack>
#include <utility>
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
    // Implementar aquí.
    return 0;
}

bool tieneCicloNoDirigido(const vector<vector<int> >& adj) {
    // Implementar aquí.
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
