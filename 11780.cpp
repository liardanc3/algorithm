#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
int dist[101][101], path[101][101];
vector<int> route[101][101];
int main() {
	[&]() {
		fill(&dist[0][0], &dist[100][101], 1e9 + 1);
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			if (dist[a][b] > c) {
				dist[a][b] = c;
				route[a][b].clear();
				route[a][b].push_back(a);
				route[a][b].push_back(b);
			}
		}
	}();
	[&]() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				for (int k = 1; k <= n; k++) {
					if (i == k || j == k) continue;
					if (dist[k][i] + dist[i][j] < dist[k][j]) {
						dist[k][j] = dist[k][i] + dist[i][j];

						route[k][j].clear();
						for (int s = 0; s < route[k][i].size(); s++) 
							route[k][j].push_back(route[k][i][s]);
						for (int s = 1; s < route[i][j].size(); s++) 
							route[k][j].push_back(route[i][j][s]);
					}
				}
			}
		}
	}();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || dist[i][j] == 1e9 + 1)
				cout << 0 << ' ';
			else
				cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << route[i][j].size() << ' ';
			for (int rt : route[i][j])
				cout << rt << ' ';
			cout << '\n';
		}
	}
	return 0;
}