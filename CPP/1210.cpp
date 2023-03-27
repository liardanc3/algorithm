#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[402];

void addedge(int s, int e, int c) {
	vect[s].push_back({ e,c,(int)vect[e].size() });
	vect[e].push_back({ s,0,(int)vect[s].size() - 1 });
}

vector<int> traceedge[402];
priority_queue<int, vector<int>, greater<int>> pq;
int n, m, tmp, src, dst, a, b, level[402], idx[402], fl, visited[402];
int bfs() {
	memset(level, -1, sizeof level);
	level[src] = 1;
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (node n : vect[now]) {
			int next = n.next;
			int capacity = n.capacity;

			if (level[next] == -1 && capacity > 0) {
				level[next] = level[now] + 1;
				q.push(next);
			}
		}
	}
	return level[dst] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == dst)
		return wat;

	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int& capacity = vect[now][i].capacity;
		int& rcapacity = vect[next][vect[now][i].revidx].capacity;

		if (level[now] + 1 == level[next] && capacity > 0) {
			int blockflow = dfs(next, min(wat,capacity));

			if (blockflow > 0) {
				capacity -= blockflow;
				rcapacity += blockflow;
				return blockflow;
			}
		}
	}
	return 0;
}
void trace(int now) {
	queue<int> q;
	q.push(src);
	visited[src] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		
		for (node n : vect[now]) {
			int next = n.next;
			int capacity = n.capacity;

			if (!visited[next] && capacity > 0) {
				q.push(next);
				visited[next] = 1;
			}
		}
	}

	for (int i = 2; i <= 2*n; i+=2) {
		if (visited[i] && !visited[i + 1])
			cout << i / 2 << ' ';
	}
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> n >> m >> src >> dst;
		src *= 2;
		dst = 2 * dst + 1;
		for (int i = 1; i <= n; i++) {
			cin >> tmp;
			addedge(2 * i, 2 * i + 1, tmp);
		}
		while (m--) {
			cin >> a >> b;
			addedge(2 * a + 1, 2 * b, 1e9);
			addedge(2 * b + 1, 2 * a, 1e9);
		}
	}();
	
	[&]() {
		while (bfs()) {
			memset(idx, 0, sizeof idx);
			while (1) {
				int flow = dfs(src, 1e9);
				if (!flow)
					break;
				fl += flow;
			}
		}
	}();

	trace(dst);
	return 0;
}