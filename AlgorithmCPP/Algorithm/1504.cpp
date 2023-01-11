#include <bits/stdc++.h>
using namespace std;
#define INF 1e7
typedef pair<int, int> pii;
int N, E, tmp1, tmp2, tmp3;
int NEED1, NEED2;
int START[3];
vector<pii> node[801];
int d[3][801];
void stra(int n) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, START[n]));
	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = pq.top().first; pq.pop();

		if (d[n][now] < dist) continue;

		for (int i = 0; i < node[now].size(); i++) {
			int cost = dist + node[now].at(i).second;

			if (cost < d[n][node[now].at(i).first]) {
				d[n][node[now].at(i).first] = cost;
				pq.push(pii(cost, node[now].at(i).first));
			}
		}
	}
}
int main() {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		node[tmp1].push_back(pii(tmp2, tmp3));
		node[tmp2].push_back(pii(tmp1, tmp3));
	}
	cin >> NEED1 >> NEED2;
	fill(&d[0][0], &d[2][801], INF); 
	d[0][1] = 0; d[1][NEED1] = 0; d[2][NEED2] = 0;
	START[0] = 1; START[1] = NEED1; START[2] = NEED2;
	stra(0); 
	stra(1); 
	stra(2);
	int min1 = d[0][NEED1] + d[1][NEED2] + d[2][N];
	int min2 = d[0][NEED2] + d[2][NEED1] + d[1][N];
	int ans = min(min1, min2);
	if (ans >= INF)
		cout << -1;
	else cout << ans;
	return 0;
}