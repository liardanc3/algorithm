#include <bits/stdc++.h>
#define DIV 9901
using namespace std;
int n, dp[100001][3];
int main() {
	dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1;
	dp[2][0] = 3, dp[2][1] = 2, dp[2][2] = 2;
	for (int i = 3; i <= 100000; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % DIV;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % DIV;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % DIV;
	}
	cin >> n;
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % DIV;
	return 0;
}