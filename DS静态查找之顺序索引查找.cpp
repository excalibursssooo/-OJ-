#include <bits/stdc++.h>
using namespace std;

struct index {
    int max;
    int pos;
}dex[101];

int main() {
    int n;
    cin >> n;
    int a[101];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    //index dex[101];
    dex[0].pos = 1;
    for (int i = 0; i < m; i++) {
        cin >> dex[i].max;
        for (int j = 1; j <= n; j++) {
            if (a[j] > dex[i].max) {
                dex[i + 1].pos = j;
                break;
            }
        }
    }
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int find;
        cin >> find;
        int j;
        int cnt = 0;
        for (j = 0; j < m; j++) {
            cnt++;
            if (find <= dex[j].max) {
                break;
            }
        }
        int k;
        int maxlength;
        if (j == m) {
            cout << "error" << endl;
            break;
        } else if (j == m - 1) {
            //cout<<"*"<<j<<endl;
            maxlength = n - dex[j].pos;
            //cout<<maxlength<<endl;
        } else {
            maxlength = dex[j + 1].pos - dex[j].pos;
        }
        for (k = dex[j].pos; k <= dex[j].pos + maxlength; k++) {
            cnt++;
            if (find == a[k]) {
                cout << k << "-" << cnt << endl;
                break;
            }
        }
        if (k == dex[j].pos + maxlength + 1) {
            cout << "error" << endl;
        }
    }
}