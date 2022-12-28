#include<iostream>
#include"界面.h"
using namespace std;


int main() {
    workermanager wm;
    while (1) {
        wm.Showpage();  //展示页面
        cout << "请输入你的选择" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
        case 0: //退出系统
            wm.exit_system();
            break;
        case 1: //增加职工
            wm.add_emp();
            break;
        case 2: //显示职工
            break;
        case 3: //删除职工
            break;
        case 4: //修改职工
            break;
        case 5: //查找职工
            break;
        case 6: //排序职工
            break;
        case 7: //清空文档
            break;
        default:
            system("cls"); //清屏
            break;
        }
    }
    system("pause");
}
