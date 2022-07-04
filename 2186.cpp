#include <bits/stdc++.h>
using namespace std;

int N, M, K, dp[80][101][101], dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 }, ans;
char arr[101][101];
string tmp;

int dynamic(int idx, int y, int x) {
	if (dp[idx][y][x] >= 0)
		return dp[idx][y][x];
	if (idx == tmp.size() - 1)
		return dp[idx][y][x] = 1;

	int ret = 0;
	for (int i = 0; i < 4; i++) {
		for (int k = 1; k <= K; k++) {
			int ddy = y + k * dy[i];
			int ddx = x + k * dx[i];

			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M && arr[ddy][ddx] == tmp[idx + 1])
				ret += dynamic(idx + 1, ddy, ddx);
		}
	}

	return dp[idx][y][x] = ret;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	fill(&dp[0][0][0], &dp[79][100][101], -1);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= M; j++) 
			arr[i][j] = tmp[j - 1];
	}
	cin >> tmp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == tmp[0])
				ans += dynamic(0, i, j);
		}
	}
	cout << ans;
	return 0;
}