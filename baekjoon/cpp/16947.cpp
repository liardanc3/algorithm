#include <bits/stdc++.h>
using namespace std;
int N, a, b, visited[3001], cycle[3001];
vector<int> vect[3001];
void dfs(int now, int first, int step) {
	visited[now] = 1;

	for (int i = 0; i < vect[now].size(); i++) {
		int next = vect[now][i];

		if (next == first && step!=2) {
			cycle[first] = 1;
			return;
		}
		if (!visited[next]) 
			dfs(next, first, step+1);
	}
	return;
}
void bfs(int now) {
	queue<int> q;
	q.push(now);
	visited[now] = 1;
	int cnt = -1;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();
		while (sz--) {
			int here = q.front();
			q.pop();

			if (cycle[here]) {
				cout << cnt << ' ';
				return;
			}

			for (int i = 0; i < vect[here].size(); i++) {
				int next = vect[here][i];
				if (!visited[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vect[a].push_back(b);
		vect[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, i, 1);
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		bfs(i);
	}
	return 0;
}