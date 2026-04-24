#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, dist[501][501];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	fill(&dist[0][0], &dist[500][501], 1e9);
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		dist[a][b] = 1, dist[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) 
				continue;
			for (int k = 1; k <= n; k++) {
				if (i == k || j == k)
					continue;
				if (dist[j][i] != 1e9 && dist[i][k] != 1e9)
					dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	cout << [&]() {
		int cnt = 0;
		for (int i = 2; i <= n; i++) {
			if (dist[1][i] <= 2 || dist[i][1] <= 2)
				cnt++;
		}
		return cnt;
	}();
	return 0;
}