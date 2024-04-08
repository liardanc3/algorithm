#include <bits/stdc++.h>
using namespace std;
#define INF 999999999
typedef pair<int, int> pii;
int N, M, s, tmp1, tmp2, tmp3;
int d[1001][1001];
vector<pii> node[1001];
void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));
	d[start][start] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second; pq.pop();
		if (d[start][now] < dist) continue;
		for (int i = 0; i < node[now].size(); i++) {
			int cost = dist + node[now].at(i).second;

			if (cost < d[start][node[now].at(i).first]) {
				d[start][node[now].at(i).first] = cost;
				pq.push(pii(cost, node[now].at(i).first));
			}
		}
	}
}
int main() {
	fill(&d[0][0], &d[1000][1000]+1, INF);
	cin >> N >> M >> s;
	while (M--) {
		cin >> tmp1 >> tmp2 >> tmp3;
		node[tmp1].push_back(pii(tmp2, tmp3));
	}
	for (int i = 1; i <= N; i++) {
		dijkstra(i);
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < d[i][s] + d[s][i])
			max = d[i][s] + d[s][i];
	}
	cout << max;
	map<string, int> M;
	M.insert(pair<string, int>("uid1234", -1));
	return 0;
}