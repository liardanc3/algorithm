#include <bits/stdc++.h>
using namespace std;
int L, R, C, visited[31][31][31], sL, sR, sC;
int dl[]{ 1,0,0,0,0,-1 }, dr[]{ 0,-1,0,0,1,0 }, dc[]{ 0,0,-1,1,0,0 };
char arr[31][31][31];
string tmp;
struct point {
	int x, y, z;
	point(int xx, int yy, int zz) {
		x = xx;
		y = yy;
		z = zz;
	}
};
void bfs() {
	int t = 0;
	queue<point> q;
	q.push(point(sL, sR, sC));
	visited[sL][sR][sC] = 1;
	while (!q.empty()) {
		t++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			point now = q.front();
			q.pop();

			int l = now.x;
			int r = now.y;
			int c = now.z;

			for (int j = 0; j < 6; j++) {
				int ddl = l + dl[j];
				int ddr = r + dr[j];
				int ddc = c + dc[j];

				if (1 <= ddl && ddl <= L && 1 <= ddr && ddr <= R && 1 <= ddc && ddc <= C) {
					if (!visited[ddl][ddr][ddc] && arr[ddl][ddr][ddc]!='#') {
						visited[ddl][ddr][ddc] = 1;

						if (arr[ddl][ddr][ddc] == 'E') {
							cout << "Escaped in " << t << " minute(s).\n";
							return;
						}
						else {
							q.push(point(ddl, ddr, ddc));
						}
					}
				}
			}
		}
	}
	cout << "Trapped!\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> L >> R >> C) {
		if (L + R + C == 0) break;
		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= R; j++) {
				cin >> tmp;
				for (int k = 1; k <= C; k++) {
					arr[i][j][k] = tmp[k - 1];
					if (arr[i][j][k] == 'S') {
						sL = i, sR = j, sC = k;
					}
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		bfs();
	}
	return 0;
}