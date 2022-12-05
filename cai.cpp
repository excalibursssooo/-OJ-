#include <iostream>
using namespace std;
#define MAX_SIZE 100
typedef struct PTnode {
    char data;
    int parent;
} PTnode;
typedef struct tree {
    PTnode node[MAX_SIZE];
    int nodenum; //结点数
} tree;
void InitTree(tree &T) {
    for (int i = 0; i < MAX_SIZE; i++) {
        T.node[i].data = '#';
        T.node[i].parent = -1;
    }
    T.nodenum = 0;
}
void CreateTree(tree &T) {
    int n = 0;
    int parent;
    char node1, node2, node;
    cin >> n;
    // parent = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> node;
        if (node != '#') {
            T.node[T.nodenum++].data = node;
        } else
            continue;
    }
    for (int i = 0; i < n; i++) {
        cin >> parent;
        if (parent != -1) {
            T.node[i].parent = parent;
        }
    }
}
void PreOrder(tree T, int i) {
    for (int j = 0; j < T.nodenum; j++) {
        if (T.node[j].parent == i) {
            cout << T.node[j].data;
            PreOrder(T, j);
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        tree t1;
        InitTree(t1);
        CreateTree(t1);
        PreOrder(t1, -1);
        cout << endl;
    }
}