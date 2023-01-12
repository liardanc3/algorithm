#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
char arr[8][8];
string tmp;
int visited[8][8];
int dy[]{ -1,-1,-1,0,0,0,1,1,1 }, dx[]{ -1,0,1,-1,0,1,-1,0,1 };
void bfs() {
	queue<pii> q;
	q.push({ 7,0});
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (arr[y][x] == '#') continue;

			for (int i = 0; i < 9; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (ddy == 0 && ddx == 7) {
					cout << 1;
					return;
				}
				if (0 <= ddy && ddy < 8 && 0 <= ddx && ddx < 8 && arr[ddy][ddx]=='.') {
					q.push({ ddy,ddx });
				}
			}
		}
		for (int i = 7; i > 0; i--) {
			for (int j = 0; j < 8; j++) {
				arr[i][j] = arr[i - 1][j];
			}
		}
		for (int i = 0; i < 8; i++)
			arr[0][i] = '.';
	}
	cout << 0;
	return;
}
int main() {
	for (int i = 0; i < 8; i++) {
		cin >> tmp;
		for (int j = 0; j < 8; j++)
			arr[i][j] = tmp[j];
	}
	bfs();
	return 0;
}