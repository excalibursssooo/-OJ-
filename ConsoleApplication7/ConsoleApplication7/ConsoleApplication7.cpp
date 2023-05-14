#include <iostream>
using namespace std;

class CPerson {
protected:
    string name;

public:
    CPerson(string _name = "zhangsan") :
        name(_name) {
        cout << "***CPerson Constructor***" << endl;
    }
    ~CPerson() {
        cout << "---CPerson distructor---" << name << endl;
    }
};
class CStudent : virtual public CPerson {
protected:
    int stuNo;

public:
    CStudent(string _name = "zhangsan", int _no = 2018150001) :
        stuNo(_no), CPerson(_name) {
        cout << "***CStudent Constructor***" << endl;
    }
    void print() {
        cout << "Student:" << name << " " << stuNo << endl;
    }
    ~CStudent() {
        cout << "---CStudent Destructor---" << endl;
    }
};
class CTeacher : virtual public CPerson {
protected:
    string title;

public:
    CTeacher(string _name = "lisi", string _title = "Professor") :
        title(_title), CPerson(_name) {
        cout << "***CTeacher Constructor***" << endl;
    }
    void print() {
        cout << "Teacher:" << name << " " << title << endl;
    }
    ~CTeacher() {
        cout << "---CTeacher Destructor---" << endl;
    }
};
class CStudentOnJob : public CStudent, public CTeacher {
private:
    string research; //研究方向
public:
    CStudentOnJob(string _name, int _stuNo, string _title, string _research) :
        CPerson(_name), //如果缺省，Cperson就会调用不带参数的构造方法，姓名并没有赋值进去。
        CStudent(_name, _stuNo),
        CTeacher(_name, _title),
        research(_research) {
        cout << "***CStudentOnJob Constructor***" << endl;
    }
    void print() {
        cout << "StudentOnJob:" << name << " " << stuNo << " " << title << " " << research << endl; //二义性
    }
    ~CStudentOnJob() {
        cout << "---CStudentOnJob Destructor---" << endl;
    }
};

int main() {
    CStudentOnJob stu("chen", 2017001, "professor", "software");
    stu.print();

    return 0;
}
