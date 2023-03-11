#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int *pa = &a, *pb = &b, *pc = &c;
        if (*pa > *pb) {
            int t = *pb;
            *pb = *pa;
            *pa = t;
        }
        if (*pa > *pc) {
            int t = *pc;
            *pc = *pa;
            *pa = t;
        }
        if (*pb > *pc) {
            int t = *pc;
            *pc = *pb;
            *pb = t;
        }
        cout << *pa << " " << *pb << " " << *pc << endl;
    }
}