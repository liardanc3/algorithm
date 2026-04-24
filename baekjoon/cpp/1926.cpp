#include <bits/stdc++.h>
using namespace std;

int arr[500][500], n, m, mx, visited[500][500], cnt, artcnt;;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
void dfs(int y, int x) {
	visited[y][x] = 1;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int ddy = y + dy[i];
		int ddx = x + dx[i];
		if (0 <= ddy && ddy < n && 0 <= ddx && ddx < m && !visited[ddy][ddx] && arr[ddy][ddx])
			dfs(ddy, ddx);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> arr[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j]) {
				cnt = 0;
				artcnt++;
				dfs(i, j);
				mx = max(mx, cnt);
			}
		}
	}

	cout << artcnt << '\n' << mx;
	return 0;
}