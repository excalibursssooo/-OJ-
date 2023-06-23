#include <iostream>
#include <math.h>
using namespace std;

class sijinzhi {
private:
    int num;

public:
    sijinzhi(int a) {
        num = a;
    }
    void set(int a) {
        num = a;
    }
    sijinzhi() {
        num = 0;
    }
    sijinzhi &operator+=(const sijinzhi &S) {
        int temp1 = num;
        int temp2 = S.num;
        int ans[10];
        for (int i = 0; i < 10; i++) ans[i] = 0;
        int i = 0;
        while (temp1 != 0) {
            ans[i] = temp1 % 10;
            temp1 /= 10;
            i++;
        }
        int j = 0;
        while (temp2 != 0) {
            ans[j] += (temp2 % 10);
            int t_j = j;
            while (ans[t_j] >= 4) {
                ans[t_j] -= 4;
                t_j++;
                ans[t_j]++;
            }
            temp2 /= 10;
            j++;
        }
        i = 0;
        num = 0;
        for (int k = 0; k < 10; k++) {
            num += ans[k] * pow(10, k);
        }
        return *this;
    }

    void print() {
        cout << num << endl;
    }
};

int main() {
    int t;
    cin >> t;
    sijinzhi S[101];
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        S[i].set(a);
    }
    sijinzhi Ans;
    for (int i = 0; i < t; i++) {
        Ans += S[i];
    }
    Ans.print();
}
