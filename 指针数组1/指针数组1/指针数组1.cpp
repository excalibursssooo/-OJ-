

#include <iostream>

using namespace std;

int main()
{

    const char* p[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
    while (1) {
        int a;
        cin >> a;
        if (a <= 0 || a > 12) {
            cout << "error" << endl;
            continue;
        }
        cout << p[a - 1] << endl;
    }
}


