#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
};

class List{
public:
    Node* root = new Node;
    int size;
    void insert(int pos,int num);
    List(){
        size = 0;
    }
    void del();
    void deldup();
};

void List::insert(int pos,int num){
    Node* p = new Node;
    p->data = num;
    Node* q = root;
    for(int i=0;i<pos;i++){
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    size++;
}


void List::del(){
     Node* p, * q, * r;
        p = root;
        while (p)
        {
            q = p;
            while (q->next)
            {
                if (q->next->data == p->data)
                {
                    r = q->next;
                    q->next = r->next;
                    free(r);
                    size--;
                }
                else q = q->next;
            }
            p = p->next;
        }
}


void List::deldup(){
    del();
    cout<<size<<": ";
    Node* p = root->next;
    for(int i = 0;i<size;i++){
        cout<<p->data;
        p = p->next;
        if(i == size-1) cout<<endl;
        else cout<<" ";
    }
}



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        List myList;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            myList.insert(i,num);
        }
        myList.deldup();
    }
}