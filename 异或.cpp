#include <stdio.h>
int main() {
    int arr[9] = {2, 4, 3, 5, 5, 4, 2, 1, 3};
    int x = 0;
    for (int i = 0; i < 9; i++) {
        printf("%d ^ %d = ", x, arr[i]);
        x = x ^ *(arr + i);
        printf("%d\n", x);
    }
    printf("%d", x);
}
