#include <bits/stdc++.h>
using namespace std;
int n, mx = -1e9, dp[100002][2], arr[100002];
int main() {
	cin >> n;
	dp[0][0] = -1e9, dp[0][1] = -1e9;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
		mx = max(mx, max(dp[i][0], dp[i][1]));
	}
	cout << mx;
	return 0; 
}