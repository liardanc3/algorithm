#include <bits/stdc++.h>
using namespace std;

int N, M, arr[51][51], visited[51][51], mx, dp[51][51];
string tmp;
int dfs(int y, int x) {
	if (dp[y][x])
		return dp[y][x];
	int ddy, ddx;

	// U
	ddy = y - arr[y][x];
	if (1 <= ddy && arr[ddy][x]) {
		if (visited[ddy][x]) {
			cout << -1;
			exit(0);
		}
		visited[ddy][x] = 1;
		dp[y][x] = max(dp[y][x], dfs(ddy, x) + 1);
		visited[ddy][x] = 0;
	}

	// D
	ddy = y + arr[y][x];
	if (ddy <= N && arr[ddy][x]) {
		if (visited[ddy][x]) {
			cout << -1;
			exit(0);
		}
		visited[ddy][x] = 1;
		dp[y][x] = max(dp[y][x], dfs(ddy, x) + 1);
		visited[ddy][x] = 0;
	}

	// L
	ddx = x - arr[y][x];
	if (1 <= ddx && arr[y][ddx]) {
		if (visited[y][ddx]) {
			cout << -1;
			exit(0);
		}
		visited[y][ddx] = 1;
		dp[y][x] = max(dp[y][x], dfs(y, ddx) + 1);
		visited[y][ddx] = 0;
	}

	// R
	ddx = x + arr[y][x];
	if (ddx <= M && arr[y][ddx]) {
		if (visited[y][ddx]) {
			cout << -1;
			exit(0);
		}
		visited[y][ddx] = 1;
		dp[y][x] = max(dp[y][x], dfs(y, ddx) + 1);
		visited[y][ddx] = 0;
	}

	return dp[y][x];
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			for (int j = 1; j <= M; j++) {
				if (tmp[j - 1] != 'H')
					arr[i][j] = tmp[j - 1] - '0';
			}
		}
	}();
	visited[1][1] = 1;
	cout << dfs(1, 1) + 1;
	return 0;
}