#include <bits/stdc++.h>
using namespace std;

class CTelNumber {
private:
    string num;

public:
    CTelNumber() {
        num = string("");
    }
    CTelNumber(string num) {
        this->num = num;
    }
    CTelNumber(CTelNumber &m) {
        for (int i = 0; i < 7; i++) {
            if (m.num[i] < '0' || m.num[i] > '9') {
                cout << "Illegal phone number" << endl;
                return;
            }
        }
        if (m.num[0] == '0' || m.num[0] == '9'|| m.num[0] == '1') {
            cout << "Illegal phone number" << endl;
            return;
        }
        if (m.num.length() != 7) {
            cout << "Illegal phone number" << endl;
            return;
        }
        if (m.num[0] >= '2' && m.num[0] <= '4') {
            num = "8" + m.num;
            cout << num << endl;
        } else if (m.num[0] >= '5' && m.num[0] <= '8') {
            num = "2" + m.num;
            cout << num << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        CTelNumber n(a);
        CTelNumber b(n);
    }
}