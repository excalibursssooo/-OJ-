#include<iostream>
using namespace std;

class lottery {
private:
    int num1[6];
    int n;
    int numm[9][6];

public:
    lottery() {
        for (int i = 0; i < 6; i++)
            num1[i] = 0;
    }
    lottery(int a[], int n) {
        for (int i = 0; i < 6; i++) {
            num1[i] = a[i];
        }
        this->n = n;
    }
    void copy() {
        for (int i = 1; i < 6; i++) {
            numm[0][i] = num1[i - 1] + 1;
        }
        numm[0][0] = num1[5] + 1;
        for (int i = 1; i < n; i++) {
            numm[i][0] = numm[i - 1][5] + 1;
            for (int j = 1; j < 6; j++) {
                numm[i][j] = numm[i - 1][j - 1] + 1;
            }
        }
    }

    void Print() {
        for (int i = 0; i < 6; i++) {
            cout << num1[i];
            if (i != 5)
                cout << " ";
            else
                cout << endl;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                cout << numm[i][j];
                if (j != 5)
                    cout << " ";
                else
                    cout << endl;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a[6];
        for (int i = 0; i < 6; i++) {
            cin >> a[i];
        }
        int n;
        cin >> n;
        lottery l(a, n);
        l.copy();
        l.Print();
    }
}