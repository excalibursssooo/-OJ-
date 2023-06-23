#include <bits/stdc++.h>
using namespace std;

class CBook {
private:
    string name;
    string editor;
    double price;
    string publish;

public:
    CBook(string s1 = " ", string s2 = " ", double a = 0, string s3 = " ") :
        name(s1), editor(s2), price(a), publish(s3){};
    friend ostream &operator<<(ostream &os, const CBook &C) {
        os << C.name << endl
           << C.editor << endl
           << C.price << endl
           << C.publish << endl;
        return os;
    }
    friend istream &operator>>(istream &os, CBook &C) {
        string s;
        getline(os, s);
        int dou1, dou2, dou3;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ',') {
                count++;
                if (count == 1) dou1 = i;
                if (count == 2) dou2 = i;
                if (count == 3) dou3 = i;
            }
        }
        C.name = s.substr(0, dou1);
        C.editor = s.substr(dou1 + 1, dou2 - dou1);
        C.price = stod(s.substr(dou2 + 1, dou3 - dou2));
        C.publish = s.substr(dou3 + 1);
        return os;
    }
    double getprice() {
        return price;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int T;
        cin >> T;
        CBook *C = new CBook[T + 1];
        for (int i = 0; i < T; i++) {
            if (i == 0) getchar();
            cin >> C[i];
        }
        for (int i = 0; i < T; i++) {
            for (int j = i + 1; j < T; j++) {
                if (C[i].getprice() < C[j].getprice()) {
                    CBook B(C[i]);
                    C[i] = C[j];
                    C[j] = B;
                }
            }
        }
        cout << C[0] << endl;
        cout << C[1] << endl;
    }
}
