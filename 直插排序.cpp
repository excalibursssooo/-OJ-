#include <iostream>
using namespace std;

int main() {
    int n;
    int a[101];
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        a[0] = a[i];
        int j;
        for (j = i; j > 0; j--) {
            if (a[0] < a[j - 1])
                a[j] = a[j - 1];
            else
                break;
        }
        a[j] = a[0];
        for (int k = 1; k <= n; k++) {
            cout << a[k];
            if (k != n)
                cout << " ";
            else
                cout << endl;
        }
    }
}