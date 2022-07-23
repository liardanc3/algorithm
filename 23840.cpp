#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;

int N, M, a, b, c, src, dst, p, tmp, dp[22][1 << 22];
int piva, pivb, ret = 1e13, pdist[22][22], d[100001];
vector<pii> vect[100001];
vector<int> P;
int TSP(int now, int visited, int depth) {
	cout << depth << '\n';
	if (dp[now][visited] != -1)
		return dp[now][visited];

	if (visited == (1 << (p+2)) - 1)
		return 0;
		
	dp[now][visited] = 1e13;
	for (int i = 0; i < p+2; i++) {
		if (i == p + 1 && depth != p) continue;
		if (!(visited & (1 << i)) && pdist[now][i] != 1e13) {
			int newdist = TSP(i, visited + (1 << i), depth+1) + pdist[now][i];
			if (newdist < dp[now][visited]) 
				dp[now][visited] = newdist;
		}
	}

	return dp[now][visited];
}
void dijkstra(int pidx) {
	fill(&d[0], &d[100001], 1e13);
	d[P[pidx]] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,P[pidx] });

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if (d[now] < cost)
			continue;

		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i].first;
			int dcost = vect[now][i].second;
			
			if (cost + dcost < d[next]) {
				d[next] = cost + dcost;
				pq.push({ d[next],next });
			}
		}
	}

	for (int i = 0; i < P.size(); i++) {
		int now = P[i];
		pdist[pidx][i] = d[now];
	}

	return;
}
signed main() {
	// input
	[&]() {
		fill(&dp[0][0], &dp[21][1 << 22], -1);
		fill(&pdist[0][0], &pdist[21][22], 1e13);
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			vect[a].push_back({ b,c });
			vect[b].push_back({ a,c });
		}
		cin >> src >> dst >> p;
		P.push_back(src);
		for (int i = 0; i < p; i++) {
			cin >> tmp;
			P.push_back(tmp);
		}
		P.push_back(dst);
	}();

	// dijkstra로 tsp할 거리 구함
	[&]() {
		for (int i = 0; i < p+2; i++) 
			dijkstra(i);
	}();
	
	// tsp
	[&]() {
		ret = TSP(0, 1, 0);
	}();

	ret >= 1e13 ? cout << -1 : cout << ret;
	return 0;
}