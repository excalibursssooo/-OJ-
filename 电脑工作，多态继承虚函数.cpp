#include <bits/stdc++.h>
using namespace std;
// CPU类
class CPU {
public:
    virtual void start() = 0;
};
// GPU类
class GPU {
public:
    virtual void start() = 0;
};
// 内存类
class Mem {
public:
    virtual void start() = 0;
};

/*CPU 的厂商*/
class intel : public CPU {
public:
    void start() {
        cout << "英特尔芯片正在工作！" << endl;
    }
};

class AMD : public CPU {
public:
    void start() {
        cout << "AMD芯片正在工作！" << endl;
    }
};

/*end*/

/*GPU的厂商*/
class Nvida : public GPU {
public:
    void start() {
        cout << "英伟达显卡正在工作！" << endl;
    }
};

class AMDYES : public GPU {
public:
    void start() {
        cout << "AMD显卡正在工作！" << endl;
    }
};
/*end*/

/*内存条的厂商*/
class samsung : public Mem {
public:
    void start() {
        cout << "三星内存正在工作!" << endl;
    }
};

class qita : public Mem {
public:
    void start() {
        cout << "不知名的内存正在工作!" << endl;
    }
};
/*end*/

class computer {
public:
    CPU *c;
    GPU *g;
    Mem *m;
    computer(CPU *c, GPU *g, Mem *m) {
        this->c = c;
        this->g = g;
        this->m = m;
    }

    void work() {
        c->start();
        g->start();
        m->start();
    }

    ~computer() {
        if (c != NULL) {
            delete c;
            c = NULL;
        }
        if (g != NULL){
            delete g;
            g = NULL;
        }
        if (m != NULL){
            delete m;
            m = NULL;
        }
    }
};

void test() {
    computer *c = new computer(new intel, new AMDYES, new samsung);
    c->work();
    delete c;
    c = new computer(new AMD, new Nvida, new qita);
    c->work();
    delete c;
}

int main() {
    test();
}
