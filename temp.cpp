#include <bits/stdc++.h>
using namespace std;
int n, dp[300001];
vector<int> ps;
signed main() {
	dp[1] = 1, dp[4] = 1;
	ps.push_back(1), ps.push_back(4);
	for (int i = 3;; i++) {
		int now = i * i + ps[i - 3];
		if (now > 300000) break;
		ps.push_back(now);
		dp[now] = 1;
	}
	for (int i = 1; i <= 300000; i++) {
		if (!dp[i]) dp[i] = i;
	}
	for (int i = 0; i < ps.size() - 1; i++) {
		for (int j = i + 1; j < ps.size(); j++) {
			int now = ps[i];
			int next = ps[j];
			for (int k = now + next, cnt = 2; k <= 300000; k += next, cnt++)
				dp[k] = min(dp[k], cnt);
		}
	}
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int left = dp[n - i];
		int right = dp[i];
		if (left == 1e9 || right == 1e9) continue;
		else dp[n] = min(dp[n], left + right);
	}
	cout << dp[n];
	return 0;
}