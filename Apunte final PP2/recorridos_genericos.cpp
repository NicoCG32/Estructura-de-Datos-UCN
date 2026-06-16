#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// ============================================================
// 1. ARBOLES BINARIOS
// ============================================================

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* crearArbolReferencia() {
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    return root;
}

void dfsInordenAux(TreeNode* root, vector<int>& orden) {
    if (root == nullptr) {
        return;
    }

    // Basado en DFS inorden:
    // 1. recorrer subarbol izquierdo
    // 2. visitar nodo actual
    // 3. recorrer subarbol derecho
    dfsInordenAux(root->left, orden);
    orden.push_back(root->val);
    dfsInordenAux(root->right, orden);
}

vector<int> dfsInorden(TreeNode* root) {
    vector<int> orden;
    dfsInordenAux(root, orden);
    return orden;
}

vector<int> bfsArbol(TreeNode* root) {
    vector<int> orden;

    if (root == nullptr) {
        return orden;
    }

    queue<TreeNode*> cola;
    cola.push(root);

    // Basado en BFS:
    // se usa queue para visitar el arbol por niveles.
    while (!cola.empty()) {
        TreeNode* actual = cola.front();
        cola.pop();

        orden.push_back(actual->val);

        if (actual->left != nullptr) {
            cola.push(actual->left);
        }

        if (actual->right != nullptr) {
            cola.push(actual->right);
        }
    }

    return orden;
}

// ============================================================
// 2. GRAFOS CON LISTA DE ARCOS / EDGELIST
// ============================================================

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

EdgeNode* crearEdgeListReferencia() {
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

vector<int> vecinosEdgeList(EdgeNode* head, int actual, int n, bool dirigido) {
    vector<int> vecinos;
    EdgeNode* arco = head;

    // Recorrido de LinkedList:
    // para conocer los vecinos de actual, se revisan todos los arcos.
    while (arco != nullptr) {
        if (arco->source == actual &&
            arco->destination >= 0 &&
            arco->destination < n) {
            vecinos.push_back(arco->destination);
        }

        if (!dirigido &&
            arco->destination == actual &&
            arco->source >= 0 &&
            arco->source < n) {
            vecinos.push_back(arco->source);
        }

        arco = arco->next;
    }

    sort(vecinos.begin(), vecinos.end());
    return vecinos;
}

vector<int> dfsEdgeList(EdgeNode* head, int n, int start, bool dirigido) {
    vector<int> orden;

    if (start < 0 || start >= n) {
        return orden;
    }

    vector<int> visitado(n, 0);
    stack<int> pila;
    pila.push(start);

    // Basado en DFS con stack.
    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (actual < 0 || actual >= n || visitado[actual] == 1) {
            continue;
        }

        visitado[actual] = 1;
        orden.push_back(actual);

        vector<int> vecinos = vecinosEdgeList(head, actual, n, dirigido);

        // Se apila al reves para visitar primero el vecino menor.
        for (int i = (int)vecinos.size() - 1; i >= 0; i--) {
            if (visitado[vecinos[i]] == 0) {
                pila.push(vecinos[i]);
            }
        }
    }

    return orden;
}

vector<int> bfsEdgeList(EdgeNode* head, int n, int start, bool dirigido) {
    vector<int> orden;

    if (start < 0 || start >= n) {
        return orden;
    }

    vector<int> visitado(n, 0);
    queue<int> cola;

    // Basado en BFS con queue.
    visitado[start] = 1;
    cola.push(start);

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        orden.push_back(actual);

        vector<int> vecinos = vecinosEdgeList(head, actual, n, dirigido);

        for (int i = 0; i < (int)vecinos.size(); i++) {
            if (visitado[vecinos[i]] == 0) {
                visitado[vecinos[i]] = 1;
                cola.push(vecinos[i]);
            }
        }
    }

    return orden;
}

// ============================================================
// 3. GRAFOS CON LISTA DE ADYACENCIA / ADYLIST
// ============================================================

vector<vector<int> > crearAdyListReferencia() {
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

vector<int> dfsAdyList(vector<vector<int> > adj, int start) {
    vector<int> orden;
    int n = adj.size();

    if (start < 0 || start >= n) {
        return orden;
    }

    vector<int> visitado(n, 0);
    stack<int> pila;
    pila.push(start);

    // Basado en DFS con lista de adyacencia.
    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (actual < 0 || actual >= n || visitado[actual] == 1) {
            continue;
        }

        visitado[actual] = 1;
        orden.push_back(actual);

        sort(adj[actual].begin(), adj[actual].end());

        for (int i = (int)adj[actual].size() - 1; i >= 0; i--) {
            int vecino = adj[actual][i];

            if (vecino >= 0 && vecino < n && visitado[vecino] == 0) {
                pila.push(vecino);
            }
        }
    }

    return orden;
}

vector<int> bfsAdyList(vector<vector<int> > adj, int start) {
    vector<int> orden;
    int n = adj.size();

    if (start < 0 || start >= n) {
        return orden;
    }

    vector<int> visitado(n, 0);
    queue<int> cola;

    // Basado en BFS con lista de adyacencia.
    visitado[start] = 1;
    cola.push(start);

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        orden.push_back(actual);

        sort(adj[actual].begin(), adj[actual].end());

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

// ============================================================
// 4. GRAFOS CON MATRIZ DE ADYACENCIA / ADYMAT / ADTMAT
// ============================================================

vector<vector<int> > crearAdyMatReferencia() {
    vector<vector<int> > matrix = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0}
    };

    return matrix;
}

vector<int> dfsAdyMat(vector<vector<int> > matrix, int start) {
    vector<int> orden;
    int n = matrix.size();

    if (start < 0 || start >= n) {
        return orden;
    }

    vector<int> visitado(n, 0);
    stack<int> pila;
    pila.push(start);

    // Basado en DFS con matriz:
    // los vecinos de actual estan en la fila matrix[actual].
    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (actual < 0 || actual >= n || visitado[actual] == 1) {
            continue;
        }

        visitado[actual] = 1;
        orden.push_back(actual);

        // Se recorre de derecha a izquierda para que el menor salga primero.
        for (int vecino = n - 1; vecino >= 0; vecino--) {
            if (matrix[actual][vecino] != 0 && visitado[vecino] == 0) {
                pila.push(vecino);
            }
        }
    }

    return orden;
}

vector<int> bfsAdyMat(vector<vector<int> > matrix, int start) {
    vector<int> orden;
    int n = matrix.size();

    if (start < 0 || start >= n) {
        return orden;
    }

    vector<int> visitado(n, 0);
    queue<int> cola;

    // Basado en BFS con matriz:
    // para buscar vecinos, se recorre toda la fila del nodo actual.
    visitado[start] = 1;
    cola.push(start);

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        orden.push_back(actual);

        for (int vecino = 0; vecino < n; vecino++) {
            if (matrix[actual][vecino] != 0 && visitado[vecino] == 0) {
                visitado[vecino] = 1;
                cola.push(vecino);
            }
        }
    }

    return orden;
}

// ============================================================
// 5. UTILIDADES DE PRUEBA
// ============================================================

void imprimirVector(string nombre, vector<int> valores) {
    cout << nombre << ": [";

    for (int i = 0; i < (int)valores.size(); i++) {
        if (i > 0) {
            cout << ", ";
        }

        cout << valores[i];
    }

    cout << "]" << endl;
}

int main() {
    TreeNode* root = crearArbolReferencia();

    imprimirVector("DFS inorden arbol", dfsInorden(root));
    imprimirVector("BFS arbol", bfsArbol(root));

    cout << endl;

    int n = 8;
    bool dirigido = true;
    EdgeNode* edges = crearEdgeListReferencia();
    vector<vector<int> > adj = crearAdyListReferencia();
    vector<vector<int> > matrix = crearAdyMatReferencia();

    imprimirVector("DFS EdgeList", dfsEdgeList(edges, n, 0, dirigido));
    imprimirVector("BFS EdgeList", bfsEdgeList(edges, n, 0, dirigido));

    cout << endl;

    imprimirVector("DFS AdyList", dfsAdyList(adj, 0));
    imprimirVector("BFS AdyList", bfsAdyList(adj, 0));

    cout << endl;

    imprimirVector("DFS AdyMat", dfsAdyMat(matrix, 0));
    imprimirVector("BFS AdyMat", bfsAdyMat(matrix, 0));

    return 0;
}
