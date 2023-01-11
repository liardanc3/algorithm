#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tp;
queue<tp> Q;
int H, N, M, z, y, x, tmp, box[100][100][100], ck[100][100][100];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,0,0,-1,1 };
int dz[] = { 0,0,-1,1,0,0 };
int bfs() {
	int cnt = -1;
	while (!Q.empty()) {
		cnt++;
		int size = Q.size();
		for (int m = 0; m < size; m++) {
			tp tmp = Q.front(); Q.pop();
			for (int i = 0; i < 6; i++) {
				z = get<0>(tmp) + dz[i];
				y = get<1>(tmp) + dy[i];
				x = get<2>(tmp) + dx[i];
				if (z<0 || z>=H || y<0 || y>=N || x<0 || x>=M) continue;
				else {
					if (box[z][y][x] == 0 && ck[z][y][x] == 0) {
						box[z][y][x] = 1; ck[z][y][x] = 1; Q.push(tp(z, y, x));
					}
				}
			}
		}
	}
	int ans = cnt; bool zero = false;
	for (int i = 0; i < H; i++)
	for (int j = 0; j < N; j++)
	for (int k = 0; k < M; k++)
	box[i][j][k] == 0 ? zero = true : 0;
	zero ? ans = -1 : 0;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tmp; box[i][j][k] = tmp;
				if (tmp == 1) {
					Q.push(tp(i, j, k));
					ck[i][j][k] = 1;
				}
			}
		}
	}
	cout << bfs();
	return 0;
}