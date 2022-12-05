#include <iostream>
using namespace std;

#define OK 0
#define ERROR -1

//结点类定义
class ListNode {
public:
	char data;
	ListNode* next;
	ListNode* pior;
	ListNode()
	{
		data = '0', next = NULL, pior = NULL;
	}
	ListNode(char item, ListNode* pt,ListNode*nt)
	{
		data = item, next = nt,pior = pt;
	}
};

class LinkList {
	//带头结点的单链表，位置从0到n，0是头结点，1是首结点，n是尾结点
private:
	ListNode* head; //头结点
	int size; //表长
	ListNode* index(int i); //定位函数，返回第i个结点
public:
	LinkList();		//构造函数，创建头结点
	~LinkList();	//析构函数，逐个结点回收
	int LL_insert(int item, int i);	//第i位置插入元素，操作成功或失败返回OK或ERROR
	int LL_del(int i);				//删除第i位置的元素，操作成功或失败返回OK或ERROR
	int LL_get(int i);				//获取位置i的元素的数值，查找成功返回数值，查找失败返回ERROR
	void LL_print();				//打印单链表所有数据
	int test(int i);
};
//提示：index函数可以不使用。如果不用要在填空区域定义一个空函数体保证语法正确性

LinkList::LinkList() : size(0)
{
	head = new ListNode();
}

LinkList::~LinkList()	//要逐个结点回收
{
	ListNode* p, * q;
	p = head->next;
	while (p != NULL) {
		q = p; p = p->next;
		delete q;
	}
	size = 0;
	head->next = NULL;
}

//以下完成其他类函数定义
/********** Write your code here! **********/

int LinkList::test(int i) {
	if (i > size + 1) return ERROR;
	ListNode* p = head;

	while (i > 1) {
		p = p->next;
		i--;
	}
	ListNode* q = new  ListNode;
	q->data = item;
	q->next = p->next;
	q->pior = p;
	p->next = q;
	p = q;
}


/*******************************************/
//主函数定义
int main()
{
	int i, t, temp, pos;
	
	return 0;
}

