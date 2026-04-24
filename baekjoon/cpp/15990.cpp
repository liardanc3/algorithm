#include <bits/stdc++.h>
#define DIV 1'000'000'009
using namespace std;
int t, n, dp[100001][4];
int main() {
	//1 1 
	//1 2
	//3 1+2 2+1 3
	//3 1+2+1 1+3 3+1
	//4 2+1+2 2+3 3+2 1+3+1 
	//8 1+2+1+2 2+1+2+1 3+2+1 1+2+3 2+3+1 2+1+3 1+3+2 3+1+2 
	dp[1][1] = 1, dp[2][2] = 1, dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%DIV;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3])%DIV;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2])%DIV;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		cout << ((dp[n][1] + dp[n][2]) % DIV + dp[n][3]) % DIV << '\n';
	}
	return 0;
}