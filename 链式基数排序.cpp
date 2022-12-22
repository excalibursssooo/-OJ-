#include <bits/stdc++.h>
using namespace std;
queue<int> q[10];
int main() {
    int T;
    cin >> T;
    int a[1001];
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int min = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= min) {
                min = a[i];
            }
            if (a[i] > max) {
                max = a[i];
            }
        }
        int cnt = 1;
        while (max) {
            max = max / 10;
            cnt++;
        }
        for (int i = 0; i < n; i++) {
            a[i] += min;
        }
        for (int i = 0; i < cnt - 1; i++) {
            for (int j = 0; j < n; j++) {
                int temp = a[j];
                for (int k = 0; k < i; k++) {
                    temp = temp / 10;
                }
                q[temp % 10].push(a[j]);
            }
            int rr = 0;
            for (int k = 0; k < 10; k++) {
                cout << k << ":";
                if (q[k].empty())
                    cout << "NULL" << endl;
                else {
                    while (!q[k].empty()) {
                        cout << "->" << q[k].front();
                        a[rr] = q[k].front();
                        rr++;
                        q[k].pop();
                    }
                    cout << "->^" << endl;
                }
            }
            for (int k = 0; k < n; k++) {
                cout << a[k];
                if (k != n - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
        cout << endl;
    }
}