#include <bits/stdc++.h>
using namespace std;

class CDate {
private:
    int year, month, day;

public:
    CDate() {
        year = 0;
        month = 0;
        day = 0;
    }
    CDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
    int getYear() {
        return year;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    int getDayofYear() // 计算日期从当年1月1日算起的天数
    {
        int i, sum = day;
        int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isLeapYear())
            for (i = 0; i < month; i++) sum += b[i];
        else
            for (i = 0; i < month; i++) sum += a[i];

        return sum;
    }
    int if_after(CDate &p) {
        if (p.getYear() > year) {
            return 1;
        } else if (p.getYear() < year) {
            return 0;
        } else {
            if (p.getMonth() > month) {
                return 1;
            } else if (p.getMonth() < month) {
                return 0;
            } else {
                if (p.getDay() >= day) {
                    return 1;
                } else if (p.getDay() < day) {
                    return 0;
                }
            }
        }
    }
    int count_date(CDate &b) {
        int year_d = b.year - year;
        if (year == 0) {
            return b.getDayofYear() - getDayofYear();
        }
        int sum = 0;
        int y = year;
        while (y < b.year) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                sum += 366;
            else
                sum += 365;
        }
        return sum + b.getDayofYear() - getDayofYear();
    }
};

class Software {
private:
    string name;
    char type;
    CDate c;
    char media;

public:
    Software() {
        name = "";
        type = 'O';
        c = CDate(0, 0, 0);
    }
    Software(string n, char t, int y, int m, int d, char mm) {
        name = n;
        media = mm;
        type = t;
        c = CDate(y, m, d);
    }
    Software(Software &p) {
        c = CDate(p.c.getYear(), p.c.getMonth(), p.c.getDay());
        type = 'B';
        media = 'H';
        name = p.name;
    }
    void printt() {
        cout << "name:" << name << endl;
        if (type == 'O')
            cout << "type:original" << endl;
        else if (type == 'B')
            cout << "type:backup" << endl;
        else if (type == 'T')
            cout << "type:trial" << endl;

        if (media == 'D')
            cout << "media:optical disk" << endl;
        else if (media == 'H')
            cout << "media:hard disk" << endl;
        else if (media == 'U')
            cout << "media:USB disk" << endl;

        if (c.getDay() == 0 && c.getMonth() == 0 && c.getYear() == 0) {
            cout << "this software has unlimited use" << endl;
            return;
        }
        CDate cc(2015, 4, 7);
        if (c.if_after(cc)) {
            cout << "this software has expired" << endl;
            return;
        } else {
            cout << "this software is going to be expired in "<<cc.count_date(c)<<" days" << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        char a, b;
        int y, m, d;
        cin >> s >> a >> b >> y >> m >> d;
        Software S(s, a, y, m, d, b);
        S.printt();
        cout << endl;
        Software SS(S);
        SS.printt();
        cout << endl;
    }
}