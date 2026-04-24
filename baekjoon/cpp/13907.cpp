#include <bits/stdc++.h>
#include <assert.h>
#define int long long
using namespace std;

typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;
vector<pii> vect[1001], ret;

int N, M, K, S, D, a, b, c, price[30001], total, ans[1001][1001];
void dijkstra() {
	// dist, now, len
	priority_queue<tii, vector<tii>, greater<tii>> pq;
	pq.push({ 0, S, 0 });
	ans[0][S] = 0;
	while (!pq.empty()) {
		tii t = pq.top();

		pq.pop();

		int dist = get<0>(t);
		int now = get<1>(t);
		int len = get<2>(t);

		if (ans[len][now] < dist || now == D || len == N-1)
			continue;

		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i].first;
			int cost = vect[now][i].second;

			if (dist+cost < ans[len+1][next]) {
				ans[len+1][next] = dist+cost;
				pq.push({ dist + cost,next,len + 1 });
			}
		}
	}
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		fill(&ans[0][0], &ans[1000][1001], 1e16);
		cin >> N >> M >> K >> S >> D;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			vect[a].push_back({ b,c });
			vect[b].push_back({ a,c });
		}
		for (int i = 1; i <= K; i++) {
			cin >> price[i];
			price[i] += price[i - 1];
		}
	}();
	dijkstra();
	for (int i = 1; i < N; i++) {
		if (ans[i][D] != 1e16)
			ret.push_back({ ans[i][D],i });
	}
	for (int i = 0; i <= K; i++) {
		int mn = 1e16;
		for (int j = 1; j < N; j++) {
			int d = ans[j][D];
			int cnt = j;
			mn = min(mn, d + cnt * price[i]);
		}
		cout << mn << '\n';
	}
	return 0;
}