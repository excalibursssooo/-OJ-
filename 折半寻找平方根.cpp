#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        double d;
        cin>>d;
        double left = 0;
        double right = d;
        double mid = (left+right)/2;
        while(abs(mid*mid-d)>0.00001){
            if(mid*mid>d){
                right = mid;
                mid = (left+right)/2;
            }
            else{
                left = mid;
                mid = (left+right)/2;
            }
        }
        cout<<fixed<<setprecision(3)<<mid<<endl;
    }
}