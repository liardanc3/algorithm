#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
set<pii> s;
int n, arr[201][201], x, y, d, g, visited[201][201], py, px, tmp[201][201], ans;
int dy[]{ 0,-2,0,2 }, dx[]{ 2,0,-2,0 };
pair<int, int> bfs(int yy, int xx) {
	int ly, lx;
	queue<pii> q;
	visited[yy][xx] = 1;
	q.push({ yy,xx });
	while (!q.empty()) {
		int ny = q.front().first;
		int nx = q.front().second;
		q.pop();

		ly = ny, lx = nx;
		for (int i = 0; i < 4; i++) {
			int ddy = ny + dy[i]/2;
			int ddx = nx + dx[i]/2;

			if (0 <= ddy && ddy <= 200 && 0 <= ddx && ddx <= 200 && !visited[ddy][ddx] && arr[ddy][ddx]) {
				visited[ddy][ddx] = 1;
				q.push({ ddy,ddx });
			}
		}
	}
	return { ly,lx };
}
void curve() {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			if (arr[i][j]) {
				int ddy = i - py;
				int ddx = j - px;

				int ny = ddx + py;
				int nx = -ddy + px;

				if (0 <= ny && ny <= 200 && 0 <= nx && nx <= 200)
					tmp[ny][nx] = 1;
			}
		}
	}
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			if (tmp[i][j])
				arr[i][j] = 1;
		}
	}
}
void insert2s() {
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			if (arr[i][j])
				s.insert({ i,j });
		}
	}
	memset(arr, 0, sizeof(arr));
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		x *= 2, y *= 2;
		arr[y][x] = 1, arr[y + dy[d]][x + dx[d]] = 1, arr[y + dy[d] / 2][x + dx[d] / 2] = 1;
		py = y + dy[d], px = x + dx[d];
		for (int i = 1; i <= g; i++) {
			curve();
			memset(visited, 0, sizeof(visited));
			pii p = bfs(y, x);
			py = p.first, px = p.second;
		}
		insert2s();
	}
	memset(tmp, 0, sizeof(tmp));
	for (pii p : s)
		tmp[p.first][p.second] = 1;
	for (int i = 0; i < 200; i+=2) {
		for (int j = 0; j < 200; j+=2) {
			if (tmp[i][j] && tmp[i + 2][j] && tmp[i][j + 2] && tmp[i + 2][j + 2])
				ans++;
		}
	}
	cout << ans;
	return 0;
}