#include <iostream>
using namespace std;

#define OK 0
#define ERROR -1

//����ඨ��
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
	//��ͷ���ĵ�����λ�ô�0��n��0��ͷ��㣬1���׽�㣬n��β���
private:
	ListNode* head; //ͷ���
	int size; //��
	ListNode* index(int i); //��λ���������ص�i�����
public:
	LinkList();		//���캯��������ͷ���
	~LinkList();	//�������������������
	int LL_insert(int item, int i);	//��iλ�ò���Ԫ�أ������ɹ���ʧ�ܷ���OK��ERROR
	int LL_del(int i);				//ɾ����iλ�õ�Ԫ�أ������ɹ���ʧ�ܷ���OK��ERROR
	int LL_get(int i);				//��ȡλ��i��Ԫ�ص���ֵ�����ҳɹ�������ֵ������ʧ�ܷ���ERROR
	void LL_print();				//��ӡ��������������
};
//��ʾ��index�������Բ�ʹ�á��������Ҫ�����������һ���պ����屣֤�﷨��ȷ��

LinkList::LinkList() : size(0)
{
	head = new ListNode();
}

LinkList::~LinkList()	//Ҫ���������
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
//����������
int main()
{
	int i, t, temp, pos;
	LinkList sl;	//����������
//��ʼ������
	cin >> t;	//�����ʼ����
	for (i = 1; i <= t; i++)
	{
		cin >> temp;	sl.LL_insert(temp, i);
	}
	sl.LL_print();
	//���β���
	for (i = 0; i < 2; i++)
	{
		cin >> pos >> temp;
		t = sl.LL_insert(temp, pos);
		if (t == ERROR) cout << "error" << endl;
		else sl.LL_print();
	}
	//����ɾ��
	for (i = 0; i < 2; i++)
	{
		cin >> pos;
		t = sl.LL_del(pos);
		if (t == ERROR) cout << "error" << endl;
		else sl.LL_print();
	}
	//���β���
	for (i = 0; i < 2; i++)
	{
		cin >> pos;
		t = sl.LL_get(pos);
		if (t == ERROR) cout << "error" << endl;
		else cout << t << endl;
	}
	return 0;
}
