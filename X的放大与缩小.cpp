#include <iostream>
using namespace std;

class CXGraph {
private:
    int n;

public:
    CXGraph(int a) {
        n = a;
    }
    friend ostream &operator<<(ostream &os, const CXGraph &C) {
        int count = C.n;
        for (int i = 0; i < C.n / 2; i++) {
            for (int j = 0; j < (C.n - count) / 2; j++) {
                os << " ";
            }
            for (int j = 0; j < count; j++) {
                os << "X";
            }

            os << endl;
            count -= 2;
        }

        count = 1;
        for (int i = 0; i <= C.n / 2; i++) {
            for (int j = 0; j < (C.n - count) / 2; j++) {
                os << " ";
            }
            for (int j = 0; j < count; j++) {
                os << "X";
            }

            os << endl;
            count += 2;
        }
        return os;
    }
    CXGraph &operator--() {
        if (n - 2 <= 1) return *this;
        n -= 2;
        return *this;
    }
    CXGraph &operator--(int) {
        if (n - 2 <= 1) return *this;
        CXGraph *A = new CXGraph(n);
        n -= 2;
        return *A;
    }
    CXGraph &operator++() {
        if (n + 2 >= 21) return *this;
        n += 2;
        return *this;
    }
    CXGraph &operator++(int) {
        if (n + 2 >= 21) return *this;
        CXGraph *A = new CXGraph(n);
        n += 2;
        return *A;
    }
};

int main() {
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--) {
        cin >> command;
        if (command == "show++") {
            cout << xGraph++ << endl;
        } else if (command == "++show") {
            cout << ++xGraph << endl;
        } else if (command == "--show") {
            cout << --xGraph << endl;
        } else if (command == "show--") {
            cout << xGraph-- << endl;
        } else if (command == "show") {
            cout << xGraph << endl;
        }
    }
}