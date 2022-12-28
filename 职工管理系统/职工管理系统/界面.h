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
    void exit_system();//�˳�ϵͳ
    void Showpage();  //��ʾ����
    void add_emp();    //�����
    void del_emp();  //ɾ����
    int e_number;  //Ա������
    void init_emp();  //��ʼ����
    void mod_emp();  //�޸���
    void show_emp();  //��ʾ��
    void find_emp();  //������
    void sort_emp();  //����
    void drop(); //���
    void save(); //����
    bool file_empty; //�ļ��Ƿ�Ϊ��
    ~workermanager(); //����
};
