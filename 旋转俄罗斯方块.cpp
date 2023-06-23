#include <iostream>
using namespace std;
#define N 4
class CBlock {
    char arr[N][N]{};

public:
    CBlock() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = '.';
            }
        }
    } // 无参构造
    CBlock(CBlock &C) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = C.arr[i][j];
            }
        }
    }
    // 1. 重载 "++" "--" 运算符（包括前置和后置）
    CBlock &operator++() {
        char tmp[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = tmp[N - 1 - j][i];
            }
        }
        return *this;
    }
    CBlock &operator++(int) {
        CBlock *B = new CBlock(*this);
        char tmp[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = tmp[N - 1 - j][i];
            }
        }
        return *B;
    }
    CBlock &operator--() {
        char tmp[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = tmp[j][N - 1 - i];
            }
        }
        return *this;
    }
    CBlock &operator--(int) {
        CBlock *B = new CBlock(*this);
        char tmp[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = tmp[j][N - 1 - i];
            }
        }
        return *B;
    }
    //    其中，"++" 实现4x4矩阵顺时针旋转, "--" 为逆时针旋转
    friend ostream &operator<<(ostream &os, const CBlock &C) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                os << C.arr[i][j];
            }
            if (i != N - 1)
                os << endl;
        }
        return os;
    }
    friend istream &operator>>(istream &os, CBlock &C) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                os >> C.arr[i][j];
            }
        }
        return os;
    }
    // ...可以添加其它任何函数, 但不得修改已有定义...
};
// 2. 为CBlock对象重载输入输出
int main() {
    int n;
    cin >> n;
    while (n--) {
        CBlock block;
        cin >> block;
        switch (n & 1) {
        case 0: (++block)++; break;
        case 1: --(block--); break;
        }
        cout << endl
             << block << endl;
    }
    return 0;
}
