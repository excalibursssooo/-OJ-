

#include <iostream>
#include<queue>
#include<string>
using namespace std;
int main()
{
    int n;
    char s[101];
    cin >> n;
    int p[101];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        getchar();
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    queue<int>  q[10];
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            q[0].push(p[i]);
        }
        else if (s[i] == 'B') {

            q[1].push(p[i]);
        }
        else if (s[i] == 'C') {

            q[2].push(p[i]);
        }
    }

    for (int i = 0; i < 3; i++) {
        int num = 0;
        int k = 0;
        while (!q[i].empty()) {
            int data = q[i].front();
            num = num + data;
            q[i].pop();
            k++;
        }
        if (k != 0) cout << num / k << endl;
    }

}


