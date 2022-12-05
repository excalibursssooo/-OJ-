// 德才论.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdio.h>
using namespace std;

void charu(int i,int num,int a[],int len) {
    for (int j = len; j > i - 1; j--) {
        a[j] = a[j - 1];
    }
    a[i - 1] = num;
}

class studnet {
private:
    int num;
    int desc;
    int caisc;
public:
    void setstudent(int s_num, int s_desc, int s_caisc) {
        num = s_num;
        desc = s_desc;
        num = s_caisc;
    }

    int total() {
        return desc + caisc;
    }

    int getnum() {
        return num;
    }
    int getdesc() {
        return desc;
    }
    int getcaisc() {
        return caisc;
    }

    void print() {
        cout << num << " " << desc << " " << caisc << endl;
    }


};

int main()
{
    int N, L, H;
    cin >> N >> L >> H;
    studnet lun[10001];
    int num1, desc1, caisc1;
    for (int i = 0; i < N; i++) {
        cin >> num1 >> desc1 >> caisc1;
        lun[i].setstudent(num1, desc1, caisc1);
    }

    int a[10001];
    int b[10001];
    int j = 1;
    a[0] = 0;
    int num;
    int no[10001];
    for (int i = 0; i < N; i++) {
        if (lun[i].getdesc() >= H && lun[i].getcaisc() >= H) {
            if (j == 1) {
                a[1] = lun[i].total();
            }
            else {
                  num = lun[i].total();
                  no[j] = lun[i].getnum();
                  j++;
                  for (int k = 0; k < j; k++) {
                      if (a[k + 1] == 0)  a[k + 1] = num;
                      else if (a[k]<num && a[k + 1]>num) {
                          charu(k + 1, num, a , j);
                      }
                      else if (a[k] == num) {
                          if(no[j])
                      }
                  }
            }
            
        }
        else if (lun[i].getdesc() >= H && lun[i].getcaisc() < H) {

        }
    }

    

}

