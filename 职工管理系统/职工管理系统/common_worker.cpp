#include"common_worker.h"

commom_worker::commom_worker(int m_Id, string m_Name, int m_DeptId) {
    this->m_Id = m_Id;
    this->m_Name = m_Name;
    this->m_DeptId = m_DeptId;
}

string commom_worker::getDeptName() {
    return string("��ͨԱ��");
}


void commom_worker::showInfo() {
    cout << "ְ����ţ� " << this->m_Id
         << "\tְ�������� " << this->m_Name
         << "\t��λ�� " << this->getDeptName()
         << "\t��λְ�� ��ɾ�����������" << endl;
}