#include <bits/stdc++.h>
#define DIV 1'000'000'000
using namespace std;
int N, K, dp[201][201];
int main() {
	for (int i = 0; i < 201; i++)
		dp[i][1] = 1;
	cin >> N >> K;
	for (int k = 0; k <= N; k++) {
		for (int i = 2; i <= K; i++) {
			for (int j = 0; j <= N; j++) {
				int next = k + j;
				if (k + j <= N) {
					dp[k + j][i] += (dp[k][i - 1]);
					dp[k + j][i] %= DIV;
				}
			}
		}
	}
	cout << dp[N][K];
	return 0;
}