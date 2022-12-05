// Date(类与对象).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>

using namespace std;

class Date {

private:
    int year;
    int month;
    int day;
public:
    Date() {
        year = 1900;
        month = 1;
        day = 1;
    }
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;

    }
   void set(int a){
        if (a < 10) {
            cout << 0;
        }
    }
    int getYear() {
        return year;
    }
    void getMonth() {
        if (month < 10) {
            cout << 0 << month;
        }
        else cout << month;
    }
    void getDay() {
        if (day < 10) {
            cout << 0 << day;
        }
        else cout << day;
    }
    void setDate(int y, int m, int d) {
        day = d;
        month = m;
        year = y;
    }
    void addOneday() {
        day++;
        if (year % 4 == 0 && year % 100 != 0||year%400==0) {
            if (month == 2) {
                if (day == 30) {
                    month++;
                    day = 1;
                }
            }
        }
        else if (month == 2 && day == 29) {
            day = 1;
            month++;
        }
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (month == 12 && day == 32) {
                day = 1;
                month = 1;
                year++;
            }
            else if (day == 32) {
                day = 1;
                month++;
            }
        }
        else {
            if (day == 31) {
                day = 1;
                month++;
            }
        }
    }
 
    void print1() {
        
        cout << "Today is " << year << "/";
        getMonth();
        cout << "/";
        getDay();
        cout<< endl;
    }
    void print2() {
        cout << "Tomorrow is " << year << "/";
        getMonth();
        cout << "/";
        getDay();
        cout<< endl;
    }
};




int main()
{
    int t;
    int y, m, d;
    cin >> t;
    while (t--) {
        cin >> y >> m >> d;
        if (t % 2 == 0) {
            Date wow(y, m, d);
            wow.print1();
            wow.addOneday();
            wow.print2();
        }
        else {
            Date wow;
            wow.setDate (y, m, d);
            wow.print1();
            wow.addOneday();
            wow.print2();
        }
    }

}

