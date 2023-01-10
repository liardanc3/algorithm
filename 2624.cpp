#include <bits/stdc++.h>
using namespace std;
int t, k, p[10001], n[101], dp[10001];
int main() {
	cin >> t >> k;
	for (int i = 1; i <= k; i++)
		cin >> p[i] >> n[i];
	dp[0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = t - p[i]; j >= 0; j--) {
			if (dp[j]) {
				for (int s = 1; s <= n[i] && j + s * p[i] <= t; s++) {
					dp[j + s * p[i]] += dp[j];
				}
			}
		}
	}
	cout << dp[t];
	return 0;
}