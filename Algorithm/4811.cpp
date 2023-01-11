#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, dp[61][61];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	dp[1][0] = 1;
	dp[1][1] = 1, dp[2][0] = 1;
	dp[2][1] = 2, dp[3][0] = 1;
	for (int i = 4; i <= 60; i++) {
		dp[i][0] = 1;
		for (int j = 1; i-j>=j; j++) {
			dp[i - j][j] += dp[i - j - 1][j] + dp[i - j][j - 1];
		}
	}
	while (cin >> n) {
		if (!n) break;
		cout << dp[n][n] << '\n';
	}
	return 0;
}