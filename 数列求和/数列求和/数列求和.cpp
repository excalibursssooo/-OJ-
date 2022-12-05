
#include <iostream>
using namespace std;
int main()
{
    int A;
    int N;
    cin >> A >> N;
    int a[10001];
    a[0] = A;
    int sum;
    sum = A;
    for (int i = 1; i < N; i++) {
        a[i] = a[i - 1] * 10 + a[0];
        sum += a[i];
    }

    cout << sum;
}

