#include <bits/stdc++.h>
#define DIV 1'000'000'009
#define int long long
using namespace std;
int n, dp[1000001], t;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 1000000; i++)
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1])%DIV;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}