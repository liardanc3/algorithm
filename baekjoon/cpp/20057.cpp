#include <bits/stdc++.h>
using namespace std;

int N, arr[500][500], sum;
int Ly[]{ -2,-1,-1,-1,0,1,1,1,2,0 }, Lx[]{ 0,-1,0,1,-2,-1,0,1,0,-1 };
int Lrate[]{ 2,10,7,1,5,10,7,1,2 };
int Ry[]{ -2,-1,-1,-1,0,1,1,1,2,0 }, Rx[]{ 0,-1,0,1,2,-1,0,1,0,1 };
int Rrate[]{ 2,1,7,10,5,1,7,10,2 };
int Ty[]{ -2,-1,-1,0,0,0,0,1,1,-1 }, Tx[]{ 0,-1,1,-2,-1,1,2,-1,1,0 };
int Trate[]{ 5,10,10,2,7,7,2,1,1 };
int By[]{ -1,-1,0,0,0,0,1,1,2,1 }, Bx[]{ -1,1,-2,-1,1,2,-1,1,0,0 };
int Brate[]{ 1,1,2,7,7,2,10,10,5 };

void dfs(int y, int x, int direct,int step, int limit) {
	if (x == 1 && y == 1)
		return;

	// 왼쪽
	if (direct == 0) {
		int now = arr[y][x - 1];
		for (int i = 0; i < 9; i++) {
			int ddy = y + Ly[i];
			int ddx = x - 1 + Lx[i];
			int move = (now * Lrate[i]) / 100;
			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N)
				arr[ddy][ddx] += move;
			else
				sum += move;
			arr[y][x - 1] -= move;
		}
		int ddy = y + Ly[9];
		int ddx = x - 1 + Lx[9];
		if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N)
			arr[ddy][ddx] += arr[y][x - 1];
		else
			sum += arr[y][x - 1];
		arr[y][x - 1] = 0;

		if (step == limit)
			dfs(y, x - 1, 1, 1, limit);
		else
			dfs(y, x - 1, direct, step + 1, limit);
		return;
	}

	// 아래
	if (direct == 1) {
		int now = arr[y + 1][x];
		for (int i = 0; i < 9; i++) {
			int ddy = y + 1 + By[i];
			int ddx = x + Bx[i];
			int move = (now * Brate[i]) / 100;
			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N)
				arr[ddy][ddx] += move;
			else
				sum += move;
			arr[y + 1][x] -= move;
		}
		int ddy = y + 1 + By[9];
		int ddx = x + Bx[9];
		if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N)
			arr[ddy][ddx] += arr[y + 1][x];
		else
			sum += arr[y + 1][x];
		if (step == limit)
			dfs(y + 1, x, 2, 1, limit + 1);
		else
			dfs(y + 1, x, direct, step + 1, limit);
		return;
	}

	// 오른쪽
	if (direct == 2) {
		int now = arr[y][x + 1];
		for (int i = 0; i < 9; i++) {
			int ddy = y + Ry[i];
			int ddx = x + 1 + Rx[i];
			int move = (now * Rrate[i]) / 100;
			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N)
				arr[ddy][ddx] += move;
			else
				sum += move;
			arr[y][x + 1] -= move;
		}
		int ddy = y + Ry[9];
		int ddx = x + 1 +  Rx[9];
		if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N)
			arr[ddy][ddx] += arr[y][x + 1];
		else
			sum += arr[y][x + 1];
		if (step == limit)
			dfs(y, x + 1, 3, 1, limit);
		else
			dfs(y, x + 1, direct, step + 1, limit);
		return;
	}

	// 위
	if (direct == 3) {
		int now = arr[y - 1][x];
		for (int i = 0; i < 9; i++) {
			int ddy = y - 1 + Ty[i];
			int ddx = x + Tx[i];
			int move = (now * Trate[i]) / 100;
			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N)
				arr[ddy][ddx] += move;
			else
				sum += move;
			arr[y - 1][x] -= move;
		}
		int ddy = y - 1 + Ty[9];
		int ddx = x  + Tx[9];
		if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N)
			arr[ddy][ddx] += arr[y - 1][x];
		else
			sum += arr[y - 1][x];
		if (step == limit)
			dfs(y - 1, x, 0, 1, limit + 1);
		else
			dfs(y - 1, x, direct, step + 1, limit);
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		cin >> arr[i][j];
	dfs(N / 2 + 1, N / 2 + 1, 0, 1, 1);
	cout << sum;
	return 0;
}