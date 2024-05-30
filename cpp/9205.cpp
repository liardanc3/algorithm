#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> tmp, vect[102];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int t, n, x, y, dist[102];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		fill(&dist[0], &dist[102], 1e9);
		tmp.clear();
		for (int i = 0; i <= n + 1; i++)
			vect[i].clear();
		for (int i = 0; i <= n + 1; i++) {
			cin >> x >> y;
			tmp.push_back({ x,y });
		}
		for (int i = 0; i <= n; i++) {
			for (int j = i + 1; j <= n + 1; j++) {
				int mh = abs(tmp[i].first - tmp[j].first) + abs(tmp[i].second - tmp[j].second);
				if (mh <= 1000) {
					vect[i].push_back({ j,1 });
					vect[j].push_back({ i,1 });
				}
			}
		}
		dist[0] = 0;
		pq.push({ 0,0 });
		while (!pq.empty()) {
			int now = pq.top().second;
			int d = pq.top().first;
		
			pq.pop();

			if (dist[now] < d)
				continue;

			for (pii p : vect[now]) {
				int next = p.first;
				int cost = p.second;

				if (d+cost < dist[next]) {
					dist[next] = d + cost;
					pq.push({ dist[next],next });
				}
			}
		}
		if (dist[n + 1] == 1e9)
			cout << "sad\n";
		else
			cout << "happy\n";
	}
	return 0;
}