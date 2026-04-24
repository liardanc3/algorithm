#include <bits/stdc++.h>
#define int long long
#define MAX 1e11
using namespace std;

typedef pair<int, int> pii;

struct node {
	pii next;
	int capacity, revidx;
	node(pii n, int c, int r) {
		next = n, capacity = c, revidx = r;
	};
}; vector<node> vect[105][105];

pii dst;
int N, M, arr[105][105], block[30], level[105][105], mx, idx[105][105];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
string tmp;
void addedge(pii s, pii e, int c) {
	vect[s.first][s.second].push_back({ e, c, (int)vect[e.first][e.second].size() });
	vect[e.first][e.second].push_back({ s, 0, (int)vect[s.first][s.second].size() - 1 });
}
void setnode() {
	for (int y = 0; y <= N + 1; y++) {
		for (int x = 0; x <= M + 1; x++) {
			if (arr[y][x] == -1)
				continue;

			addedge({ 2 * y, 2 * x }, { 2 * y + 1, 2 * x + 1 }, block[arr[y][x]] == 0 ? MAX + 1e12 : MAX + block[arr[y][x]]);
			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (0 <= ddy && ddy <= N + 1 && 0 <= ddx && ddx <= M + 1 && arr[ddy][ddx] != -1)
					addedge({ 2 * y + 1, 2 * x + 1 }, { 2 * ddy, 2 * ddx }, MAX + 1e12);
			}
		}
	}
}
int bfs(pii src, pii dst) {
	queue<pii> q;
	q.push(src);
	memset(level, -1, sizeof(level));
	level[src.first][src.second] = 1;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (node n : vect[now.first][now.second]) {
			pii next = n.next;
			int capacity = n.capacity;

			if (level[next.first][next.second] == -1 && capacity > 0) {
				level[next.first][next.second] = level[now.first][now.second] + 1;
				q.push(next);
			}
		}
	}
	return level[dst.first][dst.second] == -1 ? 0 : 1;
}
int dfs(pii now, pii end, int wat) {
	if (now == end)
		return wat;

	for (int& i = idx[now.first][now.second]; i < vect[now.first][now.second].size(); i++) {
		pii next = vect[now.first][now.second][i].next;
		int& capacity = vect[now.first][now.second][i].capacity;
		int& rcapacity = vect[next.first][next.second][vect[now.first][now.second][i].revidx].capacity;

		if (level[now.first][now.second] + 1 == level[next.first][next.second] && capacity > 0) {
			int blockflow = dfs(next, end, min(wat, capacity));

			if (blockflow > 0) {
				capacity -= blockflow;
				rcapacity += blockflow;
				return blockflow;
			}
		}
	}
	return 0;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			for (int j = 1; j <= M; j++) {
				if ('A' <= tmp[j - 1] && tmp[j - 1] <= 'Z')
					arr[i][j] = (tmp[j - 1] - 'A') + 1;
				else {
					if (tmp[j - 1] == '*') {
						arr[i][j] = 29;
						dst = { i, j };
					}
					else if (tmp[j - 1] == '-')
						arr[i][j] = -1;
				}
			}
		}
		for (int i = 1; i <= 26; i++)
			cin >> block[i];
	}();
	
	setnode();
	while (bfs({ dst.first * 2, dst.second * 2 }, { 0,0 })) {
		memset(idx, 0, sizeof idx);
		while (1) {
			int flow = dfs({ dst.first * 2, dst.second * 2 }, { 0,0 }, 1e9);
			if (!flow)
				break;
			mx += flow;
		}
	}
		
	cout << mx%(100'000'000'000);
	return 0;
}