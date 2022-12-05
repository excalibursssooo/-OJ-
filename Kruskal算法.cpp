#include <bits/stdc++.h>
using namespace std;

struct dian {
    string s;
    int flag;
};

struct bian {
    string a;
    string b;
    int len;
};
int m;
int n;
dian d[101];
bian mybian[101];
int find(string s) {
    for (int i = 0; i < n; i++) {
        if (s == d[i].s) {
            return d[i].flag;
        }
    }
}

int findx(string s){
    for (int i = 0; i < n; i++) {
        if (s == d[i].s) {
            return i;
        }
    }
}

int print() {
    for(int i = 1;i<n;i++){
        if(d[i].flag != d[i-1].flag) return 0;
    }
    return 1;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> d[i].s;
        d[i].flag = i;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> mybian[i].a >> mybian[i].b >> mybian[i].len;
    }
    int min = 9999;
    int nummin = 0;
    bian res[101];
    int visit[101];
    memset(visit, 0, 101);
    for (int i = 0; i < n - 1; i++) {
        min = 9999;
        int j;
        for (j = 0; j < m; j++) {
            // cout << find(mybian[j].a) << " " << find(mybian[j].b) << endl;
            if (mybian[j].len <= min && find(mybian[j].a) != find(mybian[j].b) && visit[j] != 1) {
                if (mybian[j].len == min) {
                    if (j > nummin) {
                        continue;
                    }
                }
                min = mybian[j].len;
                res[i] = mybian[j];
                nummin = j;
            }
        }
        visit[nummin] = 1;
        int dk = find(res[i].a);
        for (int k = 0; k < n; k++) {    
            if (d[k].flag == dk) {
                d[k].flag = find(res[i].b);
            }
        }
        
    }
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum = sum + res[i].len;
    }
    if (print() == 0)
        cout << -1 << endl;
    else {
        cout << sum << endl;
        for (int i = 0; i < n - 1; i++) {
            if(findx(res[i].a)<findx(res[i].b))
                cout << res[i].a << " " << res[i].b << " " << res[i].len << endl;
            else
                cout << res[i].b << " " << res[i].a << " " << res[i].len << endl;
        }
    }
}