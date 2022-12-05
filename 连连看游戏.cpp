#include <bits/stdc++.h>
using namespace std;
int Matrix[101][101]; //地图
int flag = 0;         //标记是否可以连起来
// x,y是当前坐标，fx,fy是终点坐标
int len;  //路径长度
int guai; //拐点数
int m, n; //地图大小
void dfs(int x, int y, int fx, int fy) {
    if (flag == 1) {
        return;
    }                         //如果已经标记为找到那就不用继续找
    if (x == fx && y == fy) { //如果找到那就标记为找到
        len++;
        cout << x << " " << y << endl; //测试用
        flag = 1;
        return;
    }
    if (x >= m || y >= n || x < 0 || y < 0) { //到达了边界，没有找到
        return;
    }
    if (Matrix[x][y] != 0)
        return; //非零的点不可以走
    else {
        cout << x << " " << y << endl;
        Matrix[x][y] = -1; //标记为走过
        len++;
        dfs(x + 1, y, fx, fy); //往右走
        guai++;
        dfs(x - 1, y, fx, fy); //往左走
        dfs(x, y + 1, fx, fy); //往下走
        dfs(x, y - 1, fx, fy); //往上走
        guai--;
        if (flag == 1) return;
        len--;
    }
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Matrix[i][j]);
        }
    }
    len = 0;
    guai = 0;
    int x, y, fx, fy;
    scanf("%d%d%d%d", &x, &y, &fx, &fy);
    Matrix[x][y] = 0;
    Matrix[fx][fy] = 0;
    dfs(x, y, fx, fy);
    cout<<guai<<endl;
    if (len == 0 || guai>2)
        printf("-1");
    else
        printf("%d", len);
}