#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
typedef pair<int, int> pii;
int N, M, tmp1, tmp2, tmp3, start, ed;
vector<pii> node[1001];
int d[1001];
void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));
	d[start] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second; pq.pop();

		if (d[now] < dist) continue;
		for (int i = 0; i < node[now].size(); i++) {
			int cost = dist + node[now].at(i).second;

			if (cost < d[node[now].at(i).first]) {
				d[node[now].at(i).first] = cost;
				pq.push(pii(cost, node[now].at(i).first));
			}
		}
	}
}

int main() {
	fill(&d[0], &d[1001] + 1, INF);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		node[tmp1].push_back(pii(tmp2, tmp3));
	} cin >> start >> ed;
	dijkstra(start);
	cout << d[ed];
	return 0;
}