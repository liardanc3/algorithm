#include <bits/stdc++.h>
using namespace std;
int t, w, dp[1001][31][3], arr[1001], mx = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t >> w;
	for (int i = 1; i <= t; i++) 
		cin >> arr[i];
	dp[1][0][1] = (arr[1] == 1) ? 1 : 0; 
	dp[1][1][2] = (arr[1] == 2) ? 1 : 0;
	for (int i = 2; i <= t; i++) {
		int tree = arr[i];

		if (tree == 1) {
			// stop
			for (int j = 0; j <= i && j<=w; j++) {
				dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + 1);
				if(j!=0)
					dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][2]);
			}	
			// move
			for (int j = 1; j <= i && j<=w; j++) {
				if (j - 1 != 0)
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][2] + 1);
				dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][1]);
			}
		}

		if (tree == 2) {
			// stop
			for (int j = 0; j <= i && j<=w; j++) {
				dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1]);
				if(j!=0)
					dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][2] + 1);
			}
			// move
			for (int j = 1; j <= i && j<=w; j++) {
				if (j - 1 != 0)
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][2]);
				dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][1]+1);
			}
		}
	}
	for (int i = 0; i <= w; i++) {
		mx = max(mx, dp[t][i][1]);
		if (i != 0)
			mx = max(mx, dp[t][i][2]);
	}
	cout << mx;
	return 0;
}