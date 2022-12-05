// 指针运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int scor[1001];
        int sc;
        int j = 0;
        for (j = 0;j < n; j++) {
            cin >> sc;
            scor[j] = sc;
        }

        int* p;
        p = &scor[j / 2];
        int need;
        cin >> need;
        int len = j / 2 +1- need;
        cout << len << endl;

        cout << *(p-1) << " " << *(p+1) << endl;
        cout << *(p - len) << endl;
    }
    
}

