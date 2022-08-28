#include <bits/stdc++.h>
using namespace std;
int TC, n, m, arr[50][50], visited[50][50], y = -1, x = -1;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
string str;
int dfs(int r, int c, int flag) {
	if (arr[r][c] != 2 && arr[r][c] != flag)
		return 1;
	int ret = 0;
	for (int i = 0; i < 4 && !ret; i++) {
		int ddy = r + dy[i];
		int ddx = c + dx[i];

		if (0 <= ddy && ddy < n && 0 <= ddx && ddx < m && !visited[ddy][ddx]) {
			visited[ddy][ddx] = 1;
			ret = max(ret, dfs(ddy, ddx, !flag));
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		[&]() {
			memset(arr, 0, sizeof(arr));
			memset(visited, 0, sizeof(visited));
			cin >> n >> m;
			for (int i = 0; i < n; i++) {
				cin >> str;
				for (int j = 0; j < m; j++) {
					arr[i][j] = str[j] == '#' ? 1 : str[j] == '.' ? 0 : 2;
					if (arr[i][j] != 2)
						y = i, x = j;
				}
			}
			cout << '#' << i << ' ';
			if (y == -1 && x == -1)
				cout << "possible\n";
			else {
				visited[y][x] = 1;
				dfs(y, x, arr[y][x]) ? cout << "impossible\n" : cout << "possible\n";
			}
		}();
	}
	return 0;
}