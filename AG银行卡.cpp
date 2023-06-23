#include <bits/stdc++.h>
using namespace std;

class C_Card {
protected:
    string ID;
    string CName;
    int Counter;

public:
    C_Card(string s = " ", string s1 = " ", int a = 0) :
        ID(s), CName(s1), Counter(a){};
    virtual void initial(string s, string s1, int a) {
        ID = s;
        CName = s1;
        Counter = a;
    }
    int save(int mon) {
        if (mon <= 0) return -1;
        Counter += mon;
        return 1;
    }
    int take(int mon) {
        if (mon <= 0) return -1;
        if (Counter - mon < 0) return -1;
        Counter -= mon;
        return 1;
    }
    virtual void info() {
        cout << ID << "-" << CName << "-" << Counter << endl;
    }
};

class T_Card : public C_Card {
protected:
    int Tcounter;

public:
    void initial(string s, string s1, int a, int b) {
        ID = s;
        CName = s1;
        Counter = a;
        Tcounter = b;
    }
    int transfer(int mon) {
        if (mon > Counter) return -1;
        Counter -= mon;
        Tcounter += mon;
        return 1;
    }
    void info() {
        cout << ID << "-" << CName << "-" << Counter << "-" << Tcounter << endl;
    }
};

class V_Card : public C_Card {
protected:
    int Credit;

public:
    void initial(string s, string s1, int a, int b) {
        ID = s;
        CName = s1;
        Counter = a;
        Credit = b;
    }
    int over(int mon) {
        if (mon > Counter + Credit) return -1;
        Credit -= (mon - Counter);
        Counter = 0;
        return 1;
    }
    void info() {
        cout << ID << "-" << CName << "-" << Counter << "-" << Credit << endl;
    }
};

void show(C_Card &C) {
    C.info();
}

int main() {
    string s, s1;
    int a, b;
    C_Card C;
    T_Card T;
    V_Card V;
    cin >> s >> s1 >> a;
    C.initial(s, s1, a);
    cin >> s >> s1 >> a >> b;
    T.initial(s, s1, a, b);
    cin >> s >> s1 >> a >> b;
    V.initial(s, s1, a, b);
    int mon1, mon2, mon3, mon4;
    cin >> mon1 >> mon2 >> mon3 >> mon4;
    C.save(mon1);
    C.save(mon2);
    C.take(mon3);
    C.take(mon4);
    cin >> mon1 >> mon2 >> mon3 >> mon4;
    T.save(mon1);
    T.take(mon2);
    T.transfer(mon3);
    T.transfer(mon4);
    cin >> mon1 >> mon2 >> mon3 >> mon4;
    V.save(mon1);
    V.take(mon2);
    V.over(mon3);
    V.over(mon4);
    show(C);
    show(T);
    show(V);
}
