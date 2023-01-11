#include <bits/stdc++.h>	
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tii;
int w, h, dy[]{ -1,0,1,0 }, dx[]{ 0,-1,0,1 }, visited[101][101];
pii src;
char arr[101][101];
string tmp;
void bfs() {
	priority_queue<tii, vector<tii>, greater<tii>> pq;
	pq.push({ 0,src.first,src.second, -1});
	while (!pq.empty()) {
		int y = get<1>(pq.top());
		int x = get<2>(pq.top());
		int dist = get<0>(pq.top());
		int direct = get<3>(pq.top());
		pq.pop();

		if (arr[y][x] == 'C' && direct!=-1) {
			cout << dist;
			exit(0);
		}

		visited[y][x] = 1;

		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];

			if (1 <= ddy && ddy <= h && 1 <= ddx && ddx <= w && !visited[ddy][ddx]&& arr[ddy][ddx]!='*') {
				if (direct != -1 && direct % 2 != i % 2)
					pq.push({ dist + 1,ddy,ddx,i });
				else
					pq.push({ dist,ddy,ddx,i });
			}
		}
	}
}

int main() {
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
	bfs();
	return 0;
}