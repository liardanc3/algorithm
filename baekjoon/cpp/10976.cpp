#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[201];

int T, N, M, x, y, level[201], idx[201], ant;
int bfs() {
	memset(level, -1, sizeof(level));
	queue<int> q;
	q.push(1);
	level[1] = 0;
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
	return level[N] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == N)
		return wat;
	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int &capacity = vect[now][i].capacity;
		int &revcapacity = vect[next][vect[now][i].revidx].capacity;

		if (level[now] + 1 == level[next] && capacity > 0) {
			int blockflow = dfs(next, min(wat, capacity));
			if (blockflow > 0) {
				capacity -= blockflow;
				revcapacity += blockflow;
				return blockflow;
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		ant = 0;
		for (int i = 1; i <= N; i++)
			vect[i].clear();

		cin >> N >> M;

		while (M--) {
			cin >> x >> y;
			if (x == 1 || y == N) {
				vect[x].push_back({ y,1,(int)vect[y].size() });
				vect[y].push_back({ x,0,(int)vect[x].size() - 1 });
			}
			else {
				vect[x].push_back({ y,(int)1e9,(int)vect[y].size() });
				vect[y].push_back({ x,0,(int)vect[x].size() - 1 });
			}
		}

		while (bfs()) {
			memset(idx, 0, sizeof(idx));
			while (1) {
				int flow = dfs(1, 1e9);
				if (!flow)
					break;
				ant += flow;
			}
		}

		cout << ant << '\n';
	}

	return 0;
}