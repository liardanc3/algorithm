#include <bits/stdc++.h>
#define DIV 1000000
using namespace std;
int n, dp[5001];
string inp;
int main() {
	cin >> inp;
	if (inp[0]=='0') {
		cout << 0;
		return 0;
	}
	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i <= inp.size(); i++) {
		int left = inp[i - 2] - '0';
		int right = inp[i - 1] - '0';

		if (left * 10 + right <= 26 && left)
			dp[i] = (dp[i] + dp[i - 2]) % DIV;

		if (right)
			dp[i] = (dp[i] + dp[i - 1]) % DIV;

		if (!dp[i]) {
			cout << 0;
			return 0;
		}
	}
	cout << dp[inp.size()] % DIV;
	return 0;
}