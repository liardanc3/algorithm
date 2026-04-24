#include <bits/stdc++.h>
using namespace std;
int n, dp[31];
int main() {
	dp[1] = 1, dp[2] = 3;
	for (int i = 3; i <= 30; i++)
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
	cin >> n;
	if (n < 3) cout << dp[n];
	else if (n % 2 == 0) cout << (dp[n] + dp[n / 2]) / 2 + dp[n / 2 - 1];
	else cout << (dp[n] + dp[n / 2]) / 2;
	return 0;
}