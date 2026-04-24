#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define INF 1e8
int n, a, b, c, cnt;
int d[10001];
vector<pii> node[10001];
int stra(int start) {
	fill(&d[0], &d[10001], INF); d[start] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));
	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = pq.top().first; pq.pop();

		if (d[now] < dist) continue;
		for (int j = 0; j < node[now].size(); j++) {
			int cost = dist + node[now].at(j).second;

			if (cost < d[node[now].at(j).first]) {
				d[node[now].at(j).first] = cost;
				pq.push(pii(cost, node[now].at(j).first));
			}
		}
	}
	d[0] = 0;
	int mx_idx = -1;
	int mx_tmp = *max_element(&d[0], &d[n + 1]);
	for (int i = 1; i <= n; i++) {
		if (d[i] == mx_tmp) {
			mx_idx = i;
			break;
		}
	}
	cnt++;
	if(cnt<2) stra(mx_idx);
	int mx = *max_element(&d[1], &d[n + 1]);

	return mx;
}
int main() {
	cin >> n; cnt = 0;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		node[a].push_back(pii(b, c));
		node[b].push_back(pii(a, c));
	} 
	cout << stra(1);
	return 0;
}