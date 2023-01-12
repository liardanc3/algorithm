#include <bits/stdc++.h>
using namespace std;
int n, m, arr[1001][1001], dp[1001][1001];
int dy[]{ 0,1,1 }, dx[]{ 1,0,1 };
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		cin >> arr[i][j];
	dp[1][1] = arr[1][1];
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			for (int i = 0; i < 3; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];
				if (ddy <= n && ddx <= m)
					dp[ddy][ddx] = max(dp[ddy][ddx], dp[y][x] + arr[ddy][ddx]);
			}
		}
	}
	cout << dp[n][m];
	return 0;
}