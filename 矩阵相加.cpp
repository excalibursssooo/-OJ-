#include <iostream>
using namespace std;

class Matrix {
private:
    int m, n;
    int **data;

public:
    Matrix(int mm, int nn) {
        data = new int *[mm];
        m = mm;
        n = nn;
        for (int i = 0; i < m; i++) {
            data[i] = new int[nn];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> data[i][j];
            }
        }
    }
    Matrix(const Matrix &M) {
        m = M.m;
        n = M.n;
        data = new int *[M.m];
        for (int i = 0; i < m; i++) {
            data[i] = new int[M.n];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = M.data[i][j];
            }
        }
    }
    Matrix operator+(Matrix &M) {
        Matrix temp(*this);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp.data[i][j] = data[i][j] + M.data[i][j];
            }
        }
        return temp;
    }
    void print() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << data[i][j];
                if (j != n - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        Matrix A(m, n);
        Matrix B(m, n);
        Matrix C(A);
        C = A + B;
        C.print();
    }
}