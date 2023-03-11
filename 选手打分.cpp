#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    string name;
    int avg_score;
    deque<int> score;
    Person(string name, int avg_score) {
        this->name = name;
        this->avg_score = avg_score;
    }
};

void CreatePerson(vector<Person> &p) {
    string s = "ABCDE";
    for (int i = 0; i < 5; i++) {
        string s1 = "member ";
        s1 += s[i];
        p.push_back(Person(s1, 0));
    }

    for (vector<Person>::iterator it = p.begin(); it != p.end(); it++) {
        for (int i = 0; i < 10; i++) {
            it->score.push_back(rand() % 41 + 60); // 放入60-100分数
        }
        sort(it->score.begin(), it->score.end());

        it->score.pop_back();
        it->score.pop_front();
        int sum = 0;

        for (int i = 0; i < it->score.size(); i++) {
            sum += it->score[i];
        }//计算总分

        it->avg_score = sum / it->score.size();
    }
}

void showPerson(vector<Person> &p){
    for(vector<Person>::iterator it = p.begin();it!=p.end();it++){
        cout<<it->name<<endl;
        for(int i = 0;i<it->score.size();i++){
            cout<<it->score[i]<<" ";
        }
        cout<<endl;
        cout<<"Average score: "<<it->avg_score<<endl;
    }
}

int main(){
    vector<Person> p;
    CreatePerson(p);
    showPerson(p);
}