#include <bits/stdc++.h>
#include <assert.h>
#define int long long
using namespace std;

int N, M, arr[1001][1001], dp[3][1001][1001], visited[1001][1001];

int dynamic(int y, int x, int come) {
	if (dp[come][y][x] != -2e9)
		return dp[come][y][x];
	int a = -2e9, b = -2e9, c = -2e9;
	// left = a
	if (x % M != 1 && !visited[y][x-1]) {
		visited[y][x - 1] = 1;
		a = arr[y][x] + dynamic(y, x - 1, 2);
		visited[y][x - 1] = 0;
	}
	// right = b
	if (x % M != 0 && !visited[y][x+1]) {
		visited[y][x + 1] = 1;
		b = arr[y][x] + dynamic(y, x + 1, 1);
		visited[y][x + 1] = 0;
	}
	// down = c
	if (y != N) {
		visited[y + 1][x] = 1;
		c = arr[y][x] + dynamic(y + 1, x, 0);
		visited[y + 1][x] = 0;
	}
	return dp[come][y][x] = max(a, max(b, c));
}

signed main() {
	[&]() {
		fill(&dp[0][0][0], &dp[2][1000][1001], -2e9);
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> arr[i][j];
				assert(abs(arr[i][j]) <= 100);
			}		
		}
	}();
	visited[1][1] = 1;
	dp[0][N][M] = arr[N][M], dp[1][N][M] = arr[N][M];
	cout << dynamic(1, 1, 0);
	return 0;
}