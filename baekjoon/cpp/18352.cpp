#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect[300001];
int N, M, K, X, a, b, dist[300001];
int dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,X });
	while (!pq.empty()) {
		int now = pq.top().second;
		int d = pq.top().first;

		pq.pop();

		if (dist[now] < d)
			continue;

		for (pii p : vect[now]) {
			if (d + p.second < dist[p.first]) {
				dist[p.first] = d + p.second;
				pq.push({ dist[p.first], p.first });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K)
			return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	fill(&dist[0], &dist[300001], 1e9);
	cin >> N >> M >> K >> X;
	dist[X] = 0;
	while (M--) {
		cin >> a >> b;
		vect[a].push_back({ b,1 });
	}
	if (dijkstra()) {
		for (int i = 1; i <= N; i++)
			if (dist[i] == K)
				cout << i << '\n';
	}
	else 
		cout << -1;
	return 0;
}