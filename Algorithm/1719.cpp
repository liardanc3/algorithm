#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, dist[201][201], ans[201][201];
int main() {
	fill(&dist[0][0], &dist[200][201], 1e9);
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
		ans[a][b] = b;
		ans[b][a] = a;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			for (int k = 1; k <= n; k++) {
				if (i == k || j == k) continue;
				if (dist[j][i] == 1e9 || dist[i][k] == 1e9) continue;
				if (dist[j][i] + dist[i][k] < dist[j][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
					ans[j][k] = ans[j][i];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}