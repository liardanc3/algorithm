#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

bool cmp(const pii& a, const pii& b) {
	if (a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}
int N, S, H, C, dp[300000];
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> S;
		for (int i = 1; i <= N; i++) {
			cin >> H >> C;
			vect.push_back({ H,C });
		}
		sort(vect.begin(), vect.end(), cmp);
	}();

	dp[0] = vect[0].second;
	int left = 0;
	for (int i = 1; i < N; i++) {
		for (int j = left; vect[j].first + S <= vect[i].first; j++) {
			if (dp[i] < dp[j] + vect[i].second) {
				left = j;
				dp[i] = dp[j] + vect[i].second;
			}
		}
		dp[i] = max(dp[i], vect[i].second);
	}
	cout << *max_element(&dp[0], &dp[N]);
	return 0;
}

