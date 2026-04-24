#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> tii;
int k, w, h, arr[201][201], visited[31][201][201];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
int cy[]{ -2,-2,-1,-1,1,1,2,2 }, cx[]{ -1,1,-2,2,-2,2,-1,1 };
void bfs() {
	visited[0][1][1] = 1;
	queue<tii> q;
	q.push({ 0,0,1,1 });

	while (!q.empty()) {
		int y = get<2>(q.front());
		int x = get<3>(q.front());
		int cnt = get<1>(q.front());
		int total = get<0>(q.front());
		q.pop();

		if (y == h && x == w) {
			cout << total;
			return;
		}

		if (cnt < k) {
			for (int i = 0; i < 8; i++) {
				int ddy = y + cy[i];
				int ddx = x + cx[i];

				if (1 <= ddy && ddy <= h && 1 <= ddx && ddx <= w && !visited[cnt+1][ddy][ddx] && !arr[ddy][ddx]) {
					visited[cnt+1][ddy][ddx] = 1;
					q.push({ total + 1,cnt + 1,ddy,ddx });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];

			if (1 <= ddy && ddy <= h && 1 <= ddx && ddx <= w && !visited[cnt][ddy][ddx] && !arr[ddy][ddx]) {
				visited[cnt][ddy][ddx] = 1;
				q.push({ total + 1,cnt,ddy,ddx });
			}
		}
	}
	cout << -1;
	return;
}
int main() {
	cin >> k >> w >> h;
	for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++)
		cin >> arr[i][j];
	bfs();
	return 0;
}