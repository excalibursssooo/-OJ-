#include <bits/stdc++.h>
using namespace std;
class BiTreeNode {
public:
    int data = -1;                               // 数据域
    BiTreeNode *leftChild, *rightChild, *father; // 左右子树指针
    BiTreeNode() :
        leftChild(NULL), rightChild(NULL), father(NULL) {
    }
    ~BiTreeNode() {
    }
};

class BiTree {
private:
    BiTreeNode *root;               // 根结点指针
    string sTree;                   // 建树字符串
    int pos;                        // 标识建树字符串的当前字符位置
    void CreateTree();              // 建树私有函数
    void PreOrder(BiTreeNode *t);   // 先序遍历实现
    void InOrder(BiTreeNode *t);    // 中序遍历实现
    void PostOrder(BiTreeNode *t);  // 后序遍历实现
    void LevelOrder(BiTreeNode *t); // 层序遍历实现
    char father[1001];
    char kids[1001];
    void showfather();
    void showkids();
    void showdeep();
    int deep = 0;
    int maxdeep = 0;
    int n;
    int temp;

public:
    BiTree() :
        root(NULL){};
    void Create();    // 建树公有接口，参数是特定的先序遍历字符串
    void PreOrder();  // 先序遍历公有接口
    void InOrder();   // 中序遍历公有接口
    void PostOrder(); // 后序遍历公有接口
    void LevelOrder();
    void Insert(int numl);
    void Del(int numl);
};
// 二叉树公有接口的实现
void BiTree::Create() {
    cin >> n;
    CreateTree();
    // 建树成功后root指向根结点
}
void BiTree::PreOrder() {
    PreOrder(root);
}
void BiTree::InOrder() {
    InOrder(root);
}
void BiTree::PostOrder() {
    PostOrder(root);
}
void BiTree::LevelOrder() {
    LevelOrder(root);
}
// 请完成上述类内部的私有函数实现
/********** Write your code here! **********/
void BiTree::CreateTree() {
    root = new BiTreeNode;
    int nn;
    cin >> nn;
    root->data = nn;
    for (int i = 1; i < n; i++) {
        BiTreeNode *p = root;
        BiTreeNode *t = new BiTreeNode;
        int data;
        cin >> data;
        t->data = data;
        while (p != NULL) {
            if (data > p->data) {
                if (p->rightChild == NULL) {
                    p->rightChild = t;
                    break;
                }
                p = p->rightChild;
            } else {
                if (p->leftChild == NULL) {
                    p->leftChild = t;
                    break;
                }
                p = p->leftChild;
            }
        }
    }
}

void BiTree::PreOrder(BiTreeNode *t) {
    BiTreeNode *p = new BiTreeNode;
    p = t;
    stack<BiTreeNode *> l;
    do {
        cout << p->data << " ";
        BiTreeNode *q = new BiTreeNode;
        q = p->rightChild;
        if (q != NULL) l.push(q);
        p = p->leftChild;
        if (p == NULL) {
            BiTreeNode *k = new BiTreeNode;
            if (!l.empty()) {
                k = l.top();
                l.pop();
                p = k;
            }
        }
    } while (!l.empty() || p != NULL);
    // cout<<endl;
}
void BiTree::InOrder(BiTreeNode *t) {
    BiTreeNode *p = new BiTreeNode;
    p = t;
    stack<BiTreeNode *> l;
    while (!l.empty() || p != NULL) {
        if (p != NULL) {
            l.push(p);
            p = p->leftChild;
        } else {
            p = l.top();
            cout << p->data << " ";
            l.pop();
            p = p->rightChild;
        }
    }
    // cout<<endl;
}
void BiTree::PostOrder(BiTreeNode *t) {
    if (t) {
        PostOrder(t->leftChild);
        PostOrder(t->rightChild);
        cout << t->data;
    }
}

void BiTree::showdeep() {
    cout << maxdeep << endl;
}
void BiTree::LevelOrder(BiTreeNode *t) {
    queue<BiTreeNode *> q;
    q.push(t);
    while (!q.empty()) {
        BiTreeNode *p = new BiTreeNode;
        p = q.front();
        q.pop();
        if (p != NULL) {
            cout << p->data;
            q.push(p->leftChild);
            q.push(p->rightChild);
        }
    }
}

void BiTree::Insert(int numl) {
    BiTreeNode *p = root;
    BiTreeNode *t = new BiTreeNode;
    t->data = numl;
    while (p != NULL) {
        if (numl > p->data) {
            if (p->rightChild == NULL) {
                p->rightChild = t;
                return;
            }
            p = p->rightChild;
        } else {
            if (p->leftChild == NULL) {
                p->leftChild = t;
                return;
            }
            p = p->leftChild;
        }
    }
}

void BiTree::Del(int numl) {
    BiTreeNode *p = root;
    BiTreeNode *k = new BiTreeNode;
    int flag = 0;
    while (p->data != numl) {
        if (p->data < numl) {
            k = p;
            p = p->rightChild;
            if (p == NULL) {
                return;
            }
            if (p != NULL && p->data == numl) {
                flag = 1;
            }
        } else {
            if (p == NULL) {
                return;
            }
            k = p;
            p = p->leftChild;
            if (p != NULL && p->data == numl) {
                flag = 2;
            }
        }
    }
    // cout << p->data << endl;
    if (p->leftChild == NULL || p->rightChild == NULL) {
        if (p->rightChild == NULL) {
            if (flag == 1) {
                k->rightChild = p->leftChild;
            }
            if (flag == 2) {
                k->leftChild = p->leftChild;
            }
        } else if (p->leftChild == NULL) {
            if (flag == 1) {
                k->rightChild = p->rightChild;
            }
            if (flag == 2) {
                k->leftChild = p->rightChild;
            }
        }
    } else {
        BiTreeNode *t = p;
        BiTreeNode *s = p->leftChild;
        while (s->rightChild != NULL) {
            t = s;
            s = s->rightChild;
        }
        p->data = s->data;
        if (p != t) {
            t->rightChild = s->leftChild;
        } else {
            t->leftChild = s->leftChild;
        }
        delete s;
    }
}
/*******************************************/
// 主函数
int main() {
    int t;
    cin >> t;
    while (t--) {
        BiTree myTree;
        myTree.Create();
        myTree.InOrder();
        cout << endl;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int g;
            cin >> g;
            myTree.Del(g);
            myTree.InOrder();
            cout << endl;
        }
    }
    return 0;
}
