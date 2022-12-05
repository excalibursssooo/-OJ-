#include <iostream>
#include <algorithm>
using namespace std;

int num1[10000];
int l[10000];
int m[10000];
void MERGE(int A[], int p, int q, int r) {
	for (int i = 1; i <= q - p+1 ; i++) {
		l[i] = A[p+i-1];
	}
	
	for (int j = 1; j <= r - q; j++) {
		m[j] = A[q+j];

	}
	int i = 1;
	int j = 1;
	for (int k = p; k <= r ; k++) {
		if (m[i] <= l[j]) {
			A[k] = m[i];
			i++;
		}
		else if(m[i] > l[j]){
			A[k] = l[j];
			j++;
		}
			
	}
}

void MERGE_SORT(int A[], int p, int r) {

	if (p < r) {
		int q = ((p + r) / 2 );
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q + 1, r);
		MERGE(A, p, q, r);
	}
}

int main()
{
	int num[] = { 1,5,69,54,78,96,45,169};
	MERGE_SORT(num, 1, 7); 
	for (int i = 1; i < 8; i++) {
		cout << num[i] << endl;

	}

}
