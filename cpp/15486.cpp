#include <bits/stdc++.h>
using namespace std;
int n, dp[1500002], t[1500001], p[1500001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		dp[i] = max(dp[i], dp[i - 1]);
		int j = i + t[i];
		if (j > n + 1) 
			continue;
		dp[j] = max(dp[j], dp[i] + p[i]);
	}
	cout << max(dp[n], dp[n + 1]);
	return 0;
}