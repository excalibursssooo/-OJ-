#include "manager.h"

//���캯��
manager::manager(int id, string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

//��ʾ������Ϣ
void manager::showInfo() {
    cout << "ְ����ţ� " << this->m_Id
         << "\tְ�������� " << this->m_Name
         << "\t��λ�� " << this->getDeptName()
         << "\t��λְ�� ����ϰ彻�������񣬲��·������Ա��" << endl;
}

//��ȡ��λ����
string manager::getDeptName() {
    return string("����");
}