#include <bits/stdc++.h>
using namespace std;
int n, arr[10001], dp[10001][4];
int max(int a, int b, int c) {
	if (a >= b && a >= c) return a;
	if (b >= a && b >= c) return b;
	if (c >= a && c >= b) return c;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[1][0] = 0;
	dp[1][1] = arr[1];
	dp[2][0] = max(dp[1][0], dp[1][1], dp[1][2]);
	dp[2][1] = dp[1][0] + arr[2];
	dp[2][2] = dp[1][1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	cout << *max_element(&dp[0][0], &dp[10000][4]);
	return 0;
}