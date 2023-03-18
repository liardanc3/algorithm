#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[501];

void addedge(int s, int e, int c) {
	vect[s].push_back({ e,c,(int)vect[e].size() });
	vect[e].push_back({ s,0,(int)vect[s].size() - 1 });
}

int n, m, a, b, c, s, t, level[501], idx[501], fl;
int bfs() {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof(level));
	level[s] = 1;
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
	return level[t] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == t)
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
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		addedge(a, b, c);
		addedge(b, a, c);
	}
	cin >> s >> t;
	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = dfs(s, 1e9);
			if (!flow)
				break;
			fl += flow;
		}
	}
	cout << fl;
	return 0;
}