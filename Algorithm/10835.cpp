#include <bits/stdc++.h>
using namespace std;
int n, L[2001], R[2001], dp[2001][2001], mx = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = n; i >= 1; i--)
		cin >> L[i];
	for (int i = n; i >= 1; i--)
		cin >> R[i];
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			// 왼쪽만 버림
			dp[i - 1][j] = max(dp[i - 1][j], dp[i][j]);
			mx = max(dp[i - 1][j], mx);
			// 둘다 버림
			dp[i - 1][j - 1] = max(dp[i - 1][j - 1], dp[i][j]);
			mx = max(dp[i - 1][j - 1], mx);
			// 오른쪽만 버림 && 오른쪽만 못뺌
			if (L[i] > R[j] && (j>=i || dp[i][j])) {
				dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + R[j]);
				mx = max(dp[i][j - 1], mx);
			}
		}
	}
	cout << mx;
	return 0;
}