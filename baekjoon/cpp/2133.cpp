#include <bits/stdc++.h>
using namespace std;
int n, dp[31];
int main() {
	// 2Ä­ 3°³
	// 4Ä­ 3*3°³ + 2°³
	dp[0] = 1, dp[2] = 3, dp[4] = 11;
	for (int i = 6; i <= 30; i += 2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += dp[j] * 2;
	}
	cin >> n;
	cout << dp[n];
	return 0;
}