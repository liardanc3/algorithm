#include <bits/stdc++.h>
using namespace std;
int t, n, dp[10001][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	dp[1][0] = 1;
	dp[2][0] = 1, dp[2][1] = 1;
	dp[3][0] = 1, dp[3][1] = 1, dp[3][2] = 1;
	for (int i = 4; i <= 10000; i++) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n][0] + dp[n][1] + dp[n][2] << '\n';
	}
	return 0;
}