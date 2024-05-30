#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> coins;

int N, M, mn = 11, yy1, x1, y2, x2, visited[21][21][21][21];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
char arr[21][21];

void bfs() {
	queue<coins> q;
	q.push(coins(pii(yy1, x1), pii(y2, x2)));
	visited[yy1][x1][y2][x1] = 1;

	int cnt = -1;
	while (!q.empty() && cnt < 10) {
		cnt++;
		int sz = q.size();

		for (int i = 0; i < sz; i++) {
			int _y1 = q.front().first.first;
			int _x1 = q.front().first.second;

			int _y2 = q.front().second.first;
			int _x2 = q.front().second.second;

			q.pop();

			bool coin1drop = false;
			bool coin2drop = false;

			if (_y1 <= 0 || _y1 > N || _x1 <= 0 || _x1 > M)
				coin1drop = true;
			if (_y2 <= 0 || _y2 > N || _x2 <= 0 || _x2 > M)
				coin2drop = true;


			// 둘다떨어진 상태면 스킵
			if (coin1drop && coin2drop) continue;

			// 하나만떨어진 상태면 종료
			if (coin1drop || coin2drop) {
				cout << cnt;
				return;
			}

			// 둘다안떨어지면 위치변경
			for (int k = 0; k < 4; k++) {
				int dy1 = _y1 + dy[k];
				int dx1 = _x1 + dx[k];

				int dy2 = _y2 + dy[k];
				int dx2 = _x2 + dx[k];

				if (visited[dy1][dx1][dy2][dx2]) continue;

				if (arr[dy1][dx1] == '#')
					dy1 -= dy[k], dx1 -= dx[k];
				if (arr[dy2][dx2] == '#')
					dy2 -= dy[k], dx2 -= dx[k];

				q.push({ {dy1,dx1},{dy2,dx2} });
				visited[dy1][dx1][dy2][dx2] = 1;
			}
		}
	}

	cout << -1;
	return;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				if (yy1 == 0) yy1 = i, x1 = j;
				else y2 = i, x2 = j;
			}
		}
	}
	bfs();
	return 0;
}