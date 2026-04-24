#include <bits/stdc++.h>
using namespace std;
int n, dp[1001];
int main() {
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;
	dp[5] = 1;
	for (int i = 6; i <= 1000; i++) {
		if (!dp[i - 3] || !dp[i - 1] || !dp[i-4])
			dp[i] = 1;
		else dp[i] = 0;
	}
	if (dp[n]) cout << "SK";
	else cout << "CY";
	return 0;
}