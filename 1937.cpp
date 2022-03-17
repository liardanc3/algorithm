#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, arr[501][501], mx = 1, dp[501][501];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
int dfs(int y, int x) {
	if (dp[y][x]) return dp[y][x];

	int next, mmx = 1;
	for (int i = 0; i < 4; i++) {
		int ddy = y + dy[i];
		int ddx = x + dx[i];

		if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= n && arr[ddy][ddx] > arr[y][x]) {
			next = 1 + dfs(ddy, ddx);
			mmx = max(mmx, next);
		}
	}
	return dp[y][x] = mmx;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> arr[i][j];
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			mx=max(mx,dfs(i, j));
	cout << mx;
	return 0;
}