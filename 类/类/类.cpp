// 类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class Person {

public:
    int age;
    int height;
    int* num = new int[10];
    Person() {
        age = 0;
        height = 0;
        num = { 0 };
    }

    Person(int a, int b) {
        cout << "gouzao" << endl;
        age = a;
        height = b;
    }

    Person(const Person& p) {
        cout << "kaobei" << endl;
        age = p.age;
        height = p.height;
    }

    ~Person()
    {
        cout << "xigou" << endl;
        delete[] num;
    }

};

int main()
{
    Person p(2,195);
    Person p1 (p);

    cout << p1.age<<" "<<p1.height<<endl;
}

