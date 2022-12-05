#include <bits/stdc++.h>
using namespace std;
char pat[101][101][20]; //文件总数，文件中单个单词数，单词长度

int judge(int a, int b, int c, int d) {
    int k = 0;
    do {
        if (pat[c][a][k] != pat[d][b][k]) {
            return 0;
        }
        k++;
        if (k == 11) break;
        if (pat[c][a][k] != pat[d][b][k]) {
            return 0;
        }
    } while (pat[c][a][k] == pat[d][b][k]);
    return 1;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 20; k++) {
                pat[i][j][k] = '#';
            }
        }
    }
    getchar();
    for (int i = 0; i < N; i++) {
        int j = 0;
        int k = 0;
        while (1) {
            char a;
            scanf("%c", &a);
            if (a == '#') {
                // getchar();
                break;
            } else if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
                if (a >= 'a' && a <= 'z') a = a - 32;
                // cout << a << endl;
                pat[i][j][k] = a;
                // cout << i << " " << j << " " << k << " " << a << endl;
                k++;
                continue;
            } else {
                if (k <= 2) {
                    k = 0;
                    continue;
                }
                if (k >= 10) {
                    int l = 10;
                    while (pat[i][j][l] != '#') {
                        pat[i][j][l] = '#';
                        l++;
                    }
                }
                if (pat[i][j][0] == '#') continue;
                j++;
                k = 0;
                continue;
            }
        }
        getchar();
    }
    // for (int i = 0; i < N; i++) {
    //     int j = 0;
    //     int k = 0;
    //     while (pat[i][j][0] != '#') {
    //         k = 0;
    //         while (pat[i][j][k] != '#') {
    //             cout << pat[i][j][k];
    //             k++;
    //         }
    //         j++;
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    int M;
    int file1, file2;
    int strnum[101];
    cin >> M;
    while (M--) {
        cin >> file1 >> file2;
        int dup1 = 0;
        int dup2 = 0;
        for (int i = 0; i < N; i++) {
            int j = 0;
            int k = 0;
            while (pat[i][j][0] != '#') {
                k = 0;
                while (pat[i][j][k] != '#') {
                    // cout << pat[i][j][k];
                    k++;
                }
                j++;
                // cout << endl;
            }
            strnum[i] = j;
            // cout << endl;
        }
        //提取出对应字符串

        // for (int i = 0; i < N; i++) {
        //     int j = 0;
        //     int k = 0;
        //     while (pat[i][j][0] != '#') {
        //         k = 0;
        //         int l = 1;
        //         // cout<<pat[i][j][k]<<"*"<<pat[i][j + l][k]<<endl;
        //         while (pat[i][j][k] == pat[i][j + l][k]) {
        //             if (pat[i][j][0] == '#') break;
        //             if (pat[i][j][k] == pat[i][j + l][k]) {
        //                 k++;
        //                 if (k == 11) {
        //                     for (int m = 0; m < k; m++) {
        //                         pat[i][j + l][m] = '+';
        //                     }
        //                     k = 0;
        //                     j++;
        //                     l = 1;
        //                     continue;
        //                 }
        //             } else {
        //                 l++;
        //                 if (pat[i][j + l][0] == '#')
        //                     break;
        //                 else {
        //                     k = 0;
        //                     j++;
        //                     l = 1;
        //                     continue;
        //                 }
        //             }
        //         }
        //         j++;
        //     }
        // }

        //检查相同
        int minfilenum = strnum[file1 - 1] <= strnum[file2 - 1] ? file1 - 1 : file2 - 1;
        int maxfilenum = strnum[file1 - 1] > strnum[file2 - 1] ? file1 - 1 : file2 - 1;
        int base = strnum[file1 - 1] <= strnum[file2 - 1] ? strnum[file1 - 1] : strnum[file2 - 1];
        int serch = strnum[file1 - 1] > strnum[file2 - 1] ? strnum[file1 - 1] : strnum[file2 - 1];
        int both = 0;

        //去除重复串
        int j = 0;
        int k = 0;
        while (pat[minfilenum][j][0] != '#') {
            k = 0;
            int l = 1;
            // cout<<pat[i][j][k]<<"*"<<pat[i][j + l][k]<<endl;
            while (pat[minfilenum][j][k] == pat[minfilenum][j + l][k]) {
                if (pat[minfilenum][j][0] == '#') break;
                if (pat[minfilenum][j][k] == pat[minfilenum][j + l][k]) {
                    k++;
                    if (k >= 10) {
                        dup1++;
                        // cout << "**" << endl;
                        for (int m = 0; m < k; m++) {
                            pat[minfilenum][j + l][m] = '+';
                        }
                        k = 0;
                        j++;
                        l = 1;
                        continue;
                    }
                } else {
                    l++;
                    if (pat[minfilenum][j + l][0] == '#')
                        break;
                    else {
                        k = 0;
                        j++;
                        l = 1;
                        continue;
                    }
                }
            }
            j++;
        }
        j = 0;
        k = 0;
        while (pat[maxfilenum][j][0] != '#') {
            k = 0;
            int l = 1;
            while (pat[maxfilenum][j][0] != pat[maxfilenum][j + l][0]) {
                //cout << pat[maxfilenum][j][0] << "*" << pat[maxfilenum][j + l][0] << endl;
                l++;
                if (pat[maxfilenum][j + l][0] == '#') {
                    break;
                }
            }
            // cout<<pat[maxfilenum][j][k]<<"*"<<pat[maxfilenum][j + l][k]<<endl;
            while (pat[maxfilenum][j][k] == pat[maxfilenum][j + l][k]) {
                if (pat[maxfilenum][j][0] == '#') break;
                if (pat[maxfilenum][j][k] == pat[maxfilenum][j + l][k]) {
                    k++;
                    if (k >= 10) {
                        // cout<<pat[maxfilenum][j + l][0];
                        // cout << "*" << endl;
                        dup2++;
                        for (int m = 0; m < k; m++) {
                            pat[maxfilenum][j + l][m] = '-';
                        }
                        k = 0;
                        j++;
                        l = 1;
                        continue;
                    }
                } else {
                    l++;
                    if (pat[maxfilenum][j + l][0] == '#')
                        break;
                    else {
                        k = 0;
                        j++;
                        l = 1;
                        continue;
                    }
                }
            }
            j++;
        }
        for (int i = 0; i < base; i++) {
            for (int j = 0; j < serch; j++) {
                if (judge(i, j, minfilenum, maxfilenum) == 1) {
                    // cout << i << " " << j << " " << minfilenum << " " << maxfilenum << endl;
                    both++;
                }
            }
        }
        //cout << both << endl;
        double res = 0;
        res = double(both) / double((base + serch - both - dup1 - dup2));
        //cout << base + serch - both - dup1 - dup2 << endl;
        //cout << res << endl;
        printf("%.1lf", res * 100);
        cout << "%" << endl;
        // for(int i = 0;i<N;i++){
        //     cout<<strnum[i]<<endl;
        // }
    }
} 