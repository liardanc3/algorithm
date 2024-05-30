#include <bits/stdc++.h>	
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tii;
int w, h, dy[]{ -1,0,1,0 }, dx[]{ 0,-1,0,1 }, visited[5][101][101];
pii src;
char arr[101][101];
string tmp;
void bfs() {
	priority_queue<tii, vector<tii>, greater<tii>> pq;
	pq.push({ 0,src.first,src.second, 4 });
	memset(visited, 0x3f, sizeof visited);
	visited[4][src.first][src.second] = 0;
	while (!pq.empty()) {
		int y = get<1>(pq.top());
		int x = get<2>(pq.top());
		int dist = get<0>(pq.top());
		int direct = get<3>(pq.top());
		pq.pop();

		//cout << y << ' ' << x << ' ' << dist << ' ' << direct << '\n';
		if (arr[y][x] == 'C' && direct != 4 && (y!=src.first || x!=src.second)) {
			cout << dist;
			exit(0);
		}

		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];

			if (1 <= ddy && ddy <= h && 1 <= ddx && ddx <= w && arr[ddy][ddx] != '*') {
				if (direct != 4 && direct % 2 != i % 2 && dist + 1 < visited[i][ddy][ddx]) {
					pq.push({ dist + 1,ddy,ddx,i });
					visited[i][ddy][ddx] = dist + 1;
				}
				else if (direct ==4 || (direct %2 == i%2 && dist < visited[i][ddy][ddx])) {
					pq.push({ dist,ddy,ddx,i });
					visited[i][ddy][ddx] = dist;
				}
			}
		}
	}
}

int main() {
	[&]() {
		cin >> w >> h;
		for (int i = 1; i <= h; i++) {
			cin >> tmp;
			for (int j = 1; j <= w; j++)
				arr[i][j] = tmp[j - 1];
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (arr[i][j] == 'C') {
					src.first = i;
					src.second = j;
					break;
				}
			}
		}
	}();

	bfs();
	return 0;
}