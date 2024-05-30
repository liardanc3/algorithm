#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, M, K, arr[21][21], dy[]{ -1,0,1,0 }, dx[]{ 0,1,0,-1 }, d = 1, y = 1, x = 1, ans;
int dice[]{ 2,4,1,3,5,6 } , tmp[6], visited[21][21];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	[&]() {
		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++)
				cin >> arr[i][j];
		}
	}();
	while (K--) {
		// step 1
		int ddy = y + dy[d];
		int ddx = x + dx[d];

		if (ddy<1 || ddy>N || ddx<1 || ddx>M) {
			ddy = y - dy[d], ddx = x - dx[d];
			d = (d + 2) % 4;
		}
		
		[&]() {
			copy(&dice[0], &dice[6], &tmp[0]);
			if (d == 0) {
				dice[0] = tmp[2], dice[1] = tmp[1], dice[2] = tmp[4];
				dice[3] = tmp[3], dice[4] = tmp[5], dice[5] = tmp[0];
			}
			else if (d == 1) {
				dice[0] = tmp[0], dice[1] = tmp[5], dice[2] = tmp[1];
				dice[3] = tmp[2], dice[4] = tmp[4], dice[5] = tmp[3];
			}
			else if (d == 2) {
				dice[0] = tmp[5], dice[1] = tmp[1], dice[2] = tmp[0];
				dice[3] = tmp[3], dice[4] = tmp[2], dice[5] = tmp[4];
			}
			else {
				dice[0] = tmp[0], dice[1] = tmp[2], dice[2] = tmp[3];
				dice[3] = tmp[5], dice[4] = tmp[4], dice[5] = tmp[1];
			}
		}();

		// step 2
		memset(visited, 0, sizeof(visited));
		[&]() {
			queue<pii> q;
			q.push({ ddy,ddx });
			visited[ddy][ddx] = 1;
			while (!q.empty()) {
				int ny = q.front().first;
				int nx = q.front().second;
			
				q.pop();

				if (arr[ny][nx] == arr[ddy][ddx])
					ans += arr[ddy][ddx];

				for (int i = 0; i < 4; i++) {
					int nny = ny + dy[i];
					int nnx = nx + dx[i];

					if (1 <= nny && nny <= N && 1 <= nnx && nnx <= M && arr[nny][nnx] == arr[ddy][ddx] && !visited[nny][nnx]) {
						visited[nny][nnx] = 1;
						q.push({ nny,nnx });
					}
				}
			}
		}();
	
		// step 3
		int A = dice[5];
		int B = arr[ddy][ddx];
		if (A > B) 
			d = (d + 1) % 4;
		else if (A < B) 
			d = (d - 1) == -1 ? 3 : d - 1;
		y = ddy, x = ddx;
	}
	cout << ans;
	return 0;
}