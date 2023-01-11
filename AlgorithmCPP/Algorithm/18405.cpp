#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, k, arr[201][201], s, y, x;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
queue<pii> q[1001];
void bfs(int i) {
	int size = q[i].size();
	while (size--) {
		int y = q[i].front().first;
		int x = q[i].front().second;
		q[i].pop();

		for (int s = 0; s < 4; s++) {
			int ddy = y + dy[s];
			int ddx = x + dx[s];

			if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= n && !arr[ddy][ddx]) {
				arr[ddy][ddx] = arr[y][x];
				q[i].push({ ddy,ddx });
			}
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				q[arr[i][j]].push({ i,j });
		}
	}
	cin >> s >> y >> x;
	while (s--) {
		for (int i = 1; i <= 1000; i++) {
			if (!q[i].empty())
				bfs(i);
		}
	}
	cout << arr[y][x];
	return 0;
}