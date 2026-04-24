#include <bits/stdc++.h>
using namespace std;
int n, dp[1025][4], mn = 1e9;
void solve() {
	fill(&dp[0][0], &dp[1024][4], 1e9);
	for (int i = 1, cnt=0; i <= 1024; i *=2, cnt+=2) {
		dp[i][2] = cnt;
		dp[i][1] = cnt + 1;
		for (int j = i - 1, ccnt = cnt + 1; j >= 1; j--, ccnt++)
			dp[j][3] = min(dp[j][3], ccnt);
	}
	for (int i = 1; i <= 1024; i++) {
		for (int j = 2 * i, cnt = 1; j <= 1024; j += i, cnt++) {
			dp[j][2] = min(dp[j][2], min(dp[i][1] + cnt, dp[i][3] + cnt + 1));
			dp[j][1] = min(dp[j][1], dp[j][2] + 1);
			for (int k = j - 1, ccnt = dp[j][2] + 1; k >= 1; k--, ccnt++)
				dp[k][3] = min(dp[k][3], ccnt);
		}
	}
	cin >> n;
	cout << min(dp[n][1], min(dp[n][2], dp[n][3]));
}
int main() {
	solve();
	return 0;
}