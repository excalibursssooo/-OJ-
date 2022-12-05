#include <bits/stdc++.h>
using namespace std;
struct share {
    int judge;
    string date;
    int price1;
    int price2;
};

int changedate(string s) {
    int sum;
    char month[2];
    month[0] = s[5];
    if (s[6] != '/') {
        month[1] = s[6];
        sum += ((month[0] - '0') * 10 + (month[0] - '0')) * 30;
        if (s[9] != '/') {
            sum += (s[8] - '0') * 10 + (s[9] - '0');
        } else {
            sum += (s[8] - '0');
        }
    } else {
        sum += (month[0] - '0') * 30;
        if (s[8] != '/') {
            sum += (s[7] - '0') * 10 + (s[8] - '0');
        } else {
            sum += (s[7] - '0');
        }
    }
    return sum;
}

char pan(share a, share b) {
    if (changedate(a.date) > changedate(b.date))
        return '>';
    else {
        return '<';
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    share sh[101];
    share open[101];
    share close[101];
    for (int i = 0; i < N; i++) {
        cin >> sh[i].date;
        string s;
        cin >> s;
        if (s == "open")
            sh[i].judge = 1;
        else
            sh[i].judge = 0;
        cin >> sh[i].price1 >> sh[i].price2;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (pan(sh[i], sh[j]) == '<') {
                share p = sh[i];
                sh[i] = sh[j];
                sh[j] = p;
            }
        }
    }
    // for(int i = 0;i<N;i++){
    //     cout<<sh[i].date<<" ";
    // }
    int j = 0;
    int k = 0;
    for (int i = 0; i < N; i++) {
        if (sh[i].judge == 1) {
            open[j] = sh[i];
            j++;
        } else {
            close[k] = sh[i];
            k++;
        }
    }
    share openres[101];
    int res = 0;
    int m = M;
    for (int i = M-1; i < j; i++) {
        int sum1 = 0;
        int sum2 = 0;

        for(int l = i-M+1;l<m;l++){
            sum1 += open[l].price1;
            sum2 += open[l].price2;
        }
        m++;
        openres[res].date = open[i].date;
        openres[res].judge = 1;
        openres[res].price1 = sum1/M;
        openres[res].price2 = sum2/M;
        res++;
    }
    for(int i = 0;i<res;i++){
        cout<<openres[i].date<<" ";
        cout<<"open";
        cout<<" "<<openres[i].price1<<" "<<openres[i].price2<<endl;
    }
    share closeres[101];
    res = 0;
    m = M;
    for (int i = M-1; i < j; i++) {
        int sum1 = 0;
        int sum2 = 0;

        for(int l = i-M+1;l<m;l++){
            sum1 += close[l].price1;
            sum2 += close[l].price2;
        }
        m++;
        closeres[res].date = close[i].date;
        closeres[res].judge = 1;
        closeres[res].price1 = sum1/M;
        closeres[res].price2 = sum2/M;
        res++;
    }
    for(int i = 0;i<res;i++){
        cout<<closeres[i].date<<" ";
        cout<<"close";
        cout<<" "<<closeres[i].price1<<" "<<closeres[i].price2<<endl;
    }
}