#include <bits/stdc++.h>
using namespace std;
int n, m, cycle, dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
char visited[4][101][101], arr[101][101], ck[101][101];
int edge(int e) {
	if (e == 0) return 3;
	if (e == 1) return 2;
	if (e == 2) return 1;
	if (e == 3) return 0;
}
void dfs(int y, int x, char ch) {
	ck[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ddy = y + dy[i];
		int ddx = x + dx[i];

		if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= m && arr[ddy][ddx]==ch) {
			if (!visited[i][y][x] && !visited[edge(i)][ddy][ddx]) {
				if (ck[ddy][ddx]) {
					cout << "Yes";
					exit(0);
				}
				visited[i][y][x] = 1;
				visited[edge(i)][ddy][ddx] = 1;
				dfs(ddy, ddx, ch);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j++)
		cin >> arr[i][j];
	for (int i = 1; i <= n&& !cycle; i++) {
		for (int j = 1; j <= m && !cycle; j++) {
			for (int k = 0; k < 4 && !cycle; k++) {
				int ddy = i + dy[k];
				int ddx = j + dx[k];
				if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= m && !visited[k][i][j] && !visited[edge(k)][ddy][ddx]) {
					if (arr[i][j] == arr[ddy][ddx]) {
						ck[i][j] = 1;
						visited[k][i][j] = 1;
						visited[edge(k)][ddy][ddx] = 1;
						dfs(ddy, ddx, arr[i][j]);
					}
				}
			}
		}
	}
	cout << "No";
	return 0;
}