#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pii point[16];
int N;
double x, y, dist[16][16], dp[16][1<<16];
double TSP(int now, int visited) {
	if (dp[now][visited] != -1)
		return dp[now][visited];

	if (visited == (1 << N) - 1)
		return dist[now][0];

	dp[now][visited] = 1e9;

	for (int i = 0; i < N; i++) {
		if (!(visited & (1 << i)))
			dp[now][visited] = min(dp[now][visited], TSP(i, visited + (1<<i)) + dist[now][i]);
	}

	return dp[now][visited];
}
int main() {
	[&]() {
		cout << fixed;
		cout.precision(7);
		fill(&dp[0][0], &dp[15][1 << 16], -1);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			point[i] = { x,y };
		}
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				double d = sqrt(pow((point[i].first - point[j].first), 2) + pow((point[i].second - point[j].second), 2));
				dist[i][j] = d;
				dist[j][i] = d;
			}
		}
	}();
	cout << TSP(0, 1);
	return 0;
}