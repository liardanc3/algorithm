#include <bits/stdc++.h>
using namespace std;
int n, s, m, v[51], dp[51][1001];
int main() {
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	dp[0][s] = 1;
	for (int i = 1; i <= n; i++) {
		int now = v[i];
		for (int next = 0; next <= m; next++) {
			if (dp[i - 1][next] && 0 <= now + next && now + next <= m)
				dp[i][now + next] = 1;
			if (dp[i - 1][next] && 0 <= -now + next && -now + next <= m)
				dp[i][-now + next] = 1;
		}
	}
	for (int i = m; i >= 0; i--) {
		if (dp[n][i]) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}