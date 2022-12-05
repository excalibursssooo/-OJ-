#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int num[1001];
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>num[i];
    }

    int a[2],b[2];
    cin>>a[0]>>b[0];
    a[1] = a[0];
    b[1] = b[0];
    do{
        
        if(a[0]>b[0]) a[0] = a[0]/2;
        else if(a[0]<b[0]) b[0] = b[0]/2;
        if(num[a[0]] == 0){
            cout<<"ERROR: T["<<a[1]<<"] is NULL"<<endl;
            break;
        }
        if(num[b[0]] == 0){
            cout<<"ERROR: T["<<b[1]<<"] is NULL"<<endl;
            break;
        }
        if(a[0] == b[0])cout<<a[0]<<" "<<num[a[0]]<<endl;
    }while(a[0]!=b[0]);

    
}