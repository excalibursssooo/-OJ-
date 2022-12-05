#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int next[10001];
        memset(next, 0, 10001);
        string pat;
        cin >> pat;
        int len = pat.length();
        next[0] = -1;
        int i = 0;
        int j = -1;
        while (i <= len) {
            if (j == -1 || pat[i] == pat[j]) {
                i++;
                j++;
                next[i] = j;
            } else
                j = next[j];
        }
        // for (int k = 0; k <= len; k++) {
        //     cout << next[k] << endl;
        // }
        if (next[len] == 0)
            cout << len << endl;
        else if (next[len] <= len / 2)
            cout << len - 2 * next[len] << endl;
        else {
            // cout<<"*"<<endl;
            int sum = 0;
            int temp = len;
            int l = len;
            while (temp/2 < next[temp]) {
                temp = next[temp];
                l = next[temp];
                //cout << temp << " " << l << endl;
            }
            cout<<temp-2*l<<endl;
            // cout << sum - len % sum << endl;
        }
    }
}