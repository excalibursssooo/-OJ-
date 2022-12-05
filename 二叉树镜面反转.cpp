#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        data = '#';
        left = NULL;
        right = NULL;
    }
};

class Tree {
private:
    TreeNode *Create(TreeNode *p);
    TreeNode *root;
    string s;
    int pos = 0;
    void PreOrder(TreeNode *p) {
        if (root == NULL) {
            cout << "NULL";
            return;
        }
        if (p != NULL) {
            cout << p->data << " ";
            PreOrder(p->left);
            PreOrder(p->right);
        }
    }
    void InOrder(TreeNode *p) {
        if (root == NULL) {
            cout << "NULL";
            return;
        }
        if (p != NULL) {
            InOrder(p->left);
            cout << p->data << " ";
            InOrder(p->right);
        }
    }
    void PostOrder(TreeNode *p) {
        if (root == NULL) {
            cout << "NULL";
            return;
        }
        if (p != NULL) {
            PostOrder(p->left);
            PostOrder(p->right);
            cout << p->data << " ";
        }
    }
    void Reverse(TreeNode *p);

public:
    Tree() {
        root = new TreeNode;
        cin >> s;
    }
    void Create() {
        pos = 0;
        root = Create(root);
    }
    void PreOrder() {
        PreOrder(root);
    };
    void PostOrder() {
        PostOrder(root);
    };
    void InOrder() {
        InOrder(root);
    };
    void Reverse() {
        Reverse(root);
    };
    void LevelOrder();
};

TreeNode *Tree::Create(TreeNode *p) {
    if (s[0] == '#') {
        return NULL;
    }
    TreeNode *t = new TreeNode;
    if (s[pos] != '#') {
        t->data = s[pos];
        pos++;
        t->left = Create(t);
        t->right = Create(t);
    } else {
        t = NULL;
        pos++;
    }
    return t;
}

void Tree::Reverse(TreeNode *p) {
    if (p != NULL) {
        TreeNode *t = p->left;
        p->left = p->right;
        p->right = t;
        Reverse(p->left);
        Reverse(p->right);
    }
}

void Tree::LevelOrder() {
    if (root == NULL) {
        cout << "NULL";
        return;
    }
    queue<TreeNode *> q;
    TreeNode *p = root;
    q.push(p);
    while (!q.empty()) {
        TreeNode *t = q.front();
        cout << t->data << " ";
        q.pop();
        if (t->left != NULL) q.push(t->left);
        if (t->right != NULL) q.push(t->right);
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Tree myTree;
        myTree.Create();
        myTree.Reverse();
        myTree.PreOrder();
        cout << endl;
        myTree.InOrder();
        cout << endl;
        myTree.PostOrder();
        cout << endl;
        myTree.LevelOrder();
    }
}