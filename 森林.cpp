#include<bits/stdc++.h>
using namespace std;
int node;
class Treenode{
public:
    char a;
    Treenode** child;
    Treenode(int node){
        child = new Treenode *[node];
        for (int i = 0; i < node; ++i){
            child[i] = NULL;
        }

    }
};//树的结点

struct BiNode{
    char data;
    BiNode *lChild;
    BiNode *rChild;
    BiNode():lChild(NULL),rChild(NULL){}
};//二叉树结点

class Tree{
public:
    Treenode* root;
    Tree(){
        root = CreateTree();
    }
    Treenode* CreateTree();
    BiNode *getBiTree(){//获取对应二叉树
    	return transferToBT(root);
    }
    BiNode *transferToBT(Treenode* p);//转换成二叉树
};

Treenode* Tree::CreateTree(){
    char b;
    cin>>b;
    if(b == '0') return NULL;
    Treenode *p = new Treenode(node);
    p->a = b;
    for(int i=0;i<node;i++){
        p->child[i] = CreateTree();
    }
    return p;
}

BiNode* Tree::transferToBT(Treenode* p){
    if(p == NULL) return NULL;
    BiNode *t = new BiNode;
    t->data = p->a;
    int j;
    for(j=0;j<node;j++){
        t->lChild = transferToBT(p->child[j]);
        if(t->lChild) break;
    }
    
    if(t->lChild){
        BiNode *q = new BiNode;
        q = t->lChild;
        for(int i=j+1;i<node;i++){
            q->rChild = transferToBT(p->child[i]);
            if(q->rChild) q = q->rChild;
        }
    }
    return t;
}

class BiTree{
private:
    void PreOrder(BiNode *p){
    if(p){
        cout<<p->data<<" ";
        PreOrder(p->lChild);
        PreOrder(p->rChild);
        }
    }
    void InOrder(BiNode *p){
    if(p){
        InOrder(p->lChild);
        cout<<p->data<<" ";
        InOrder(p->rChild);
        }
    }  

public:
    BiNode* root;
    void merge(BiNode** p,int n){
        root = p[0];
        for(int i = 0;i<n-1;i++){
            p[i]->rChild = p[i+1];
        }
    }
    stack<int> l,temp;
    void PreOrder(){
        PreOrder(root);
    }
    void InOrder(){
        InOrder(root);
    }
    void findleaf(BiNode* p){
        if(!p) return;
        if(p->lChild == NULL && p->rChild == NULL){
            while(!l.empty()){
                temp.push(l.top());
                l.pop();
            }
            while(!temp.empty()){
                cout<<temp.top();
                l.push(temp.top());
                temp.pop();
                if(!temp.empty()) cout<<" ";
            } 
            cout<<endl;
        }
        if(p){
            l.push(0);
            findleaf(p->lChild);
            if(!l.empty()) l.pop();
            l.push(1);
            findleaf(p->rChild);
            if(!l.empty()) l.pop();
        }
    }
};






int main(){
    int m;
    cin>>m>>node;
    Tree *p = new Tree[m];
    BiNode **root = new BiNode*[m];
    for(int i=0;i<m;i++){
        root[i] = p[i].getBiTree();
    }
    BiTree myBi;
    myBi.merge(root,m);
    myBi.findleaf(myBi.root);
}

