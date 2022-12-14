#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        int a[101];
        int hash[101];
        for (int i = 0; i < m+1; i++) {
            hash[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int key = a[i];
            int num = 1;
            int j = 0;
            int flag = 0;
            while (hash[(key + j)%11] != 0 && hash[(key - j)%11] != 0) {
                j++;
                if (hash[key % 11 + j] == 0 && (key + j) % 11 == 0) {
                    cout << "*"<<endl;
                    hash[key % 11 + j] = a[i];
                    flag = 1;
                    break;
                }
                
            }
            if (hash[(key + j) % 11] == 0 && flag != 1) {
                hash[(key + j) % 11] = a[i];
                cout << (key + j) %11<< "*" << a[i] << endl;
            } else if (hash[(key - j) % 11] == 0 &&flag != 1) {
                hash[(key - j) % 11] = a[i];
                cout << (key - j) % 11 << " " << a[i] << endl;
            }      
        }
        for (int i = 0; i < m; i++) {
            if (hash[i] == 0)
                cout << "NULL";
            else
                cout << hash[i];
            if (i < m-1) cout << " ";
        }
        cout << endl;

        int K;
        cin >> K;
        for (int i = 0; i < K; i++) {
            int res;
            cin >> res;
            int flag = 0;
            int key = res % 11;
            int num = 1;
        }
    }
}