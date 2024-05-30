#include <bits/stdc++.h>
using namespace std;

int N, dist[17][17], dp[17][1 << 17], ans, start, cnt, P;
string tmp;
int dynamic(int good, int visited) {
	if (dp[good][visited] != -1)
		return dp[good][visited];

	if (good >= P)
		return dp[good][visited] = 0;

	dp[good][visited] = 1e9;
	
	for (int i = 0; i < N; i++) {
		if (visited & 1 << i) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (!(visited & 1<<j))
					dp[good][visited] = min(
						dp[good][visited],
						dist[i][j] + dynamic(good + 1, visited | 1 << j)
						);
			}
		}
	}
	
	return dp[good][visited];
}
int main() {
	[&]() {
		memset(dp, -1, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
			cin >> dist[i][j];
		cin >> tmp;
		for (int i = 0; i < N; i++) {
			if (tmp[i] == 'Y')
				start |= 1 << i, cnt++;
		}
		cin >> P;
	}();
	ans = dynamic(cnt, start);
	ans == 1e9 ? cout << -1 : cout << ans;
	return 0;
}