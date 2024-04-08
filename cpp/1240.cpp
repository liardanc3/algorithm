#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, a, b, d, visited[1001];
vector<pii> vect[1001];
void bfs() {
	queue<pii> q;
	q.push({ a,0 });
	visited[a] = 1;
	while (!q.empty()) {
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i].first;
			int d = vect[now][i].second;

			if (next == b) {
				cout << dist + d << '\n';
				return;
			}

			if (!visited[next]) {
				visited[next] = 1;
				q.push({ next,dist + d });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> d;
		vect[a].push_back({ b,d });
		vect[b].push_back({ a,d });
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		bfs();
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}