#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    virtual void speak() {
        return;
    }
    virtual ~Animal() {
        cout << "Animal delete" << endl;
    }
    //virtual ~Animal() = 0;  纯虚构
};
/*
纯虚构需要定义虚构
Animal::~Animal(){
}
*/
class Cat : public Animal {
public:
    string *name;
    Cat(string name) {
        this->name = new string(name);
    }
    virtual void speak() {
        cout << "这是猫" << endl;
    }
    ~Cat() {
        if (name != NULL) {
            cout << "cat delete" << endl;
            delete this->name;
        }
    }
};

class Dog : public Animal {
public:
    string *name;
    Dog(string name) {
        this->name = new string(name);
    }
    virtual void speak() {
        cout << "这是狗" << endl;
    }
    ~Dog() {
        if (name != NULL) {
            cout << "dog delete" << endl;
            delete this->name;
        }
    }
};

void Animalspeak(Animal *a) {
    a->speak();
    delete a;
}

void test() {
    Animalspeak(new Cat("Tom"));
    Animalspeak(new Dog("Jerry"));
}

int main() {
    test();
}