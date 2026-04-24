#include <bits/stdc++.h>
using namespace std;

int N, f, level[123], mx, idx[123], start, end;
char src, dst;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[123];

int bfs() {
	memset(level, -1, sizeof(level));
	queue<int> q;
	q.push('A');
	level['A'] = 0;
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
	return level['Z'] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == 'Z')
		return wat;
	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int capacity = vect[now][i].capacity;

		if (level[now] + 1 == level[next] && capacity > 0) {
			int blockflow = dfs(next, min(wat, capacity));
			if (blockflow > 0) {
				vect[now][i].capacity -= blockflow;
				vect[next][vect[now][i].revidx].capacity += blockflow;
				return blockflow;
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> src >> dst >> f;
		vect[src].push_back({ dst, f, (int)vect[dst].size() });
		vect[dst].push_back({ src, f, (int)vect[src].size() - 1 });
	}
	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = dfs('A', 1e9);
			if (!flow)
				break;
			mx += flow;
		}
	}
	cout << mx;
	return 0;
}