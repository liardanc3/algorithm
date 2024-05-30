#include <bits/stdc++.h>
using namespace std;
int n, age[1001], dp[1001], mn[1001][1001], mx[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&mn[0][0], &mn[1000][1001], 1e9);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> age[i];
		for (int j = 1; j <= i; j++) {
			mn[j][i] = min(mn[j][i], min(mn[j][i - 1], age[i]));
			mx[j][i] = max(mx[j][i], max(mx[j][i - 1], age[i]));
		}
		for (int j = 0; j + 1 <= i; j++)
			dp[i] = max(dp[i], dp[j] + abs(mx[j + 1][i] - mn[j + 1][i]));
	}
	cout << dp[n];
	return 0;
}