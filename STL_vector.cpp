#include <bits/stdc++.h>
using namespace std;

void myPrint(int val) {
    cout << val << endl;
}

void test() {
    vector<int> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(i * 10);
    }
    // 1.
    for_each(v.begin(), v.end(), myPrint);
    // 2.
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }
}

class Person {
public:
    string name;
    int age;
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

ostream &operator<<(ostream &cout, Person p) {
    cout << p.name << " " << p.age << endl;
    return cout;
}

void testprint(Person p) {
    cout << p;
}

void test01() {
    vector<Person> P;
    Person p1("wowo", 12);
    Person p2("Walson", 15);
    Person p3("Petter", 19);
    Person p4("Daneil", 11);
    Person p5("Jason", 15);
    P.push_back(p1);
    P.push_back(p2);
    P.push_back(p3);
    P.push_back(p4);
    P.push_back(p5);
    for (vector<Person>::iterator it = P.begin(); it != P.end(); it++) {
        cout<<*it;
    }
}

int main() {
    test01();
}