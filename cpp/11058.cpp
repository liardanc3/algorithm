#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, dp[101][5];
signed main() {
	dp[1][1] = 1, dp[1][2] = 0, dp[1][3] = 0, dp[1][4] = 0; 
	dp[2][1] = 2, dp[2][2] = 1, dp[2][3] = 0, dp[2][4] = 0; 
	dp[3][1] = 3, dp[3][2] = 2, dp[3][3] = 1, dp[3][4] = 0; 
	dp[4][1] = 4, dp[4][2] = 3, dp[4][3] = 2, dp[4][4] = 1;
	for (int i = 5; i <= 100; i++) {
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][4]) + 1;
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][4]);
		dp[i][3] = dp[i - 1][2];
		for (int j = 3; j < i; j++)
			dp[i][4] = max(dp[i][4], dp[j][3] * (i - j + 1));
	}
	cin >> n;
	cout << max(dp[n][1], dp[n][4]);
	return 0;
}