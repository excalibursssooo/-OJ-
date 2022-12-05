#include <bits/stdc++.h>
using namespace std;
class BiTreeNode {
public:
    char data;                                   //数据域
    BiTreeNode *leftChild, *rightChild, *father; //左右子树指针
    BiTreeNode() :
        leftChild(NULL), rightChild(NULL), father(NULL) {
    }
    ~BiTreeNode() {
    }
};

class BiTree {
private:
    BiTreeNode *root;                      //根结点指针
    string sTree;                          //建树字符串
    int pos;                               //标识建树字符串的当前字符位置
    BiTreeNode *CreateTree(BiTreeNode *t); //建树私有函数
    void PreOrder(BiTreeNode *t);          //先序遍历实现
    void InOrder(BiTreeNode *t);           //中序遍历实现
    void PostOrder(BiTreeNode *t);         //后序遍历实现
    void LevelOrder(BiTreeNode *t);        //层序遍历实现
    int num;
    char father[1001];
    char kids[1001];
    void showfather();
    void showkids();
    void showdeep();
    int deep = 0;
    int maxdeep = 0;

public:
    BiTree() :
        root(NULL){};
    void Create(string vArray); //建树公有接口，参数是特定的先序遍历字符串
    void PreOrder();            //先序遍历公有接口
    void InOrder();             //中序遍历公有接口
    void PostOrder();           //后序遍历公有接口
    void LevelOrder();
    int cnt = 0;
    void showf();
    void showk();
    void showd();
};
//二叉树公有接口的实现
void BiTree::Create(string vArray) {
    pos = 0;
    num = 0;
    sTree.assign(vArray);    //把参数保存到内部字符串
    root = CreateTree(root); //建树成功后root指向根结点
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
void BiTree::showf() {
    showfather();
}
void BiTree::showk() {
    showkids();
}
void BiTree::showd() {
    showdeep();
}
//请完成上述类内部的私有函数实现
/********** Write your code here! **********/
BiTreeNode *BiTree::CreateTree(BiTreeNode *t) {
    BiTreeNode *p = new BiTreeNode;
    p->father = t;
    if (sTree[pos] == '#') {
        p = NULL;
        pos++;
    } else {
        p->data = sTree[pos];
        pos++;
        p->leftChild = CreateTree(p);
        p->rightChild = CreateTree(p);
    }
    if (p != NULL) {
        if (p->leftChild == NULL && p->rightChild == NULL) {
            father[num] = p->father->data;
            kids[num] = p->data;
            num++;
        }
    }
    return p;
}

void BiTree::PreOrder(BiTreeNode *t) {
    cout << "PreOrder:";
    BiTreeNode *p = new BiTreeNode;
    p = t;
    stack<BiTreeNode *> l;
    do {
        cout << " " << p->data;
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
    cout << endl;
}
void BiTree::InOrder(BiTreeNode *t) {
    cout << "InOrder:";
    BiTreeNode *p = new BiTreeNode;
    p = t;
    stack<BiTreeNode *> l;
    while (!l.empty() || p != NULL) {
        if (p != NULL) {
            l.push(p);
            p = p->leftChild;
        } else {
            p = l.top();
            cout << " " << p->data;
            l.pop();
            p = p->rightChild;
        }
    }
    cout << endl;
}
void BiTree::PostOrder(BiTreeNode *t) {
    cout << "PostOrder:";
    int tag = 0;
    stack<BiTreeNode *> S1;
    stack<int> S2;
    if (t == NULL) return;
    BiTreeNode *p = t;
    do {
        if (p != NULL) {
            S1.push(p);
            tag = 0;
            S2.push(tag);
            p = p->leftChild;
        }

        if (S1.empty()) break;
        if (p == NULL) {
            if (S2.top() == 0) {
                // cout<<"**"<<endl;
                S2.top() = 1;
                p = S1.top()->rightChild;
                // if(p) cout<<p->data;
            } else if (S2.top() == 1) {
                // cout<<"*"<<endl;
                p = S1.top();
                cout << " " << p->data;
                S1.pop();
                S2.pop();
                p = NULL;
            }
        }
    } while (!S1.empty());
    cout << endl;
}

void BiTree::showfather() {
    for (int i = 0; i < num; i++) {
        cout << father[i] << " ";
    }
}

void BiTree::showkids() {
    for (int i = 0; i < num; i++) {
        cout << kids[i] << " ";
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

/*******************************************/
//主函数
int main() {
    string vArray;
    cin >> vArray;
    BiTree myTree;
    myTree.Create(vArray);
    myTree.InOrder();
    myTree.PreOrder();
    myTree.PostOrder();
    return 0;
}
