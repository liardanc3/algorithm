#include <bits/stdc++.h>
using namespace std;
int N, r, c, sum, dp[501][501], arr[501][2];

void makedp(int g) {

	for (int i = 1; i <= N - g; i++) {
		int mn = 2147483000;
		for (int j = 1; j < g - 1; j++) {
			if (dp[i][i + j] + dp[i + j + 1][i + g] + arr[i][0] * arr[i + j + 1][0] * arr[i + g][1] < mn)
				mn = dp[i][i + j] + dp[i + j + 1][i + g] + arr[i][0] * arr[i + j + 1][0] * arr[i + g][1];
		}
		dp[i][i + g] = min(mn, min(
			dp[i][i + g - 1] + arr[i][0] * arr[i + g][0] * arr[i + g][1],
			dp[i + 1][i + g] + arr[i][0] * arr[i + 1][0] * arr[i + g][1]));
		if (g > 2)
			dp[i][i + g] = min(dp[i][i + g],
				dp[i + 1][i + g - 1] + arr[i][0] * arr[i + 1][0] * arr[i + g - 1][1] + arr[i][0] * arr[i + g][0] * arr[i + g][1]);
	}
	if (N - g > 1) makedp(++g);
}


int main() {
	sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 1; i <= N - 1; i++)
		dp[i][i + 1] = arr[i][0] * arr[i + 1][0] * arr[i + 1][1];
	makedp(2);
	cout << dp[1][N];
	return 0;
}