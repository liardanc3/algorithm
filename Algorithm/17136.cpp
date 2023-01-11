#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int arr[11][11], mn = 1e9, cnt[6];
void dfs(int y, int x, int paper) {
	if (paper >= mn)
		return;
	if (y == 10 && x == 11) {
		mn = min(mn, paper);
		return;
	}
	if (x == 11)
		y++, x = 1;
	if (arr[y][x] == 0) {
		dfs(y, x + 1, paper);
		return;
	}
		

	vector<pii> vect;
	
	// 5x5
	if (cnt[5]) {
		bool flag = 0;
		vect.clear();
		if (y + 4 <= 10 && x + 4 <= 10) {
			flag = 1;
			for (int i = y; i <= y + 4 && flag; i++) {
				for (int j = x; j <= x + 4 && flag; j++) {
					if (arr[i][j] == 0)
						flag = 0;
					else {
						vect.push_back({ i,j });
						arr[i][j] = 0;
					}
				}
			}
		}
		if (flag) {
			cnt[5]--;
			dfs(y, x + 1, paper+1);
			cnt[5]++;
		}
		for (pii p : vect)
			arr[p.first][p.second] = 1;
	}
	// 4x4
	if (cnt[4]) {
		bool flag = 0;
		vect.clear();
		if (y + 3 <= 10 && x + 3 <= 10) {
			flag = 1;
			for (int i = y; i <= y + 3 && flag; i++) {
				for (int j = x; j <= x + 3 && flag; j++) {
					if (arr[i][j] == 0)
						flag = 0;
					else {
						vect.push_back({ i,j });
						arr[i][j] = 0;
					}
				}
			}
		}
		if (flag) {
			cnt[4]--;
			dfs(y, x + 1, paper + 1);
			cnt[4]++;
		}
		for (pii p : vect)
			arr[p.first][p.second] = 1;
	}
	// 3x3
	if (cnt[3]) {
		bool flag = 0;
		vect.clear();
		if (y + 2 <= 10 && x + 2 <= 10) {
			flag = 1;
			for (int i = y; i <= y + 2 && flag; i++) {
				for (int j = x; j <= x + 2 && flag; j++) {
					if (arr[i][j] == 0)
						flag = 0;
					else {
						vect.push_back({ i,j });
						arr[i][j] = 0;
					}
				}
			}
		}
		if (flag) {
			cnt[3]--;
			dfs(y, x + 1, paper + 1);
			cnt[3]++;
		}
		for (pii p : vect)
			arr[p.first][p.second] = 1;
	}
	// 2x2
	if (cnt[2]) {
		bool flag = 0;
		vect.clear();
		if (y + 1 <= 10 && x + 1 <= 10) {
			flag = 1;
			for (int i = y; i <= y + 1 && flag; i++) {
				for (int j = x; j <= x + 1 && flag; j++) {
					if (arr[i][j] == 0)
						flag = 0;
					else {
						vect.push_back({ i,j });
						arr[i][j] = 0;
					}
				}
			}
		}
		if (flag) {
			cnt[2]--;
			dfs(y, x + 1, paper + 1);
			cnt[2]++;
		}
		for (pii p : vect)
			arr[p.first][p.second] = 1;
	}
	// 1x1
	if (cnt[1]) {
		if (arr[y][x] == 1) {
			arr[y][x] = 0;
			cnt[1]--;
			dfs(y, x + 1, paper + 1);
			cnt[1]++;
			arr[y][x] = 1;
		}
	}
	return;
}
int main() {
	[&]() {
		for (int i = 1; i <= 5; i++)
			cnt[i] = 5;
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		for (int i = 1; i <= 10; i++) for (int j = 1; j <= 10; j++)
			cin >> arr[i][j];
	}();
	dfs(1, 1, 0);
	mn == 1e9 ? cout << -1 : cout << mn;
	return 0;
}