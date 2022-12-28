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
        cout << "倒入水" << endl;
    }
    virtual void cailiao() {
        cout << "tomato,eggs" << endl;
    }
    virtual void method() {
        cout << "蒸" << endl;
    }
    virtual void tiaoliao() {
        cout << "sugar,sult,生粉" << endl;
    }
};

class paigu : public Cook {
    public:
    virtual void prepare() {
        cout << "倒入水" << endl;
    }
    virtual void cailiao() {
        cout << "排骨" << endl;
    }
    virtual void method() {
        cout << "焖" << endl;
    }
    virtual void tiaoliao() {
        cout << "sugar,sult,生粉" << endl;
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
    //制作西红柿
    beginCook(new tomato);
    //制作排骨
    beginCook(new paigu);
}


int main(){
    test();
}