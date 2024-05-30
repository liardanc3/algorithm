#include <bits/stdc++.h>
using namespace std;
#define INF 1e8
typedef pair<int, int> pii;
int N, M;
int arr[1001][1001];
int d[2][1001][1001];
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
queue<pii> q;
int bfs() {
	while (!q.empty()) {
		pii now = q.front();
		int y = now.first;
		int x = now.second;
		q.pop();
		for (int j = 0; j < 4; j++) {
			int ddy = y + dy[j];
			int ddx = x + dx[j];

			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M) {
				if (arr[ddy][ddx] == 0) {
					int cost1 = d[0][y][x] + 1;
					int cost2 = d[1][y][x] + 1;
					if (cost1 < d[0][ddy][ddx]) {
						d[0][ddy][ddx] = cost1;
						q.push(pii(ddy, ddx));
					}
					if (cost2 < d[1][ddy][ddx]) {
						d[1][ddy][ddx] = cost2;
						if (cost1 >= d[0][ddy][ddx])
							q.push(pii(ddy, ddx));
					}
				}
				if (arr[ddy][ddx] == 1) {
					int cost1 = d[0][y][x] + 1;
					if (cost1 < d[0][ddy][ddx]) {
						d[1][ddy][ddx] = cost1;
						q.push(pii(ddy, ddx));
					}
				}
			}
		}
	}
	if (d[0][N][M] >= INF && d[1][N][M] >=INF)
		return -1;
	else return min(d[0][N][M],d[1][N][M]);
}

void input() {
	cin >> N >> M;
	string tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = tmp[j - 1] - '0';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	fill(&d[0][0][0], &d[1][1000][1001], INF);
	d[0][1][1] = 1;
	q.push(pii(1,1));
	cout << bfs();
	return 0;
}