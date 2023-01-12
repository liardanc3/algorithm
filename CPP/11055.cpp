#include <bits/stdc++.h>
using namespace std;
int n, arr[1001], dp[1001];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}
	cout << *max_element(&dp[0], &dp[1001]);
	return 0;
}