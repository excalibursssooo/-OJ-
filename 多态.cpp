#include <bits/stdc++.h>
using namespace std;

class Dad {
public:
    //虚函数
    virtual void index() {
        cout << "这是爸爸" << endl;
    }
};

class Son : public Dad {
public:
    void index() {
        cout << "这是儿子" << endl;
    }
};

class Daughter : public Dad {
public:
    void index() {
        cout << "这是女儿" << endl;
    }
};

void showindex(Dad &d) {
    d.index();
}

void show() {
    Son s;
    Daughter d;
    showindex(s);
    showindex(d);
}

int main() {
    show();
}