#include <iostream>
using namespace std;

int min(int a, int b, int c) {
	int ret = a;
	if (b < ret) ret = b;
	if (c < ret) ret = c;
	return ret;
}

int main() {
	int X; cin >> X;
	int* dp = new int[X+1] {0, };
	if (X >= 2) dp[2] = 1;
	for (int i = 3; i <= X; i++) {
		if (i % 3 == 0 && i % 2 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i / 2] + 1, dp[i - 1] + 1);
		else if (i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1,dp[i-1] + 1);
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2] +1, dp[i - 1] + 1,dp[i-1] + 1);
		else
			dp[i] = dp[i - 1] + 1;
	}
	cout << dp[X];
	return 0;
}