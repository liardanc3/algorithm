#include <bits/stdc++.h>
using namespace std;
int n, m, dp[16][16], k;
int main() {
	dp[0][1] = 1;
	cin >> n >> m >> k;
	if (k) {
		int r = k % m ? k / m + 1 : k / m;
		int c = k % m ? k % m : m;
		for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		for (int i = r; i <= n; i++) for (int j = c; j <= m; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}
	else {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}
	cout << dp[n][m];
	return 0;
}