#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "������n��";
    cin >> n;

    int matrix[n][n];
    int num = 1;

    // ������ξ���
    for (int i = 0; i < n / 2; i++) {
        // �Ϸ�������
        for (int j = i; j < n - i - 1; j++) {
            matrix[i][j] = num++;
        }
        // �Ҳ���ϵ���
        for (int j = i; j < n - i - 1; j++) {
            matrix[j][n - i - 1] = num++;
        }
        // �·����ҵ���
        for (int j = n - i - 1; j > i; j--) {
            matrix[n - i - 1][j] = num++;
        }
        // �����µ���
        for (int j = n - i - 1; j > i; j--) {
            matrix[j][i] = num++;
        }
    }

    // ������ĵ㣨���nΪ������
    if (n % 2 == 1) {
        matrix[n / 2][n / 2] = num;
    }

    // ������ξ���
    cout << "���ξ���" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
