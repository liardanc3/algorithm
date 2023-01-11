#include <bits/stdc++.h>
using namespace std;

int N, a, b, level[1000001], dp[2][1000001];
vector<int> vect[1000001], rvect[1000001];

void dfs(int now, int l) {
	level[now] = l;
	for (int next : vect[now]) {
		if (!level[next]) {
			rvect[now].push_back(next);
			dfs(next, l + 1);
		}	
	}
	return;
}

int dynamic(int ck1, int ck2, int now) {
	if (dp[ck2][now] != 1e9)
		return dp[ck2][now];

	if (rvect[now].empty())
		return dp[ck2][now] = ck2;

	dp[ck2][now] = ck2;

	for (int i = 0; i < rvect[now].size(); i++) {
		int next = rvect[now][i];

		if (ck2)
			dp[ck2][now] += min(dynamic(ck2, 0, next), dynamic(ck2, 1, next));
		else
			dp[ck2][now] += dynamic(ck2, 1, next);
	}

	return dp[ck2][now];
}

int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		fill(&dp[0][0], &dp[1][1000001], 1e9);
		cin >> N;
		for (int i = 0; i < N-1; i++) {
			cin >> a >> b;
			vect[a].push_back(b);
			vect[b].push_back(a);
		}
		dfs(1, 1);
	}();
	dynamic(0, 0, 1);
	dynamic(0, 1, 1);
	cout << min(dp[0][1],dp[1][1]);
	return 0;
}