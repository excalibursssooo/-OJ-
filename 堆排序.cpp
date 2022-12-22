#include <bits/stdc++.h>
using namespace std;

void adjust(int a[], int key, int n) {
    int temp = a[key];
    int j;
    for (int j = 2 * key; j <= n; j *= 2) {
        if (j < n && a[j] > a[j + 1]) j++;
        if (temp <= a[j]) break;
        a[key] = a[j];
        key = j;
    }
    a[key] = temp;
}

void duisort(int a[], int n) {
    for (int i = n / 2; i > 0; i--) {
        adjust(a, i, n);
    }
    cout << n << " ";
    for (int i = 1; i <= n; i++) {
        cout << a[i];
        if (i != n)
            cout << " ";
        else
            cout << endl;
    }
    int temp = 0;
    for (int i = n; i > 1; i--) {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        adjust(a, 1, i - 1);
        cout << n << " ";
        for (int i = 1; i <= n; i++) {
            cout << a[i];
            if (i != n)
                cout << " ";
            else
                cout << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a[1001];
    a[0] = 1001;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    duisort(a, n);
}