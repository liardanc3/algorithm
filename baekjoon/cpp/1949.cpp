#include <bits/stdc++.h>
using namespace std;

int N, arr[10001], a, b, visited[10001], dp[2][10001];
vector<int> vect[10001], rvect[10001];

void dfs(int now) {
	visited[now] = 1;
	for (int i = 0; i < vect[now].size(); i++) {
		int next = vect[now][i];

		if (!visited[next]) {
			rvect[now].push_back(next);
			dfs(next);
		}
	}
	return;
}
int dynamic(int n, int now) {
	if (dp[n][now] != -1)
		return dp[n][now];

	dp[n][now] = n * arr[now];

	for (int i = 0; i < rvect[now].size(); i++) {
		int next = rvect[now][i];

		if (n)
			dp[n][now] += dynamic(0, next);
		else
			dp[n][now] += max(dynamic(0, next), dynamic(1, next));
	}

	return dp[n][now];
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		fill(&dp[0][0], &dp[1][10001], -1);
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		for (int i = 0; i < N - 1; i++) {
			cin >> a >> b;
			vect[a].push_back(b);
			vect[b].push_back(a);
		}
		dfs(1);
	}();
	dynamic(1, 1);
	dynamic(0, 1);
	cout << max(dp[0][1], dp[1][1]);
	return 0;
}