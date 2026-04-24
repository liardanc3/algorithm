#include <bits/stdc++.h>
using namespace std;

int C, R, K, arr[1001][1001], X, Y;
void up(int xx, int yy);
void left(int xx, int yy) {
	int x, y;
	for (x = xx, y = yy; x >= 1 && arr[x][y] == 0; x--) {
		arr[x][y] = K--;
		if (K == 0) {
			cout << x << ' ' << y;
			exit(0);
		}
	}
	x++;
	if (arr[x][y + 1] == 0)
		up(x, y + 1);
}
void down(int xx, int yy) {
	int x, y;
	for (x = xx, y = yy; y >= 1 && arr[x][y] == 0; y--) {
		arr[x][y] = K--;
		if (K == 0) {
			cout << x << ' ' << y;
			exit(0);
		}
	}
	y++;
	if (arr[x - 1][y] == 0)
		left(x - 1, y);
}

void right(int xx, int yy) {
	int x, y;
	for (x = xx, y = yy; x <= C && arr[x][y] == 0; x++) {
		arr[x][y] = K--;
		if (K == 0) {
			cout << x << ' ' << y;
			exit(0);
		}
	}
	x--;
	if (arr[x][y - 1] == 0)
		down(x, y - 1);
}
void up(int xx, int yy) {
	int x, y;
	for (x = xx, y = yy; y <= R && arr[x][y] == 0; y++) {
		arr[x][y] = K--;
		if (K == 0) {
			cout << x << ' ' << y;
			exit(0);
		}
	}
	y--;
	if (arr[x + 1][y] == 0)
		right(x + 1, y);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> C >> R >> K;
	up(1, 1);
	cout << 0;
	return 0;
}
