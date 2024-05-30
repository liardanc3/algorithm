#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int N, M, Hy, Hx, Ey, Ex, arr[1001][1001], visited[2][1001][1001], cnt = -1;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
int bfs() {
	queue<pip> q;
	q.push({ 0,{Hy,Hx} });
	visited[0][Hy][Hx] = 1;
	while (!q.empty()) {
		int sz = q.size(); cnt++;
		while (sz--) {
			int magic = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;

			q.pop();

			if (y == Ey && x == Ex)
				return cnt;

			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M) {
					if (Ey == ddy && Ex == ddx)
						return cnt + 1;

					if (arr[ddy][ddx] && magic == 0) {
						if (!visited[1][ddy][ddx]) {
							q.push({ 1,{ddy,ddx} });
							visited[1][ddy][ddx] = 1;
						}
					}

					if (!arr[ddy][ddx] && !visited[magic][ddy][ddx]) {
						q.push({ magic,{ddy,ddx} });
						visited[magic][ddy][ddx] = 1;
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> Hy >> Hx >> Ey >> Ex;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
	cout << bfs();
	return 0;
}