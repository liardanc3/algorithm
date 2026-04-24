#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pii arr[4][4], fish[17];
int mx, a, b, dy[]{ 0,-1,-1,0,1,1,1,0,-1 }, dx[]{ 0,0,-1,-1,-1,0,1,1,1 };
void dfs(int y, int x, int d, int sum) {
	mx = max(mx, sum);
	pii tmp[4][4], fishtmp[17];
	copy(&arr[0][0], &arr[3][4], &tmp[0][0]);
	copy(&fish[0], &fish[17], &fishtmp[0]);

	fish[arr[y][x].first] = { -1,-1 };
	arr[y][x] = { 0,0 };
	
	// fish
	[&]() {
		for (int i = 1; i <= 16; i++) {
			int fy = fish[i].first;
			int fx = fish[i].second;

			int d = arr[fy][fx].second;

			if (fy == y && fx == x)
				continue;
			if (fy == -1 && fx == -1)
				continue;

			for (int j = 0; j < 8; j++) {
				int dd = d + j;
				if (dd > 8)
					dd -= 8;

				int ffy = fy + dy[dd];
				int ffx = fx + dx[dd];

				if (0 <= ffy && ffy < 4 && 0 <= ffx && ffx < 4 && (ffy != y || ffx != x)) {
					arr[fy][fx] = arr[ffy][ffx];
					fish[arr[ffy][ffx].first] = { fy,fx };

					arr[ffy][ffx] = { i,dd };
					fish[i] = { ffy,ffx };

					break;
				}
			}
		}
	}();

	// shark
	pii ttmp[4][4];
	copy(&arr[0][0], &arr[3][4], &ttmp[0][0]);
	for (int i = 1; i <= 3; i++) {
		int sy = y + i * dy[d];
		int sx = x + i * dx[d];

		if (0 <= sy && sy < 4 && 0 <= sx && sx < 4 && arr[sy][sx].first != 0) {
			dfs(sy, sx, arr[sy][sx].second, sum + arr[sy][sx].first);
			copy(&ttmp[0][0], &ttmp[3][4], &arr[0][0]);
		}

	}

	copy(&tmp[0][0], &tmp[3][4], &arr[0][0]);
	copy(&fishtmp[0], &fishtmp[17], &fish[0]);
	return;
}
int main() {
	[&]() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> a >> b;
				arr[i][j] = { a,b };
				fish[a] = { i,j };
			}
		}
	}();
	dfs(0, 0, arr[0][0].second, arr[0][0].first);
	cout << mx;
	return 0;
}