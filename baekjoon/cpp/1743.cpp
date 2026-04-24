#include <bits/stdc++.h>
using namespace std;

int N, M, K, R, C, arr[101][101], mx, tmp, visited[101][101];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
void dfs(int y, int x) {
	visited[y][x] = 1, tmp++;
	for (int i = 0; i < 4; i++) {
		int ddy = y + dy[i];
		int ddx = x + dx[i];

		if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M && !visited[ddy][ddx] && arr[ddy][ddx])
			dfs(ddy, ddx);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;
	while (K--) {
		cin >> R >> C;
		arr[R][C] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && arr[i][j]) {
				tmp = 0;
				dfs(i, j);
				mx = max(mx, tmp);
			}
		}
	}
	cout << mx;
	return 0;
}