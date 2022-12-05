// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int num1[];
int l[];
int m[];
void MERGE(int A[], int p, int q, int r) {
	for (int i = 1; i <= q-p+1; i++) {
		l[i] = A[p];
		p++;
	}
	for (int j = 1; j <= r - q; j++) {
		m[j] = A[q];
		q++;
	}

	int i = 1;
	int j = 1;
	for (int k = 1; k < r - p + 1; k++) {
		if (m[i] <= l[j]) {
			A[k] = m[i];
			i++;
		}
		else {
			A[k] = l[j];
			j++;
		}
	}
}

void MERGE_SORT(int A[], int p, int q) {
	if (p < q) {
		int r = (p + q) / 2;
		MERGE_SORT(A, p, r);
		MERGE_SORT(A, r + 1, q);
		MERGE(A,p ,r ,q);
	}
}

int main()
{
	int num[] = { 1,5,69,54,78,63 };
	MERGE_SORT(num, 0, 5);
	for (int i = 0; i < 6; i++) {
		cout << num[i];

	}

}
