#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define INF 1e9
int arr[501][501];
int d[501][501];
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
int bfs() {
	queue<pii> q;
	q.push(pii(0, 0));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second; q.pop();
		int dist = d[y][x];
		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];
			if (ddy >= 0 && ddy <= 500 && ddx >= 0 && ddx <= 500 && arr[ddy][ddx] != -1) {
				int cost = dist + arr[ddy][ddx];

				if (cost < d[ddy][ddx]) {
					d[ddy][ddx] = cost;
					q.push(pii(ddy, ddx));
				}
			}
		}
	}
	return 0;
}

void input() {
	int N, M, x1, x2, y1, y2;
	cin >> N;
	while (N--) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++)
				arr[j][i] = 1;
		}
	}
	cin >> M;
	while (M--) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++)
				arr[j][i] = -1;
		}
	} arr[0][0] = 0;
}
int main() {
	fill(&d[0][0], &d[500][501], INF);
	d[0][0] = 0;
	input();
	bfs();
	if (d[500][500] == INF)
		cout << -1;
	else cout << d[500][500];
	return 0;
}