#include <bits/stdc++.h>
using namespace std;
int N, K, ck[100001];
queue<int> q;
int bfs() {
	int cnt = -1;
	while (!q.empty()) {
		cnt++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front(); 
			q.pop();
			if (now == K) return cnt;
			for (int j = now - 1; j >= 0 && j <= 100000; j *= 2) {
				if (ck[j] == 0) {
					q.push(j);
					ck[j] = 1;
				}
				else break;
			}
			for (int j = now + 1; j <= 100000; j *= 2) {
				if (ck[j] == 0) {
					q.push(j);
					ck[j] = 1;
				}
				else break;
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> K;
	for (int i = N; i <= 100000; i *= 2) {
		q.push(i); ck[i] = 1;
		if (i == 0) break;
	}
	cout << bfs();
	return 0;
}