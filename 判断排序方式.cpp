#include <iostream>
using namespace std;

int judge(int a[], int b[], int n) {
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int judgemm(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int n;
    int a[101], b[101];
    int tempa[101], tempb[101];
    cin >> n;
    a[0] = 0;
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tempa[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        tempb[i] = b[i];
    }
    int flag = 0;
    for (int i = 2; i <= n; i++) {
        tempa[0] = tempa[i];
        int j;
        for (j = i; j > 0; j--) {
            if (tempa[0] < tempa[j - 1])
                tempa[j] = tempa[j - 1];
            else
                break;
        }
        tempa[j] = tempa[0];
        if (flag == 1) {
            cout << "Insertion Sort" << endl;
            for (int i = 1; i <= n; i++) {
                cout << tempa[i];
                if (i != n)
                    cout << " ";
                else
                    cout << endl;
            }
            return 0;
        }
        if (judge(tempa, b, n) == 1) {
            flag = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = a[i + 1];
        b[i] = b[i + 1];
    }
    int temp[101];
    int t = 2;
    while (t < n)
        t *= 2;
    for (int i = 2; i < t + 1; i *= 2) {
        for (int j = 0; j < n; j += i) {
            int head = j, tail = j + i / 2;
            if (tail > n)
                break;
            int middle = tail - 1;
            int temp_loc = head;
            while (head <= middle && tail < j + i && tail < n) {
                if (a[head] < a[tail])
                    temp[temp_loc++] = a[head++];
                else
                    temp[temp_loc++] = a[tail++];
            }
            while (head <= middle)
                temp[temp_loc++] = a[head++];
            while (tail < j + i && tail < n)
                temp[temp_loc++] = a[tail++];
            for (int m = j; m < j + i && m < n; m++) {
                a[m] = temp[m];
            }
        }

        
        if (flag == 1) {
            cout << "Merge Sort" << endl;
            for (int k = 0; k < n; k++) {
                
                cout << a[k];
                if (k != n - 1)
                    cout << " ";
            }
            cout << endl;
            return 0;
        }
        if (judgemm(a, b, n) == 1) {
            flag = 1;
        }
    }
}