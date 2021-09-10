#include <bits/stdc++.h>
using namespace std;
int n, c[5001], p[5001], dp[10001];
double m, tmp;
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	while (cin >> n >> m) {
		if (n == 0 && m == 0.00) break;
		for (int i = 1; i <= n; i++) {
			cin >> c[i]; cin >> tmp;
			p[i] = (int)(100 * tmp + 0.5);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = p[i]; j <= (int)(m * 100 + 0.5); j++) {
				dp[j] = max(dp[j], dp[j - p[i]] + c[i]);
			}
		}
		cout << dp[(int)(m * 100 + 0.5)] << '\n';
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}