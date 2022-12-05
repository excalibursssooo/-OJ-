#include <bits/stdc++.h>
using namespace std;

stack<string> p, q; // p是向后，q是向前
string URL = "http://www.acm.org/";
void action(string s) {
    if (s == "VISIT") {
        p.push(URL);
        cin >> URL;
        cout << URL << endl;
        ;
        while (!q.empty()) {
            q.pop();
        }
    }
    if (s == "BACK") {
        if (p.empty()) {
            cout << "Ignored" << endl;
        } else {
            q.push(URL);
            URL = p.top();
            p.pop();
            cout << URL << endl;
        }
    }
    if (s == "FORWARD") {
        if (q.empty()) {
            cout << "Ignored" << endl;
        } else {
            p.push(URL);
            URL = q.top();
            q.pop();
            cout << URL << endl;
        }
    }
}

int main() {
    string sc;
    cin >> sc;
    while (sc != "QUIT") {
        action(sc);
        cin >> sc;
    }
}