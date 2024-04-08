#include <bits/stdc++.h>
using namespace std;
int n, k, dp[10001], coin[101];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		if (coin[i] > 10000) continue;
		dp[coin[i]]++;
		for (int j = coin[i]; j <= k; j++) {
			if (dp[j - coin[i]])
				dp[j]+=dp[j-coin[i]];
		}
	}	
	cout << dp[k];
	return 0;
}