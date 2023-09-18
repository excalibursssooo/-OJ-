#include <bits/stdc++.h>
using namespace std;

template <class T>
void Mysort(T num[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (num[j] < num[i]) {
                T tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << num[i];
        if (i != size - 1)
            cout << " ";
        else
            cout << endl;
    }
}

int main() {
    int t;

    while (1) {
        cin >> t;
        if (t == 0) break;
        if (t == 1) {
            int size;
            cin >> size;
            int *num = new int[size + 1];
            for (int i = 0; i < size; i++) {
                cin >> num[i];
            }
            Mysort(num, size);
        } else if (t == 2) {
            int size;
            cin >> size;
            char *num = new char[size + 1];
            for (int i = 0; i < size; i++) {
                cin >> num[i];
            }
            Mysort(num, size);
        } else if (t == 3) {
            int size;
            cin >> size;
            double *num = new double[size + 1];
            for (int i = 0; i < size; i++) {
                cin >> num[i];
            }
            Mysort(num, size);
        } else if (t == 4) {
            int size;
            cin >> size;
            string *num = new string[size + 1];
            for (int i = 0; i < size; i++) {
                cin >> num[i];
            }
            Mysort(num, size);
        }
    }
}