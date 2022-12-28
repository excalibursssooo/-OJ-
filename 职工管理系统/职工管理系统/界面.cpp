#include<iostream>
using namespace std;
#include "界面.h"


workermanager::workermanager() {
    //1、文件不存在

    ifstream ifs;
    ifs.open(FILENAME, ios::in); // 读文件

    if (!ifs.is_open()) {
        //cout << "文件不存在" << endl;
        //初始化属性
        //初始化记录人数
        this->e_number = 0;
        //初始化数组指针
        this->ww = NULL;
        //初始化文件是否为空
        this->file_empty = true;
        ifs.close();
        return;
    }

    //2、文件存在 数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        //文件为空
        //cout << "文件为空！" << endl;
        //初始化记录人数
        this->e_number = 0;
        //初始化数组指针
        this->ww = NULL;
        //初始化文件是否为空
        this->file_empty = true;
        ifs.close();
        return;
    }


}

void workermanager::Showpage() {
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void workermanager::exit_system() {
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}


void workermanager::add_emp() {
    cout << "请输入您要添加的员工数" << endl;
    int size;
    cin >> size;
    if (size > 0) {
        Worker **new_w = new Worker*[size + this->e_number];
        if (ww != NULL) {
            for (int i = 0; i < e_number; i++) {
                new_w[i] = this->ww[i];
            }
        }
        for (int i = 0; i < size; i++) {
            int id;      //职工编号
            string name; //职工姓名
            int dSelect; // 部门选择

            cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
            cin >> id;

            cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
            cin >> name;

            cout << "请选择该职工岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect) {
            case 1:
                worker = new commom_worker(id, name, 1);
                break;
            case 2:
                worker = new manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            //将创建职工职责 ，保存到数组中
            new_w[this->e_number + i] = worker;
        }
        delete[] this->ww;  //删除原数组

        this->ww = new_w;

        this->e_number += size;

        cout << "添加成功！" << endl;

        this->save();

    } else {
        cout << "输入信息有误！" << endl;
    }

    system("pause");
    system("cls");
}

void workermanager::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < e_number; i++) {
        ofs << this->ww[i]->m_Id << " "
            << this->ww[i]->m_Name << " "
            << this->ww[i]->m_DeptId << endl;
    }
    ofs.close();
}

workermanager::~workermanager() {

}
