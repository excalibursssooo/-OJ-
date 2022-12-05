#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int visit[101];
        for (int i = 0; i < n; i++) {
            visit[i] = 0;
        }
        int Matrix[60][60];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> Matrix[i][j];
            }
        }
        int flag = 0;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                flag = 0;
                for (int j = 0; j < n; j++) {
                    if (Matrix[j][i] == 1) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                    continue;
                else {
                    if (visit[i] == 0) {
                        visit[i] = 1;
                        cout << i << " ";
                        for (int j = 0; j < n; j++) {
                            Matrix[i][j] = 0;
                        }
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
}