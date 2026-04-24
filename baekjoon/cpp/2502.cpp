#include <bits/stdc++.h>
using namespace std;
int d, dp[31], k;
int main() {
	cin >> d >> k;
	dp[d] = k;
	for (int i = k-1; i >= 1; i--) {
		dp[d - 1] = i;
		for (int j = d - 2; j >= 1; j--) {
			dp[j] = dp[j + 2] - dp[j + 1];
			if (dp[j] <= 0 || dp[j]>dp[j+1]) break;
			if (j == 1 && dp[j] > 0) {
				cout << dp[1] << '\n' << dp[2];
				return 0;
			}
		}
	}
}