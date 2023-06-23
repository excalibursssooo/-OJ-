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
    cin >> t;
    
}