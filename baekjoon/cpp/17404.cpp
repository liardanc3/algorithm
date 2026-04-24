#include <bits/stdc++.h>
using namespace std;
int N;
int pay[1001][3];

int dynamic() {
	int mn = 1e9;
	int dp[1001][3];
	for (int k = 0; k < 3; k++) {
		fill(&dp[0][0], &dp[1000][3], 1e8);
		dp[1][k] = pay[1][k];

		for (int i = 2; i <= N; i++) {
			dp[i][0] = min(dp[i - 1][1] + pay[i][0], dp[i - 1][2] + pay[i][0]);
			dp[i][1] = min(dp[i - 1][0] + pay[i][1], dp[i - 1][2] + pay[i][1]);
			dp[i][2] = min(dp[i - 1][0] + pay[i][2], dp[i - 1][1] + pay[i][2]);
		}
		dp[N][k] = 1e8;
		
		mn = min(mn,min(dp[N][0], min(dp[N][1], dp[N][2])));
	}
	
	return mn;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> pay[i][j];
		}
	}

	cout << dynamic();

	return 0;
}