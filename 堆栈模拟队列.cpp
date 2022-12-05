#include<bits/stdc++.h>
using namespace std;

int main(){
    int asize,bsize;
    cin>>asize>>bsize;
    int mins = min(asize,bsize);
    stack<int> a,b;
    while(1){
        char C;
        cin>>C;
        if(C == 'T') break;
        else if(C == 'A'){
            int ans;
            cin>>ans;
            if(a.size()>=mins){
                if(!b.empty()){
                    cout<<"ERROR:Full"<<endl;
                    continue;
                }
                else{
                    while(!a.empty()){
                        b.push(a.top());
                        a.pop();
                    }
                    a.push(ans);
                }
            }
            else{
                a.push(ans);
            }
        }
        else if(C == 'D'){
            if(b.empty()&&a.empty()){
                cout<<"ERROR:Empty"<<endl;
                continue;
            }
            else if(!b.empty()){
                cout<<b.top()<<endl;
                b.pop();
            }
            else if(b.empty()){
                while(!a.empty()){
                    b.push(a.top());
                    a.pop();
                }
                cout<<b.top()<<endl;
                b.pop();
            }
        }
    }
}