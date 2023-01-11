#include <bits/stdc++.h>
#define DIV 1'000'000'003
#define int long long
using namespace std;
int n, k, now, dp[1004][1001], sum = 0;
int dynamic(int color, int cnt, int flag) {
	if (dp[color][cnt] >= 0) return dp[color][cnt];
	if (cnt == k) return dp[color][cnt] = 1;
	if (color > n-flag) return dp[color][cnt] = 0;
	dp[color][cnt] = 0;
	dp[color][cnt] += dynamic(color + 2, cnt + 1, flag);
	dp[color][cnt] = (dp[color][cnt] + dynamic(color + 1, cnt, flag)) % DIV;
	return dp[color][cnt];
}
signed main() {
	cin >> n >> k;
	fill(&dp[0][0], &dp[1003][1001], -1);
	sum += dynamic(2, 0, 0);
	fill(&dp[0][0], &dp[1003][1001], -1);
	sum = (sum + dynamic(3, 1, 1)) % DIV;
	cout << sum % DIV;
	return 0;
}