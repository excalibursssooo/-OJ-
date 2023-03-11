#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int findnum;
        cin >> findnum;
        int flag = 0;
        int mid = n / 2;
        int begin = 0;
        int end = n - 1;
        while (begin < end) {
            if (findnum < v[mid]) {
                end = mid - 1;
                mid = (begin + end) / 2;
            } else if (findnum > v[mid]) {
                begin = mid + 1;
                mid = (begin + end) / 2;
            } else if (findnum == v[mid]) {
                flag = 1;
                cout << mid + 1 << " ";
                break;
            }
        }
        if (flag == 0) {
            cout << -1 << " ";
        }
    }
}