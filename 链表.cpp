#include <iostream>
using namespace std;

#define OK 0
#define ERROR -1

//结点类定义
class ListNode {
public:
	int data;
	ListNode* next;
	ListNode()
	{
		data = -9999, next = NULL;
	}
	ListNode(int item, ListNode* pt)
	{
		data = item, next = pt;
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

int LinkList::LL_insert(int item, int i) {
	if (i > size + 1)  return ERROR;
	ListNode* p = head;

	while (i > 1) {
		p = p->next;
		i--;
	}
	ListNode* q = new ListNode;
	q->data = item;
	q->next = p->next;
	p->next = q;
	size++;
	return OK;
}


int LinkList::LL_del(int i) {
	if (i > size)  return ERROR;
	ListNode* p = head, * temp;
	while (i > 1) {
		p = p->next;
		i--;
	}
	temp = p->next;
	p->next = p->next->next;
	delete temp;
	size--;
	return OK;
}

int LinkList::LL_get(int i) {
	if (i > size)  return ERROR;
	ListNode* p = head;
	while (i > 0) {
		p = p->next;
		i--;
	}
	return p->data;
}

void LinkList::LL_print() {
	ListNode* p = head->next;
	for (int i = 0; i < size; i++) {
		cout << p->data;
		if (i != size - 1) cout << " ";
		else cout << endl;
		p = p->next;
	}
}


/*******************************************/
//主函数定义
int main()
{
	int i, t, temp, pos;
	LinkList sl;	//创建单链表
//初始化链表
	cin >> t;	//输入初始长度
	for (i = 1; i <= t; i++)
	{
		cin >> temp;	sl.LL_insert(temp, i);
	}
	sl.LL_print();
	//两次插入
	for (i = 0; i < 2; i++)
	{
		cin >> pos >> temp;
		t = sl.LL_insert(temp, pos);
		if (t == ERROR) cout << "error" << endl;
		else sl.LL_print();
	}
	//两次删除
	for (i = 0; i < 2; i++)
	{
		cin >> pos;
		t = sl.LL_del(pos);
		if (t == ERROR) cout << "error" << endl;
		else sl.LL_print();
	}
	//两次查找
	for (i = 0; i < 2; i++)
	{
		cin >> pos;
		t = sl.LL_get(pos);
		if (t == ERROR) cout << "error" << endl;
		else cout << t << endl;
	}
	return 0;
}
