#include <bits/stdc++.h>
using namespace std;

int n, m, arr[301][301], tmp[301][301], mn = 0;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };

void melt() {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j]) {
				for (int k = 0; k < 4; k++) {
					int ddy = i + dy[k];
					int ddx = j + dx[k];

					if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= m && !arr[ddy][ddx])
						tmp[i][j]--;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] += tmp[i][j];
			if (arr[i][j] < 0) arr[i][j] = 0;
		}
	}
}
void dfs(int y, int x) {
	tmp[y][x] = 1;
	for (int k = 0; k < 4; k++) {
		int ddy = y + dy[k];
		int ddx = x + dx[k];
		if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= m && !tmp[ddy][ddx] && arr[ddy][ddx])
			dfs(ddy, ddx);
	}
}
bool check() {
	memset(tmp, 0, sizeof(tmp));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!tmp[i][j] && arr[i][j]) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	return cnt >= 2;
}
bool clear() {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		if (arr[i][j] != 0) return false;
	}
	return true;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		cin >> arr[i][j];
	for (int i = 1;; i++) {
		melt();
		if (check()) {
			cout << i;
			break;
		}
		if (clear()) {
			cout << 0;
			break;
		}
	}
	return 0;
}