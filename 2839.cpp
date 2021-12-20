#include <bits/stdc++.h>
using namespace std;
int dp[5001]{ 0, };
void dynamic(int now) {
	if (dp[now] + 1 < dp[now + 3]) {
		dp[now + 3] = dp[now] + 1;
		dynamic(now+3);
	}
	if (dp[now] + 1 < dp[now + 5]) {
		dp[now + 5] = dp[now] + 1;
		dynamic(now+5);
	}
}
int main() {
	int N; cin >> N;
	fill(&dp[0], &dp[5001], 1e9);
	dp[0] = 0;
	dynamic(0);
	if (dp[N] == 1e9) cout << -1;
	else cout << dp[N];
	return 0;
}