#include <bits/stdc++.h>
using namespace std;
int coin[21], dp[10001], N, M, ans;

int ksp() {
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = coin[i]; j <= M; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	return dp[M];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) 
			cin >> coin[i];
		cin >> M;
		memset(dp, 0, sizeof(dp));
		cout << ksp() << '\n';
	}
	return 0;
}