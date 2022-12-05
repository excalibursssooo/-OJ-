#include<iostream>

using namespace std;

void search(int m, char a[], int b[][1001]) {
    int k = 0;
    while (b[m][k] != -1) {
        if (b[m][k] == -1) cout << a[m];
        search(b[m][k], a, b);
        k++;
    }
}


int main() {
    int N, gen;
    cin >> N >> gen;
    char aa[1001]; 
    int bb[1001][1001];
    for (int i = 0; i < N; i++) {
        cin >> aa[i];
        int l = 0; //记录多少个孩子
        cin >> bb[i][l];
        while (bb[i][l - 1] != -1) {
            cin >> bb[i][l];
        }
    }
    search(gen, aa, bb);
    cout << endl;
}