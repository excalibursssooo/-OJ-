#include <iostream>
using namespace std;
int cnt = 0;
struct Node {
    int Data;
    Node *Next;
};
Node *CreateList() {
    Node *head = new Node;
    head->Next = NULL;
    int flag = 0;
    while (flag == 0) {
        Node *node = new Node;
        cin >> node->Data;
        if (node->Data < 0) {
            node->Next = NULL;
            flag = 1;
        } else {
            cnt++;
            node->Next = head->Next;
            head->Next = node;
        }
    }
    return head;
}

int FindNode(Node *node, int k) {
    if (k > cnt) {
        cout << "NULL";
    } else {
        for (int i = 0; i < k; i++) {
            node = node->Next;
        }
        cout << node->Data;
    }
}
int main() {
    int k;
    cin >> k;
    Node *L;
    L = CreateList();
    FindNode(L, k);
    return 0;
}