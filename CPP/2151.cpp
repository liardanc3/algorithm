#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int, int> tii;

int N, sy, sx, ey, ex, dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 }, visited[4][51][51], mn = 1e9;
char arr[51][51];
string tmp;

void init() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	fill(&visited[0][0][0], &visited[3][50][51], 1e9);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= N; j++) {
			arr[i][j] = tmp[j - 1];
			if (arr[i][j] == '#') {
				if (sy == 0)
					sy = i, sx = j;
				else
					ey = i, ex = j;
			}
		}
	}
}

void bfs() {
	queue<tii> q;
	for (int i = 0; i < 4; i++) {
		visited[i][sy][sx] = 0;
		q.push({ i,0,sy,sx });
	}
	while (!q.empty()) {
		int y = get<2>(q.front());
		int x = get<3>(q.front());
		int m = get<1>(q.front());
		int i = get<0>(q.front());

		q.pop();

		if (y == ey && x == ex) {
			mn = min(mn, m);
			continue;
		}

		int ddy = y + dy[i];
		int ddx = x + dx[i];

		if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && arr[ddy][ddx] != '*') {
			if (m < visited[i][ddy][ddx]) {
				visited[i][ddy][ddx] = m;
				q.push({ i,m,ddy,ddx });
			}

			if (arr[ddy][ddx] == '!') {
				int a, b;
				if (i == 0) a = 1, b = 2;
				else if (i == 1) a = 0, b = 3;
				else if (i == 2) a = 0, b = 3;
				else a = 1, b = 2;

				if (m + 1 < visited[a][ddy][ddx]) {
					visited[a][ddy][ddx] = m + 1;
					q.push({ a,m + 1,ddy,ddx });
				}

				if (m + 1 < visited[b][ddy][ddx]) {
					visited[b][ddy][ddx] = m + 1;
					q.push({ b,m + 1,ddy,ddx });
				}
			}
		}
	}
	return;
}

int main() {
	init();
	bfs();
	cout << mn;
	return 0;
}