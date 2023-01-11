#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> vect[2001];
vector<int> dst;

int T, n, m, t, s, g, h, a, b, d, x, dist[2001];
void dijkstra() {
	dist[s] = 0;
	pq.push({ 0,s});
	while (!pq.empty()) {
		int d = pq.top().first;
		int now = pq.top().second;
		
		pq.pop();

		if (dist[now] < d)
			continue;

		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i].second;
			int cost = vect[now][i].first;
			if (d + cost < dist[next]) {
				dist[next] = d + cost;
				pq.push({ dist[next], next });
			}
		}
	}
	for (int _dst : dst) {
		if (dist[_dst] % 2)
			cout << _dst << ' ';
	}
	cout << '\n';
}
void init() {
	fill(&dist[0], &dist[2001], 2e9);
	while (!pq.empty())
		pq.pop();
	cin >> n >> m >> t >> s >> g >> h;
	for (int i = 1; i <= n; i++)
		vect[i].clear();
	dst.clear();
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> d;
		int g2h = (a == h && b == g) || (a == g && b == h);
		vect[a].push_back({ d * 2 - g2h,b });
		vect[b].push_back({ d * 2 - g2h,a });
	}
	for (int i = 1; i <= t; i++) {
		cin >> x;
		dst.push_back(x);
	}
	sort(dst.begin(), dst.end());
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		init();
		dijkstra();
	}
	return 0;
}