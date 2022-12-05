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
	LinkList();
	~LinkList();
	int LL_insert(int item, int i); //第i位置插入元素，操作成功或失败返回OK或ERROR
	int LL_del(int i);
	int LL_get(int i);
	void LL_print();
	int LL_swap(int a, int b); 
	int LL_merge(ListNode* La, ListNode* Lb);
	ListNode* gethead()
	{
		return head;
	}
};
//提示：index函数可以不使用。如果不用要在填空区域定义一个空函数体保证语法正确性

LinkList::LinkList() : size(0)
{
	head = new ListNode();
}

LinkList::~LinkList()
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
ListNode* LinkList::index(int i)//定位函数，返回第i个结点
{
	ListNode* p = head;
	int j = 0;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}
int LinkList::LL_insert(int item, int i) //第i位置插入元素item，操作成功或失败返回OK或ERROR
{
	if (i > size + 1)
		return ERROR;
	ListNode* p = head;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	ListNode* s = new ListNode(item, p->next);
	p->next = s;
	size++;
	return OK;
}
int LinkList::LL_del(int i) //删除第i位置的元素，操作成功或失败返回OK或ERROR
{
	if (i > size)
		return ERROR;
	ListNode* p = head;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	ListNode* tmp = p->next;
	p->next = tmp->next;
	delete tmp;
	size--;
	return OK;
}
int LinkList::LL_get(int i) //获取位置i的元素的数值，查找成功返回数值，查找失败返回ERROR
{
	if (i > size)
		return ERROR;
	ListNode* p = head->next;
	int j = 1;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p->data;
}
void LinkList::LL_print()
{
	if (size == 0)
		return;
	ListNode* p = head->next;
	int j = 1;
	while (p != NULL && j <= size)
	{
		cout << p->data;
		if (j != size)
			cout << " ";
		p = p->next;
		j++;
	}
	cout << endl;
}


int LinkList::LL_swap(int a, int b)
{
	if (a > size)
		return ERROR;
	ListNode* p1 = head;
	int j1 = 0;
	while (p1 != NULL && j1 < a - 1)
	{
		p1 = p1->next;
		j1++;
	}
	if (b > size)
		return ERROR;
	ListNode* p2 = head;
	int j2 = 0;
	while (p2 != NULL && j2 < b - 1)
	{
		p2 = p2->next;
		j2++;
	}
	ListNode* tmp1 = p1->next;
	ListNode* tmp2 = p1->next->next;
	p1->next->next = p2->next->next;
	p2->next->next = tmp2;
	p1->next = p2->next;
	p2->next = tmp1;
	return OK;
}

int LinkList::LL_merge(ListNode* La, ListNode* Lb)
{
	ListNode* Lc = head;
	while (La != NULL && Lb != NULL)
	{
		if (La->data > Lb->data)
		{
			Lc->next = Lb;
			Lc = Lc->next;
			Lb = Lb->next;
		}
		else
		{
			Lc->next = La;
			Lc = Lc->next;
			La = La->next;
		}
		size++;
	}
	while (La != NULL)
	{
		Lc->next = La;
		Lc = Lc->next;
		La = La->next;
		size++;
	}
	while (Lb != NULL)
	{
		Lc->next = Lb;
		Lc = Lc->next;
		Lb = Lb->next;
		size++;
	}
	return OK;
}
//主函数定义
int main()
{
	int i, t, temp, pos;
	LinkList sl;
//初始化链表
	cin >> t; //输入初始长度
	for (i = 1; i <= t; i++)
	{
		cin >> temp;
		sl.LL_insert(temp, i);
	}
	//    sl.LL_print();


	LinkList sk;
//初始化链表
	cin >> t; //输入初始长度
	for (i = 1; i <= t; i++)
	{
		cin >> temp;
		sk.LL_insert(temp, i);
	}
	//    sk.LL_print();

	LinkList sj;
	ListNode* p1 = sl.gethead()->next;
	ListNode* p2 = sk.gethead()->next;
	sj.LL_merge(p1, p2);
	sj.LL_print();

	// //两次插入
	//  for (i=0; i<2; i++)
	//  {
	//      cin>>pos>>temp;
	//      t=sl.LL_insert(temp, pos);
	//      if (t==ERROR) cout<<"error"<<endl;
	//      else sl.LL_print();
	//  }
	// //两次删除
	//  for (i=0; i<2; i++)
	//  {
	//      cin>>pos;
	//      t=sl.LL_del(pos);
	//      if (t==ERROR) cout<<"error"<<endl;
	//      else sl.LL_print();
	//  }
	// //两次查找
	//  for (i=0; i<2; i++)
	//  {
	//      cin>>pos;
	//      t=sl.LL_get(pos);
	//      if (t==ERROR) cout<<"error"<<endl;
	//      else cout<<t<<endl;
	//  }
	//     cin >> pos >> temp;
	//     if(!sl.LL_swap(pos, temp))
	//         sl.LL_print();
	//     else
	//         cout << "error" << endl;
	//     cin >> pos >> temp;
	//     if(!sl.LL_swap(pos, temp))
	//         sl.LL_print();
	//     else
	//         cout << "error" << endl;
	return 0;
}


