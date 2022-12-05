#include <iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int t;
int cnt[10001];
int IN(int a, int b[][101]) {
    for (int j = 0; j < t; j++) {
        for (int i = 0; i < cnt[j]; i++) {
            if (a == b[j][i]) {
                return j;
            }
        }
    }
    return -1;
}
int main()
{

    int a[101][101];
    int n;
    cin >> t;
    queue<int> q[10001];
    string s;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cnt[i] = n;
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];

        }
    }int ans[10001] = {0};
    while (1) {

        cin >> s;
        if (s == "STOP") break;
        else if (s == "ENQUEUE")
        {
            int data;
            cin >> data;
            int flag=0;
            
            for (int i = 0; i <= 10001; i++) {
                if (ans[i]==0) {
                    q[i].push(data);
                    ans[i] = 1;
                    break;
                }
                else if (!q[i].empty()) {
                    int temp = q[i].front();
                    if (IN(temp, a) == IN(data, a)) {
                        q[i].push(data);
                        break;
                    }
                }
            }
        }
        else if (s == "DEQUEUE")
        {
            int i = 0;
            for (i = 0; i <= 10001; i++) {
                if (!q[i].empty()) {
                    cout << q[i].front() << " ";
                    q[i].pop();
                    break;
                }
            }
        }
    }
}

