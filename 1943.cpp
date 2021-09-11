#include <bits/stdc++.h>
using namespace std;
int N, tmp1, tmp2, total;
int dp[50001];
typedef pair<int, int> pii;
pii q[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 3; i++) {
		memset(dp, 0, sizeof(dp));
		cin >> N;
		total = 0;
		for (int j = 1; j <= N; j++) {
			cin >> q[j].first >> q[j].second;
			total += q[j].first * q[j].second;
		}
		if (total % 2 == 1) {
			cout << 0 << '\n';
			continue;
		}

		dp[0] = 1;
		for (int j = 1; j <= N; j++) {
			int coin = q[j].first;
			int cnt = q[j].second;
			for (int s = total/2; s >= coin; s--) {
				if (dp[s - coin] != 0) {
					for (int k = 0; k < cnt && s + k * coin <= total/2; k++)
						dp[s + k * coin] = 1;
				}
			}
		}
		if (dp[total / 2] != 0)
			cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}