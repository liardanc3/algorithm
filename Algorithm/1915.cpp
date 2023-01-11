#include <bits/stdc++.h>
using namespace std;
int n, m, arr[1001][1001], dp[1001][1001], mx = 0;
int dx[]{ 1,0,1 }, dy[]{ 0,1,1 };
string tmp;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		for (int j = 1; j <= m; j++)
			arr[i][j] = tmp[j - 1]-'0';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j])
				dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
			mx = max(mx, dp[i][j]);
		}
	}
	cout << mx * mx;
	return 0;
}