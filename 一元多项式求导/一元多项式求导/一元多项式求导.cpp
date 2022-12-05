
//

#include <iostream>
#include<stdio.h>
using namespace std;


int main()
{
    
    int a[1001];
    int b[1001];
    int i = 0, j = 0;
    while (cin>>a[i]>>b[i]) {
        i++;
        j++;
    }

    for (int k = 0; k < i; k++) {
        if (b[k] == 0)  continue;
        if (k>=1&&k<i)  printf(" ");
        printf("%d %d", a[k] * b[k], b[k] - 1);
    }

    return 0;

}

