#include<iostream>
using namespace std;
#include "����.h"


workermanager::workermanager() {
    //1���ļ�������

    ifstream ifs;
    ifs.open(FILENAME, ios::in); // ���ļ�

    if (!ifs.is_open()) {
        //cout << "�ļ�������" << endl;
        //��ʼ������
        //��ʼ����¼����
        this->e_number = 0;
        //��ʼ������ָ��
        this->ww = NULL;
        //��ʼ���ļ��Ƿ�Ϊ��
        this->file_empty = true;
        ifs.close();
        return;
    }

    //2���ļ����� ����Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        //�ļ�Ϊ��
        //cout << "�ļ�Ϊ�գ�" << endl;
        //��ʼ����¼����
        this->e_number = 0;
        //��ʼ������ָ��
        this->ww = NULL;
        //��ʼ���ļ��Ƿ�Ϊ��
        this->file_empty = true;
        ifs.close();
        return;
    }


}

void workermanager::Showpage() {
    cout << "********************************************" << endl;
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void workermanager::exit_system() {
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}


void workermanager::add_emp() {
    cout << "��������Ҫ��ӵ�Ա����" << endl;
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
            int id;      //ְ�����
            string name; //ְ������
            int dSelect; // ����ѡ��

            cout << "������� " << i + 1 << " ����ְ����ţ� " << endl;
            cin >> id;

            cout << "������� " << i + 1 << " ����ְ�������� " << endl;
            cin >> name;

            cout << "��ѡ���ְ����λ�� " << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
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
            //������ְ��ְ�� �����浽������
            new_w[this->e_number + i] = worker;
        }
        delete[] this->ww;  //ɾ��ԭ����

        this->ww = new_w;

        this->e_number += size;

        cout << "��ӳɹ���" << endl;

        this->save();

    } else {
        cout << "������Ϣ����" << endl;
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
