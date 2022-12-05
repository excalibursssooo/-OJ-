#include<bits/stdc++.h>
using namespace std;
class BiTreeNode {
public:
	char  data;					//数据域
    int quan;
	BiTreeNode  *leftChild,  *rightChild, *father;	//左右子树指针
	BiTreeNode():leftChild(NULL), rightChild(NULL),father(NULL){}
	~BiTreeNode() {}
};

class BiTree {
private:
	BiTreeNode *root;	//根结点指针
	string sTree;		//建树字符串
	int pos;			//标识建树字符串的当前字符位置
	BiTreeNode * CreateTree(BiTreeNode  *t);//建树私有函数
	void PreOrder(BiTreeNode  *t);	//先序遍历实现
	void InOrder(BiTreeNode  *t);	//中序遍历实现
	void PostOrder(BiTreeNode  *t);	//后序遍历实现
    void LevelOrder(BiTreeNode  *t);	//层序遍历实现
    int num;
    char father[1001];
    char kids[1001];
    void showfather();
    void showkids();
    void showdeep();
    int deep=0;
    int maxdeep=0;
    int maxlu(BiTreeNode *t){
        if(t == NULL) return 0;
        return max(maxlu(t->leftChild)+t->quan,maxlu(t->rightChild)+t->quan);
    }
public:
	BiTree():root(NULL) {};	
	void Create(string vArray);	//建树公有接口，参数是特定的先序遍历字符串
	void PreOrder();			//先序遍历公有接口
	void InOrder();				//中序遍历公有接口
	void PostOrder();			//后序遍历公有接口
    void LevelOrder();
    int cnt = 0;
    void showf();
    void showk();
    void showd();
    int leaf[1001];
    int sum;
    int quan;
    void showmax(){
        cout<<maxlu(root)<<endl;
    }
};
//二叉树公有接口的实现
void BiTree::Create(string vArray) 
{	pos=0;
    num=0;
    sum = 0;
    deep = 0;
	sTree.assign(vArray);	//把参数保存到内部字符串
	root = CreateTree(root);	//建树成功后root指向根结点
}
void BiTree::PreOrder()
{	num = 0;PreOrder(root);	}
void BiTree::InOrder()
{	InOrder(root);	}
void BiTree::PostOrder()
{	PostOrder(root);	}
void BiTree::LevelOrder()
{	LevelOrder(root);	}
void BiTree::showf(){
    showfather();
}
void BiTree::showk(){
    showkids();
}
void BiTree::showd(){
    showdeep();
}
//请完成上述类内部的私有函数实现
/********** Write your code here! **********/
BiTreeNode * BiTree::CreateTree(BiTreeNode  *t){
    BiTreeNode *p = new BiTreeNode;
    p->father = t;
    if(sTree[pos] == '0'){
        p = NULL;
        pos++;
    }
    else{
        p->data = sTree[pos];
        pos++;
        deep++;
        p->leftChild = CreateTree(p);
        p->rightChild = CreateTree(p);
        deep--;
    }
    
    return p;
}

void BiTree::PreOrder(BiTreeNode  *t){
    BiTreeNode *p = new BiTreeNode;
    p = t;
    stack<BiTreeNode*> l;
    do{
        if(p){
            p->quan = leaf[num];
            //cout<<p->data<<p->quan<<endl;
            num++;
        }
        BiTreeNode *q = new BiTreeNode;
        q = p->rightChild;
        if(q != NULL) l.push(q);
        p = p->leftChild;
        if(p == NULL){
            BiTreeNode *k = new BiTreeNode;
            if(!l.empty()){
                k = l.top();
                l.pop();
                p=k;
            }
        } 
    }while(!l.empty()||p != NULL);
    //cout<<endl;
}
void BiTree::InOrder(BiTreeNode  *t){
    BiTreeNode *p = new BiTreeNode;
    p = t;
    stack<BiTreeNode*> l;
    while(!l.empty()||p != NULL){
        if(p != NULL){
            l.push(p);
            p = p->leftChild;
        }
        else{
            p = l.top();
            cout<<p->data<<" ";
            l.pop();
            p = p->rightChild;
        }
    }
    //cout<<endl;
}
void BiTree::PostOrder(BiTreeNode  *t){
    if(t){
        PostOrder(t->leftChild);
        PostOrder(t->rightChild);
        cout<<t->data;
    }
}

void BiTree::showfather(){
    for(int i=0;i<num;i++){
        cout<<father[i]<<" ";
    }
}

void BiTree::showkids(){
    for(int i=0;i<num;i++){
        cout<<kids[i]<<" ";
    }
}
void BiTree::showdeep(){
    cout<<maxdeep<<endl;
}
void BiTree::LevelOrder(BiTreeNode  *t){
    queue<BiTreeNode*> q;
    q.push(t);
    while(!q.empty()){
        
        BiTreeNode *p = new BiTreeNode;
        p = q.front();
        q.pop();
        if(p!=NULL){
            cout<<p->data;
            q.push(p->leftChild);
            q.push(p->rightChild);
        }
    }
}

/*******************************************/
//主函数
int main()
{	int t;
	string vArray;
    
	cin>>t;
	while(t--)
	{	cin>>vArray;
        
		BiTree myTree;
        cin>>myTree.quan;
        for(int i=0;i<myTree.quan;i++){
            cin>>myTree.leaf[i];
        }
		myTree.Create(vArray);
        myTree.PreOrder();
        myTree.showmax();
	}
	return 0;
}
