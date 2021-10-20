#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, from, to, d[10001];
typedef pair<int, int> pii;
vector<pii> vect[10001];
void solution() {
	priority_queue<pii> pq;
	pq.push({ 0,from });
	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = pq.top().first; pq.pop();

		if (dist < d[now]) continue;

		for (int i = 0; i < vect[now].size(); i++) {
			int cost = min(dist,vect[now][i].second);
			if (cost == 0) cost = vect[now][i].second;
			int next = vect[now][i].first;
			
			if (d[next] < cost) {
				d[next] = cost;
				if (next != to)
					pq.push({ cost,next });
			}
		}
	}
	cout << d[to];
}
int main() {
	fill(&d[0], &d[10001], 0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		vect[a].push_back({ b,c });
		vect[b].push_back({ a,c });
	}
	cin >> from >> to;
	solution();
	return 0;
}