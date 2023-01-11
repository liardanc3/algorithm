#include <bits/stdc++.h>
#define DIV 10'007
using namespace std;
int n, dp[1001][10], sum = 0;
int main() {
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++)
				dp[i][k] = (dp[i][k] + dp[i - 1][j]) % DIV;
		}
	}
	cin >> n;
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n][i]) % DIV;
	cout << sum;
	return 0;
}