#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, M, arr[1001][1001], h, w, sr, sc, fr, fc, visited[1001][1001], cnt;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
void bfs() {
	visited[sr][sc] = 1;
	queue<pii> q;
	q.push({ sr,sc });
	while (!q.empty()) {
		int sz = q.size(); cnt++;
		while (sz--) {
			pii p = q.front();
			q.pop();

			int y = p.first;
			int x = p.second;

			for (int j = 0; j < 4; j++) {
				int ddy = y + dy[j];
				int ddx = x + dx[j];

				if (1 <= ddy && ddy <= N - h + 1 && 1 <= ddx && ddx <= M - w + 1 && !visited[ddy][ddx] && !arr[ddy][ddx]) {
					visited[ddy][ddx] = 1;
					q.push({ ddy,ddx });

					if (fr == ddy && fc == ddx) {
						cout << cnt;
						exit(0);
					}
				}
			}
		}
	}
	cout << -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
	cin >> h >> w >> sr >> sc >> fr >> fc;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j]) {
				for (int y = -h + 1; y <= 0; y++) {
					for (int x = -w + 1; x <= 0; x++) {
						if (i + y >= 1 && j + x >= 1)
							arr[i + y][j + x] = 1;
					}
				}
			}
		}
	}
	if (sr == fr && sc == fc)
		cout << 0;
	else
		bfs();
	return 0;
}