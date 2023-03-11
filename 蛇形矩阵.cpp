#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "请输入n：";
    cin >> n;

    int matrix[n][n];
    int num = 1;

    // 填充蛇形矩阵
    for (int i = 0; i < n / 2; i++) {
        // 上方从左到右
        for (int j = i; j < n - i - 1; j++) {
            matrix[i][j] = num++;
        }
        // 右侧从上到下
        for (int j = i; j < n - i - 1; j++) {
            matrix[j][n - i - 1] = num++;
        }
        // 下方从右到左
        for (int j = n - i - 1; j > i; j--) {
            matrix[n - i - 1][j] = num++;
        }
        // 左侧从下到上
        for (int j = n - i - 1; j > i; j--) {
            matrix[j][i] = num++;
        }
    }

    // 填充中心点（如果n为奇数）
    if (n % 2 == 1) {
        matrix[n / 2][n / 2] = num;
    }

    // 输出蛇形矩阵
    cout << "蛇形矩阵：" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
