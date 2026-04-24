#include <bits/stdc++.h>
using namespace std;
int t, visited[10000], prime[10000], a, b;
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(&prime[2], &prime[10000], 1);
	for (int i = 2; i < 10000; i++) {
		if (!prime[i]) continue;
		for (int j = 2 * i; j < 10000; j += i)
			prime[j] = 0;
	}
	cin >> t;
}
void bfs() {
	queue<int> q;
	q.push(a);
	visited[a] = 1;
	int cnt = -1;
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		for (int i = 0; i < size; i++) {
			int now = q.front(); q.pop();

			if (now == b) {
				cout << cnt << '\n';
				return;
			}

			// 1000磊府
			for (int k = 1; k <= 9; k++) {
				int next = k * 1000 + now % 1000;
				if (!visited[next] && prime[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}

			// 100磊府
			for (int k = 0; k <= 9; k++) {
				int next = 1000 * (now/1000) + k * 100 + now % 100;
				if (!visited[next] && prime[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}

			// 10磊府
			for (int k = 0; k <= 9; k++) {
				int next = 100 * (now / 100) + k * 10 + now % 10;
				if (!visited[next] && prime[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}

			// 1磊府
			for (int k = 0; k <= 9; k++) {
				int next = 10 * (now / 10) + k;
				if (!visited[next] && prime[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}
		}
	}
	cout << "Impossible\n";
}
int main() {
	init();
	while (t--) {
		cin >> a >> b;
		bfs();
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}