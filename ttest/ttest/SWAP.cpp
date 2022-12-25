#include <iostream>
using namespace std;

void SWAP(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}