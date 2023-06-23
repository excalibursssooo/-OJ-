#include <bits/stdc++.h>
using namespace std;

class Fraction {
private:
    int numerator, demoninator;
    int common_divisor() {
    }
    void contracted() {
    }

public:
    Fraction(int a, int b) {
        numerator = a;
        demoninator = b;
    }
    Fraction(Fraction &F) {
        numerator = F.numerator;
        demoninator = F.demoninator;
    }
    Fraction operator+(Fraction F) {
        Fraction temp(0, 0);
        temp.demoninator = demoninator * F.demoninator;
        temp.numerator = numerator * F.demoninator + F.numerator * demoninator;
        return temp;
    }
    Fraction operator-(Fraction F) {
        Fraction temp(0, 0);
        temp.demoninator = demoninator * F.demoninator;
        temp.numerator = numerator * F.demoninator - F.numerator * demoninator;
        return temp;
    }
    Fraction operator*(Fraction F) {
        Fraction temp(0, 0);
        temp.demoninator = demoninator * F.demoninator;
        temp.numerator = numerator * F.numerator;
        return temp;
    }
    Fraction operator/(Fraction F) {
        Fraction temp(0, 0);
        temp.demoninator = demoninator * F.numerator;
        temp.numerator = numerator * F.demoninator;
        return temp;
    }
    void print() {
        cout << "fraction=";
        if (demoninator * numerator < 0) cout << "-";
        cout << abs(numerator) << "/" << abs(demoninator) << endl;
    }
};

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Fraction A(a, b);
    Fraction B(c, d);
    Fraction Answer(0, 0);
    Answer = A + B;
    Answer.print();
    Answer = A - B;
    Answer.print();
    Answer = A * B;
    Answer.print();
    Answer = A / B;
    Answer.print();
}