#include <iostream>
using namespace std;

#define OK 0
#define ERROR -1

void printfu(int i) {
	if (i < 0) cout << "(" << i << ")";
	else if (i == 0) return;
	else  cout << i;
}

void printx(int i) {
	if (i < 0) cout << "x^" << "(" << i << ")";
	else if (i == 0) return;
	else if (i > 0) cout << "x^" << i;
}

//结点类定义
class ListNode {
public:
	int data1;
	int data2;
	ListNode* next;
	ListNode()
	{
		data1 = -9999, data2 = -9999, next = NULL;
	}
	ListNode(int item1, int item2 ,ListNode* pt)
	{
		data1 = item1, data2 = item2, next = pt;
	}
};

class LinkList {
	//带头结点的单链表，位置从0到n，0是头结点，1是首结点，n是尾结点
private:
	ListNode* head; //头结点
	int size; //表长

public:
	LinkList();  //构造函数，创建头结点
	ListNode* index(int i); //定位函数，返回第i个结点
	~LinkList(); //析构函数，逐个结点回收
	int LL_insert(int item1, int item2, int i); //第i位置插入元素，操作成功或失败返回OK或ERROR
	int LL_del(int i);    //删除第i位置的元素，操作成功或失败返回OK或ERROR
	int LL_get(int i);    //获取位置i的元素的数值，查找成功返回数值，查找失败返回ERROR
	void LL_print();    //打印单链表所有数据
	int LL_exchange(int a, int b);
	void merge(ListNode* a, ListNode* b);
	int LL_get2(int i);
	void LL_muiti(ListNode* a, ListNode* b);
	void Init();
	ListNode* LL_gethead();
};
//提示：index函数可以不使用。如果不用要在填空区域定义一个空函数体保证语法正确性

ListNode* LinkList::index(int i) {
	ListNode* p = head;
	while (i > 0) {
		p = p->next;
		i--;
	}
	return p;
}

LinkList::LinkList() : size(0)
{
	head = new ListNode();
}

LinkList::~LinkList() //要逐个结点回收
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



ListNode* LinkList::LL_gethead() {
	return head;
}

void LinkList::LL_muiti(ListNode* a, ListNode* b) {
	ListNode* c = head->next;
	a = a->next;
	b = b->next;
	while (a && b) {
		if (a->data2 < b->data2) {
			LL_insert(a->data1, a->data2, size+1);
			a = a->next;
		}
		else if (a->data2 > b->data2) {
			LL_insert(b->data1, b->data2, size+1);
			b = b->next;
		}
		else if (a->data2 == b->data2) {
			LL_insert(b->data1+a->data1, b->data2, size + 1);
			a = a->next;
			b = b->next;
		}
	}
	while (b) {
		LL_insert(b->data1, b->data2, size + 1);
		b = b->next;
	}
	while (a) {
		LL_insert(a->data1, a->data2, size + 1);
		a = a->next;
	}
}

int LinkList::LL_insert(int item1, int item2, int i) {
	if (i > size + 1)  return ERROR;
	ListNode* p = head;

	while (i > 1) {
		p = p->next;
		i--;
	}
	ListNode* q = new ListNode;
	q->data1 = item1;
	q->data2 = item2;
	q->next = p->next;
	p->next = q;
	size++;
	return OK;
}

void LinkList::LL_print() {
	ListNode* p = head->next;
	int flag = 0;
	for (int i = 1; i <= size; i++) {
		if (p->data1 == 0) {
			p = p->next;
			continue;
		}
		if(flag)
			cout << " + ";
		if (p->data1 != 0)flag = 1;
		printfu(p->data1);
		printx(p->data2);
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int i, t, temp, pos, pos1, pos2, m, n;
	

	cin >> t;
	while (t--) {
		LinkList sl; 
		LinkList s2;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			sl.LL_insert(a, b, i);
		}
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			s2.LL_insert(a, b, i);
		}
		sl.LL_print();
		s2.LL_print();
		LinkList s3;
		s3.LL_muiti(sl.LL_gethead(), s2.LL_gethead());
		s3.LL_print();
	}
	
	return 0;
}
