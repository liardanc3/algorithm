#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, num, k, arr[21], dp[21], visited[21];
signed main() {
	dp[1] = 1;
	for (int i = 2; i <= 20; i++)
		dp[i] = dp[i - 1] * i;
	cin >> n >> num;
	if (num == 1) {
		cin >> k;
		int len = n-1;
		while (k>1) {
			for (int i = 1; i <= n; i++) {
				if (visited[i]) continue;
				if (dp[len] < k)
					k-=dp[len];
				else {
					visited[i] = 1;
					cout << i << ' ';
					len--;
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) cout << i << ' ';
		}
	}
	else {
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		int ans = 1, len = n - 1, idx = 1;
		while (len) {
			for (int i = 1; i <= n; i++) {
				if (visited[i]) continue;
				if (arr[idx] == i) {
					len--;
					idx++;
					visited[i] = 1;
					break;
				}
				else 
					ans += dp[len];
			}
		}
		cout << ans;
	}

	return 0;
}