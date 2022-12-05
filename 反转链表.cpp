#include<bits/stdc++.h>

using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* front;
    Node(){
        data = 0;
        next = NULL;
        front = NULL;
    }
};

class List{
public:
    Node* head;
    int len=0;
    int start;
    int num;
    List(){
        head = new Node;
        len = 0;
    }
    void InsertList(int pos,int data){
        Node* p = new Node;
        Node* q = head;
        p->data = data;
        while(pos){
            q = q->next;
            pos--;
        }
        p->next = q->next;
        p->front = q;
        q->next = p;
        len++;
    }
    void print(){
        Node *p = head->next;
        for(int i=0;i<len;i++){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
    void Reverse(){
        Node* p = new Node;
        Node* q = head;
        for(int i = 0;i<len;i++){
            q = q->next;
        }
        head =q;
        for(int i=0;i<len;i++){
            q->next = q->front;
            //cout<<q->front->data;
            q = q->front;
        }
    }
    void index(int pos){
        Node* p = head;
        while(pos>1){
            p = p->next;
            pos--;
        }
        cout<<p->data;
    }
    void circle(){
        Node* p = head;
        for(int i=0;i<len;i++){
            p = p->next;
        }
        head->next->front = p;
        p->next = head->next;
    }
    void yuesefu(int start,int num){
        Node* p = head->next;
        while(p->next!=p){
            for(int i=0;i<start;i++){
                p = p->next;
            }
            for(int i=0;i<num-1;i++){
                p = p->next;
            }
            cout<<p->next->data<<" ";
            p->next = p->next->next;
        }
    }
};

int main(){
    List l1;
    int le;
    cin>>le;
    int start,num;
    cin>>l1.start>>l1.num;
    for(int i=0;i<le;i++){
        
        l1.InsertList(i,i+1);
    }
    l1.circle();
    l1.yuesefu(start,num);
}