#include <bits/stdc++.h>
using namespace std;

template <class T>
void Combine(T num1[], T num2[], int size) {
    for (int i = 0; i < size; i++) {
        cout << num2[i];
    }
    for (int i = 0; i < size; i++) {
        cout << num1[i];
    }
    cout << endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        char C;
        std::cin >> C;
        if (C == 'I') {
            int size;
            std::cin >> size;
            int *num1 = new int[size + 1];
            int *num2 = new int[size + 1];
            for (int i = 0; i < size; i++) {
                std::cin >> num1[i];
            }
            for (int i = 0; i < size; i++) {
                std::cin >> num2[i];
            }
            Combine(num1, num2, size);
        } else if (C == 'D') {
            int size;
            std::cin >> size;
            double *num1 = new double[size + 1];
            double *num2 = new double[size + 1];
            for (int i = 0; i < size; i++) {
                std::cin >> num1[i];
            }
            for (int i = 0; i < size; i++) {
                std::cin >> num2[i];
            }
            Combine(num1, num2, size);
        } else if (C == 'C') {
            int size;
            std::cin >> size;
            char *num1 = new char[size + 1];
            char *num2 = new char[size + 1];
            for (int i = 0; i < size; i++) {
                std::cin >> num1[i];
            }
            for (int i = 0; i < size; i++) {
                std::cin >> num2[i];
            }
            Combine(num1, num2, size);
        }
    }
}