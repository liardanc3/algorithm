#include <bits/stdc++.h>
using namespace std;

int N, dist[16][16], dp[16][1 << 16];
int TSP(int now, int visited) {
	if (dp[now][visited] != -1)
		return dp[now][visited];

	if (visited == (1 << N) - 1) 
		return dist[now][0];

	int ret = 1e9;
	for (int i = 0; i < N; i++) {
		if (!(visited & (1 << i)) && dist[now][i] != 1e9)
			ret = min(ret, TSP(i, visited + (1 << i)) + dist[now][i]);
	}
	return dp[now][visited] = ret;
}
int main() {
	[&]() {
		fill(&dp[0][0], &dp[15][1 << 16], -1);
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> dist[i][j];
				if (i != j && dist[i][j] == 0)
					dist[i][j] = 1e9;
			}
		}
	}();
	cout << TSP(0, 1);
	return 0;
}