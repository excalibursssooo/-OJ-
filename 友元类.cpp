#include <bits/stdc++.h>
using namespace std;

class Myself {
    friend class Others; // ��Ԫ�����Է���˽�У�ʹ���������к������ɷ���
    friend void Others::visitMe(); //��һ��д������ʹ�ض�������Ϊ��Ԫ��ֻ��ָ���������Է���
private:
    int weight;

public:
    string hobby;
    Myself() {
        weight = 130;
        hobby = "��,��,RAP,����";
    }
};

class Others {
public:
    Myself *Me = new Myself;
    void visitMe() {
        cout << "��֪����İ�����" << Me->hobby << endl;
        cout << "�һ�֪�����������" << Me->weight << endl;
    }
};

void show() {
    Others p;
    p.visitMe();
}

int main() {
    show();
}