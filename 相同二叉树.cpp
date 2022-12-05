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
int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
char re1[101];
char re2[101];
char re3[101];
char re4[101];
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
    BiTreeNode *p = new BiTreeNode;
    p = t;
    stack<BiTreeNode *> l;
    do {
        // cout << p->data << " ";
        re1[res1] = p->data;
        res1++;
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
            // cout << p->data << " ";
            re3[res3] = p->data;
            res3++;
            l.pop();
            p = p->rightChild;
        }
    }
    // cout<<endl;
}

string shun;
void Preshun(int num) {
    if (num > shun.length() || shun[num - 1] == '#')
        return;
    else {
        // cout<<shun[num-1];
        re2[res2] = shun[num - 1];
        res2++;
        Preshun(2 * num);
        Preshun(2 * num + 1);
    }
}

void Inshun(int num) {
    if (num > shun.length() || shun[num - 1] == '#')
        return;
    else {
        Inshun(2 * num);
        // cout<<shun[num-1];
        re4[res4] = shun[num - 1];
        res4++;
        Inshun(2 * num + 1);
    }
}

int judge(char a[], char b[]) {
    for (int i = 0; i < res1; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

/*******************************************/
//主函数
int main() {
    int t;
    string vArray;

    cin >> t;
    while (t--) {
        res1 = 0;
        res2 = 0;
        res3 = 0;
        res4 = 0;
        cin >> shun;
        Preshun(1);
        // cout<<endl;
        Inshun(1);
        // cout<<endl;
        cin >> vArray;
        BiTree myTree;
        myTree.Create(vArray);
        myTree.PreOrder();
        myTree.InOrder();
        if (res1 != res2) {
            cout << "NO" << endl;
        } else if (judge(re1, re2) == 0 || judge(re3, re4) == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
