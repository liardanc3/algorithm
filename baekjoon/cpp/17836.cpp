#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, t, arr[101][101], visited[101][101];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
void bfs() {
	int mn = 1e9;
	queue<pii> q;
	q.push({ 1,1 });
	visited[1][1] = 1;
	int kt = 0;
	while (!q.empty() && kt <= t+1) {
		kt++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			pii now = q.front(); q.pop();
			int y = now.first;
			int x = now.second;

			for (int j = 0; j < 4; j++) {
				int ddy = y + dy[j];
				int ddx = x + dx[j];

				if (y == n && x == m) {
					cout << min(kt, mn);
					return;
				}

				if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= m) {
					if (arr[ddy][ddx]==2)
						mn = min(mn, kt + (n - ddy) + (m - ddx));
					else if (!visited[ddy][ddx] && arr[ddy][ddx] == 0) {
						visited[ddy][ddx] = 1;
						q.push({ ddy,ddx });
					}
					
				}
			}
		}
	}
	if (mn > t) cout << "Fail";
	else cout << mn;
}
int main() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		cin >> arr[i][j];
	bfs();
	return 0;
}