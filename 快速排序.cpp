#include <iostream>
using namespace std;
int n;
int qsortpart(int a[], int low, int high) {
    int pivot = a[low];
    a[0] = a[low];
    while (low < high) {
        while (a[high] >= pivot && low < high) high--;
        a[low] = a[high];
        while (a[low] <= pivot && low < high) low++;
        a[high] = a[low];
    }
    a[low] = a[0];
    for (int i = 1; i <= n; i++) {
        cout << a[i];
        if (i < n) cout << " ";
    }
    cout << endl;
    return low;
}

void qsort(int a[], int low, int high) {
    int pivot;
    if (low < high) {
        pivot = qsortpart(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int a[101];
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        qsort(a, 1, n);
        cout << endl;
    }
}