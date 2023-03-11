#include <bits/stdc++.h>
using namespace std;

void PrintDeque(const deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    deque<int> d1;
    for (int i = 0; i < 5; i++) {
        d1.push_back(i);
    }
    for (int i = 5; i < 10; i++) {
        d1.push_front(i);
    }
    PrintDeque(d1);

    deque<int> d2 = d1;

    PrintDeque(d2);

    deque<int> d3;
    d3.assign(d1.begin(),d1.end());

    PrintDeque(d3);


    sort(d1.begin(),d1.end());

    PrintDeque(d1);
}

int main() {
    test();
}