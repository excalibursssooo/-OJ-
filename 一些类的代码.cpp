#include <bits/stdc++.h>
using namespace std;

class Myclass {
    friend void friendfunc(Myclass *p); //ȫ�ֺ�����Ԫ�����Է��ʸ�����˽��
private:
    int age;
    int height;
    int *a = new int[100];
    int IQ;
    mutable int m_age;
public:
    static int wow; // ��̬��Ա�����������һ��
    // ����
    Myclass() {
        age = 10;
        height = 180;
        for (int i = 0; i < 100; i++) {
            a[i] = i;
        }
        IQ = 0;
    }
    // �вι���
    Myclass(int a, int b, int IQ) {
        age = a;
        height = b;
        this->IQ = IQ; // thisָ���Ӧ�ã�����ظ�������������
    }
    // ���
    Myclass(const Myclass &p) {
        age = p.age;
        height = p.height;
        a = new int[100];
        for (int i = 0; i < 100; i++) {
            a[i] = p.a[i];
        }
        IQ = p.IQ;
    }
    // thisָ���Ӧ�ã����ض����������
    Myclass& addothersAge(const Myclass &p){ //ע��Ҫ��������
        this->age += p.age;
        return *this;
    }
    //
    //������
    void normalfunc() const{
        //age = 0;  ��ͨ��int�����Ը�
        m_age = 0; //����mutable�ı������Ը�
    }
    void show_index() {
        cout << age << " " << height << " " << wow << endl;
    }
    ~Myclass() {
        //cout << "delete suscessfully" << endl;
        delete[] a;
    }
};

void friendfunc(Myclass *p){
    cout<<p->age<<" "<<p->height<<endl;
}

int Myclass::wow = 100;

int main() {
    Myclass c(100, 130, 131);
    Myclass p(c);
    c.wow = 200; // ����ı���c��wow��Ϊ���Ǿ�̬����ͬʱҲ�ı���p��wow
    p.addothersAge(c).addothersAge(c).addothersAge(c);
    p.show_index();
    cout<<"***"<<endl;
    friendfunc(&p);
}