#include<iostream>
#include"����.h"
using namespace std;


int main() {
    workermanager wm;
    while (1) {
        wm.Showpage();  //չʾҳ��
        cout << "���������ѡ��" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
        case 0: //�˳�ϵͳ
            wm.exit_system();
            break;
        case 1: //����ְ��
            wm.add_emp();
            break;
        case 2: //��ʾְ��
            break;
        case 3: //ɾ��ְ��
            break;
        case 4: //�޸�ְ��
            break;
        case 5: //����ְ��
            break;
        case 6: //����ְ��
            break;
        case 7: //����ĵ�
            break;
        default:
            system("cls"); //����
            break;
        }
    }
    system("pause");
}
