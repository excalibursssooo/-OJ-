#include <bits/stdc++.h>
using namespace std;
void getnext(string tmp, int *next) {
    int len = tmp.length();
    int i = 0;
    int j = -1;
    next[i] = j;
    while (i <= len) {
        if (j == -1 || (tmp[i] == tmp[j] && j <= i / 2)) {
            next[++i] = ++j;
        } else {
            j = next[j];
        }
    }
    for (int k = 0; k <= len; k++) {
        cout << next[k] << " ";
    }
    cout << endl;
}
int opera(string tmp) {
    int len = tmp.length();
    int next[1001];
    getnext(tmp, next);
    int res = -1;
    for (int i = 1; i <= len; i++) {
        res = max(res, next[i]);
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int l = str.length();
        int maxx = -1;
        for (int i = 0; i < l; i++) {
            maxx = max(maxx, opera(str.substr(i)));
        }
        cout << (maxx ? maxx : -1) << endl;
    }
}