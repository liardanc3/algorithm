#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int r, c, dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 }, sy, sx, by, bx, visited[51][51];
char arr[51][51], tmp[51][51];

void spread() {
	copy(&arr[0][0], &arr[50][51], &tmp[0][0]);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] == 'X' || arr[i][j] == 'D' || arr[i][j] == '*') continue;
			for (int k = 0; k < 4; k++) {
				int ddy = i + dy[k];
				int ddx = j + dx[k];
				if (1 <= ddx && ddx <= c && 1 <= ddy && ddy <= r && arr[ddy][ddx] == '*') {
					tmp[i][j] = '*';
					break;
				}
			}
		}
	}
	copy(&tmp[0][0], &tmp[50][51], &arr[0][0]);
}
void bfs() {
	queue<pii> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;
	int t = -1;
	while (!q.empty()) {
		t++;
		spread();
		int size = q.size();
		for (int k = 0; k < size; k++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == by && x == bx) {
				cout << t;
				return;
			}
			
			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (1 <= ddy && ddy <= r && 1 <= ddx && ddx <= c && 
					arr[ddy][ddx] != 'X' && arr[ddy][ddx] != '*' && !visited[ddy][ddx]) {
					visited[ddy][ddx] = 1;
					q.push({ ddy,ddx });
				}
			}
		}
	}
	cout << "KAKTUS";
	return;
}
int main() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				sy = i, sx = j;
				arr[i][j] = '.';
			}
			if (arr[i][j] == 'D')
				by = i, bx = j;
		}
	}
	bfs();
	return 0;
}