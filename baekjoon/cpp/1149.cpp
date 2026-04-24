#include <bits/stdc++.h>
using namespace std;
int RGB[1000][3]{ 0, }, dp[1000][3], n, tmp;
int dyn() {
	for (int i = 0; i < 3; i++)
		dp[0][i] = RGB[0][i];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1] + RGB[i][0], dp[i - 1][2] + RGB[i][0]);
		dp[i][1] = min(dp[i - 1][0] + RGB[i][1], dp[i - 1][2] + RGB[i][1]);
		dp[i][2] = min(dp[i - 1][0] + RGB[i][2], dp[i - 1][1] + RGB[i][2]);
	}
	return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++){
		for (int j = 0; j < 3; j++) {
			cin >> tmp;
			RGB[i][j] = tmp;
		}
	} cout << dyn();
	return 0;
}