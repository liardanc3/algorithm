#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll dp[81]{ 0, }, DP[81]{ 0, };
	int N; cin >> N; N--;
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 80; i++) 
		dp[i] = dp[i - 1] + dp[i - 2];
	if (N == 0) cout << 4;
	else if (N == 1) cout << 6;
	else if (N == 2) cout << 10;
	else cout << 3 * dp[N] + 2 * dp[N - 1] + 2 * dp[N - 2] + dp[N - 3];
	return 0;
}