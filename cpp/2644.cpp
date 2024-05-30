#include <bits/stdc++.h>
using namespace std;

int n, src, dst, m, x, y, dist[101][101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	fill(&dist[0][0], &dist[100][101], 1e9);
	cin >> n >> src >> dst >> m;
	while (m--) {
		cin >> x >> y;
		dist[x][y] = 1, dist[y][x] = 1;
	}
	[&]() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (dist[j][i] != 1e9 && dist[i][k] != 1e9)
						dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
				}
			}
		}
	}();
	if (dist[src][dst] == 1e9)
		cout << -1;
	else
		cout << dist[src][dst];
	return 0;
}