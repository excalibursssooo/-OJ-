#include <iostream>
using namespace std;
class node//链表结点
{
public:
	node* next = NULL;
	int num = 0;//结点作为头结点的序号
};
class list
{
public:
	node* root = new node;
	char data;
};
class graph
{
public:
	//list* a = new list;//链表数组
	list a[100];
	void create(int n, int m);
	int find(int t, int n);
	void link(int b, int c, int n);
	void printf(int n);
};
void graph::create(int n, int m)//n是结点数，m是弧的数目
{
	char b; char c;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].data;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b >> c;
		link(b, c, n);
	}
}
int graph::find(int t, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (t == a[i].data)
			return i;
	}
}
void graph::link(int b, int c, int n)
{
	node* p = new node;
	int b1 = find(b, n);
	int c1 = find(c, n);
	//A->B 创建A到B的弧，找到B的序号然后赋值，找到A，在它的链表中接上B
	p->num = c1;
	p->next = NULL;
	node* head = a[b1].root;
	cout << b1 << endl;
		while (head!= NULL)
		{
			if (head->next == NULL) {
				p->next = head->next;
				head->next = p;
				break;
			}
			head= head->next;
		}
}
void graph::printf(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << a[i].data;
		node* head = a[i].root;
		while (head->next!= NULL)
		{
			cout << "-" << head->next->num;
			head = head->next;
		}
		cout << "-" << "^" << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		graph g;
		g.create(n, m);
		g.printf(n);
	}
	return 0;
}