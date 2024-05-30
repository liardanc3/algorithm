#include <bits/stdc++.h>
using namespace std;
int m, n, arr[501][501], dp[501][501], visited[501][501];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
int dynamic(int y, int x) {
	if (dp[y][x] > -1) return dp[y][x];
	for (int i = 0; i < 4; i++) {
		int ddy = y + dy[i];
		int ddx = x + dx[i];

		if (1 <= ddy && ddy <= m && 1 <= ddx && ddx <= n && arr[y][x] > arr[ddy][ddx] && !visited[ddy][ddx]) {
			visited[ddy][ddx] = 1;
			dp[y][x] += dynamic(ddy, ddx);
			visited[ddy][ddx] = 0;
		}
	}
	return dp[y][x] = (dp[y][x] >= 0) ? ++dp[y][x] : 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&dp[0][0], &dp[500][501], -1);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
		cin >> arr[i][j];
	visited[1][1] = 1;
	dp[m][n] = 1;
	cout << dynamic(1, 1);
	return 0;
}