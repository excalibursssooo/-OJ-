#include <iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;

char change(int a) {
	if (a == 10) return 'A';
	if (a == 11) return 'B';
	if (a == 12) return 'C';
	if (a == 13) return 'D';
	if (a == 14) return 'E';
	if (a == 15) return 'F';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		double num;
		cin >> num;
		int n;
		cin >> n;
		int num1 = (int)num;
		double small = num - num1;
		queue<int>p;
		stack<int>q;

		while (num1 > 0) {
			q.push(num1 % n);
			num1 = num1 / n;
		}
		for (int i = 0; i < 3; i++) {
			int data = (int)(small * n);
			p.push(data);
			small = small * n - data;
		}
		if (q.empty()) {
			cout << 0;
		}
		else {
			while (!q.empty()) {
				if (q.top() >= 10) {
					cout << change(q.top());
					q.pop();
				}
				else {
					cout << q.top();
					q.pop();
				}
			}
		}
		cout << ".";
		for (int i = 0; i < 3; i++) {
			if (p.front() >= 10) {
				cout << change(p.front());
				p.pop();
			}
			else {
				cout << p.front();
				p.pop();
			}
		}
		cout << endl;

	}
}