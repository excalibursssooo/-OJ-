#include<stack>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>	
using namespace std;

const int maxW = 9999;	   //设定无穷大权值

//Huffman树结点结构
class HuffNode {	//哈夫曼树的结点结构
public:
    int weight;		//权值
    int parent;		//双亲下标
    int lchild;	//左孩子下标
    int rchild;	//右孩子下标
};

//Huffman树结构
class HuffMan {
private:
    int len;		//结点总数，等于lnum*2-1
    int lnum;		//叶子数量
    HuffNode* HuffTree;	//保存构建后的赫夫曼树信息
    void selectMin(int n, int& x1, int& x2);
    //函数selectMin是从已生成的n个结点中(包含叶子)，选出未选的且权值最小的两个结点的下标
    //两个下标结果保存在x1和x2中
    //第一小权值的结点下标保存在x1，第二小权值的结点下标保存在x2
    //如果不想用这个函数，就在类外定义中定义一个空函数体，避免语法错误

    //string* HuffCode; //保存叶子的赫夫曼编码
    //char** HC;		//保存叶子的赫夫曼编码
//如果不喜欢用string，可以用二维字符数组HC
//HuffCode和HC，两者只用一个保存赫夫曼编码就可以了 

public:
    HuffMan(int n, int w[]); //输入叶子数量和叶子权重，初始化HuffTree和HuffCode（或HC）
    void buildTree();		//构建赫夫曼树，保存在HuffTree中
    void Coding();			//生成赫夫曼编码，保存在HuffCode或HC中
    void printCode();		//输出赫夫曼编码
    void Decoding(string cs);
    //~HuffMan();//回收空间
};

//请完成Huffman树的剩下部分类定义
/********** Write your code here! **********/

stack <int> p[100];


HuffMan::HuffMan(int n, int w[]) {
    HuffTree = new HuffNode[100];
    len = n;
    lnum = len * 2 - 1;
    for (int i = 0; i < len; i++) {
        HuffTree[i].weight = w[i];
        //cout<<i<<" "<<HuffTree[i].weight<<endl;
        HuffTree[i].lchild = 0;
        HuffTree[i].rchild = 0;
        HuffTree[i].parent = 0;
    }
    for (int i = len; i < lnum; i++) {
        HuffTree[i].weight = 0;
        HuffTree[i].lchild = 0;
        HuffTree[i].rchild = 0;
        HuffTree[i].parent = 0;
    }
}

void HuffMan::selectMin(int n, int& x1, int& x2) {
    int x = 9999;
    for (int i = 0; i < n; i++) {
        if (HuffTree[i].weight < x && HuffTree[i].parent == 0) {
            x = HuffTree[i].weight;
            x1 = i;
        }
    }
    x = 9999;
    for (int i = 0; i < n; i++) {
        if (HuffTree[i].weight < x && i != x1 && HuffTree[i].parent == 0) {
            x = HuffTree[i].weight;
            x2 = i;
        }
    }
}

void HuffMan::buildTree() {
    for (int i = len; i < lnum; i++) {
        int a, b;
        selectMin(i, a, b);
        HuffTree[i].lchild = a;
        HuffTree[i].rchild = b;
        HuffTree[a].parent = i;
        HuffTree[b].parent = i;
        HuffTree[i].weight = HuffTree[a].weight + HuffTree[b].weight;
        //cout << HuffTree[i].weight << endl;
    }
}

void HuffMan::Coding() {

    for (int i = 0; i < len; i++) {
        int j;
        int parent = HuffTree[i].parent;

        for (j = i; parent != 0; j = parent, parent = HuffTree[parent].parent) {
            if (HuffTree[parent].lchild == j) {
                p[i].push(0);
            }
            else if (HuffTree[parent].rchild == j) {
                p[i].push(1);
            }
        }

    }
}

void HuffMan::printCode() {
    for (int i = 0; i < len; i++) {
        cout << HuffTree[i].weight << "-";
        //strrev(HC[i]);
        int j = 0;
        while (!p[i].empty()) {
            cout << p[i].top();
            p[i].pop();
        }
        cout << endl;
    }
}

/*******************************************/
//主函数如下
int main(void)
{
    int n, wt[100];
    char ct[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    HuffMan huff(n, wt);
    huff.buildTree();
    huff.Coding();
    huff.printCode();

    return 0;
}
