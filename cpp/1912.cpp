#include <bits/stdc++.h>
using namespace std;
int n, dp[100001], tmp;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		if (dp[i - 1] + tmp < tmp) dp[i] = tmp;
		else dp[i] = dp[i - 1] + tmp;
	}
	cout << *max_element(&dp[1], &dp[n + 1]);
}