#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int arr[201][201], visited[201][201], r1, c1, r2, c2, cnt, n;
int dy[]{ -2,-2,0,0,2,2 }, dx[]{ -1,1,-2,2,-1,1 };
int main() {
	cin >> n >> r1 >> c1 >> r2 >> c2;
	queue<pii> q;
	q.push({ r1,c1 });
	visited[r1][c1] = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int s = 0; s < size; s++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == r2 && x == c2) {
				cout << cnt;
				return 0;
			}

			for (int i = 0; i < 6; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (0 <= ddy && ddy <= n && 0 <= ddx && ddx <= n && !visited[ddy][ddx]) {
					visited[ddy][ddx] = 1;
					q.push({ ddy,ddx });
				}
			}
		}
		cnt++;
	}
	cout << -1;
	return 0;
}