#include <iostream>
using namespace std;
int n;

void shellsort(int a[], int del) {
    for (int i = del+1; i <= n; i++) {
        if(a[i] > a[i-del]){
            int j;
            a[0] = a[i];
            for(j = i-del;j>0&&a[0]>a[j];j-=del){
                a[j+del] = a[j];
            }
            a[j+del] = a[0];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i];
        if (i < n) cout << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int a[101];
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int del = n/2;
        for(int i = del;i>0;i/=2){
            //cout<<i<<endl;
            shellsort(a,i);
        }
        cout << endl;
    }
}