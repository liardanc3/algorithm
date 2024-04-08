#include <bits/stdc++.h>
using namespace std;
int n, arr[50001], m, dp[4][50001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}	
	cin >> m;
	for (int i = 1; i <= 3; i++) {
		for (int j = m; j <= n && j+(3-i)*m <= n; j++) 
			dp[i][j] = max(dp[i][j-1], dp[i - 1][j - m] + arr[j] - arr[j - m]);
	}
	cout << dp[3][n];
	return 0;
}