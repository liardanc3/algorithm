#include <bits/stdc++.h>
#define DIV 1'000'000'000
using namespace std;
int n, dp[1000001];
int main() {
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 1000000; i++)
		dp[i] = i % 2 ? dp[i - 1] : (dp[i - 2] + dp[i / 2]) % DIV;
	cin >> n;
	cout << dp[n];
}