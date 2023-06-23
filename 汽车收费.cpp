#include <bits/stdc++.h>
using namespace std;

class Vehicle

{
protected:
    string no; // 编号

public:
    Vehicle(string s) :
        no(s){};
    virtual void display() = 0; // 应收费用
};

class Car : virtual public Vehicle {
protected:
    int p_no;
    int weight;

public:
    Car(string s, int a, int b) :
        Vehicle(s) {
        p_no = a;
        weight = b;
    }
    void display() {
        cout << no << " " << p_no * 8 + weight * 2 << endl;
    }
};

class Truck : virtual public Vehicle {
protected:
    int weight;

public:
    Truck(string s, int a) :
        Vehicle(s) {
        weight = a;
    }
    void display() {
        cout << no << " " << weight * 5 << endl;
    }
};

class Bus : virtual public Vehicle {
protected:
    int p_no;

public:
    Bus(string s, int a) :
        Vehicle(s) {
        p_no = a;
    }
    void display() {
        cout << no << " " << p_no * 3 << endl;
    }
};

int main() {
    Vehicle *V;
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        if (num == 1) {
            string s;
            int a, b;
            cin >> s >> a >> b;
            Car C(s, a, b);
            V = &C;
            V->display();
        }
        if (num == 2) {
            string s;
            int a, b;
            cin >> s >> a;
            Truck T(s, a);
            V = &T;
            V->display();
        }
        if (num == 3) {
            string s;
            int a;
            cin >> s >> a;
            Bus B(s, a);
            V = &B;
            V->display();
        }
    }
}