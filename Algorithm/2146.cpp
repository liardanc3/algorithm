#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, arr[101][101], visited[101][101], cnt, mn = 1e9;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };

void route(int yy, int xx) {
	queue<pii> q;
	q.push({ yy,xx });
	visited[yy][xx] = 1;

	int len = -1;
	while (!q.empty()) {
		len++;
		int sz = q.size();
		for (int s = 0; s < sz; s++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= n && !visited[ddy][ddx]) {
					visited[ddy][ddx] = 1;

					if (arr[ddy][ddx] && arr[ddy][ddx] != arr[yy][xx]) {
						mn = min(mn, len);
						return;
					}

					if (arr[ddy][ddx] == 0) {
						visited[ddy][ddx] = 1;
						q.push({ ddy,ddx });
					}
				}
			}
		}
	}
}

void bfs(int yy, int xx) {
	++cnt;
	arr[yy][xx] = cnt;
	queue<pii> q;
	q.push({ yy,xx });
	visited[yy][xx] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];

			if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= n && !visited[ddy][ddx] && arr[ddy][ddx]) {
				arr[ddy][ddx] = cnt;
				visited[ddy][ddx] = 1;
				q.push({ ddy,ddx });
			}
		}
	}

	return;
}
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> arr[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && arr[i][j])
				bfs(i, j);
		}
	}
}
int main() {
	init();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 0) continue;
			for (int s = 0; s < 4; s++) {
				int ddy = i + dy[s];
				int ddx = j + dx[s];

				if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= n && arr[ddy][ddx] == 0) {
					memset(visited, 0, sizeof(visited));
					route(i, j);
					break;
				}
			}
		}
	}
	cout << mn;
	return 0;
}