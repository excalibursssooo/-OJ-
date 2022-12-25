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

    /*��ֵ����
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
   
    /*�ȵȺ�����*/
    bool operator==(Myclass &p) {
        if (this->a == p.a && this->b == p.b) {
            return true;
        }
        return false;
    }
    /*end*/

    /*����ǰ��++*/
    Myclass &operator++() {
        this->a++;
        this->b++;
        return *this; // ��Ҫ�������ã�����ֻ�ܲ���һ��
    }
    /*end*/

    /*���غ���++*/
    Myclass operator++(int) {
        Myclass temp;
        temp = *this; // ��¼��ǰֵ����Ϊ���ص���++ǰ��ֵ
        this->a++;
        this->b++;
        return temp; // ���ﲻ�Ƿ������ã���Ϊtemp�Ǿֲ����������������ͻᱻ����
    }
    /*end*/

    /*��Ա�������������*/
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

/*������ȫ�ֺ����������������

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

// ������������أ���Ҫ��Ϊȫ�ֺ���
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
    cout << p3 << " �����������������" << endl;
    cout << ++(++p3) << " ǰ��++���������" << endl;
    cout << p3++ << " ����++��������� " << p3 << endl;
}

int main() {
    test();
}