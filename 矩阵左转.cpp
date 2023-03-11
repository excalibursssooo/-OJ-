#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[2][3];
    for(int i = 0;i<2;i++){
        for(int j = 0;j<3;j++){
            cin>>a[i][j];
        }
    }
    int (*pa)[3] = a;
    for(int i = 2;i>=0;i--){
        for(int j = 0;j<2;j++){
            cout<<*(*(pa+j)+i)<<" ";
        }
        cout<<endl;
    }
}