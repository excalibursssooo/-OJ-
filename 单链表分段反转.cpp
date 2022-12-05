#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        data = 0;
        next = NULL;
    }
};

class List {
public:
    Node *head;
    int size;
    List() {
        head = new Node;
        size = 0;
    }
    void insert(int pos, int num) {
        if (pos == 0) {
            head->data = num;
            size++;
            return;
        }
        Node *p = new Node;
        p->data = num;
        Node *q = head;
        for (int i = 1; i < size; i++) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        size++;
    }
    void print() {
        Node *q = head;
        for (int i = 0; i < size; i++) {
            cout << q->data << " ";
            q = q->next;
        }
        cout << endl;
    }
    void Reverse(int K) {
        int ka = K - 1;
        Node *p = head;
        Node *cur = p;
        Node *pre = NULL;
        Node *nex = p->next;
        cur->next = pre;
        int num = size / K;
        //cout << num << endl;
        while (ka--) {
            pre = cur;
            cur = nex;
            nex = cur->next;
            cur->next = pre;
        }
        p->next = nex;
        head = cur;
        num--;
        while (num) {
            ka = K - 1;
            pre = p;
            p = nex;
            cur = p;
            nex = p->next;
            cur->next = pre;
             Node* t = pre;
            //cout<<p->data<<endl;
            //cout<<p->data<<"/"<<cur->data<<" "<<nex->data<<"*"<<endl;
            while (ka--) {
                pre = cur;
                cur = nex;
                nex = cur->next;
                cur->next = pre;
            }
            //cout<<p->data<<"/"<<cur->data<<" "<<nex->data<<"*"<<endl;
            t->next = cur;
            p->next = nex;
            num--;
        }
        // cout<<cur->data<<endl;
    }
};

int main() {
    int n;
    cin >> n;
    List myList = List();
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        myList.insert(i, num);
    }
    int K;
    cin >> K;
    myList.Reverse(K);
    myList.print();
}