#include <bits/stdc++.h>
using namespace std;
int flag;
int output = 0;
queue<int> q;
void dfs(int hang, int lie, int Matrix[][101]) {
    if (Matrix[hang][lie] == 1) return;
    if (Matrix[hang][lie] == 0) {
        output++;
        Matrix[hang][lie] = 1;
        dfs(hang + 1, lie, Matrix);
        dfs(hang - 1, lie, Matrix);
        dfs(hang, lie + 1, Matrix);
        dfs(hang, lie - 1, Matrix);
    }
}

void judge(int hang, int lie, int Matrix[][101], int a, int b) {
    // cout<<hang<<" "<<lie<<endl;
    // cout<<flag<<endl;
    if (flag == 1) {
        return;
    }
    if (hang < 0 || lie < 0 || hang >= a || lie >= b) {
        flag = 1;
        return;
    }
    if (Matrix[hang][lie] == 1) {
        return;
    }
    if (Matrix[hang][lie] == 0) {
        Matrix[hang][lie] = 1;
        judge(hang + 1, lie, Matrix, a, b);
        judge(hang - 1, lie, Matrix, a, b);
        judge(hang, lie + 1, Matrix, a, b);
        judge(hang, lie - 1, Matrix, a, b);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        output = 0;
        int hang, lie;
        cin >> hang >> lie;
        int Matrix[101][101];
        for (int i = 0; i < hang; i++) {
            for (int j = 0; j < lie; j++) {
                cin >> Matrix[i][j];
            }
        }
        for (int i = 0; i < hang; i++) {
            for (int j = 0; j < lie; j++) {
                int Matr[101][101];
                for (int i = 0; i < hang; i++) {
                    for (int j = 0; j < lie; j++) {
                        Matr[i][j] = Matrix[i][j];
                    }
                }
                flag = 0;
                if (Matrix[i][j] == 1) continue;
                judge(i, j, Matr, hang, lie);
                if (flag == 0) {
                    dfs(i, j, Matrix);
                }
            }
        }
        cout << output << endl;
    }
}