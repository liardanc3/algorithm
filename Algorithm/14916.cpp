#include <bits/stdc++.h>
using namespace std;
int n, dp[100001];
void dynamic(int now, int cnt) {
	if (cnt < dp[now]) {
		dp[now] = cnt;
		dynamic(now + 5, cnt + 1);
		dynamic(now + 2, cnt + 1);
	}
	return;
}
int main() {
	fill(&dp[0], &dp[100001], 1e9);
	dynamic(0, 0);
	cin >> n;
	if (dp[n] == 1e9) cout << -1;
	else cout << dp[n];
	return 0;
}