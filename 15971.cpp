#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int n, a, b, dist[100001], s, len, e, mx;
vector<pii> vect[100001];
void dijkstra() {
	priority_queue<piii, vector<piii>, greater<piii>> pq;
	pq.push({ { 0,a }, 0 });
	while (!pq.empty()) {
		int now = pq.top().first.second;
		int d = pq.top().first.first;
		int len = pq.top().second;
		pq.pop();

		if (now == b) mx = max(mx, len);
		if (dist[now] < d) continue;

		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i].first;
			int cost = vect[now][i].second;

			if (d + cost < dist[next]) {
				dist[next] = d + cost;
				pq.push({{ d + cost, next }, max(len,cost)});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> a >> b;
	fill(&dist[0], &dist[100001], 1e9);
	dist[a] = 0;#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int n, a, b, dist[100001], s, len, e, mx;
vector<pii> vect[100001];
void dijkstra() {
	priority_queue<piii, vector<piii>, greater<piii>> pq;
	pq.push({ { 0,a }, 0 });
	while (!pq.empty()) {
		int now = pq.top().first.second;
		int d = pq.top().first.first;
		int len = pq.top().second;
		pq.pop();

		if (now == b) mx = max(mx, len);
		if (dist[now] < d) continue;

		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i].first;
			int cost = vect[now][i].second;

			if (d + cost < dist[next]) {
				dist[next] = d + cost;
				pq.push({{ d + cost, next }, max(len,cost)});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> a >> b;
	fill(&dist[0], &dist[100001], 1e9);
	dist[a] = 0;

	for (int i = 1; i < n; i++) {
		cin >> s >> e >> len;
		vect[s].push_back({ e,len });
		vect[e].push_back({ s,len });
	}
	
	dijkstra();
	cout << dist[b] - mx;
	return 0;
}

	for (int i = 1; i < n; i++) {
		cin >> s >> e >> len;
		vect[s].push_back({ e,len });
		vect[e].push_back({ s,len });
	}
	
	dijkstra();
	cout << dist[b] - mx;
	return 0;
}