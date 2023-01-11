#include <bits/stdc++.h>
using namespace std;
#define INF 999999999
typedef pair<int, int> pii;
int tmp1, tmp2, tmp3, n, d, c;
int dp[10001];
pii bfs(int start, vector<pii> vect[]) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));
	dp[start] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second; pq.pop();

		if (dp[now] < dist) continue;
		for (int i = 0; i < vect[now].size(); i++) {
			int cost = dist + vect[now].at(i).second;
			if (cost < dp[vect[now].at(i).first]) {
				dp[vect[now].at(i).first] = cost;
				pq.push(pii(cost, vect[now].at(i).first));
			}
		}
	}
	int ret1 = 0, ret2 = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] != INF) {
			ret1++;
			if (dp[i] > ret2) ret2 = dp[i];
		}
	}
	return pii(ret1, ret2);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		vector<pii> vect[10001];
		fill(&dp[0], &dp[10001], INF);
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			cin >> tmp1 >> tmp2 >> tmp3;
			vect[tmp2].push_back(pii(tmp1, tmp3));
		}
		pii ans = bfs(c,vect);
		cout << ans.first << " " << ans.second << '\n';
	}
	return 0;
}