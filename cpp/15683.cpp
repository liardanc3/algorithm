#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, arr[9][9], mx, tmp[9][9];
vector<pii> vect, wall;
void Right(int ddy, int ddx, vector<pii> &eyesight) {
	int d = 0;
	while (1 <= ddx + d && ddx + d <= m && arr[ddy][ddx + d] != 6) {
		tmp[ddy][ddx + d]++;
		eyesight.push_back({ ddy,ddx + d });
		d++;
	}
}
void Left(int ddy, int ddx, vector<pii> &eyesight) {
	int d = 0;
	while (1 <= ddx + d && ddx + d <= m && arr[ddy][ddx + d] != 6) {
		tmp[ddy][ddx + d]++;
		eyesight.push_back({ ddy,ddx + d });
		d--;
	}
}
void Top(int ddy, int ddx, vector<pii> &eyesight) {
	int d = 0;
	while (1 <= ddy + d && ddy + d <= n && arr[ddy + d][ddx] != 6) {
		tmp[ddy + d][ddx]++;
		eyesight.push_back({ ddy + d,ddx });
		d--;
	}
}
void Bottom(int ddy, int ddx, vector<pii> &eyesight) {
	int d = 0;
	while (1 <= ddy + d && ddy + d <= n && arr[ddy + d][ddx] != 6) {
		tmp[ddy + d][ddx]++;
		eyesight.push_back({ ddy + d,ddx });
		d++;
	}
}
void dfs(int idx) {
	if (idx == vect.size()) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (tmp[i][j])
					cnt++;
			}
		}
		mx = max(mx, cnt);
		return;
	}

	int y = vect[idx].first;
	int x = vect[idx].second;
	int camera = arr[y][x];

	vector<pii> eyesight;

	if (camera == 1) {

		// Right
		Right(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

		// Left
		Left(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

		// Top
		Top(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

		// Bottom
		Bottom(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();
	}

	if (camera == 2) {

		// Right & Left
		Right(y, x, eyesight), Left(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

		// Top & Bottom
		Top(y, x, eyesight), Bottom(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();
	}

	if (camera == 3) {
		// Top & Right
		Top(y, x, eyesight), Right(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

		// RIght & Bottom
		Right(y, x, eyesight), Bottom(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

		// Bottom & Left
		Bottom(y, x, eyesight), Left(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

		// Left & Top
		Left(y, x, eyesight), Top(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

	}

	if (camera == 4) {

		// except Top
		Right(y, x, eyesight), Bottom(y, x, eyesight), Left(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

		// except Right
		Bottom(y, x, eyesight), Left(y, x, eyesight), Top(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

		// except Bottom
		Top(y, x, eyesight), Right(y, x, eyesight), Left(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();

		// except Left
		Top(y, x, eyesight), Right(y, x, eyesight), Bottom(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();
	}

	if (camera == 5) {
		Right(y, x, eyesight), Bottom(y, x, eyesight);
		Left(y, x, eyesight), Top(y, x, eyesight);
		dfs(idx + 1);
		for (pii p : eyesight)
			tmp[p.first][p.second]--;
		eyesight.clear();
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (1 <= arr[i][j] && arr[i][j] <= 5) 
				vect.push_back({ i,j });
			if (arr[i][j] == 6)
				tmp[i][j]++;
		}
	}
	dfs(0);
	cout << n * m - mx;
	return 0;
}