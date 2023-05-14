#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

using namespace std;

class good {
private:
    string type;
    string name;
    string color;
    string chi;
    double price;
    double num;

public:
    good() {
        type = "type";
        name = "n";
        color = "co";
        chi = "ch";
        price = 0;
        num = 0;
    }
    double total_price() {
        return price * num;
    }
    string get_type() {
        return type;
    }
    good(good &p) {
        type = p.type;
        name = p.name;
        color = p.color;
        chi = p.chi;
        price = p.price;
        num = p.num;
    }
    good(string t, string n, string co, string ch, double pr, double nm) {
        type = t;
        name = n;
        color = co;
        chi = ch;
        price = pr;
        num = nm;
    }
    void change_num_up() {
        num++;
    }
    void change_num_down() {
        num--;
    }
    double get_num() {
        return num;
    }
    void good_print() {
        cout << name << "," << color << "," << chi << "," << fixed << setprecision(2) << price << "," << setprecision(0)<<num << "," << fixed << setprecision(2) << total_price() << endl;
    }
};

class shop_car {
private:
    good g[100];
    int good_num;
    double total_p;
    int op;
    int now_pos;
    double sum;

public:
    shop_car(int n) {
        sum = 0;
        op = n;
        good_num = 0;
        now_pos = 0;
        operate();
    }
    void operate() {
        for (int i = 0; i < op; i++) {
            string oper;
            cin >> oper;
            jud_run_operate(oper);
        }
        print_car();
    }
    void jud_run_operate(string o) {
        if (o == "ADD") {
            ADD();
        } else if (o == "UP") {
            UP();
        } else if (o == "DOWN") {
            DOWN();
        } else if (o == "DELETE") {
            DELETE();
        }
    }

    void ADD() {
        string t, n, co, ch;
        double pr, nm;
        cin >> t >> n >> co >> ch >> pr >> nm;
        g[good_num] = good(t, n, co, ch, pr, nm);
        now_pos += nm;
        good_num++;
    }
    void UP() {
        string t;
        cin >> t;
        for (int i = 0; i < good_num; i++) {
            if (t == g[i].get_type()) {
                g[i].change_num_up();
            }
        }
    }
    void DOWN() {
        string t;
        cin >> t;
        for (int i = 0; i < good_num; i++) {
            if (t == g[i].get_type()) {
                g[i].change_num_down();
            }
        }
    }
    void DELETE() {
        string t;
        cin >> t;
        for (int i = 0; i < good_num; i++) {
            if (t == g[i].get_type()) {
                for (int j = i; j < good_num - 1; j++) {
                    g[j] = g[j + 1];
                }
                good_num--;
                now_pos -= g[i].get_num();
                break;
            }
        }
    }
    void get_total_price() {
        for (int i = 0; i < good_num; i++) {
            sum += g[i].total_price();
        }
    }
    void print_car() {
        cout << "商品清单:" << endl;
        cout << "商品,颜色,尺码,单价,数量,小计" << endl;
        for (int i = good_num - 1; i >= 0; i--) {
            g[i].good_print();
        }
        cout << "----------" << endl;
        get_total_price();
        cout << now_pos << "件商品,总商品金额" << fixed << setprecision(2) << sum << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        shop_car s(n);
    }
}
