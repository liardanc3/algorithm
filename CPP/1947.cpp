#include <bits/stdc++.h>
#define int long long
#define DIV 1'000'000'000

using namespace std;

int N, dp[1000001];
signed main() {
	dp[1] = 0, dp[2] = 1, dp[3] = 2, dp[4] = 9, dp[5] = 44;
	for (int i = 6; i <= 1000000; i++) {
		dp[i] = (((i-1) * dp[i - 1]) + ((i-1) * dp[i - 2])) % DIV;
	}
	cin >> N;
	cout << dp[N];
	return 0;
}