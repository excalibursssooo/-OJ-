
#include <iostream>
#include<stack>

using namespace std;
int n;
int flag;
struct point
{
	int x;
	int y;
}cod;

stack<point> path1;

void dfs(int x, int y, int map[][101]) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) {
		return;
	}
	else if (flag == 1) return;
	else if (x == n - 1 && y == n - 1) {
		cod.x = x;
		cod.y = y;
		path1.push(cod);
		map[x][y] = 1;
		flag = 1;
		return;
	}
	else if (map[x][y] == 0) {
		cod.x = x;
		cod.y = y;
		path1.push(cod);
		//cout << path1.top().x << " " << path1.top().y << endl;
		map[x][y] = 1;
	}
	else if (map[x][y] == 1) return;
	
	dfs(x, y + 1, map);
	dfs(x + 1, y, map);
	dfs(x, y - 1, map); 
	dfs(x-1, y, map);
	if (flag==1)
	{
		return;
	}
	path1.pop();
}

int main()
{
	
	int t;
	cin >> t;
	while (t--) {
		flag = 0;
		cin >> n;
		int a[101][101];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		dfs(0, 0, a);
		int i = 0;
		if (flag == 1) {
			stack<point> path;
			while (!path1.empty()) {
				path.push(path1.top());
				path1.pop();
			}
			while (!path.empty()) {
				cod = path.top();
				if ((++i) % 4 == 0) cout << "[" << cod.x << "," << cod.y << "]" << "--" << endl;
				else cout << "[" << cod.x << "," << cod.y << "]" << "--";
				path.pop();
			}
			cout << "END" << endl;
		}
		else cout << "no path" << endl;
	}
}

