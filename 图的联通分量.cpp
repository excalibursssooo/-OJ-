#include <bits/stdc++.h>
using namespace std;

struct dian {
    string s;
    int flag;
};

struct bian {
    string a;
    string b;
};
int m;
int n;
dian d[101];
bian mybian[101];
int find(string s) {
    for (int i = 0; i < n; i++) {
        if (s == d[i].s) {
            return i;
        }
    }
}

int findx(string s) {
    for (int i = 0; i < n; i++) {
        if (s == d[i].s) {
            return d[i].flag;
        }
    }
}

int print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; i++) {
            if (d[i].s == mybian[j].a || d[i].s == mybian[j].b) {
                return i;
            }
        }
    }
    return -1;
}

int findnum(int temp[], int num) {
    for (int i = 0; i < n; i++) {
        if (temp[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> d[i].s;
            d[i].flag = i;
        }
        for (int i = 0; i < n; i++) {
            cout<<d[i].s;
            if(i<n-1) cout<<" ";
        }
        cout<<endl;
        int Matrix[20][20];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Matrix[i][j] = 0;
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> mybian[i].a >> mybian[i].b;
            Matrix[find(mybian[i].a)][find(mybian[i].b)] = 1;
            Matrix[find(mybian[i].b)][find(mybian[i].a)] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << Matrix[i][j];
                if (j < n - 1) cout << " ";
            }
            cout << endl;
        }
        bian res;
        for (int i = 0; i < m; i++) {
            res = mybian[i];
            int dk = findx(res.a);
            // cout<<res.a<<" "<<res.b<<endl;
            for (int k = 0; k < n; k++) {
                // cout<<findx(res.a)<<endl;
                if (d[k].flag == dk) {
                    d[k].flag = findx(res.b);
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout << d[i].flag << endl;
        // }
        int cnt = 0;
        int temp[101];
        memset(temp, -1, 101);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (findnum(temp, d[i].flag) == 0) {
                cnt++;
                temp[j] = d[i].flag;
                j++;
            }
        }
        cout << cnt << endl;
        cout<<endl;
    }
}