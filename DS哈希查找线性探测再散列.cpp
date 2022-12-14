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
        for (int i = 0; i < m + 1; i++) {
            hash[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int key = a[i];
            key = key % 11;
            int num = 1;
            int j = 0;
            int flag = 0;
            int keys[6];
            if (key + 1 == m)
                keys[0] = 0;
            else
                keys[0] = key + 1;
            if (key - 1 == -1)
                keys[1] = m - 1;
            else
                keys[1] = key - 1;
            if (key + 4 >= m)
                keys[2] = key - m + 4;
            else
                keys[2] = key + 4;
            if (key - 4 < 0)
                keys[3] = key - 4 + m;
            else
                keys[3] = key - 4;
            if (key + 9 >= m)
                keys[4] = key - m + 9;
            else
                keys[4] = key + 9;
            if (key - 9 < 0)
                keys[5] = key - 9 + m;
            else
                keys[5] = key - 9;
            if (hash[key] == 0) {
                hash[key] = a[i];
                continue;
            } else {
                for (int j = 0; j < 6; j++) {
                    if (hash[keys[j]] == 0) {
                        // cout << keys[j] << " " << a[i] << endl;
                        hash[keys[j]] = a[i];
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (hash[i] == 0)
                cout << "NULL";
            else
                cout << hash[i];
            if (i < m - 1) cout << " ";
        }
        cout << endl;

        int K;
        cin >> K;
        for (int i = 0; i < K; i++) {
            int flag = 1;
            int j;
            int res;
            cin >> res;
            int key = res % 11;
            int num = 1;
            int keys[6];
            if (key + 1 == m)
                keys[0] = 0;
            else
                keys[0] = key + 1;
            if (key - 1 == -1)
                keys[1] = m - 1;
            else
                keys[1] = key - 1;
            if (key + 4 >= m)
                keys[2] = key - m + 4;
            else
                keys[2] = key + 4;
            if (key - 4 < 0)
                keys[3] = key - 4 + m;
            else
                keys[3] = key - 4;
            if (key + 9 >= m)
                keys[4] = key - m + 9;
            else
                keys[4] = key + 9;
            if (key - 9 < 0)
                keys[5] = key - 9 + m;
            else
                keys[5] = key - 9;
            if (hash[key] == res) {
                cout<<1<<" "<<num<<" "<<key+1<<endl;
                continue;
            } else {
                for (j = 0; j < 6; j++) {
                    num++;
                    if(hash[keys[j]] == 0){
                        flag = 0;
                        break;
                    }
                    if (hash[keys[j]] == res) {
                        cout<<1<<" "<<num<<" "<<keys[j]+1<<endl;
                        break;
                    }
                }
            }
            if(flag == 0){
                cout<<0<<" "<<num<<endl;
            }
        }
    }
}