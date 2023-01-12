#include <bits/stdc++.h>
using namespace std;
int n, m, dp[101][51], arr[101], mx = -1e9;
int main() {
	fill(&dp[0][0], &dp[100][51], -1e9);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][1] = max(arr[i], dp[i - 1][1] + arr[i]);
	}
	for (int i = 2; i <= m; i++) {
		for (int j = i*2-1; j <= n; j++) {
			for(int k=j-2; k>=1; k--)
				dp[j][i] = max(dp[j][i], max(dp[j-1][i]+arr[j], dp[k][i-1]+arr[j]));
		}
	}
	for (int i = 1; i <= n; i++)
		mx = max(mx, dp[i][m]);
	cout << mx;
	return 0;
}