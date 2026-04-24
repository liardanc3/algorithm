#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, tmp, sum = 0, dp[1001], cnt = 0;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		sum = (sum + tmp) % m;
		cnt += (++dp[sum] - 1);
		if (!sum) cnt++;
	}
	cout << cnt;
	return 0;
}