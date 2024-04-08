#include <bits/stdc++.h>
#define DIV 1'000'000
using namespace std;
int n, dp[1001][3][4];
int dynamic(int day, int a, int b) {
	if (day > n || a==2 || b==3) return 0;
	if (dp[day][a][b]) return dp[day][a][b];

	// 출석
	dp[day][a][b] = (dp[day][a][b] + dynamic(day + 1, a, 0)) % DIV;
	// 지각
	dp[day][a][b] = (dp[day][a][b] + dynamic(day + 1, a + 1, 0)) % DIV;
	// 결석
	dp[day][a][b] = (dp[day][a][b] + dynamic(day + 1, a, b + 1)) % DIV;

	return dp[day][a][b] % DIV;
}
int main() {
	cin >> n;
	dp[n][0][0] = 1, dp[n][1][0] = 1;
	dp[n][0][1] = 1, dp[n][1][1] = 1;
	dp[n][0][2] = 1, dp[n][1][2] = 1;
	cout << dynamic(0,0,0);
	return 0;
}