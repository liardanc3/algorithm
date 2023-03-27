#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[2003];

void addedge(int s, int e, int c) {
	vect[s].push_back({ e,c,(int)vect[e].size() });
	vect[e].push_back({ s,0,(int)vect[s].size() - 1 });
}

int N, M, K, n, tmp, level[2003], idx[2003], work;
int bfs() {
	queue<int> q;
	q.push(0);
	memset(level, -1, sizeof level);
	level[0] = 1;
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
	return level[2001] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == 2001)
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
	cin >> N >> M >> K;
	addedge(0, 2002, K);
	for (int i = 1; i <= N; i++) {
		addedge(0, i, 1);
		addedge(2002, i, 1);
	}
	for (int i = 1001; i <= 1000 + M; i++) 
		addedge(i, 2001, 1);
	for (int i = 1; i <= N; i++) {
		cin >> n;
		while (n--) {
			cin >> tmp;
			addedge(i, tmp + 1000, 1);
		}
	}
	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = dfs(0, 1e9);
			if (!flow)
				break;
			work += flow;
		}
	}
	cout << work;
	return 0;
}