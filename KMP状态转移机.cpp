#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
    time_t begin, end;
    double ret;
    begin = clock();
    string pat, text;
    cin >> pat >> text;
    int dp[1001][256];
    dp[0][pat[0]] = 1;
    int x = 0;
    for (int i = 1; i < pat.length(); i++) {
        for (int j = 0; j < 256; j++) {
            if (pat[i] == j)
                dp[i][j] = i + 1;
            else
                dp[i][j] = dp[x][j];
        }
        x = dp[x][pat[i]];
        cout << x << "******************" << endl;
    }
    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        j = dp[j][text[i]];
        if (j == pat.length()) {
            cout << i - j + 1 << endl;
            break;
        }
    }
    end = clock();
    ret = double(end - begin) / CLOCKS_PER_SEC;
    cout << "runtime:   " << ret << endl;
}