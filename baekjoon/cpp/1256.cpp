#include <bits/stdc++.h>
#define MAX 1'000'000'000
using namespace std;
int n, m, k, dp[101][101];
int dynamic(int a, int z, int cnt) {
	if (a == 0 && z == 0) return dp[a][z] = 1;
	if (dp[a][z]) return dp[a][z];

	if (a > 0)
		dp[a][z] = min(MAX, dp[a][z] + dynamic(a - 1, z, cnt));
	
	if (z > 0) {
		if (a == 0)
			dp[a][z] = min(MAX, dp[a][z] + dynamic(a, z - 1, cnt));
		else
			dp[a][z] = min(MAX, dp[a][z] + dynamic(a, z - 1, cnt + 1));
	}	
	return dp[a][z];
}
int main() {
	cin >> n >> m >> k;
	if (k > dynamic(n, m, 1))
		cout << -1;
	else {
		string ans = "";
		while (n+m > 0) {
			int a_now = dp[n - 1][m];
			int z_now = dp[n][m - 1];

			if (n == 0) {
				for(int i=1; i<=m; i++)
					ans += "z";
				break;
			}
			else if (m == 0) {
				for(int i=1; i<=n; i++)
					ans += "a";
				break;
			}
			else if (k <= a_now) {
				ans += "a";
				n--;
			}
			else {
				k -= z_now;
				ans += "z";
				m--;
			}
		}
		cout << ans;
	}
	return 0;
}