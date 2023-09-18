#include <bits/stdc++.h>
using namespace std;

class Vehicle {
protected:
    int weight;

public:
    Vehicle(int a) {
        weight = a;
        cout << "����Vehicle�๹�캯��" << endl;
    }
    void setWeight(int a) {
        weight = a;
        cout << "������������" << endl;
    }
    virtual void display() {
        cout << "������" << weight << "��";
    }
};

class Car : virtual public Vehicle {
protected:
    int aird;

public:
    Car(int a, int b) :
        Vehicle(a) {
        aird = b;
        cout << "����Car�๹�캯��" << endl;
    }
    void setAird(int a) {
        aird = a;
        cout << "�������ÿ�������" << endl;
    }
    virtual void display() {
        cout << "����������" << weight << "CC";
    }
};

class Boat : virtual public Vehicle {
protected:
    double tonnage;

public:
    Boat(int a, double b) :
        Vehicle(a) {
        tonnage = b;
        cout << "����Boat�๹�캯��" << endl;
    }
    void setTonnage(double a) {
        tonnage = a;
        cout << "����������ˮ��" << endl;
    }
    virtual void display() {
        cout << "��ˮ����" << weight << "��";
    }
};

class AmphibianCar : virtual public Boat, virtual public Car {
public:
    AmphibianCar(int a, int b, double c) :
        Vehicle(a), Car(a, c), Boat(a, b) {
        cout << "����AmphibianCar�๹�캯��" << endl;
    }
    void set(int a, int b, double c) {
        setWeight(a);
        setAird(b);
        setTonnage(c);
    }
    void display() {
        Vehicle::display();
        cout << "��";
        Car::display();
        cout << "��";
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
