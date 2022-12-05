#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> text >> pat;
        int next[1001];
        int i = 0, j = -1;
        next[0] = -1;
        while (i < pat.length()) {
            if (j == -1 || pat[i] == pat[j])
                next[++i] = ++j;
            else
                j = next[j];
        }
        i = 0;
        j = -1;
        while (i < text.length()) {
            if (j == -1 || text[i] == pat[j]) {
                i++;
                j++;
            } else
                j = next[j];
            if (j == pat.length()) break;
        }
        for (int i = 0; i < pat.length(); i++) {
            cout << next[i] << " ";
        }
        cout << endl;
        if (j == pat.length()){
            cout << i - j + 1 << endl;
        }
            
        else
            cout << 0 << endl;
    }
}