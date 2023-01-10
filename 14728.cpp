#include <bits/stdc++.h>
using namespace std;
int N, T, K, S, dp[10001], w[101], v[101];
int main() {
	cin >> N >> T;
	for (int i = 1; i <= N; i++) 
		cin >> w[i] >> v[i];
	for (int i = 1; i <= N; i++) {
		for (int j = T; j >= 1; j--) {
			if (w[i] > j) break;
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[T];
	return 0;
}