#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, home[17][17]{ 0, }, dp[17][17]{ 0, };
int dfs(int y,int x, int state) {
	if (state == 1) {
		if (x + 1 <= N && home[y][x + 1] == 0) {
			dp[y][x + 1]++;
			dfs(y, x + 1, 1);
		}
		if (x + 1 <= N && y + 1 <= N && home[y][x + 1] == 0 && home[y + 1][x + 1] == 0 && home[y + 1][x] == 0) {
			dp[y + 1][x + 1]++;
			dfs(y + 1, x + 1, 3);
		}
	}
	else if (state == 2) {
		if (y + 1 <= N && home[y + 1][x] == 0) {
			dp[y + 1][x]++;
			dfs(y + 1, x, 2);
		}
		if (y + 1 <= N && x + 1 <= N && home[y + 1][x] == 0 && home[y + 1][x + 1] == 0 && home[y][x + 1] == 0) {
			dp[y + 1][x + 1]++;
			dfs(y + 1, x + 1, 3);
		}
	}
	else {
		if (x + 1 <= N && home[y][x + 1] == 0) {
			dp[y][x + 1]++;
			dfs(y, x + 1, 1);
		}
		if (y + 1 <= N && home[y + 1][x] == 0) {
			dp[y + 1][x]++;
			dfs(y + 1, x, 2);
		}
		if (y + 1 <= N && x + 1 <= N && home[y + 1][x + 1] == 0 && home[y][x + 1] == 0 && home[y + 1][x] == 0) {
			dp[y + 1][x + 1]++;
			dfs(y + 1, x + 1, 3);
		}
	}
	return 0;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> home[i][j];
	dfs(1, 2, 1);
	cout << dp[N][N];
	return 0;
}