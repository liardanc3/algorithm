#include <bits/stdc++.h>
using namespace std;
int n, tmp;
int tri[501][501]{ 0, }, dp[501][501]{ 0, };
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tmp;
			tri[i][j] = tmp;
		}
	}
	dp[1][1] = tri[1][1];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + tri[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + tri[i + 1][j + 1]);
		}
	}
	cout << *max_element(&dp[n][0], &dp[n][500]);
	return 0;
}