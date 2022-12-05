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
	
public:
	LinkList();  //构造函数，创建头结点
	ListNode* index(int i); //定位函数，返回第i个结点
	~LinkList(); //析构函数，逐个结点回收
	int LL_insert(int item, int i); //第i位置插入元素，操作成功或失败返回OK或ERROR
	int LL_del(int i);    //删除第i位置的元素，操作成功或失败返回OK或ERROR
	int LL_get(int i);    //获取位置i的元素的数值，查找成功返回数值，查找失败返回ERROR
	void LL_print();    //打印单链表所有数据
	int LL_exchange(int a,int b);
	void merge(ListNode* a, ListNode* b);
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


int LinkList:: LL_insert(int item, int i) {
	if (i > size+1)  return ERROR;
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

int LinkList::LL_exchange(int a,int b) {
	if (a > size || b > size)  return ERROR;
	ListNode* p, * q;
	ListNode* temp1 = new ListNode;
	ListNode* temp2 = new ListNode;
	p = head;
	q = head;
	while (a>1) {
		p = p->next;
		a--;
	}
	while (b>1) {
		q = q->next;
		b--;
	}
	temp1->data = p->next->data;
	temp2 ->data= q->next->data;
	temp1->next = q->next->next;
	q->next = temp1;
	temp2->next = p->next->next;
	p->next = temp2;
	return OK;
}

int LinkList::LL_del(int i) {
	if (i > size)  return ERROR;
	ListNode* p=head,*temp;
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
	if (i > size||i<=0)  return ERROR;
	ListNode* p=head;
	while (i > 0) {
		p = p->next;
		i--;
	}
	return p->data;
}

void LinkList::LL_print() {
	ListNode* p = head->next;
	for (int i = 0; i < size; i++) {
		cout << p->data ;
		if (i != size - 1) cout << " ";
		else cout << endl;
		p = p->next;
	}
}

void LinkList::merge(ListNode *a,ListNode *b) {
	ListNode* pa, * pb;
	
	pa = a->next;
	pb = b->next;
	ListNode* pc = head ;
	while (pa !=NULL&& pb!=NULL) {
		if (pa->data <= pb->data) {
			LL_insert(pa->data, size + 1);
			pa = pa->next;
		}
		else {
			LL_insert(pb->data, size + 1);
			pb = pb->next;
		}
		
	}
	while (pa!=NULL) {
		LL_insert(pa->data, size + 1);
		pa = pa->next;
		
	}
	while(pb!=NULL) {
		LL_insert(pb->data, size + 1);
		pb = pb->next;
		
	}
}

/*******************************************/
//主函数定义
int main()
{
	int i, t, temp, pos,pos1,pos2,m;
	LinkList sl; //创建单链表
	LinkList s2;
   //初始化链表
	cin >> t; //输入初始长度
	for (i = 1; i <= t; i++)
	{
		cin >> temp; sl.LL_insert(temp, i);
	}
	
	cin >> m;
	for (i = 1; i <= m; i++)
	{
		cin >> temp; s2.LL_insert(temp, i);
	}
	LinkList s3;
	s3.merge(sl.index(0), s2.index(0));
	s3.LL_print();
	/*for (i = 0; i < 2; i++)
	{
		cin >> pos >> temp;
		t = sl.LL_insert(temp, pos);
		if (t == ERROR) cout << "error" << endl;
		else sl.LL_print();
	}
	for (i = 0; i < 2; i++)
	{
		cin >> pos;
		t = sl.LL_del(pos);
		if (t == ERROR) cout << "error" << endl;
		else sl.LL_print();
	}
	for (i = 0; i < 2; i++)
	{
		cin >> pos;
		t = sl.LL_get(pos);
		if (t == ERROR) cout << "error" << endl;
		else cout << t << endl;
	}*/
	//两次交换
	/*for (i = 0; i < 2; i++) {
		cin >> pos1 >> pos2;
		int t = sl.LL_exchange(pos1, pos2);
		if (t == ERROR) printf("error\n");
		else sl.LL_print();
	}*/
	return 0;
}
