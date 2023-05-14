#include <bits/stdc++.h>

using namespace std;

void wap(int *a, int *b) {
    int *p = a;
    a = b;
    b = p;
}


void wwap(int *a,int *b){
    int p = *a;
    *a = *b;
    *b = p;
}

int main() {
    int a = 0;
    int b = 1;
    int *pa = &a, *pb = &b;
    wap(pa, pb);

    cout << a << " " << b << endl;

    wwap(pa,pb);

    cout << a << " " << b << endl;
}