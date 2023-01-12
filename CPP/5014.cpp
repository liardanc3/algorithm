#include <bits/stdc++.h>
using namespace std;
int f, s, g, u, d, visited[10000001];
void bfs() {
	queue<int> q;
	q.push(s);
	int cnt = -1;
	visited[s] = 1;
	while (!q.empty()) {
		cnt++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			if (now == g) {
				cout << cnt;
				return;
			}
			if (1 <= now + u && now + u <= f && visited[now + u] == 0) {
				visited[now + u] = 1;
				q.push(now + u);
			}
			if (1 <= now - d && now - d <= f && visited[now - d] == 0) {
				visited[now - d] = 1;
				q.push(now - d);
			}
		}
	}
	cout << "use the stairs";
	return;
}
int main() {
	cin >> f >> s >> g >> u >> d;
	if (s == g) cout << 0;
	else bfs();
	return 0;
}