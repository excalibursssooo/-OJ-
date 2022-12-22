#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(cin>>N){
        int a[101];
        for(int i = 0;i<N;i++){
            cin>>a[i];
        }
        int cnt = 0;
        for(int i = 0;i<N;i++){
            for(int j = i+1;j<N;j++){
                if(a[j]<a[i]){
                    int temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}