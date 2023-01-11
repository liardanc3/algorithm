#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;

int N, M, arr[101][101], r, c, direct, visited[5][101][101], dr, dc, dd;
int dy[]{ 0,0,0,1,-1 }, dx[]{ 0,1,-1,0,0 };
void init() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
	cin >> r >> c >> direct >> dr >> dc >> dd;
}
void bfs() {
	queue<tii> q;
	q.push({ direct, r,c, });
	visited[direct][r][c] = 1;
	int cnt = -1;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();
		while (sz--) {
			int d = get<0>(q.front());
			int y = get<1>(q.front());
			int x = get<2>(q.front());

			//cout << "cost : " << cnt << " -> " << d << ", " << y << ", " << x << '\n';
			q.pop();
			if (d == dd && y == dr && x == dc) {
				cout << cnt;
				return;
			}

			// turn left
			int leftd = -1;
			if (d == 1) leftd = 4;
			else if (d == 2) leftd = 3;
			else if (d == 3) leftd = 1;
			else leftd = 2;
			if (!visited[leftd][y][x]) {
				visited[leftd][y][x] = 1;
				q.push({ leftd,y,x });
			}

			// turn right
			int rightd = -1;
			if (d == 1) rightd = 3;
			else if (d == 2) rightd = 4;
			else if (d == 3) rightd = 2;
			else rightd = 1;
			if (!visited[rightd][y][x]) {
				visited[rightd][y][x] = 1;
				q.push({ rightd,y,x });
			}

			// go 123
			int ddy1 = y + 1 * dy[d];
			int ddy2 = y + 2 * dy[d];
			int ddy3 = y + 3 * dy[d];
			int ddx1 = x + 1 * dx[d];
			int ddx2 = x + 2 * dx[d];
			int ddx3 = x + 3 * dx[d];

			if (1 <= ddy1 && ddy1 <= N && 1 <= ddx1 && ddx1 <= M && !arr[ddy1][ddx1]) {
				if (!visited[d][ddy1][ddx1]) {
					visited[d][ddy1][ddx1] = 1;
					q.push({ d,ddy1,ddx1 });
				}
				if (1 <= ddy2 && ddy2 <= N && 1 <= ddx2 && ddx2 <= M && !arr[ddy2][ddx2]) {
					if (!visited[d][ddy2][ddx2]) {
						visited[d][ddy2][ddx2] = 1;
						q.push({ d,ddy2,ddx2 });
					}
					if (1 <= ddy3 && ddy3 <= N && 1 <= ddx3 && ddx3 <= M && !arr[ddy3][ddx3]) {
						if (!visited[d][ddy3][ddx3]) {
							visited[d][ddy3][ddx3] = 1;
							q.push({ d,ddy3,ddx3 });
						}
					}
				}
			}
		}
	}
	return;
}
int main() {
	init();
	bfs();
	return 0;
}