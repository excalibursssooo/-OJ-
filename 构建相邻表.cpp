
#include<iostream>
using namespace std;

class Node {
public:
    int pos = 0;
    Node* next = NULL;
};

class MapNode {
public:
    char data;
    Node* root;
    MapNode() {
        data = '^';
        root = new Node;
    }
    void Insert(int pos) {
        Node* p = new Node;
        p->pos = pos;
        Node* q = root;
        while (q->next != NULL) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        cout << q->next->pos << endl;
    }
    void show() {
        cout << data;
        Node* q = root;
        q = q->next;
        while (q!=NULL) {
            cout <<  "-"<< q->pos;
            q = q->next;
        }
        cout << "-^" << endl;
    }
};


class Map {
public:
    int ding;
    int bian;
    char d[100];
    MapNode** head = new MapNode*[20];
    void Initial() {
        cin >> ding;
        cin >> bian;
        for (int i = 0; i < ding; i++) {
            char letter;
            cin >> letter;
            head[i] = new MapNode;
            head[i]->data = letter;
            d[i] = letter;
        }
        for (int i = 0; i < bian; i++) {
            char a;
            cin >> a;
            int j = 0;
            for (j = 0; j < ding; j++) {
                if (d[j] == a) break;
            }
            char b;
            cin >> b;
            int k = 0;
            for (k = 0; k < ding; k++) {
                if (d[k] == b) break;
            }
            cout << j << " " << k << endl;
            head[j]->Insert(k);
        }
    }
    void show() {
        for (int i = 0; i < ding; i++) {
            cout << i << " ";
            head[i]->show();
        }
        cout << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Map myMap;
        myMap.Initial();
        myMap.show();
    }
}