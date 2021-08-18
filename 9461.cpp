#include <iostream>
using namespace std;
long long dp[101];

long long dynamic(int a) {
	if (a <= 0) return 0;
	if (dp[a] != 0)
		return dp[a];
	else dp[a] = dynamic(a - 1) + dynamic(a - 5);
	return dp[a];
}

int main() {
	int T, N;
	cin >> T;
	dp[0] = 0; dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2;
	for (int i = 0; i < T; i++) {
		cin >> N;
		if (N < 5) cout << dp[N] << "\n";
		else cout << dynamic(N) << "\n";
	}
	return 0;
}