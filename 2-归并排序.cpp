#include<bits/stdc++.h>
using namespace std;
int n;
string nums[101], temp[101];
void Merge_sort() {
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
                if (nums[head] > nums[tail])
                    temp[temp_loc++] = nums[head++];
                else
                    temp[temp_loc++] = nums[tail++];
            }
            while (head <= middle)
                temp[temp_loc++] = nums[head++];
            while (tail < j + i && tail < n)
                temp[temp_loc++] = nums[tail++];
            for (int m = j; m < j + i && m < n; m++) {
                nums[m] = temp[m];
            }
        }
        for (int k = 0; k < n; k++) {
            cout << nums[k];
            if (k != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Merge_sort();
        cout << endl;
    }
}