#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, arr[101][101], mx, mn = 1e9, ans, tmp[101][101], visited[101][101];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
void bfs(int i, int j) {
	queue<pii> q;
	q.push({ i,j });
	visited[i][j] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int s = 0; s < 4; s++) {
			int ddy = y + dy[s];
			int ddx = x + dx[s];

			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && tmp[ddy][ddx] && !visited[ddy][ddx]) {
				visited[ddy][ddx] = 1;
				q.push({ ddy,ddx });
			}
		}
	}
}
void f(int h) {
	int cnt = 0;
	memset(tmp, 0, sizeof(tmp));
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] > h)
				tmp[i][j] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && tmp[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	ans = max(ans, cnt);
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			mn = min(mn, arr[i][j]);
			mx = max(mx, arr[i][j]);
		}
	}
	for (int i = mn-1; i <= mx; i++)
		f(i);
	cout << ans;
	return 0;
}