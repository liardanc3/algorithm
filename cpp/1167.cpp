#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int V, a, b, c, tri, mx;
int d[100001];
vector<pii> vect[100001];
void stra(int start) {
	if (tri == 2) return;
	tri++;
	d[0] = -1;
	fill(&d[1], &d[V+1], 1e9);
	d[start] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));
	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = pq.top().first; pq.pop();

		if (d[now] < dist) continue;
		for (int i = 0; i < vect[now].size(); i++) {
			int cost = dist + vect[now].at(i).second;

			if (cost < d[vect[now].at(i).first]) {
				d[vect[now].at(i).first] = cost;
				pq.push(pii(cost, vect[now].at(i).first));
			}
		}
	}
	mx = *max_element(&d[1], &d[V + 1]);
	int idx = -1;
	for (int i = 1; i <= V; i++) {
		if (d[i] == mx) {
			idx = i; 
			break;
		}
	}
	stra(idx);
}
int main() {
	tri = 0;
	d[1] = 0;
	cin >> V;
	for (int i = 1; i <= V; i++) {
		cin >> a;
		while (cin >> b) {
			if (b == -1) break;
			cin >> c;
			vect[a].push_back(pii(b, c));
		}
	}
	stra(1);
	cout << mx;
	return 0;
}