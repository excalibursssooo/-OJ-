#include <bits/stdc++.h>
using namespace std;

template <typename T>
void SWAP(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
    
}
template <typename T>
void SORT(T a[],int len){
    for(int i = 0;i<len;i++){
        int min = i;
        for(int j = i+1;j<len;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        T temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

int main() {
    int a = 0;
    int b = 5;
    double c = 0.2;
    double d = 9.9;
    char cc = 'a';
    char ccc = 'b';
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    cout << cc << " " << ccc << endl;
    cout<<"--------------------------------------"<<endl;
    SWAP(a, b);
    SWAP(c, d);
    SWAP(cc, ccc);
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    cout << cc << " " << ccc << endl;


    int shu[10] = {1,5,6,8,7,2,49,39,56,4};
    char zifu[10] = {'a','g','A','1','9','t','T','/','~','&'};

    SORT(shu,10);
    SORT(zifu,10);


    for(int i = 0;i<10;i++){
        cout<<shu[i]<<" ";
    }
    cout<<endl;
    for(int i = 0;i<10;i++){
        cout<<zifu[i]<<" ";
    }
    cout<<endl;
}
