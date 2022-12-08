#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    int a[1001];
    for (int i = 1; i <= T; i++) {
        cin >> a[i];
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int key;
        cin>>key;
        a[0] = key;
        for(int j = T+1;j>=0;j--){
            if(key == a[j]){
                if(j != 0){
                    cout<<j<<endl;
                    break;
                }
                else{
                    cout<<"error"<<endl;
                    break;
                }
            }
        }
    }
}