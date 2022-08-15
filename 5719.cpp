#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
pii visited[500];
vector<pii> vect[500];
int N, M, src, dst, a, b, c, dist[500], ban[500][500], ck[500];

void dijkstra() {
	fill(&dist[0], &dist[500], 2e9);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,src });
	dist[src] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if (cost > dist[now])
			continue;

		for (pii next : vect[now]) {
			if (ban[now][next.first])
				continue;
			if (cost + next.second < dist[next.first]) {
				dist[next.first] = cost + next.second;
				pq.push({dist[next.first], next.first});
			}
		}
	}
}
pii dfs(int now, int total) {
	//cout << "now : " << now << ", total : " << total << '\n';
	if (total > dist[dst])
		return visited[now] = { 0,total };
	if (now == dst)
		return visited[now] = { dist[dst] == total, total };
	int p = 0;
	for (int i = 0; i < vect[now].size(); i++) {
		int next = vect[now][i].first;
		int cost = vect[now][i].second;

		if (visited[next].first == 1) {
			if (visited[next].second == total+cost)
				ban[now][next] = 1;
			p = max(p,(int)(visited[next].second == total+cost));
			continue;
		}
			
		if (visited[next].first == 0 && visited[next].second == total + cost)
			continue;

		if (ck[next])
			continue;
		ck[next] = 1;
		pii nextp = dfs(next, total + cost);
		if (nextp.first == 1 && nextp.second == total+cost)
			ban[now][next] = 1;
		p = max(p, nextp.first);
		ck[next] = 0;
	}
	return visited[now] = { p,total };
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (cin >> N >> M) {
		if (!N && !M)
			break;
		[&]() {
			fill(&dist[0], &dist[500], 2e9);
			memset(visited, 0, sizeof(visited));
			memset(ck, 0, sizeof(ck));
			memset(ban, 0, sizeof(ban));
			for (int i = 0; i < 500; i++)
				vect[i].clear();
			cin >> src >> dst;
			for (int i = 0; i < M; i++) {
				cin >> a >> b >> c;
				vect[a].push_back({ b,c });
			}
		}();
		dijkstra();
		dfs(src, 0);
		dijkstra();
		dist[dst] == 2e9 ? cout << -1 << '\n' : cout << dist[dst] << '\n';
	}
	return 0;
}