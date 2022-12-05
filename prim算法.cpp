#include <bits/stdc++.h>
using namespace std;

int n, m;
string d[101];
struct bian {
    string a;
    string b;
    int len;
};

void change(string s, int visit[]) {
    for (int i = 0; i < n; i++) {
        if (s == d[i]) {
            visit[i] = 1;
            return;
        }
    }
}

int judge(string s, int visit[]) {
    for (int i = 0; i < n; i++) {
        if (s == d[i]) {
            if (visit[i] == 1)
                return 0;
            else
                return 1;
        }
    }
}

int main() {
    cin >> n;
    int visit[101];
    memset(visit, 0, 101);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        visit[i] = 0;
    }
    cin >> m;
    bian mybian[101];
    bian result[101];
    for (int i = 0; i < m; i++) {
        cin >> mybian[i].a >> mybian[i].b >> mybian[i].len;
    }
    string now[101];
    cin >> now[0];
    int num = 0;
    int res = 0;
    string rr[101];
    while (res < n - 1) {
        change(now[num], visit);
        num++;
        int min = 9999;
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < m; j++) {
                if (now[i] == mybian[j].a) {
                    if (judge(mybian[j].b, visit) == 1 && mybian[j].len < min) {
                        min = mybian[j].len;
                        result[res] = mybian[j];
                        now[num] = mybian[j].b;
                    }
                } else if (now[i] == mybian[j].b) {
                    if (judge(mybian[j].a, visit) == 1 && mybian[j].len < min) {
                        min = mybian[j].len;
                        result[res] = mybian[j];
                        now[num] = mybian[j].a;
                    }
                }
            }
        }
        
        if (now[num] == result[res].a)
            rr[res] = result[res].b;
        else
            rr[res] = result[res].a;
        res++;
    }
    int sum = 0;
    for (int i = 0; i < res; i++) {
        sum += result[i].len;
    }
    cout << sum << endl;
    for (int i = 0; i < res; i++) {
        if(result[i].a == rr[i]){
            cout<<rr[i]<<" "<<result[i].b<<" "<<result[i].len<<endl;
        }
        else{
            cout<<rr[i]<<" "<<result[i].a<<" "<<result[i].len<<endl;
        }
    }
}