#include <bits/stdc++.h>
using namespace std;

int N, arr[3000][3000];
void solve(int n, int lx, int rx, int ty, int by) {
	if (n > N) {
		for (int i = by; i <= ty; i++) {
			int mx;
			for (int j = lx; j <= rx; j++) {
				if (arr[i][j])
					mx = j;
			}
			for (int j = lx; j <= mx; j++) {
				if (arr[i][j])
					cout << '*';
				else
					cout << ' ';
			}
			cout << '\n';
		}
		return;
	}
		

	// ¿ª»ï°¢Çü
	if (n % 2 == 0) {
		int w = rx - lx + 1;
		int h = ty - by + 1;
		int x_mid = (rx + lx) / 2;

		rx = x_mid + w / 2 + h + 1;
		lx = x_mid - w / 2 - h - 1;
		by--;
		ty += h;

		for (int x1 = x_mid, x2 = x_mid, y = ty; x1 <= rx; x1++, x2--, y--) {
			arr[y][x1] = 1;
			arr[y][x2] = 1;
			arr[by][x1] = 1;
			arr[by][x2] = 1;
		}

		solve(n + 1, lx, rx, ty, by);
	}

	// »ï°¢Çü
	else {
		int w = rx - lx + 1;
		int h = ty - by + 1;
		int x_mid = (rx + lx) / 2;

		rx = x_mid + w / 2 + h + 1;
		lx = x_mid - w / 2 - h - 1;
		by -= h;
		ty++;

		for (int x1 = x_mid, x2 = x_mid, y = by; x1 <= rx; x1++, x2--, y++) {
			arr[y][x1] = 1;
			arr[y][x2] = 1;
			arr[ty][x1] = 1;
			arr[ty][x2] = 1;
		}

		solve(n + 1, lx, rx, ty, by);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	arr[1500][1500] = 1;
	solve(2, 1500, 1500, 1500, 1500);
	return 0;
}