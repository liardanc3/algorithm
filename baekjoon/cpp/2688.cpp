#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, dp[65][10], sum;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++)
				dp[i][j] += dp[i - 1][k];
		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		sum = 0;
		for (int i = 0; i <= 9; i++)
			sum += dp[n][i];
		cout << sum << '\n';
	}
	return 0;
}