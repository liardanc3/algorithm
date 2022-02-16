#include <bits/stdc++.h>
using namespace std;
int n, arr[1001], dp[1001][1001], mn[1001][1001], mx[1001][1001];
int main() {
	fill(&mn[0][0], &mn[1000][1001], 1e9);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		for (int j = 1; j <= i; j++) {
			mn[j][i] = min(mn[j][i-1], arr[i]);
			mx[j][i] = max(mx[j][i-1], arr[i]);
		}
		for(int k=1; k<=i; k++)
		for (int j = 1; j + 1 <= i; j++)
			dp[1][i] = max(dp[1][i], (dp[1][j] + dp[j + 1][i]));
		dp[1][i] = max(dp[1][i], abs(mn[1][i] - mx[1][i]));
	}
	cout << dp[1][n];
	return 0;
}