#include <bits/stdc++.h>
using namespace std;

class Dad {
public:
    //�麯��
    virtual void index() {
        cout << "���ǰְ�" << endl;
    }
};

class Son : public Dad {
public:
    void index() {
        cout << "���Ƕ���" << endl;
    }
};

class Daughter : public Dad {
public:
    void index() {
        cout << "����Ů��" << endl;
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