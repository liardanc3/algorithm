#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
struct node {
	int next, capacity, cost, revidx;
	node(int n, int c, int co, int r) {
		next = n, capacity = c, cost = co, revidx = r;
	}
}; vector<node> vect[203];

int N, M, tmp, idx[203], visited[203], dist[203], inq[203], mc;
int spfa() {
	fill(&dist[0], &dist[203], 1e9);
	inq[1] = 1, dist[1] = 0;
	queue<int> q; q.push(1);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		inq[now] = 0;

		for (node n : vect[now]) {
			int next = n.next;
			int capacity = n.capacity;
			int d = n.cost;

			if (capacity > 0 && dist[now] + d < dist[next]) {
				dist[next] = dist[now] + d;
				if (!inq[next]) {
					inq[next] = 1;
					q.push(next);
				}
			}
		}
	}
	return dist[1 + N + M + 1] == 1e9 ? 0 : 1;
}
int dfs(int now, int wat) {
	visited[now] = 1;
	if (now == 1 + N + M + 1)
		return wat;

	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int& capacity = vect[now][i].capacity;
		int cost = vect[now][i].cost;
		int& rcapacity = vect[next][vect[now][i].revidx].capacity;

		if (!visited[next] && capacity > 0 && dist[now] + cost == dist[next]) {
			int blockflow = dfs(next, min(wat, capacity));
			if (blockflow > 0) {
				capacity -= blockflow;
				rcapacity += blockflow;
				return blockflow;
			}
		}
	}

	return 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		vect[1].push_back({1 + i, tmp, 0, (int)vect[1 + i].size()});
		vect[1 + i].push_back({ 1, 0, 0, (int)vect[1].size() - 1 });
	}
	for (int i = 1; i <= M; i++) {
		cin >> tmp;
		vect[1 + N + i].push_back({ 1 + N + M + 1, tmp, 0, (int)vect[1 + N + M + 1].size() });
		vect[1 + N + M + 1].push_back({ 1 + N + i, 0, 0, (int)vect[1 + N + i].size() - 1 });
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			vect[1 + j].push_back({ 1 + N + i, 1'000'000'000, tmp, (int)vect[1 + N + i].size() });
			vect[1 + N + i].push_back({ 1 + j, 0, -tmp,(int)vect[1 + j].size() - 1 });
		}
	}
	while (spfa()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = dfs(1, 1e9);
			memset(visited, 0, sizeof(visited));
			if (!flow)
				break;
			mc += flow * dist[1 + N + M + 1];
		}
	}
	cout << mc;
	return 0;
}