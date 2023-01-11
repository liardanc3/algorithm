#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, M, dist[18][18], a, b, c, dp[18][1 << 18], ans, path[18][1<<18][18];

int TSP(int now, int visited, int depth) {
	if (dp[now][visited] != -1)
		return dp[now][visited];

	if (visited == (1 << N) - 1) {
		path[now][visited][depth] = now + 1;
		return dist[now][0];
	}
		
	dp[now][visited] = 1e9;
	for (int i = 0; i < N; i++) {
		if (!(visited & (1 << i)) && dist[now][i] != 1e9) {
			int nxt = dist[now][i];
			int tsp = TSP(i, visited + (1 << i), depth + 1);
			if (tsp != 1e9) {
				if (dp[now][visited] > max(nxt, tsp)) {
					dp[now][visited] = max(nxt, tsp);
					copy(&path[i][visited + (1 << i)][0], &path[i][visited + (1 << i)][18], &path[now][visited][0]);
					path[now][visited][depth] = now + 1;
				}
			}
		}
	}

	return dp[now][visited];
}

int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		memset(dp, -1, sizeof(dp));
		fill(&dist[0][0], &dist[17][18], 1e9);
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			dist[a - 1][b - 1] = c;
		}
	}();
	ans = TSP(0, 1, 0);
	ans == 1e9 ? cout << -1 : cout << ans << '\n';
	if (ans != 1e9) {
		for (int i = 0; i < N; i++)
			cout << path[0][1][i] << ' ';
	}
	return 0;
}