#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;

vector<pii> vect[1001];
int N, Q, a, b, c, dist[1001];

void dijkstra(int a, int b) {
	fill(&dist[0], &dist[1001], 1e9);
	dist[a] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,a });
	while (!pq.empty()) {
		int now = pq.top().second;
		int d = pq.top().first;

		pq.pop();

		if (dist[now] < d)
			continue;

		for (pii p : vect[now]) {
			int next = p.first;
			int cost = p.second;

			if (d + cost < dist[next]) {
				dist[next] = d + cost;
				pq.push({ d + cost,next });
			}
		}
	}
	cout << dist[b] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		vect[a].push_back({ b,c });
		vect[b].push_back({ a,c });
	}
	while (Q--) {
		cin >> a >> b;
		dijkstra(a, b);
	}
	return 0;
}