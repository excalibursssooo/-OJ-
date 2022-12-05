

#include <iostream>
using namespace std;
void point(int *a,int *b) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			*(b + 4 - 2 * j + i) = *(a + 3 * i + j);
		}
	}
}
int main()
{
	int M[6];
	int t;
	int N[100];
	cin >> t;
	while (t--) {
		for (int i = 0;  i< 2; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> M[i*3+j];
			}
		}
		point(M, N);
		int* p;
		p = &N[0];
		for (int i = 0; i < 6; i++) {
			cout << *p;
			p++;
			cout << " ";
			if (i % 2 == 1) cout << endl;
		}
		
	}
	return 0;
}


