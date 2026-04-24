#include <bits/stdc++.h>
using namespace std;
string a, b;
int alen, blen;
int dp[1000][1000];
int LCS(int alen, int blen) {
	if (alen == -1 || blen == -1) return 0;
	if (dp[alen][blen] != -1)
		return dp[alen][blen];
	if (a[alen] == b[blen])
		dp[alen][blen] = LCS(alen - 1, blen - 1) + 1;
	else dp[alen][blen] = max(LCS(alen, blen - 1), LCS(alen - 1, blen));
	return dp[alen][blen];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&dp[0][0], &dp[999][1000], -1);
	cin >> a >> b;
	int ans = LCS(a.size()-1,b.size()-1);
	cout << ans;
	return 0;
}