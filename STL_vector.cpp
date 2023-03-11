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
        cout << *it;
    }
}

void test02() {
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; i++) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
            cout<<(*vit)<<" ";
        }
        cout<<endl;
    }
}

void test03(){
    vector<int> v;
    for(int i = 0;i<100000;i++){
        v.push_back(i);
    }
    cout<<"size: "<<v.size()<<endl;
    cout<<"容量: "<<v.capacity()<<endl;
    v.resize(3);
    cout<<"after resize: "<<endl;
    cout<<"size: "<<v.size()<<endl;
    cout<<"容量: "<<v.capacity()<<endl;

    vector<int>(v).swap(v);

    cout<<"after resize and swap: "<<endl;
    cout<<"size: "<<v.size()<<endl;
    cout<<"容量: "<<v.capacity()<<endl;

}


int main() {
    test03();
}