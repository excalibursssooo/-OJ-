#include<iostream>
int a[10001];
int b[10001];
int ans[10001];
using namespace std;

void judge(int n) {
	int bools;
	cin >> bools;
	if (bools == 0) {
		int move;
		cin >> move;
		for (int i = 0; i < move; i++) {
			b[i] = a[i];
		}
		for (int i = 0; i < n; i++) {
			a[i] = a[i + move];
		}
		int j = 0;
		for (int i = n - move; i < n; i++) {
			a[i] = b[j];
			j++;
		}

		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	else {
		int move;
		cin >> move;
		int j = 0;
		for (int i = n - 1; i >= n - move; i--) {
			b[j] = a[i];
			j++;
		}


		for (int i = n - 1; i > move - 1; i--) {
			a[i] = a[i - move];
		}
		for (int i = 0; i < move; i++) {
			a[i] = b[j - 1];
			j--;
		}

		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	int move;
	cin >> move;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a[i] = num;
	}
	for (int i = 0; i < move; i++) {
		b[i] = a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] = a[i + move];
	}
	int j = 0;
	for (int i = n - move; i < n; i++) {
		a[i] = b[j];
		j++;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	

}