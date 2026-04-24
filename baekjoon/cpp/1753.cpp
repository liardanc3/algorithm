#include <bits/stdc++.h>
#define INF 999999999
using namespace std;
typedef pair<int, int> pii;
int V, E, s, tmp1, tmp2, tmp3;
int dist[20001];
vector<pii> node[20001];
void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> PQ;
	PQ.push(pii(0, start));
	dist[start] = 0;
	while (!PQ.empty()) {
		int dis = PQ.top().first;
		int now = PQ.top().second; PQ.pop();

		if (dist[now] < dis)
			continue;

		for (int i = 0; i < node[now].size(); i++) {
			int cost = dis + node[now].at(i).second;
			if (cost < dist[node[now].at(i).first]) {
				dist[node[now].at(i).first] = cost;
				PQ.push(pii(cost, node[now].at(i).first));
			}
		}
	}
}

int main() {
	fill(dist, dist + 20001, INF);
	cin >> V >> E >> s;
	for (int i = 0; i < E; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		node[tmp1].push_back(pii(tmp2, tmp3));
	}
	dijkstra(s);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else cout << dist[i] << '\n';
	}
	return 0;
}