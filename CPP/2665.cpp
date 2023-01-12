#include <bits/stdc++.h>
#define INF 999999999
using namespace std;
typedef pair<int, int> pii;
int N; string tmp;
int arr[51][51], d[51][51];
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
queue<pii> q;
int bfs() {
	d[1][1] = 0;
	q.push(pii(1, 1));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];
			if (ddy >= 1 && ddy <= N && ddx >= 1 && ddx <= N) {
				if (d[y][x] + arr[ddy][ddx] < d[ddy][ddx]) {
					d[ddy][ddx] = d[y][x] + arr[ddy][ddx];
					q.push(pii(ddy, ddx));
				}
			}
		}
	}
	return d[N][N];
}

int main() {
	fill(&d[0][0], &d[50][51], INF);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= N; j++) 
			arr[i][j] = ((tmp[j - 1] - '0')+1)%2;
	}
	cout << bfs();
	return 0;
}