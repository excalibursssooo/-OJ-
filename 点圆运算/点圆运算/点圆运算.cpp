// 点圆运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class point {
private:
	int x;
	int y;
public:
	point(int a,int b) {
		x = a;
		y = b;
	}
	point() {
		x = 0;
		y = 0;
	}
	void Setzero(){
		x = 0;
		y = 0;
		cout << "point clear" << endl;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void Setxy(int a,int b) {
		x = a;
		y = b;

	}

};

class circle {
private:
	int c_x;
	int c_y;
	int r;
public:
	circle(int x, int y,int R) {
		c_x = x;
		c_y = y;
		r=R;
	}
	int circleX() {
		return c_x;
	}
	int circleY(){
		return c_y;
	}
	void setczero() {
		c_y = 0;
		c_x = 0;
		r = 0;
		cout << "circle clear";
	}

	void contain(point a) {
		if ((a.getX() - c_x) * (a.getX() - c_x) + (a.getY() - c_y) * (a.getY() - c_y) > r * r) {
			cout << "out"<<endl;
		}
		else cout << "in" << endl;
	}
};

int main()
{
	int p, q;
	cin >> p >> q;
	point wow(p, q);
	point cai[10001];
	int t;
	cin >> t;
	int z = t;
	int i = 0;
	while (t--) {
		int u, v;
		cin >> u >> v;
		cai[i].Setxy(u, v);
		i++;
	}
	int x, y, r;
	cin >> x >> y >> r;
	circle xu(x,y,r);
	xu.contain(wow);
	int j = 0;
	while (z--) {
		
		xu.contain(cai[j]);
		j++;
	}
	xu.setczero();
	cout << endl;
	wow.Setzero();
	
	return 0;
}


