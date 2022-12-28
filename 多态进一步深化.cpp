#include <bits/stdc++.h>
using namespace std;

class Cook {
public:
    virtual void prepare() = 0;
    virtual void cailiao() = 0;
    virtual void method() = 0;
    virtual void tiaoliao() = 0;
};

class tomato : public Cook {
public:
    virtual void prepare() {
        cout << "����ˮ" << endl;
    }
    virtual void cailiao() {
        cout << "tomato,eggs" << endl;
    }
    virtual void method() {
        cout << "��" << endl;
    }
    virtual void tiaoliao() {
        cout << "sugar,sult,����" << endl;
    }
};

class paigu : public Cook {
    public:
    virtual void prepare() {
        cout << "����ˮ" << endl;
    }
    virtual void cailiao() {
        cout << "�Ź�" << endl;
    }
    virtual void method() {
        cout << "��" << endl;
    }
    virtual void tiaoliao() {
        cout << "sugar,sult,����" << endl;
    }
};


void beginCook(Cook* c){
    c->cailiao();
    c->method();
    c->prepare();
    c->tiaoliao();
    delete c;
    c = NULL;
}

void test(){
    //����������
    beginCook(new tomato);
    //�����Ź�
    beginCook(new paigu);
}


int main(){
    test();
}