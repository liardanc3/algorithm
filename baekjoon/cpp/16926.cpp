#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

int N, M, R, arr[301][301], ans[301][301], visited[301][301];
void down(int y, int x, int mnx, int mxx, int mny, int mxy, int r, int val);
void left(int y, int x, int mnx, int mxx, int mny, int mxy, int r, int val) {
	if (!r) {
		ans[y][x] = val;
		return;
	}
	r--;
	if (x - 1 >= mnx)
		left(y, x - 1, mnx, mxx, mny, mxy, r, val);
	else
		down(y + 1, x, mnx, mxx, mny, mxy, r, val);
}
void up(int y, int x, int mnx, int mxx, int mny, int mxy, int r, int val) {
	if (!r) {
		ans[y][x] = val;
		return;
	}
	r--;
	if (y - 1 >= mny)
		up(y - 1, x, mnx, mxx, mny, mxy, r, val);
	else
		left(y, x - 1, mnx, mxx, mny, mxy, r, val);
}
void right(int y, int x, int mnx, int mxx, int mny, int mxy, int r, int val) {
	if (!r) {
		ans[y][x] = val;
		return;
	}
	r--;
	if (x + 1 <= mxx)
		right(y, x + 1, mnx, mxx, mny, mxy, r, val);
	else
		up(y - 1, x, mnx, mxx, mny, mxy, r, val);
}
void down(int y, int x, int mnx, int mxx, int mny, int mxy, int r, int val) {
	if (!r) {
		ans[y][x] = val;
		return;
	}
	r--;
	if (y + 1 <= mxy) 
		down(y + 1, x, mnx, mxx, mny, mxy, r, val);
	else 
		right(y, x + 1, mnx, mxx, mny, mxy, r, val);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)
		cin >> arr[i][j];
	
	int mny = 0, mxy = N-1, mnx = 0, mxx = M-1;
	while (mny <= mxy && mnx <= mxx) {
		[&]() {
			for (int i = mny; i <= mxy; i++) {
				for (int j = mnx; j <= mxx; j++) {
					bool cond1 = mny == i;
					bool cond2 = mxy == i;
					bool cond3 = mnx == j;
					bool cond4 = mxx == j;

					// down
					if (cond3 && !cond2)
						down(i, j, mnx, mxx, mny, mxy, R, arr[i][j]);

					// right
					if (cond2 && !cond4)
						right(i, j, mnx, mxx, mny, mxy, R, arr[i][j]);

					// up
					if (cond4 && !cond1)
						up(i, j, mnx, mxx, mny, mxy, R, arr[i][j]);

					// left
					if (cond1 && !cond3)
						left(i, j, mnx, mxx, mny, mxy, R, arr[i][j]);
				}
			}
		}();
		
		mny++, mnx++, mxy--, mxx--;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}