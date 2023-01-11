#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, dp[42][3], arr[42], tmp;
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		arr[tmp] = 1;
	}
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = arr[1] || arr[2] ? 0 : 1;
	
	dp[2][0] = arr[1] || arr[2] ? 0 : 1;
	dp[2][1] = 1;
	dp[2][2] = arr[3] || arr[2] ? 0 : 1;
	
	for (int i = 3; i <= n - 1; i++) {
		dp[i][0] = arr[i - 1] || arr[i] ? 0 : dp[i - 2][0] + dp[i - 1][2];
		dp[i][1] = arr[i - 2] ? dp[i - 1][1] : dp[i - 2][2] + dp[i - 1][1];
		dp[i][2] = arr[i] || arr[i + 1] ? 0 : dp[i - 2][2] + dp[i - 1][1];
	}

	if (n >= 3) {
		dp[n][0] = arr[n] ? 0 : dp[n - 1][2];
		dp[n][1] = arr[n - 1] ? dp[n - 1][1] : dp[n - 2][2] + dp[n - 1][1];
	}
	
	cout << dp[n][0] + dp[n][1];
	return 0;
}