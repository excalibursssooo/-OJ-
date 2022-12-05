#include <bits/stdc++.h>
using namespace std;
int main() {
    int M, N, K;
    cin >> M >> N >> K;
    while (K--) {
        stack<int> p;
        int num[1002];
        int dui[1002];
        for (int i = 1; i <= N; i++) {
            cin >> num[i];
            dui[i] = i;
        }
        int flag = 1;
        int j = 2;
        int k = 1;
        p.push(1);
        while (k <= N) {
            if(p.empty()){
                p.push(j);
                j++;
            }
            if (num[k] != p.top()) {
                if (p.size() == M) {
                    flag = 0;
                    break;
                }
                p.push(j);
                j++;
            } else {
                p.pop();
                k++;
            }
        }
        if (flag == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}