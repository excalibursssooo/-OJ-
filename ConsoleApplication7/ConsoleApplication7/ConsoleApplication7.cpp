#include <iostream>
using namespace std;

class Clock {
private:
    int minute, hour, second;

public:
    Clock(int a, int b, int c) {
        minute = b;
        hour = a;
        second = c;
    }
    Clock &operator++(int) {
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
        }
        if (minute >= 60) {
            minute = 0;
            hour++;
        }
        if (hour >= 12) {
            hour = 0;
        }
        return *this;
    }
    Clock operator--() {
        Clock temp(*this);
        second--;
        if (second < 0) {
            second = 59;
            minute--;
        }
        if (minute < 0) {
            minute = 59;
            hour--;
        }
        if (hour < 0) {
            hour = 11;
        }
        return temp;
    }
    void print() {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    Clock C(a,b,c);
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        if (num > 0) {
            while (num--) {
                C++;
            }
            C.print();
        } else {
            int newnum = abs(num);
            while (newnum--) {
                --C;
            }
            C.print();
        }
    }
}