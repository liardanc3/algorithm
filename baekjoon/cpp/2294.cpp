#include <bits/stdc++.h>
using namespace std;
int n, k, dp[10001], coin;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&dp[1], &dp[10001], 1e9);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin;
		if (coin <= k) {
			for (int j = coin; j <= k; j++)
				dp[j] = min(dp[j], dp[j - coin] + 1);
		}		
	}
	dp[k]==1e9 ? cout << -1 : cout << dp[k];
	return 0;
}