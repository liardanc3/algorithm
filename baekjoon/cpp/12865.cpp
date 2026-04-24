#include <bits/stdc++.h>
using namespace std;
int N, K;
int dp[100001];
int w[101], v[101];
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) 
		cin >> w[i] >> v[i];
	for (int i = 1; i <= N; i++) {
		for (int j = K; j >=1; j--) {
			if (w[i] <= j)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[K];
	return 0;
}