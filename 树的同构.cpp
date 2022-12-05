#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int lchild = -1;
    int rchild = -1;
    int parent = -1;
    char data = '#';
};

int flag = 0;
void find(TreeNode* t1,TreeNode* t2,int root1,int root2){
    if(flag == 1) return;
    int l,r;
    l = t1[root1].lchild;
    r = t1[root1].rchild;
    int l2,r2;
    l2 = t2[root2].lchild;
    r2 = t2[root2].rchild;
    if(l2 == -1&&r2 == -1){
        
        if(l!=-1||r!=-1){
            //cout<<"****"<<endl;
            flag = 1;
            return;
        }
        else return;
    }
    if(l2 == -1||r2 ==-1){
        if(l == -1&&r == -1){
            flag = 1;
            return;
        }
        if(l2 == -1){
            if(l == -1 && t1[r].data == t2[r2].data){
                find(t1,t2,r,r2);
            }
            else if(r == -1&&t1[l].data == t2[r2].data){
                t1[root1].lchild = r;
                t1[root1].rchild = l;
                find(t1,t2,t1[root1].rchild,r2);
            }
            else{
                flag = 1;
                return;
            }
        }
        else if(r2 == -1){
            if(l == -1 && t1[r].data == t2[r2].data){
                t1[root1].lchild = r;
                t1[root1].rchild = l;
                find(t1,t2,t1[root1].lchild,l2);
            }
            else if(r == -1&&t1[l].data == t2[l2].data){
                find(t1,t2,l,l2);
            }
            else{
                flag = 1;
                return;
            }
        }
    }
    
    else if(t1[l].data!=t2[l2].data&&t1[l].data!=t2[r2].data){
        flag = 1;
        return;
    }
    else if(t1[r].data!=t2[l2].data&&t1[r].data!=t2[r2].data){
        flag = 1;
        return;
    }
    else if(t1[r].data == t2[r2].data&&t1[l].data == t2[l2].data){
        
        find(t1,t2,l,l2);
        find(t1,t2,r,r2);
    }
    else{
        t1[root1].lchild = r;
        t1[root1].rchild = l;
        find(t1,t2,t1[root1].lchild,l2);
        find(t1,t2,t1[root1].rchild,r2);
    }

    

    
}

int main() {
    TreeNode* t1 = new TreeNode[101];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin>>t1[i].data;
        char a, b;
        cin >> a;
        if (a == '-') t1[i].lchild = -1;
        else t1[i].lchild = a - '0';
        cin >> b;
        if (b == '-') t1[i].rchild = -1;
        else t1[i].rchild = b - '0';
    }
    int root1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (t1[j].lchild == i || t1[j].rchild == i) {
                t1[i].parent = j;
                break;
            }
        }
        if (t1[i].parent == -1) root1 = i;
    }
    TreeNode* t2 = new TreeNode[101];
    int n1;
    cin >> n1;
    if(n1!=n) cout<<"NO"<<endl;
    for (int i = 0; i < n1; i++) {
        cin>>t2[i].data;
        char a, b;
        cin >> a;
        if (a == '-') t2[i].lchild = -1;
        else t2[i].lchild = a - '0';
        cin >> b;
        if (b == '-') t2[i].rchild = -1;
        else t2[i].rchild = b - '0';
    }
    
    int root2 = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            if (t2[j].lchild == i || t2[j].rchild == i) {
                t2[i].parent = j;
                break;
            }
        }
        if (t2[i].parent == -1) root2 = i;
    }
    
    find(t1,t2,root1,root2);
    if(flag == 1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    

}