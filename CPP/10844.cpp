#include <bits/stdc++.h>
#define DIV 1'000'000'000
using namespace std;
int n, dp[101][10], sum = 0;
int main() {
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= 100; i++) {
		dp[i][0] = dp[i-1][1];
		for (int j = 1; j <= 8; j++) 
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % DIV;
		dp[i][9] = dp[i-1][8];
	}
	cin >> n;
	for (int i = 0; i <= 9; i++)
		sum = (sum + dp[n][i]) % DIV;
	cout << sum;
	return 0;
}