#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    int a[1001];
    a[0] = 0;
    for (int i = 1; i <= T; i++) {
        cin >> a[i];
    }
    //sort(a,a+T);
    int M;
    cin >> M;
    for(int i = 0;i<M;i++){
        int key;
        cin>>key;
        int t = (T+1)/2;
        int templ = 1;
        int  tempr = T;
        while(1){
            if(templ>tempr){
                cout<<"error"<<endl;
                break;
            }
            if(key == a[t]){
                cout<<t<<endl;
                break;
            }
            else if(key < a[t]){
                tempr = t-1;
                t = (tempr+templ)/2;
                
            }
            else if(key > a[t]){
                templ = t+1;
                t = (templ+tempr)/2;
            }
        }
    }
}