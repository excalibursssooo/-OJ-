#include <bits/stdc++.h>
using namespace std;

class Vehicle {
protected:
    int weight;

public:
    Vehicle(int a) {
        weight = a;
        cout << "载入Vehicle类构造函数" << endl;
    }
    void setWeight(int a) {
        weight = a;
        cout << "重新设置重量" << endl;
    }
    virtual void display() {
        cout << "重量：" << weight << "吨";
    }
};

class Car : virtual public Vehicle {
protected:
    int aird;

public:
    Car(int a, int b) :
        Vehicle(a) {
        aird = b;
        cout << "载入Car类构造函数" << endl;
    }
    void setAird(int a) {
        aird = a;
        cout << "重新设置空气排量" << endl;
    }
    virtual void display() {
        cout << "空气排量：" << weight << "CC";
    }
};

class Boat : virtual public Vehicle {
protected:
    double tonnage;

public:
    Boat(int a, double b) :
        Vehicle(a) {
        tonnage = b;
        cout << "载入Boat类构造函数" << endl;
    }
    void setTonnage(double a) {
        tonnage = a;
        cout << "重新设置排水量" << endl;
    }
    virtual void display() {
        cout << "排水量：" << weight << "吨";
    }
};

class AmphibianCar : virtual public Boat, virtual public Car {
public:
    AmphibianCar(int a, int b, double c) :
        Vehicle(a), Car(a, c), Boat(a, b) {
        cout << "载入AmphibianCar类构造函数" << endl;
    }
    void set(int a, int b, double c) {
        setWeight(a);
        setAird(b);
        setTonnage(c);
    }
    void display() {
        Vehicle::display();
        cout << "，";
        Car::display();
        cout << "，";
        Boat::display();
        cout << endl;
    }
};

int main() {
    int a, b;
    double c;
    cin >> a >> b >> c;
    AmphibianCar A(a, b, c);
    A.display();
    cin >> a >> b >> c;
    A.set(a, b, c);
    A.display();
}
