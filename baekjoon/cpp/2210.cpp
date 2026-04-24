#include <bits/stdc++.h>
using namespace std;

int arr[5][5], visited[5][5][100000];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
set<int> s;
void dfs(int y, int x, int now, int tick) {
	if (tick == 6) {
		s.insert(now);
		return;
	}
	if (visited[y][x][now] == 1)
		return;
	visited[y][x][now] == 1;
	for (int i = 0; i < 4; i++) {
		int ddy = y + dy[i];
		int ddx = x + dx[i];
		if (0 <= ddy && ddy < 5 && 0 <= ddx && ddx < 5)
			dfs(ddy, ddx, 10 * now + arr[ddy][ddx], tick+1);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			dfs(i, j, arr[i][j], 1);
	}
	for (int i : s)
		cout << i << '\n';
	cout << s.size();
	return 0;
}