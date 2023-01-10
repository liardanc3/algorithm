#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, dp[101][101], arr[101][101];
void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> arr[i][j];
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!dp[i][j] || !arr[i][j]) continue;
			int jump = arr[i][j];
			int dx = j + jump;
			int dy = i + jump;
			if (dx <= n) dp[i][dx] += dp[i][j];
			if (dy <= n) dp[dy][j] += dp[i][j];
		}
	}
}
signed main() {
	init();
	cout << dp[n][n];
	return 0;
}