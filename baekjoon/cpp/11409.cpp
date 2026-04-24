#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct node {
	int next, capacity, cost, revidx;
	node(int n, int c, int co, int r) {
		next = n, capacity = c, cost = co, revidx = r;
	}
}; vector<node> vect[803];

int N, M, workcnt, worknum, pay, idx[803], dist[803], inq[803], visited[803], mc, mf;
int bfs() {
	fill(&dist[0], &dist[803], 1e9);
	dist[1] = 0; inq[1] = 1;
	queue<int> q; q.push(1);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		inq[now] = 0;

		for (node n : vect[now]) {
			int next = n.next;
			int capacity = n.capacity;
			int dst = n.cost;

			if (capacity > 0 && dist[now] + dst < dist[next]) {
				dist[next] = dist[now] + dst;
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

		if (!visited[next] && dist[now] + cost == dist[next] && capacity > 0) {
			int blockflow = dfs(next, min(capacity, wat));
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
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			vect[1].push_back({ 1 + i,1,0,(int)vect[1 + i].size() });
			vect[1 + i].push_back({ 1,0,0,(int)vect[1].size() - 1 });

			cin >> workcnt;
			for (int j = 1; j <= workcnt; j++) {
				cin >> worknum >> pay;

				int src = 1 + i;
				int dst = 1 + N + worknum;

				vect[src].push_back({ dst, 1, -pay, (int)vect[dst].size() });
				vect[dst].push_back({ src, 0, pay, (int)vect[src].size() - 1 });
			}
		}
		for (int j = 1; j <= M; j++) {
			vect[1 + N + j].push_back({ 1 + N + M + 1, 1, 0, (int)vect[1 + N + M + 1].size() });
			vect[1 + N + M + 1].push_back({ 1 + N + j, 0, 0, (int)vect[1 + N + j].size() - 1 });
		}
	}();
	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = dfs(1, 1e9);
			memset(visited, 0, sizeof(visited));
			if (!flow)
				break;
			mc += flow * -dist[1 + N + M + 1];
			mf += flow;
		}
	}
	cout << mf << '\n' << mc;
	return 0;
}