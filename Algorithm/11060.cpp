#include <bits/stdc++.h>
using namespace std;
int n, arr[1001], dp[1001];
int main() {
	fill(&dp[2], &dp[1001], 1e9);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		for (int j = 1; j <= arr[i] && j + i <= n; j++)
			dp[i + j] = min(dp[i + j], dp[i] + 1);
	}
	cin >> arr[0];
	dp[n] == 1e9 ? cout << -1 : cout << dp[n];
	return 0;
}