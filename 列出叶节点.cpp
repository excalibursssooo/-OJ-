#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int lchild = -1;
    int rchild = -1;
    int parent = -1;
    int pos = 0;
};

int main() {
    TreeNode* t = new TreeNode[101];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a;
        if (a == '-') t[i].lchild = -1;
        else t[i].lchild = a - '0';
        cin >> b;
        if (b == '-') t[i].rchild = -1;
        else t[i].rchild = b - '0';
        t[i].pos = i;
    }

    int root = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (t[j].lchild == i || t[j].rchild == i) {
                t[i].parent = j;
                break;
            }
        }
       // cout << t[i].parent;
        if (t[i].parent == -1) root = i;
    }
    int begin = root;
    queue <TreeNode> p;
    p.push(t[begin]);
    do {
        
        TreeNode f;
        f = p.front();
        //cout << f.lchild << " " << f.rchild << endl;
        p.pop();
        if (f.lchild == -1 && f.rchild == -1) {
            cout << f.pos << " ";
            
        }
        
        if (f.lchild != -1) {
            p.push(t[f.lchild]);
        }
            
        if (f.rchild != -1) {
            p.push(t[f.rchild]);
        }
            
    } while (!p.empty());
}