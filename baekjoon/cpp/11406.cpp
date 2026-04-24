#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[202];

int N, M, tmp, level[202], idx[202], mx;
int bfs() {
	memset(level, -1, sizeof(level));
	level[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (node n : vect[now]) {
			int next = n.next;
			int capacity = n.capacity;

			if (level[next] == -1 && capacity > 0) {
				level[next] = level[now] + 1;
				q.push(next);
			}
		}
	}
	return level[N + M + 1] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == N + M + 1)
		return wat;
	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int& capacity = vect[now][i].capacity;
		int& rcapacity = vect[next][vect[now][i].revidx].capacity;

		if (level[now] + 1 == level[next] && capacity > 0) {
			int blockflow = dfs(next, min(wat, capacity));
			if (blockflow > 0) {
				capacity -= blockflow;
				rcapacity += blockflow;
				return blockflow;
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		vect[0].push_back({ i,tmp,(int)vect[i].size() });
		vect[i].push_back({ 0, 0, (int)vect[0].size() - 1 });
	}
	for (int i = 1; i <= M; i++) {
		cin >> tmp;
		vect[N + i].push_back({ N + M + 1, tmp, (int)vect[N + M + 1].size() });
		vect[N + M + 1].push_back({ N + i, 0, (int)vect[N + i].size() - 1 });
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			vect[j].push_back({ N + i, tmp, (int)vect[N + i].size() });
			vect[N + i].push_back({ j,0,(int)vect[j].size() - 1 });
		}
	}
	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = dfs(0, 1e9);
			if (!flow)
				break;
			mx += flow;
		}
	}
	cout << mx;
	return 0;
}