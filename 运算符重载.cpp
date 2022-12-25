#include <bits/stdc++.h>
using namespace std;

class Myclass {
public:
    int a;
    int b;
    int *c = new int(0);
    Myclass() {
        a = 10;
        b = 20;
        *c = 30;
    }
    Myclass(int a, int b) {
        this->a = a;
        this->b = b;
    }

    /*赋值重置
    Myclass& operator=(Myclass &p){
        if(c != NULL){
            delete c;
            c = NULL;
        }
        a = p.a;
        b = p.b;
        c = new int(*p.c);
    }
    */
   
    /*等等号重置*/
    bool operator==(Myclass &p) {
        if (this->a == p.a && this->b == p.b) {
            return true;
        }
        return false;
    }
    /*end*/

    /*重载前置++*/
    Myclass &operator++() {
        this->a++;
        this->b++;
        return *this; // 需要返回引用，否则只能操作一次
    }
    /*end*/

    /*重载后置++*/
    Myclass operator++(int) {
        Myclass temp;
        temp = *this; // 记录当前值，因为返回的是++前的值
        this->a++;
        this->b++;
        return temp; // 这里不是返回引用，因为temp是局部变量，函数结束就会被清理
    }
    /*end*/

    /*成员函数重载运算符*/
    Myclass operator+(Myclass &p) {
        Myclass temp;
        temp.a = this->a + p.a;
        temp.b = this->b + p.b;
        return temp;
    }
    Myclass operator-(Myclass &p) {
        Myclass temp;
        temp.a = this->a - p.a;
        temp.b = this->b - p.b;
        return temp;
    }
    Myclass operator*(Myclass &p) {
        Myclass temp;
        temp.a = this->a * p.a;
        temp.b = this->b * p.b;
        return temp;
    }
    Myclass operator/(Myclass &p) {
        Myclass temp;
        temp.a = this->a / p.a;
        temp.b = this->b / p.b;
        return temp;
    }
    /*end*/
};

/*下面是全局函数重载四则运算符

Myclass operator+(Myclass &p1, Myclass &p2) {
    Myclass temp;
    temp.a = p1.a + p2.a;
    temp.b = p1.b + p2.b;
    return temp;
}

Myclass operator-(Myclass &p1, Myclass &p2) {
    Myclass temp;
    temp.a = p1.a - p2.a;
    temp.b = p1.b - p2.b;
    return temp;
}

Myclass operator*(Myclass &p1, Myclass &p2) {
    Myclass temp;
    temp.a = p1.a * p2.a;
    temp.b = p1.b * p2.b;
    return temp;
}

end*/

// 左移运算符重载，需要作为全局函数
ostream &operator<<(ostream &cout, Myclass c) {
    cout << c.a << " " << c.b;
    return cout;
}

void test() {
    Myclass p1(20, 30);
    Myclass p2(100, 150);
    Myclass p3;
    if (p1 == p2) {
        cout << "YES!" << endl;
    } else
        cout << "NO~" << endl;
    p3 = p1 + p2;
    cout << p3.a << " " << p3.b << endl;
    p3 = p1 - p2;
    cout << p3.a << " " << p3.b << endl;
    p3 = p1 * p2;
    cout << p3.a << " " << p3.b << endl;
    cout << p3 << " 这是左移运算符重载" << endl;
    cout << ++(++p3) << " 前置++运算符重载" << endl;
    cout << p3++ << " 后置++运算符重载 " << p3 << endl;
}

int main() {
    test();
}