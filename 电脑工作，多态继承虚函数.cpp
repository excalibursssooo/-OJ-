#include <bits/stdc++.h>
using namespace std;
// CPU��
class CPU {
public:
    virtual void start() = 0;
};
// GPU��
class GPU {
public:
    virtual void start() = 0;
};
// �ڴ���
class Mem {
public:
    virtual void start() = 0;
};

/*CPU �ĳ���*/
class intel : public CPU {
public:
    void start() {
        cout << "Ӣ�ض�оƬ���ڹ�����" << endl;
    }
};

class AMD : public CPU {
public:
    void start() {
        cout << "AMDоƬ���ڹ�����" << endl;
    }
};

/*end*/

/*GPU�ĳ���*/
class Nvida : public GPU {
public:
    void start() {
        cout << "Ӣΰ���Կ����ڹ�����" << endl;
    }
};

class AMDYES : public GPU {
public:
    void start() {
        cout << "AMD�Կ����ڹ�����" << endl;
    }
};
/*end*/

/*�ڴ����ĳ���*/
class samsung : public Mem {
public:
    void start() {
        cout << "�����ڴ����ڹ���!" << endl;
    }
};

class qita : public Mem {
public:
    void start() {
        cout << "��֪�����ڴ����ڹ���!" << endl;
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
