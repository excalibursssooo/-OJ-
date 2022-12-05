#include <iostream>
using namespace std;

#define OK 0
#define ERROR -1

void printfu(int i) {
	if (i < 0) cout << "(" << i << ")";
	else cout << i;
}

void printx(int i) {
	if (i < 0) cout << "x^" << "(" << i << ")";
	else if (i == 0) return;
	else if (i > 0) cout << "x^" << i;
}

//����ඨ��
class ListNode {
public:
	int data1;
	int data2;
	ListNode* next;
	ListNode()
	{
		data1 = -9999,data2 = -9999 , next = NULL;
	}
	ListNode(int item1,int item2 ,ListNode* pt)
	{
		data1 = item1,data2=item2 ,next = pt;
	}
};

class LinkList {
	//��ͷ���ĵ�������λ�ô�0��n��0��ͷ��㣬1���׽�㣬n��β���
private:
	ListNode* head; //ͷ���
	int size; //����

public:
	LinkList();  //���캯��������ͷ���
	ListNode* index(int i); //��λ���������ص�i�����
	~LinkList(); //�������������������
	int LL_insert(int item1,int item2, int i); //��iλ�ò���Ԫ�أ������ɹ���ʧ�ܷ���OK��ERROR
	int LL_del(int i);    //ɾ����iλ�õ�Ԫ�أ������ɹ���ʧ�ܷ���OK��ERROR
	int LL_get(int i);    //��ȡλ��i��Ԫ�ص���ֵ�����ҳɹ�������ֵ������ʧ�ܷ���ERROR
	void LL_print();    //��ӡ��������������
	int LL_exchange(int a, int b);
	void merge(ListNode* a, ListNode* b);
	int LL_get2(int i);
};
//��ʾ��index�������Բ�ʹ�á��������Ҫ�����������һ���պ����屣֤�﷨��ȷ��

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

LinkList::~LinkList() //Ҫ���������
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

//������������ຯ������
/********** Write your code here! **********/


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

int LinkList::LL_get(int i) {
	if (i > size)  return ERROR;
	ListNode* p = head;
	while (i > 0) {
		p = p->next;
		i--;
	}
	return p->data1;
}

int LinkList::LL_get2(int i) {
	if (i > size)  return ERROR;
	ListNode* p = head;
	while (i > 0) {
		p = p->next;
		i--;
	}
	return p->data2;
}

void LinkList::LL_print() {
	ListNode* p = head->next;
	if (p->data2 == 0) {
		cout << p->data1 ;
		cout << " + ";
		p = p->next;
	}
	for (int i = 1; i < size; i++) {
		printfu(p->data1);
		printx(p->data2);
		if(p->next!=NULL) cout << " + ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int i, t, temp, pos, pos1, pos2, m,n;
	LinkList sl; //����������
	LinkList s2;

	cin >> t;
	cout << t;
	while (t--) {
		cin >> m;
		cout << m;
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
	}
	sl.LL_print();
	s2.LL_print();
	return 0;
}
