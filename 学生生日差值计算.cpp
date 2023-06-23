#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int year, month, day;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    Student() {
        name = " ";
        year = 0;
        month = 0;
        day = 0;
    }
    void set(string n, int a, int b, int c) {
        name = n;
        year = a;
        month = b;
        day = c;
    }
    bool cmp(Student &S) {
        if (year != S.year) {
            return year < S.year;
        }
        if (month != S.month) {
            return month < S.month;
        }
        if (day != S.day) {
            return day < S.day;
        }
        return 0;
    }
    int operator-(Student &S) {
        int cnt = 0;
        if (cmp(S)) {
            Student temp;
            temp.set(name, year, month, day);
            while (temp.day != S.day || temp.month != S.month || temp.year != S.year) {
                temp.day++;
                if (temp.day > days[temp.month - 1]) {
                    temp.day = 1;
                    temp.month++;
                }
                if (temp.month > 12) {
                    temp.month = 1;
                    temp.year++;
                }
                cnt++;
            }
        } else {
            Student temp(S);
            while (temp.day != day || temp.month != month || temp.year != year) {
                temp.day++;
                if (temp.day > days[temp.month - 1]) {
                    temp.day = 1;
                    temp.month++;
                }
                if (temp.month > 12) {
                    temp.month = 1;
                }
                cnt++;
            }
        }
        return cnt;
    }
    string get_name() {
        return name;
    }
};

int main() {
    int t;
    cin >> t;
    Student S[101];
    for (int i = 0; i < t; i++) {
        string n;
        int a, b, c;
        cin >> n >> a >> b >> c;
        S[i].set(n, a, b, c);
    }
    int maxx = 0;
    int ii = 0;
    int jj = 0;
    for (int i = 0; i < t; i++) {
        for (int j = i + 1; j < t; j++) {
            int maxxx = S[i] - S[j];
            if (maxxx > maxx) {
                maxx = maxxx;
                ii = i;
                jj = j;
            }
        }
    }
    cout << S[ii].get_name() << "和" << S[jj].get_name() << "年龄相差最大，为" << maxx << "天。" << endl;
}