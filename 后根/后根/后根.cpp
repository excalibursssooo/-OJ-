#include<iostream>
using namespace std;

void search(int m, char a[], int b[][101]) {
    int k = 0;
    do{
        if (b[m][k] == -1) { 
            cout << a[m];
            return;
        }
        search(b[m][k], a, b);
        k++;
        if (b[m][k] == -1) {
            cout << a[m];
            return;
        }
    }while (b[m][k] != -1);
}


int main() {
    int N, gen;
    cin >> N >> gen;
    char a[101];
    int b[101][101];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        int l = 0; //记录多少个孩子
        do {
            int p;
            cin >> p;
            b[i][l] = p;
            l++;
        } while (b[i][l - 1] != -1);
    }
    search(gen, a, b);
    cout << endl;
}