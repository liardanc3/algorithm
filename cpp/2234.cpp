#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[51][51][5], visited[51][51], dy[]{ 0,-1,0,1 }, dx[]{ -1,0,1,0 }, rmx, mx, rcnt, num[51][51], n;
void bfs(int i, int j) {
	visited[i][j] = 1;
	queue<pii> q;
	vector<pii> vect;
	q.push({ i,j });
	vect.push_back({ i,j });
	int cnt = 1;
	while (!q.empty()) {
		pii now = q.front(); q.pop();

		int y = now.first;
		int x = now.second;

		for (int k = 0; k < 4; k++) {
			int ddy = y + dy[k];
			int ddx = x + dx[k];

			if (arr[y][x][k]) continue;
			
			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M && !visited[ddy][ddx]) {
				cnt++;
				q.push({ ddy,ddx });
				vect.push_back({ ddy,ddx });
				visited[ddy][ddx] = 1;
			}
		}
	}
	for (pii p : vect) {
		arr[p.first][p.second][4] = cnt;
		num[p.first][p.second] = n;
	}
		
	rmx = max(rmx, cnt);
}
void init() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++)
		cin >> arr[i][j][4];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 4; k++) {
				if (arr[i][j][4] & (1 << k))
					arr[i][j][k] = 1;
			}
		}
	}
}
int main() {
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j]) {
				n++;
				rcnt++;
				bfs(i, j);
			}
		}
	}
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			for (int k = 0; k < 4; k++) {
				int ddy = y + dy[k];
				int ddx = x + dx[k];

				if (1<=ddy&&ddy<=N&&1<=ddx&&ddx<=M&&num[y][x] != num[ddy][ddx]) 
					mx = max(mx, arr[y][x][4] + arr[ddy][ddx][4]);
			}
		}
	}
	cout << rcnt << '\n' << rmx << '\n' << mx;
	return 0;
}