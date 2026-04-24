#include <bits/stdc++.h>
using namespace std;
int N, total, dp[100001];
pair<int, int> pii[101];
int main() {
	int tr = 3;
	while (tr--) {
		memset(dp, 0, sizeof(dp));
		cin >> N;
		total = 0;
		for (int i = 1; i <= N; i++) {
			cin >> pii[i].first >> pii[i].second;
			total += (pii[i].first * pii[i].second);
		}
		if (total % 2 == 1) {
			cout << "0\n";
			continue;
		}
		dp[0] = 1;
		for (int i = 1; i <= N; i++) {
			int coin = pii[i].first;
			if (coin > (total / 2)) continue;
			int cnt = pii[i].second;
			for (int j = total / 2; j >= coin; j--) {
				if (dp[j - coin]) {
					for (int k = 0; j + k * coin <= total / 2 && k < cnt; k++) {
						dp[j + k * coin] = 1;
					}
				}
			}
		}
		cout << dp[total / 2] << '\n';
	}
	return 0;
}