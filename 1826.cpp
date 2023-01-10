#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
priority_queue<int,vector<int>,greater<int>> oil[101];

int N, a, b, L, P, cnt, x, flag;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		oil[b].push(a);
	}
	cin >> L >> P;
	while (P < L && !flag) {
		flag = 1;
		for (int i = 100; i >= 1; i--) {
			if (oil[i].empty()) continue; 
			int dist = oil[i].top();
			if (dist <= P) {
				//cout << "dist : " << dist << " , oil : " << i << '\n';
				P += i;
				oil[i].pop();
				cnt++;
				flag = 0;
				break;
			}
		}
	}
	if (P >= L)
		cout << cnt;
	else
		cout << -1;
	return 0;
}