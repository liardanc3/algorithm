#include <bits/stdc++.h>
using namespace std;
string a, b, ans;
int dp[1001][1001];
int dps(int alen, int blen) {
	if (alen == 0 || blen == 0)
		return 0;
	if (a[alen-1] == b[blen-1]) {
		dps(alen - 1, blen - 1);
		cout << a[alen-1];
	}
	else 
		dp[alen - 1][blen] > dp[alen][blen - 1] ? dps(alen - 1, blen) : dps(alen, blen - 1);
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&dp[0][0], &dp[1000][1001], 0);
	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i-1] == b[j-1]) 
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else 
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	cout << dp[a.size()][b.size()] << '\n';
	dps(a.size(), b.size());
	return 0;
}