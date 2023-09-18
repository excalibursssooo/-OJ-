#include <bits/stdc++.h>
using namespace std;

class employee {
protected:
    string name;
    string Work;
    int level;
    int year;

public:
    employee(string s1, string s2, int a, int b) :
        name(s1), Work(s2), level(a), year(b){};
    virtual int salary() {
        return 1000 + 500 * level + 50 * year;
    }
    virtual void display() {
        if (Work != "Employee") {
            cout << "error position." << endl;
            return;
        }
        if (level < 0 || year < 0) {
            cout << "error grade or year." << endl;
            return;
        }
        cout << name << ":" << Work << ",Salary:" << salary() << endl;
    }
};

class teamleader : public employee {
public:
    teamleader(string s1, string s2, int a, int b) :
        employee(s1, s2, a, b){};
    virtual int salary() {
        return 3000 + 800 * level + 100 * year;
    }
    virtual void display() {
        if (Work != "Teamleader") {
            cout << "error position." << endl;
            return;
        }
        if (level < 0 || year < 0) {
            cout << "error grade or year." << endl;
            return;
        }
        cout << name << ":" << Work << ",Salary:" << salary() << endl;
    }
};

class manager : public employee {
public:
    manager(string s1, string s2, int a, int b) :
        employee(s1, s2, a, b){};
    virtual int salary() {
        return 5000 + 1000 * level + 1000 * year;
    }
    virtual void display() {
        if (Work != "Manager") {
            cout << "error position." << endl;
            return;
        }
        if (level < 0 || year < 0) {
            cout << "error grade or year." << endl;
            return;
        }
        cout << name << ":" << Work << ",Salary:" << salary() << endl;
    }
};

int main() {
    int t;
    cin >> t;
    employee *E = new employee(" ", " ", 0, 0);
    while (t--) {
        string s1, s2;
        int a, b;
        cin >> s1 >> s2 >> a >> b;
        if (s2 == "Manager") {
            manager *M = new manager(s1, s2, a, b);
            E = M;
            E->display();
        } else if (s2 == "Teamleader") {
            teamleader *M = new teamleader(s1, s2, a, b);
            E = M;
            E->display();
        } else if (s2 == "Employee") {
            employee *M = new employee(s1, s2, a, b);
            E = M;
            E->display();
        } else {
            cout << "error position." << endl;
        }
    }
}