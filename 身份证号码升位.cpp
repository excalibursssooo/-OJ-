#include<iostream>
#include<string>
using namespace std;

class CDate

{
private:
    int year, month, day;
    int month_day_noleap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_day_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    CDate() {
        year = 0;
        month = 1;
        day = 1;
    }
    CDate(int a, int b, int c) {
        year = a;
        month = b;
        day = c;
    }

    bool check() {
        if (year < 0) return 0;
        if (month > 12 || month < 1) return 0;
        if (day < 1 || day > 31) return 0;
        if (isLeap()) {
            if (day > month_day_leap[month - 1]) return 0;
        } else {
            if (day > month_day_noleap[month - 1]) return 0;
        }
        return 1;
    }
    int getYear() {
        return year;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    bool isLeap() {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    bool if_same(CDate &p) {
        if (p.year == year && p.month == month && p.day == day) return 1;
        return 0;
    }
    void print() {
        cout << year << "年" << month << "月" << day << "日";
    }
    string change_to_string() {
        string s = "";
        s = s + to_string(year);
        if (month >= 10)
            s += to_string(month);
        else
            s = s + "0" + to_string(month);

        if (day >= 10)
            s += to_string(day);
        else
            s = s + "0" + to_string(day);

        return s;
    }
};

class CStudentID

{
private:
    string p_id, p_name; // 身份证号码，姓名

    CDate birthday; // 出生日期

    int registered; // 登记否

    int jiao[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

    string jiaoshu[11] = {"1", "0", "X", "9", "8", "7", "6", "5", "4", "3", "2"};

public:
    CStudentID(string p_idval, string p_nameval, CDate &day) {
        registered = 1;
        birthday = day;
        p_id = p_idval;
        p_name = p_nameval;
        if (!day.check()) {
            registered = 0;
            return;
        }
        if (p_id.length() == 15) {
            for (int i = 0; i < 15; i++) {
                if (p_id[i] < '0' || p_id[i] > '9') {
                    registered = 0;
                    return;
                }
            }
            if (p_id.substr(6, 6) != day.change_to_string().substr(2, 6)) {
                registered = 0;
                return;
            }
        } else if (p_id.length() == 18) {
            for (int i = 0; i < 17; i++) {
                if (p_id[i] < '0' || p_id[i] > '9') {
                    registered = 0;
                    return;
                }
            }
            if (p_id[17] < '0' || p_id[17] > '9') {
                if (p_id[17] != 'X') {
                    registered = 0;
                    return;
                }
            }
            if (p_id.substr(6, 8) != day.change_to_string()) {
                registered = 0;
                return;
            }
            if (p_id[17] != get_jiao()[0]) {
                registered = 0;
                return;
            }
        } else {
            registered = 0;
            return;
        }

    } // 构造函数，若:日期非法;日期与id日期不符;id有非法字符;id不是15位或18位;id是18位但检验码不对,则输出"illegal id"并置registered=0。否则输出对象的属性并置registered=1.

    CStudentID(CStudentID &r) {
        p_name = r.p_name;
        registered = r.registered;
        birthday = r.birthday;
        if (r.p_id.length() == 18)
            return;
        else {
            string s = r.p_id.substr(0, 6);
            string ss = r.p_id.substr(6);
            string y = r.birthday.change_to_string();
            s += y.substr(0, 2);
            s += ss;
            p_id = s;
            p_id += get_jiao();
        }
    } // 拷贝构造函数，若r.p_id为15位则升到18位(加年份的19和校验位)

    bool checked() {
        return registered;
    }

    string get_jiao() {
        int sum = 0;
        for (int i = 0; i < 17; i++) {
            sum += (p_id[i] - '0') * jiao[i];
        }
        return jiaoshu[sum % 11];
    }

    void pprint() {
        cout << p_name << " ";
        birthday.print();
        cout << " " << p_id << endl;
    }

    void illegal_print() {
        cout << p_name << " illegal id" << endl;
    }

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d, m, y;
        cin >> y >> m >> d;
        CDate c(y, m, d);
        string name, id;
        cin >> name >> id;
        CStudentID C(id, name, c);
        if (C.checked()) {
            C.pprint();
            CStudentID CC(C);
            CC.pprint();
        } else {
            C.illegal_print();
        }
    }
}
