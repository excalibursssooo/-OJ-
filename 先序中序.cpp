#include <iostream>
#include <string>
using namespace std;
class BiTreeNode {
public:
    char  data;					//数据域
    BiTreeNode* leftChild, * rightChild;	//左右子树指针
    BiTreeNode() :leftChild(NULL), rightChild(NULL) {}
    ~BiTreeNode() {}
};

class BiTree {
private:
    BiTreeNode* root;	//根结点指针
    string sTree;		//建树字符串
    int pos;			//标识建树字符串的当前字符位置
    BiTreeNode* CreateTree(char* pre, char* in, int n);//建树私有函数
    void PreOrder(BiTreeNode* t);	//先序遍历实现
    int deep(BiTreeNode* t) {
        if (t == NULL) return -1;
        else return max(deep(t->leftChild), deep(t->rightChild))+1;
    }
public:
    BiTree() :root(NULL) {};
    void Create();	//建树公有接口，参数是特定的先序遍历字符串
    void PreOrder();			//先序遍历公有接口
    char pre[100];
    char in[100];
    int len;
    void deep() {
        cout << deep(root);
    }
};
//二叉树公有接口的实现
void BiTree::Create()
{
    root = CreateTree(pre, in, len);	//建树成功后root指向根结点
}
void BiTree::PreOrder() { PreOrder(root); }
//请完成上述类内部的私有函数实现
/********** Write your code here! **********/
BiTreeNode* BiTree::CreateTree(char* pre, char* in, int n) {
    BiTreeNode* p = new BiTreeNode;
    if (n <= 0) p == NULL;
    else {
        int l;
        char* a;
        p->data = *pre;
        for (a = in; a < in + n; a++) {
            if (*a == *pre) break;
        }
        l = a - in;
        p->leftChild = CreateTree(pre + 1, in, l);
        p->rightChild = CreateTree(pre + 1 + l, a + 1, n - l - 1);
    }
    return p;
}

void BiTree::PreOrder(BiTreeNode* t) {
    if (t) {
        cout << t->data;
        PreOrder(t->leftChild);
        PreOrder(t->rightChild);
    }
}

/*******************************************/
//主函数
int main()
{
    int t;

    BiTree myTree;
    cin >> myTree.len;
    for (int i = 0; i < myTree.len; i++) {
        cin >> myTree.pre[i];
    }
    for (int i = 0; i < myTree.len; i++) {
        cin >> myTree.in[i];
    }
    myTree.Create();
    myTree.deep();
    return 0;
}
