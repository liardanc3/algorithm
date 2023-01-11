#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, M, H, a, b, mn = 4, visited[3], arr[32][12];
vector<pii> vect;

bool down(int idx) {
	int y = 0;
	int x = idx;

	while (y != H + 1) {
		int d1 = arr[y + 1][x - 1];
		int d2 = arr[y + 1][x];

		if (d1)
			y++, x--;
		else if (d2)
			y++, x++;
		else
			y++;
	}

	return x == idx;
}

void go(int cnt) {
	for (int i = 1; i <= N; i++) {
		if (down(i))
			continue;
		else
			return;
	}
	mn = cnt;
	return;
}

void dfs(int yy, int xx, int cnt) {
	if (cnt >= mn)
		return;

	if (cnt <= 3)
		go(cnt);
	for (int y = yy; y <= H; y++) {
		for (int x = xx; x < N; x++) {
			if (arr[y][x - 1] || arr[y][x] || arr[y][x + 1]) continue;
			arr[y][x] = 1;
			if (x + 2 >= N)
				dfs(y + 1, 1, cnt + 1);
			else
				dfs(y, x + 2, cnt + 1);
			arr[y][x] = 0;
		}
		xx = 1;
	}
	return;
}

int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M >> H;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			arr[a][b] = 1;
		}
	}();
	dfs(1, 1, 0);
	mn == 4 ? cout << -1 : cout << mn;
	return 0;
}