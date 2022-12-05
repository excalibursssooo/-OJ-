#include <iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

struct people {
	int arrive;
	int deal;
};

int main() {
	int N;
	queue<people> person;
	cin >> N;
	for (int i = 0; i < N; i++) {
		people p;
		cin >> p.arrive;
		int deal;
		cin >> deal;
		if (deal > 60) p.deal = 60;
		else p.deal = deal;
		person.push(p);
	}
	int K;
	cin >> K;
	int sum=0;
	int last;
	int begin[101] = {0};
	int wait[101] = {0};
	int cnt[101] = { 0 };
	int maxtime=0;
	for (int i = 0; i < N; i++) {
		int tem = 0;
		for (int j = 0; j < K; j++) {
			if (begin[j] + wait[j] - person.front().arrive <= 0) {
				begin[j] = person.front().arrive;
				wait[j] = person.front().deal;
				cnt[j]++;
				tem = 1;
				if(i==N-1) last = person.front().arrive + person.front().deal;
				person.pop();
				break;
			}
		}
		if (tem == 1) {
			continue;
		}
		int mini[101] = {0};
		for (int j = 0; j < K; j++) {
			mini[j] = begin[j] + wait[j] - person.front().arrive;
		}
		int min = mini[0];
		int minweb = 0;
		for (int j = 0; j < K; j++) {
			if (mini[j] < min) {
				min = mini[j];
				minweb = j;
			}
		}
		sum += min;
		if (min > maxtime) maxtime = min;
		if(i==N-1) last = person.front().arrive+person.front().deal+min;
		begin[minweb] = person.front().arrive+min;
		wait[minweb] = person.front().deal;
		cnt[minweb]++;
		person.pop();
	}
	int last1[101] = {0};

	for (int i = 0; i < K; i++) {
		last1[i]= begin[i] + wait[i];
	}
	int maxlast = last1[0];
	for (int i = 0; i < K; i++) {
		if (last1[i] > maxlast) maxlast = last1[i];
	}

	printf("%.1lf %d %d\n", sum/(N * 1.0), maxtime, maxlast);
	for (int i = 0; i < K-1; i++) {
		cout << cnt[i] << " ";
	}
	cout << cnt[K - 1] <<endl;

}