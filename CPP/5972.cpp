#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect[50001];

int N, M, a, b, c, dist[50001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	fill(&dist[0], &dist[50001], 1e9);
	dist[1] = 0;
	cin >> N >> M;
	while (M--) {
		cin >> a >> b >> c;
		vect[a].push_back({ b,c });
		vect[b].push_back({ a,c });
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int now = pq.top().second;
		int d = pq.top().first;

		pq.pop();

		if (dist[now] < d)
			continue;
		
		for (pii p : vect[now]) {
			int next = p.first;
			int dd = p.second;

			if (d + dd < dist[next]) {
				dist[next] = d + dd;
				pq.push({ dist[next],next });
			}
		}
	}
	cout << dist[N];
	return 0;
}