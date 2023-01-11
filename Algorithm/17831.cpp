#include <bits/stdc++.h>
using namespace std;

int N, tmp, arr[200001], dp[2][200001];
vector<int> vect[200001];
int dynamic(int n, int now) {
	if (dp[n][now] != -1)
		return dp[n][now];

	dp[n][now] = 0;

	if (!n) {
		for (int next : vect[now]) 
			dp[n][now] += max(dynamic(0, next), dynamic(1, next));
		return dp[n][now];
	}

	else {
		vector<int> v1,v2;
		
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i];

			int _1 = arr[now] * arr[next] + dynamic(0, next);
			int _2 = max(dynamic(0, next), dynamic(1, next));

			v1.push_back(_1);
			v2.push_back(_2);

			sum1 += _1;
			sum2 += _2;
		}

		int mx = sum2;

		for (int i = 0; i < vect[now].size(); i++) {
			int tmp = sum2 - v2[i] + v1[i];
			mx = max(mx, tmp);
		}
		return dp[n][now] = mx;
	}
}
signed main() {
	[&]() {
		fill(&dp[0][0], &dp[1][200001], -1);
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for (int i = 2; i <= N; i++) {
			cin >> tmp;
			vect[tmp].push_back(i);
		}
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
	}();
	cout << max(dynamic(0, 1), dynamic(1, 1));
	return 0;
}