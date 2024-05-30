#include <bits/stdc++.h>
using namespace std;

int n, a, b, visited[100001], dp[4][100001], ans = 1e9;
vector<int> vect[100001], rvect[100001];
void dfs(int now) {
	visited[now] = 1;
	for (int next : vect[now]) {
		if (!visited[next]) {
			rvect[now].push_back(next);
			dfs(next);
		}
	}
	return;
}
int dynamic(int color, int now) {
	if (dp[color - 1][now] != -1)
		return dp[color - 1][now];

	dp[color - 1][now] = color;

	for (int i = 0; i < rvect[now].size(); i++) {
		int next = rvect[now][i];

		int mn = 1e9;
		for (int j = 1; j <= 4; j++) {
			if (j == color) continue;
			
			mn = min(mn, dynamic(j, next));
		}

		dp[color - 1][now] += mn;
	}

	return dp[color - 1][now];
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		fill(&dp[0][0], &dp[3][100001], -1);
		cin >> n;
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			vect[a].push_back(b);
			vect[b].push_back(a);
		}
		dfs(1);
	}();
	for (int i = 1; i <= 4; i++) 
		ans = min(ans, dynamic(i, 1));
	cout << ans;
	return 0;
}