#include <bits/stdc++.h>
using namespace std;

class Myself {
    friend class Others; // 友元，可以访问私有，使该类内所有函数均可访问
    friend void Others::visitMe(); //另一种写法，可使特定函数作为友元，只有指定函数可以访问
private:
    int weight;

public:
    string hobby;
    Myself() {
        weight = 130;
        hobby = "唱,跳,RAP,篮球";
    }
};

class Others {
public:
    Myself *Me = new Myself;
    void visitMe() {
        cout << "我知道你的爱好是" << Me->hobby << endl;
        cout << "我还知道你的体重是" << Me->weight << endl;
    }
};

void show() {
    Others p;
    p.visitMe();
}

int main() {
    show();
}