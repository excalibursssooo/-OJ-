// 数制转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stack>
#include<queue>
using namespace std;

char change(int a) {
    if (a == 10) return 'A';
    if (a == 11) return 'B';
    if (a == 12) return 'C';
    if (a == 13) return 'D';
    if (a == 14) return 'E';
    if (a == 15) return 'F';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        double num;
        int a;
        cin >> num >> a;
        int num1;
        num1 = (int)num;
        double small = num - num1;
        stack<int>p;
        queue<int>q;
            while (num1 > 0) {
                p.push(num1 % a);
                num1 /= a;
            }
            for (int i = 0; i < 3; i++) {
                int temp = (int)(small * a);
                q.push(temp);
                small = small * a - temp;
            }
            while (!p.empty()) {
                if (p.top() >= 10) {
                    cout << change(p.top());
                }
                else cout << p.top();
                p.pop();
            }
            cout << ".";
            while (!q.empty()) {
                if (q.front() >= 10) {
                    cout << change(q.front());
                }
                else cout << q.front();
                q.pop();
            }
            cout << endl;
        }
}

