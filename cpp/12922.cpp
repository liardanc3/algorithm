#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> dst;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[5003];

int N, arr[52][52], visited[5003], idx[5003], level[5003], mx;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
string tmp;
void addedge(int s, int d, int c) {
	vect[s].push_back({ d,c,(int)vect[d].size() });
	vect[d].push_back({ s,0,(int)vect[s].size() - 1 });
}

void setnode() {
	queue<pii> q;
	q.push(dst[0]);
	visited[2 * ((dst[0].first - 1) * N + dst[0].second)] = 1;

	while (!q.empty()) {
		pii p = q.front(); q.pop();
		int y = p.first, x = p.second;
		int start = 2 * ((y - 1) * N + x);

		if (arr[y][x] == 2) {
			addedge(start + 1, 0, 1e9);
			continue;
		}


		for (int i = 0; i < 4; i++) {
			int ddy1 = y + dy[i];
			int ddy2 = y + 2 * dy[i];
			int ddy3 = y + 3 * dy[i];
			int ddx1 = x + dx[i];
			int ddx2 = x + 2 * dx[i];
			int ddx3 = x + 3 * dx[i];

			int end1 = (ddy1 - 1) * N + ddx1; end1 += end1;
			int end2 = (ddy2 - 1) * N + ddx2; end2 += end2;
			int end3 = (ddy3 - 1) * N + ddx3; end3 += end3;

			if (1 <= ddy1 && ddy1 <= N && 1 <= ddx1 && ddx1 <= N) {
				if (arr[ddy1][ddx1] > 0) 
					addedge(start + 1, end1, 1e9);
			}
			if (1 <= ddy2 && ddy2 <= N && 1 <= ddx2 && ddx2 <= N) {
				if (arr[ddy2][ddx2] > 0) 
					addedge(start + 1, end2, 1e9);
			}
			if (1 <= ddy3 && ddy3 <= N && 1 <= ddx3 && ddx3 <= N) {
				if (arr[ddy3][ddx3] == 0)
					continue;

				if (!visited[end3] && (arr[ddy1][ddx1] > 0 || arr[ddy2][ddx2] > 0)) {
					visited[end3] = 1;
					q.push({ ddy3,ddx3 });
				}

				if (arr[ddy3][ddx3] > 0) {
					if (arr[ddy1][ddx1] > 0)
						addedge(end1 + 1, end3, 1e9);
					if (arr[ddy2][ddx2] > 0)
						addedge(end2 + 1, end3, 1e9);
				}
			}

		}
	}

	return;
}
int bfs() {
	memset(level, -1, sizeof level);
	level[2 * ((dst[0].first - 1) * N + dst[0].second)] = 1;
	queue<int> q; q.push(2 * ((dst[0].first - 1) * N + dst[0].second));
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

	return level[0] == -1 ? 0 : 1;
}
int fl(int now, int wat) {
	if (now == 0)
		return wat;

	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int& capacity = vect[now][i].capacity;
		int& rcapacity = vect[next][vect[now][i].revidx].capacity;

		if (level[now] + 1 == level[next] && capacity > 0) {
			int blockflow = fl(next, min(wat, capacity));
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
	[&]() {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			for (int j = 1; j <= N; j++) {
				int now = (i - 1) * N + j;
				if (tmp[j - 1] == '.') {
					arr[i][j] = 1;
					addedge(2 * now, 2 * now + 1, 1);
				}
				else if (tmp[j - 1] == 'b') {
					arr[i][j] = 2;
					addedge(2 * now, 2 * now + 1, 1e7);
				}
				else if (tmp[j - 1] == '$') {
					arr[i][j] = 3;
					addedge(2 * now, 2 * now + 1, 1e7);
					dst.push_back({ i,j });
				}
			}
		}
	}();

	setnode();

	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = fl(2 * ((dst[0].first - 1) * N + dst[0].second), 1e7);
			if (!flow)
				break;
			mx += flow;;
		}
	}
	if (mx >= 1e7)
		cout << -1;
	else
		cout << mx;
	return 0;
}