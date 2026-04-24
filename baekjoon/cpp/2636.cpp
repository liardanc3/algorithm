#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int r, c, arr[101][101], visited[101][101];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };

pii solve() {
	int t = -1, cnt = 0, bcnt = 0;
	while (1) {
		bcnt = 0;
		memset(visited, 0, sizeof(visited));
		t++;
		queue<pii> q;
		q.push({ 1,1 });
		visited[1][1] = 1;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int ddy = y + dy[k];
				int ddx = x + dx[k];

				if (1 <= ddy && ddy <= r && 1 <= ddx && ddx <= c && !visited[ddy][ddx]) {
					visited[ddy][ddx] = 1;

					if (arr[ddy][ddx]) {
						bcnt++;
						arr[ddy][ddx] = 0;
					}
					else
						q.push({ ddy,ddx });
				}
			}
		}
		if (!bcnt) 
			return { t,cnt };
		else cnt = bcnt;
	}
}
void init() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++)
		cin >> arr[i][j];
}
int main() {
	init();
	pii p = solve();
	cout << p.first << '\n' << p.second;
	return 0;
}