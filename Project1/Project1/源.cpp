#include <iostream>
using namespace std;
class CArray {
public:
    CArray() {
    }
    CArray(int nValue, int mValue) :
        n(nValue), m(mValue) {
        data = new int *[n];
        for (int i = 0; i < n; i++)
            data[i] = new int[m];
    }
    CArray(const CArray &a) {
        n = a.n;
        m = a.m;
        data = new int *[n];
        for (int i = 0; i < n; i++)
            data[i] = new int[m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; j++)
                data[i][j] = a.data[i][j];
    }
    CArray &operator=(const CArray &a)
    //要重载=号，不重载就是浅拷贝
    {
        if (data != NULL) {
            for (int i = 0; i < n; i++)
                delete[] data[i];
            delete[] data;
        }
        n = a.n;
        m = a.m;
        data = new int *[n];
        for (int i = 0; i < n; i++)
            data[i] = new int[m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; j++)
                data[i][j] = a.data[i][j];
        return *this;
    }
    ~CArray() {
        for (int i = 0; i < n; i++)
            delete[] data[i];
        delete[] data;
    }
    /*operator int**()
		{
			return data;
		}*/
    int *const operator[](const int k) {
        return data[k];
    }
    int operator()(int i, int j) {
        return data[i][j];
    }

private:
    int n, m;
    int **data;
};

int main() {
    int t;
    int n, m;
    int i, j;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        CArray matrixA(n, m);
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; j++)
                cin >> matrixA[i][j];
        cout << "MatrixA:" << endl;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; j++) {
                cout << matrixA(i, j) << " ";
            }
            cout << endl;
        }
        cout << "MatrixB:" << endl;
        CArray matrixB;
        matrixB = matrixA;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << matrixB[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
