#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int r, c, visited[51][51], dist=0;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
char arr[51][51];
string tmp;
void bfs(int y, int x) {
	queue<pii> q;
	q.push({ y,x });
	visited[y][x] = 1;
	int cnt = -1;
	while (!q.empty()) {
		cnt++;
		dist = max(dist, cnt);
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int yy = q.front().first;
			int xx = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int ddy = yy + dy[k];
				int ddx = xx + dx[k];

				if (1 <= ddy && ddy <= r && 1 <= ddx && ddx <= c && !visited[ddy][ddx] && arr[ddy][ddx] == 'L') {
					visited[ddy][ddx] = 1;
					q.push({ ddy,ddx });
				}
			}
		}
	}
	return;
}
int main() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		cin >> tmp;
		for (int j = 1; j <= c; j++)
			arr[i][j] = tmp[j - 1];
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] == 'W') continue;
			memset(visited, 0, sizeof(visited));
			bfs(i, j);
		}
	}
	cout << dist;
	return 0;
}