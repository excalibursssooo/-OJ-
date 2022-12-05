#include <bits/stdc++.h>

using namespace std;
int nextnum[1001];
void next(string s) {
    nextnum[0] = -1;
    int i = 0;
    int j = -1;
    while (i <= s.length()) {
        if (j == -1 || s[i] == s[j])
            nextnum[++i] = ++j;
        else
            j = nextnum[j];
    }
}

int kmp(string pat, string text) {
    string p = text.substr(0, pat.length());
    if (pat == text || p == pat) {
        return pat.length();
    }
    int i = 0, j = -1;
    while (i <= text.length()) {
        if (j == -1 || pat[j] == text[i]) {
            i++;
            j++;
        } else {
            j = nextnum[j];
        }
        if (j == pat.length()) return i - j + 1;
    }
    return -2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s;
        int big;
        big = -1;
        int i = s.length() / 2;
        int flag = 0;
        while (i > 0) {
            string p;
            for (int j = 0; j <= s.length()-i; j++) {
                //memset(nextnum, -1, 1001);
                p = s.substr(j, i);
                string h = s.substr(j + i);
                //cout<<p<<" "<<h<<endl;
                //next(p);
                if (h.find(p) == string::npos) {
                    continue;
                } else {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                i--;
            else
                break;
        }
        big = i;
        if (big == 0)
            cout << -1 << endl;
        else
            cout << big << endl;
    }
}