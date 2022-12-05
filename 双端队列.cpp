#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *front;
    Node *next;
    Node() {
        data = 0;
        front = NULL;
        next = NULL;
    }
};

class Dqueue {
private:
    int Maxsize;
    int nowsize;

public:
    Node *head;
    Node *back;
    Dqueue() {
        head = new Node;
        back = new Node;
        head->next = back;
        back->front = head;
        nowsize = 0;
        cin >> Maxsize;
    }
    void Push(int num);
    void Pop();
    void Eject();
    void Inject(int num);
    void action();
};

void Dqueue::Push(int num) {
    if (nowsize == Maxsize) {
        cout << "Deque is Full!" << endl;
        return;
    }
    Node *p = new Node;
    p->data = num;
    p->next = head->next;
    p->front = head;
    head->next->front = p;
    head->next = p;
    nowsize++;
}

void Dqueue::Inject(int num) {
    if (nowsize == Maxsize) {
        cout << "Deque is Full!" << endl;
        return;
    }
    Node *p = new Node;
    Node *t = back->front;
    p->data = num;
    t->next = p;
    p->front = t;
    p->next = back;
    // p->front->next = p;
    back->front = p;
    nowsize++;
}

void Dqueue::Pop() {
    if (nowsize == 0) {
        cout << "Deque is Empty!" << endl;
        return;
    }
    cout << head->next->data << " is out" << endl;
    head->next->next->front = head;
    head->next = head->next->next;
    nowsize--;
}

void Dqueue::Eject() {
    if (nowsize == 0) {
        cout << "Deque is Empty!" << endl;
        return;
    }
    cout << back->front->data << " is out" << endl;
    back->front->front->next = back;
    back->front = back->front->front;
    nowsize--;
}

void Dqueue::action() {
    while (1) {
        string s;
        cin >> s;
        if (s == "End") {
            break;
        }
        if (s == "Pop") {
            Pop();
        }
        if (s == "Inject") {
            int a;
            cin >> a;
            Inject(a);
        }
        if (s == "Push") {
            int a;
            cin >> a;
            Push(a);
        }
        if (s == "Eject") {
            Eject();
        }
    }
}

int main() {
    Dqueue myDeque;
    myDeque.action();
}