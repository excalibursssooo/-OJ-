#include <iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;

int main()
{
	string s;
	stack<int>p;
	stack<char>q;
	cin >> s;
	q.push(s[0]);
	p.push(0);
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == q.top()) {
			q.push(s[i]);
			p.push(i);
		}
		else if (s[i] != q.top()) {
			cout << p.top() << " " << i << endl;
			p.pop();
			q.pop();
		}
	}
}