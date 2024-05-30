#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int t, n, sy, sx, fy, fx, visited[301][301];
int dy[]{ -2,-2,-1,-1,1,1,2,2 }, dx[]{ -1,1,-2,2,-2,2,-1,1 };
void bfs() {
	int cnt = -1;
	queue<pii> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		cnt++;
		int size = q.size();
		for (int s = 0; s < size; s++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (y == fy && x == fx) {
				cout << cnt << '\n';
				return;
			}

			for (int i = 0; i < 8; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= n && !visited[ddy][ddx]) {
					visited[ddy][ddx] = 1;
					q.push({ ddy,ddx });
				}
			}
		}
	}
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> sy >> sx >> fy >> fx;
		sy++, sx++, fy++, fx++;
		bfs();
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}