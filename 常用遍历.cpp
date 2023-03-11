#include <bits/stdc++.h>
using namespace std;

class tran {
public:
    int operator()(int val) {
        return val * 2;
    }
};

class Myprint {
public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void PrintVector(vector<int> &v) {
    for_each(v.begin(), v.end(), Myprint());
    cout << endl;
}

void test() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i * 2);
    }
    vector<int> v1;
    v1.resize(v.size());//需要设置大小
    transform(v.begin(), v.end(), v1.begin(), tran());

    PrintVector(v);
    PrintVector(v1);
}

int main() {
    test();
}
