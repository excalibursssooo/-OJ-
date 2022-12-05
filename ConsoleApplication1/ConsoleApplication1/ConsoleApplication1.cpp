// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;
int num[];
int L[];
int M[];
int r;
void MERGRE(int A[], int a, int b, int c) {
	for (int i = 0; i <= b - a + 1; i++)   L[i] = A[a + i];
	for (int j = 0; j <= c - b; j++)  M[j] = A[b + j - 1];
	int i = 0;
	int j = 0;
	for (int k = a; k <= r; k++) {
		if (L[i] <= M[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = M[j];
			j++;
		}
	}
}


void MERGE_SORT(int A[],int p,int q) {
	if (p < q) {
		r = (p + q) / 2;
		MERGE_SORT(A, p, r);
		MERGE_SORT(A, r+1, q);
		MERGRE(A, p, r, q);
	}
}



int main() {
	int num[] = { 1,2,9,15,13,91,65,46,10 };
	MERGE_SORT(num, 0, 9);
	for (int i = 1; i <= 8; i++)  cout << num[i];
}
