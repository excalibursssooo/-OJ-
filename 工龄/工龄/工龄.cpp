

#include <iostream>
#include<algorithm>
using namespace std;


int main()
{
    int N;
    cin >> N;
    int a[10001];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    sort(a, a + N);
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (a[i + 1] == a[i]) {
            j++;
        }
        else if (a[i + 1] != a[i]) {
            cout << a[i] << ":" << j+1 << endl;
            j = 0;
        }
    }

}


