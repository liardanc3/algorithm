#include <bits/stdc++.h>
using namespace std;
int N, dp[1001];
int main() {
	cin >> N;
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i <= 1000; i++) {
		if (min(dp[i - 1], min(dp[i - 3], dp[i - 4])) == 0)
			dp[i] = 1;
		else dp[i] = 0;
	}
	if (dp[N]) cout << "SK";
	else cout << "CY";
	return 0;
}