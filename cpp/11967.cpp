#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> light[101][101];
int N, M, x, y, a, b, arr[101][101], visited[101][101], ans;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
void bfs() {
	queue<pii> q;
	q.push({ 1,1 });
	visited[1][1] = 1;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		for (int i = 0; i < light[xx][yy].size(); i++) {
			int nextx = light[xx][yy][i].first;
			int nexty = light[xx][yy][i].second;

			arr[nextx][nexty] = 1;
			for (int j = 0; j < 4; j++) {
				int dnextx = nextx + dx[j];
				int dnexty = nexty + dy[j];
				if (visited[dnextx][dnexty] && !visited[nextx][nexty]) {
					visited[nextx][nexty] = 1;
					q.push({ nextx,nexty });
					break;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int ddx = xx + dx[i];
			int ddy = yy + dy[i];

			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && !visited[ddx][ddy] && arr[ddx][ddy]) {
				visited[ddx][ddy] = 1;
				q.push({ ddx,ddy });
			}
		}
	}
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		ans += arr[i][j];
	cout << ans;
	return;
}
int main() {
	[&]() {
		arr[1][1] = 1;
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		while (M--) {
			cin >> x >> y >> a >> b;
			light[x][y].push_back({ a,b });
		}
	}();
	bfs();
	return 0;
}