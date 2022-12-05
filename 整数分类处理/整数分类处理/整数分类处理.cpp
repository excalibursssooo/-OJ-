

#include <iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int desc(int a,int b) {
    return b < a;
}

int main()
{
    int N;
    cin >> N;
    int a[10001];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a+N,desc);
    
    for (int i = 0; i < N; i++) {
        if (a[i] % 3 == 0) {
        cout << a[i] << " ";
        break;
        }
    }
    int j = 0;
    double k = 0;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        if ((a[i] - 1) % 3 == 0) {
            j++;
        }
        if ((a[i] - 2) % 3 == 0) {
            sum += a[i];
            k++;
        }
    }

    if (j != 0)  cout << j <<" ";
    else cout << "NONE" << " ";
    double ave;
    ave = sum / k;
    if (k != 0)  cout <<fixed<< setprecision(1) << ave;
    else cout << "NONE" ;
}


