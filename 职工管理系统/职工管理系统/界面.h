#pragma once
#include<iostream>
#include "worker.h"
#include "common_worker.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#include <fstream>
#define FILENAME "empFile.txt"

class workermanager {
public:
    workermanager();  //
    Worker **ww;
    void exit_system();//退出系统
    void Showpage();  //显示界面
    void add_emp();    //添加人
    void del_emp();  //删除人
    int e_number;  //员工人数
    void init_emp();  //初始化人
    void mod_emp();  //修改人
    void show_emp();  //显示人
    void find_emp();  //查找人
    void sort_emp();  //排序
    void drop(); //清空
    void save(); //保存
    bool file_empty; //文件是否为空
    ~workermanager(); //析构
};
