#include <bits/stdc++.h>
using namespace std;

class Student {
protected:
    string name;
    string ID;
    static double max_score;

public:
    Student(string s = " ", string num = " ") :
        ID(s), name(num){};
    virtual void display() = 0;
};

double Student::max_score = 0;

class GroupA : public Student {
protected:
    int C1, C2;

public:
    GroupA(string s = " ", string num = " ", int a = 0, int b = 0) :
        Student(s, num), C1(a), C2(b) {
        if ((a + b) / 2 > max_score) {
            max_score = (a + b) / 2;
        }
    };
    void display() {
        if ((C1 + C2) / 2 == max_score) {
            cout << ID << " " << name << endl;
        }
    }
};

class GroupB : public Student {
protected:
    int C1, C2;
    char gs;

public:
    GroupB(string s = " ", string num = " ", int a = 0, int b = 0, char g = 'D') :
        Student(s, num), C1(a), C2(b), gs(g) {
        if ((a + b) / 2 > max_score) {
            max_score = (a + b) / 2;
        }
    };
    void display() {
        if ((C1 + C2) / 2 >= max_score * 0.7 && gs == 'A') {
            cout << ID << " " << name << endl;
        }
    }
};

class GroupC : public Student {
protected:
    int C1, C2, C3, C4, C5;

public:
    GroupC(string s = " ", string num = " ", int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) :
        Student(s, num), C1(a), C2(b), C3(c), C4(d), C5(e){

                                                     };
    void display() {
        if ((C1 + C2 + C3 + C4 + C5) / 5 >= max_score * 0.9) {
            cout << ID << " " << name << endl;
        }
    }
};

int main() {
    const int Size = 50;
    string num, name;
    int i, ty, s1, s2, s3, s4, s5;
    char gs;
    Student *pS[Size];
    int count = 0;
    for (i = 0; i < Size; i++) {
        cin >> ty;
        if (ty == 0)
            break;
        cin >> num >> name >> s1 >> s2;
        switch (ty) {
        case 1:
            pS[count++] = new GroupA(num, name, s1, s2);
            break;
        case 2:
            cin >> gs;
            pS[count++] = new GroupB(num, name, s1, s2, gs);
            break;
        case 3:
            cin >> s3 >> s4 >> s5;
            pS[count++] = new GroupC(num, name, s1, s2, s3, s4, s5);
            break;
        }
    }
    for (i = 0; i < count; i++) {
        pS[i]->display();
        delete pS[i];
    }
    return 0;
}