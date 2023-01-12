#include <bits/stdc++.h>
using namespace std;
int n, p[10001], dp[10001];
int main() {
	fill(&dp[0], &dp[10001], 1e9);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		dp[i] = p[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			dp[i] = min(dp[i], dp[i - j] + p[j]);
	}
	cout << dp[n];
	return 0;
}