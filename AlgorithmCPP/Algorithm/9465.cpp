#include <bits/stdc++.h>
using namespace std;
int sticker[2][100000];
int dp[2][100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T,n,tmp; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> tmp;
				sticker[i][j] = tmp;
			}
		} memset(dp, 0, sizeof(dp));
		dp[0][0] = sticker[0][0]; // 50
		dp[1][0] = sticker[1][0]; // 30
		for (int i = 1; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1] + sticker[0][i], dp[0][i - 1]);
			dp[1][i] = max(dp[0][i - 1] + sticker[1][i], dp[1][i - 1]);
		}
		int max = dp[0][n - 1] > dp[1][n - 1] ? dp[0][n - 1] : dp[1][n - 1];
		cout << max << '\n';
	}
	return 0;
}