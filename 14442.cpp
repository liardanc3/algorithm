#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;

int N, M, K, arr[1001][1001], visited[1001][1001][11];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
string tmp;

void bfs() {
	queue<tii> q;
	q.push({ 1,1,0 });
	visited[1][1][0] = 1;
	int cnt = -1;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();
		while (sz--) {
			int y = get<0>(q.front());
			int x = get<1>(q.front());
			int k = get<2>(q.front());

			q.pop();

			if (y == N && x == M) {
				cout << cnt+1;
				return;
			}

			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M) {
					if (k+1<=K && arr[ddy][ddx] == 1 && !visited[ddy][ddx][k+1]) {
						visited[ddy][ddx][k + 1] = 1;
						q.push({ ddy,ddx,k + 1 });
					}
					if (arr[ddy][ddx] == 0 && !visited[ddy][ddx][k]) {
						visited[ddy][ddx][k] = 1;
						q.push({ ddy,ddx,k });
					}
				}
			}
		}
	}
	cout << -1;
	return;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= M; j++)
			arr[i][j] = tmp[j - 1] - '0';
	}
	if (N == 0 && M == 0)
		cout << 0;
	else 
		bfs();
	return 0;
}