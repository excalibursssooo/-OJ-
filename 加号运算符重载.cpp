#include <bits/stdc++.h>
using namespace std;

class Myclass {
public:
    int a;
    int b;
    Myclass() {
        a = 10;
        b = 20;
    }
    Myclass(int a, int b) {
        this->a = a;
        this->b = b;
    }
};

Myclass operator+(Myclass &p1, Myclass &p2) {
    Myclass temp;
    temp.a = p1.a + p2.a;
    temp.b = p1.b + p2.b;
    return temp;
}

Myclass operator-(Myclass &p1, Myclass &p2) {
    Myclass temp;
    temp.a = p1.a - p2.a;
    temp.b = p1.b - p2.b;
    return temp;
}

Myclass operator*(Myclass &p1, Myclass &p2) {
    Myclass temp;
    temp.a = p1.a * p2.a;
    temp.b = p1.b * p2.b;
    return temp;
}

void test() {
    Myclass p1(20, 30);
    Myclass p2(100, 150);
    Myclass p3;
    p3 = p1 + p2;
    cout << p3.a << " " << p3.b << endl;
    p3 = p1 - p2;
    cout << p3.a << " " << p3.b << endl;
    p3 = p1 * p2;
    cout << p3.a << " " << p3.b << endl;
}

int main() {
    test();
}