#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[301];

int n, m, a, b, c, level[301], idx[301], mx;
int bfs() {
	memset(level, -1, sizeof(level));
	level[1] = 0;
	queue<int> q;
	q.push(1);
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
	return level[n] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == n)
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
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		vect[a].push_back({ b,c,(int)vect[b].size() });
		vect[b].push_back({ a,0,(int)vect[a].size() - 1 });

		vect[b].push_back({ a,c,(int)vect[a].size() });
		vect[a].push_back({ b,0,(int)vect[b].size() - 1 });
	}

	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = dfs(1, 1e9);
			if (!flow)
				break;
			mx += flow;
		}
	}

	cout << mx;
	return 0;
}