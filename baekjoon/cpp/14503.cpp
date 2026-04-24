#include <bits/stdc++.h>
using namespace std;
int n, m, arr[51][51], r, c, d, cnt = 0;
int dy[]{ -1,0,1,0 }, dx[]{ 0,1,0,-1 };
void dfs(int y, int x, int direct) {
	if(arr[y][x]==0)
		cnt++;
	arr[y][x] = -1;
	// 2.a - 2.b
	for (int i = 0; i < 4; i++) {
		direct--;
		if (direct == -1) direct = 3;
		if (1 <= y + dy[direct] && y + dy[direct] <= n && 1 <= x + dx[direct] && x + dx[direct] <= m) {
			if (arr[y + dy[direct]][x + dx[direct]] == 0) {
				dfs(y + dy[direct], x + dx[direct], direct);
				return;
			}
		}
		if (i == 3) {
			int next_direct = direct;
			next_direct += 2;
			next_direct %= 4;
			x += dx[next_direct];
			y += dy[next_direct];
			if (1 <= y && y <= n && 1 <= x && x <= m) {
				if (arr[y][x] == 1)
					return;
				else
					i = -1;
			}
		}
	}
	return;
}
int main() {
	cin >> n >> m >> r >> c >> d;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		cin >> arr[i][j];
	dfs(r+1, c+1, d);
	cout << cnt;
	return 0;
}