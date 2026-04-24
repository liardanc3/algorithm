#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, arr[21][21], gap = 1e9, visited[21][21], line[21][21];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
void bfs(int x, int y) {
	queue<pii> q;
	q.push({ x,y });
	line[x][y] = 2;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ddx = xx + dx[i];
			int ddy = yy + dy[i];

			if (1 <= ddx && ddx <= n && 1 <= ddy && ddy <= n && !line[ddy][ddx]) {
				line[ddy][ddx] = 2;
				q.push({ ddy,ddx });
			}
		}
	}
}
void gerrymandering(int x, int y, int d1, int d2) {
	memset(visited, 0, sizeof(visited));
	memset(line, 0, sizeof(line));
	int a = 0, b = 0, c = 0, d = 0, e = 0, mx = 0, mn = 1e9;

	for (int i = x, j = y; i <= x + d1 && j >= y - d1; i++, j--)
		line[i][j] = 2;
	for (int i = x, j = y; i <= x + d2 && j <= y + d2; i++, j++)
		line[i][j] = 2;
	for (int i = x + d1, j = y - d1; i <= x + d1 + d2 && j <= y - d1 + d2; i++, j++)
		line[i][j] = 2;
	for (int i = x + d2, j = y + d2; i <= x + d2 + d1 && j >= y + d2 - d1; i++, j--)
		line[i][j] = 2;

	// 1번 선거구
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (line[i][j] == 2) break;
			if (!visited[i][j]) {
				a += arr[i][j];
				visited[i][j] = 1;
			}
		}
	}
	mx = max(mx, a), mn = min(mn, a);

	// 2번 선거구
	for (int i = 1; i <= x + d2; i++) {
		for (int j = n; j >= y+1; j--) {
			if (line[i][j] == 2) break;
			if (!visited[i][j]) {
				b += arr[i][j];
				visited[i][j] = 1;
			}
		}
	}
	mx = max(mx, b), mn = min(mn, b);

	// 3번 선거구
	for (int i = x + d1; i <= n; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {
			if (line[i][j] == 2) break;
			if (!visited[i][j]) {
				c += arr[i][j];
				visited[i][j] = 1;
			}
		}
	}
	mx = max(mx, c), mn = min(mn, c);

	// 4번 선거구
	for (int i = x + d2 + 1; i <= n; i++) {
		for (int j = n; j >= y - d1 + d2; j--) {
			if (line[i][j] == 2) break;
			if (!visited[i][j]) {
				d += arr[i][j];
				visited[i][j] = 1;
			}
		}
	}
	mx = max(mx, d), mn = min(mn, d);

	// 5번 선거구
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j])
				e += arr[i][j];
		}
	}
	mx = max(mx, e), mn = min(mn, e);
	gap = min(gap, mx - mn);
}
void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> arr[i][j];
}
int main() {
	init();
	//gerrymandering(3, 3, 1, 1);
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					if (1 <= x && x < x + d1 + d2 && x + d1 + d2 <= n && 1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= n)
						gerrymandering(x, y, d1, d2);
					else 
						break;
				}
			}
		}
	}
	cout << gap;
	return 0;
}