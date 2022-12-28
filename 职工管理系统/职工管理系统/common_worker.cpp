#include"common_worker.h"

commom_worker::commom_worker(int m_Id, string m_Name, int m_DeptId) {
    this->m_Id = m_Id;
    this->m_Name = m_Name;
    this->m_DeptId = m_DeptId;
}

string commom_worker::getDeptName() {
    return string("普通员工");
}


void commom_worker::showInfo() {
    cout << "职工编号： " << this->m_Id
         << "\t职工姓名： " << this->m_Name
         << "\t岗位： " << this->getDeptName()
         << "\t岗位职责： 完成经理交给的任务" << endl;
}