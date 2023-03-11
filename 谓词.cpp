#include <bits/stdc++.h>
using namespace std;

class Mycompare {
public:
    bool operator()(int val1, int val2) {
        return val1 > val2;
    }
};

class Biggerthan5{
public:
    bool operator()(int val){
        return val>5;
    }
};

void Printvector(const vector<int> &v) {
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    vector<int> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(i * 10);
    }
    sort(v.begin(), v.end());
    Printvector(v);
    sort(v.begin(),v.end(),Mycompare());
    Printvector(v);
}

void test01(){
    vector<int> v;
    for(int i = 0;i<10;i++){
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(),v.end(),Biggerthan5());
    if(it!=v.end()){
        cout<<"find the number "<<*it<<" bigger than 5"<<endl;
    }
    else{
        cout<<"can't find the number bigger than 5"<<endl;
    }
}

int main(){
    //test();
    test01();
}