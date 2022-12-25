#include <bits/stdc++.h>
using namespace std;

class Dad {
public:
    int a;
    Dad(){
        a = 100;
    }
    void dadinfo() {
        cout << "这是公共部分" << endl;
    }
    void dadinfo2() {
        cout << "this is public aspect" << endl;
    }
};

class son : public Dad {
public:
    son(){
        a = 200;
    }
    int a;
    void pprintt(string s) {
        cout << "儿子" << s << endl;
    }
};

void test() {
    son a, b, c, d;
    string s;
    cin >> s;
    a.pprintt(s);
    a.dadinfo();
    a.dadinfo2();
    cout << "---------------------------------------" << endl;
    cin >> s;
    b.pprintt(s);
    b.dadinfo();
    b.dadinfo2();
    cout << "---------------------------------------" << endl;

    cin >> s;
    c.pprintt(s);
    c.dadinfo();
    c.dadinfo2();
    cout << "---------------------------------------" << endl;

    cin >> s;
    d.pprintt(s);
    d.dadinfo();
    d.dadinfo2();
    cout << "---------------------------------------" << endl;

    cout<<"这是访问子类a"<<d.a<<endl;
    cout<<"这是访问父类a"<<d.Dad::a<<endl;


}

int main() {
    test();
}