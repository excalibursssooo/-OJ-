#include<iostream>
using namespace std;
#include "SWAP.h"

int main() {
    int a = 50, b = 60;
    SWAP(&a, &b);
    cout << a << " " << b << endl;
}