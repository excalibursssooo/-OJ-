// 宿舍管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<list>
#include<cstring>
using namespace std;

struct cxk{
	string s;
	int num;
}q,p;

int main() {
	list<cxk> sushe;
	int n;
	cin >> n;
	int a[1001];
	memset(a, 0, sizeof(a));
	while (n--) {
		cin >>q.s>>q.num;
		a[q.num] = 1;
		sushe.push_back(q);
	}

	list<cxk> no_use;

	for (int i = 101; i <= 120; i++) {
		if (a[i] == 0) {
			p.num = i;
			p.s = "NULL";
			no_use.push_back(p);
		}
	}

	int m;
	cin >> m;
	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "assign") {
			string name;
			cin >> name;
			cxk a = no_use.front();
			a.s = name;
			for (list<cxk>::iterator np = sushe.begin(); np != sushe.end(); np++) {
				if (np->num > a.num) {

					sushe.insert(np, a);
					break;
				}

			}
			no_use.pop_front();
		}
		else if (cmd == "return") {
			int tui;
			cin >> tui;
			for (list<cxk>::iterator np = sushe.begin(); np != sushe.end(); np++) {
				if (np->num == tui) {
					sushe.erase(np);
					break;
				}
			}
			q.s = "empty";
			q.num = tui;
			no_use.push_back(q);
		}
		else if (cmd == "display_used") {
			for (list<cxk>::iterator np = sushe.begin(); np != sushe.end(); np++) {
				if (np != sushe.begin()) cout << "-";
				cout << np->s << "(" << np->num << ")";
			}
			cout << endl;
		}
		else if (cmd == "display_free") {
			for (list<cxk>::iterator np = no_use.begin(); np != no_use.end(); np++) {
				if (np != no_use.begin()) cout << "-";
				cout << np->num ;
			}
			cout << endl;
		}
	}

}

