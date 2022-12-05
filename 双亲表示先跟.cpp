#include<bits/stdc++.h>

using namespace  std;

void search(int n,int m,char a[],int b[]){
    for(int i=0;i<m;i++){
        if(b[i] == n){
            cout<<a[i];
            search(i,m,a,b);
        }
    }
}


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        char a[1001];
        int b[1001];
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        for(int i=0;i<N;i++){
            cin>>b[i];
        }
        int k = -1;
        search(k,N,a,b);
        cout<<endl;
    }
}