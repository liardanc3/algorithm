#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp[4000][4000], mx = 0;
int main() {
	cin >> a >> b;
	if (a[0] == b[0]) dp[0][0] = 1;
	if (a[0] == b[1]) dp[0][1] = 1;
	if (a[1] == b[0]) dp[1][0] = 1;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				if (j == 0 || i==0) dp[i][j] = max(dp[i][j], 1);
				else dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
			mx = max(mx, dp[i][j]);
		}
	}
	cout << mx;
	return 0;
}