#include <bits/stdc++.h>
using namespace std;
int arr[3001][3001], r, c, h, w, dp[3001][3001];
void solve() {
	int mn = 1e9, mx = 0;
	cin >> r >> c >> h >> w;
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) {
		cin >> arr[i][j];
		mn = min(arr[i][j], mn);
		mx = max(arr[i][j], mx);
	}
	int left = mn, right = mx, ans=0;

	// O(log(n^2))
	while (left <= right) {
		int mid = (left + right) / 2;
		bool flag = true;

		// O(n^2)
		memset(dp, 0, sizeof(dp));
		for (int y = 1; y <= r; y++) {
			for (int x = 1; x <= c; x++) {
				int cnt = 0;
				if (arr[y][x] > mid)
					cnt = 1;
				else if (arr[y][x] < mid)
					cnt = -1;
				dp[y][x] = cnt - dp[y - 1][x - 1] + dp[y][x - 1] + dp[y - 1][x];
				
				if (y >= h && x >= w) {
					int now = dp[y][x] - dp[y - h][x] - dp[y][x - w] + dp[y - h][x - w];
					if (now == 0) {
						ans = mid;
						flag = false;
					}
					if (now < 0) {
						flag = false;
						y = 1e9; break;
					}
				}
			}
		}
		if (flag) 
			left = mid + 1;
		else 
			right = mid - 1;
	}
	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}