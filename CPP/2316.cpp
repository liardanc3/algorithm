#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[801];

int N, P, a, b, idx[801], level[801], mx;
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
	return level[401] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == 401)
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
	cin >> N >> P;
	while (P--) {
		cin >> a >> b;

		// a -> b
		vect[a].push_back({ b, 1, (int)vect[b].size() });
		vect[b].push_back({ a, 0, (int)vect[a].size() - 1 });
	
		// b(+400) -> a(+400)
		if (a != 2) a += 400;
		if (b != 2) b += 400;
		vect[b].push_back({ a, 1, (int)vect[a].size() });
		vect[a].push_back({ b, 0, (int)vect[b].size() - 1 });
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