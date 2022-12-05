#include <iostream>
using namespace std;
#include <string>
#include <ctime>
int main() {
    time_t begin, end;
    double ret;
    begin = clock();
    string pat, text;
    cin >> pat >> text;
    for (int i = 0; i < text.length(); i++) {
        int j;
        for (j = 0; j < pat.length(); j++) {
            if (pat[j] != text[i + j]) break;
        }
        if (j == pat.length()) {
            cout << i << endl;
            break;
        }
    }
    end = clock();
    ret = double(end - begin) / CLOCKS_PER_SEC;
    cout << "runtime:   " << ret << endl;
}