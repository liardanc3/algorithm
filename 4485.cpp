#include <bits/stdc++.h>
using namespace std;
#define INF 999999999
typedef pair<int, int> pii;
int N, ans, tmp1, tmp2, tmp3;
int arr[126][126];
int d[126][126];
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
int bfs() {
	queue<pii> q;
	q.push(pii(1, 1));
	d[1][1] = arr[1][1];
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ans = 1;
	while (cin >> N) {
		if (N == 0) break;
		fill(&d[0][0], &d[125][126], INF);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
			}
		}
		cout << "Problem " << ans++ << ": " << bfs() << '\n';
	}
	return 0;
}