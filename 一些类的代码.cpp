#include <bits/stdc++.h>
using namespace std;

class Myclass {
    friend void friendfunc(Myclass *p); //全局函数友元，可以访问该类内私有
private:
    int age;
    int height;
    int *a = new int[100];
    int IQ;
    mutable int m_age;
public:
    static int wow; // 静态成员，多个对象共用一个
    // 构造
    Myclass() {
        age = 10;
        height = 180;
        for (int i = 0; i < 100; i++) {
            a[i] = i;
        }
        IQ = 0;
    }
    // 有参构造
    Myclass(int a, int b, int IQ) {
        age = a;
        height = b;
        this->IQ = IQ; // this指针的应用，解决重复变量名的问题
    }
    // 深拷贝
    Myclass(const Myclass &p) {
        age = p.age;
        height = p.height;
        a = new int[100];
        for (int i = 0; i < 100; i++) {
            a[i] = p.a[i];
        }
        IQ = p.IQ;
    }
    // this指针的应用，返回对象本身的引用
    Myclass& addothersAge(const Myclass &p){ //注意要返回引用
        this->age += p.age;
        return *this;
    }
    //
    //常函数
    void normalfunc() const{
        //age = 0;  普通的int不可以改
        m_age = 0; //加了mutable的变量可以改
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
    c.wow = 200; // 这里改变了c的wow因为这是静态所以同时也改变了p的wow
    p.addothersAge(c).addothersAge(c).addothersAge(c);
    p.show_index();
    cout<<"***"<<endl;
    friendfunc(&p);
}