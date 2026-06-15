#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    ~TreeNode() {}
};

TreeNode* crearArbolEjercicio4() {
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->right->right = new TreeNode(14);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right->left = new TreeNode(13);

    return root;
}

void zigzagConSuma(TreeNode* root) {
    if (root == nullptr) {
        cout << "Arbol vacio" << endl;
        return;
    }

    queue<TreeNode*> cola;
    cola.push(root);

    bool izquierdaDerecha = true;
    int numeroNivel = 1;

    int mayorSuma = 0;
    int nivelMayorSuma = 1;
    bool primeraSuma = true;

    while (!cola.empty()) {
        int cantidad = static_cast<int>(cola.size());
        vector<int> nivel;
        int sumaNivel = 0;

        for (int i = 0; i < cantidad; i++) {
            TreeNode* actual = cola.front();
            cola.pop();

            nivel.push_back(actual->val);
            sumaNivel = sumaNivel + actual->val;

            if (actual->left != nullptr) {
                cola.push(actual->left);
            }

            if (actual->right != nullptr) {
                cola.push(actual->right);
            }
        }

        cout << "Nivel " << numeroNivel << ": ";

        if (izquierdaDerecha) {
            for (int i = 0; i < static_cast<int>(nivel.size()); i++) {
                if (i > 0) {
                    cout << " ";
                }
                cout << nivel[i];
            }
        } else {
            for (int i = static_cast<int>(nivel.size()) - 1; i >= 0; i--) {
                if (i != static_cast<int>(nivel.size()) - 1) {
                    cout << " ";
                }
                cout << nivel[i];
            }
        }

        cout << " | suma = " << sumaNivel << endl;

        if (primeraSuma || sumaNivel > mayorSuma) {
            mayorSuma = sumaNivel;
            nivelMayorSuma = numeroNivel;
            primeraSuma = false;
        }

        izquierdaDerecha = !izquierdaDerecha;
        numeroNivel++;
    }

    cout << endl;
    cout << "Nivel con mayor suma: " << nivelMayorSuma << endl;
    cout << "Mayor suma: " << mayorSuma << endl;
}

int main() {
    TreeNode* root = crearArbolEjercicio4();

    zigzagConSuma(root);

    return 0;
}
