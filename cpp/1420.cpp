#include <bits/stdc++.h>
#define y first
#define x second
using namespace std;

typedef pair<int, int> pii;

struct node {
	pii next;
	int capacity, revidx;
	node(pii n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[202][202];

void addedge(pii s, pii e, int c) {
	vect[s.y][s.x].push_back({ e,c,(int)vect[e.y][e.x].size() });
	vect[e.y][e.x].push_back({ s,0,(int)vect[s.y][s.x].size() - 1 });
}

pii src, dst;
int N, M, arr[101][101], level[202][202], idx[202][202], fl;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
string tmp;
int bfs() {
	queue<pii> q; q.push(src);
	memset(level, -1, sizeof level);
	level[src.y][src.x] = 1;
	while (!q.empty()) {
		pii now = q.front(); q.pop();

		for (node n : vect[now.y][now.x]) {
			pii next = n.next;
			int capacity = n.capacity;

			if (level[next.y][next.x] == -1 && capacity > 0) {
				level[next.y][next.x] = level[now.y][now.x] + 1;
				q.push(next);
			}
		}
	}
	return level[dst.y][dst.x] == -1 ? 0 : 1;
}
int dfs(pii now, int wat) {
	if (now == dst)
		return wat;
	for (int& i = idx[now.y][now.x]; i < vect[now.y][now.x].size(); i++) {
		pii next = vect[now.y][now.x][i].next;
		int &capacity = vect[now.y][now.x][i].capacity;
		int& rcapacity = vect[next.y][next.x][vect[now.y][now.x][i].revidx].capacity;

		if (level[now.y][now.x] + 1 == level[next.y][next.x] && capacity > 0) {
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
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			if (tmp[j - 1] == '#')
				arr[i][j] = 1;
			else if (tmp[j - 1] != '.') {
				arr[i][j] = 2;

				if (tmp[j - 1] == 'K')
					src = { 2 * i, 2 * j };
				if (tmp[j - 1] == 'H')
					dst = { 2 * i + 1, 2 * j + 1 };
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0)
				addedge({ 2 * i,2 * j }, { 2 * i + 1,2 * j + 1 }, 1);
			else if (arr[i][j] == 2)
				addedge({ 2 * i,2 * j }, { 2 * i + 1,2 * j + 1 }, 1e9);

			for (int k = 0; k < 4; k++) {
				int ddy = i + dy[k];
				int ddx = j + dx[k];

				if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M)
					addedge({ i * 2 + 1,j * 2 + 1 }, { ddy * 2,ddx * 2 }, 1e9);
			}
		}
	}

	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = dfs(src, 1e9);
			if (!flow)
				break;
			fl += flow;
		}
	}

	fl >= 1e9 ? cout << -1 : cout << fl;
	return 0;
}