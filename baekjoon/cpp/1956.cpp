#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
int V, E, a, b, c, dist[401][401], mn = 1e9;

signed main() {
	fill(&dist[0][0], &dist[400][401], 1e9);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}

	for (int i = 1; i <= V; i++) 
		mn = min(mn, dist[i][i]);

	if (mn == 1e9) cout << -1;
	else cout << mn;
	return 0;
}