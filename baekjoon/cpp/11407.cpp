#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, pay, revidx;
	node(int n, int c, int p, int r) {
		next = n, capacity = c, pay = p, revidx = r;
	}
}; vector<node> vect[203];

int N, M, tmp, a, b, c[203][203], inq[203], dist[203], idx[203], visited[203], fl, ct;
int spfa() {
	memset(dist, 0x3f, sizeof dist);
	queue<int> q; q.push(1);
	inq[1] = 1; dist[1] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		inq[now] = 0;

		for (node n : vect[now]) {
			int next = n.next;
			int capacity = n.capacity;
			int pay = n.pay;

			if (dist[now] + n.pay < dist[next] && capacity > 0) {
				dist[next] = dist[now] + n.pay;
				if (!inq[next]) {
					inq[next] = 1;
					q.push(next);
				}
			}
		}
	}
	return dist[1 + N + M + 1] > 1e9 ? 0 : 1;
}
int dfs(int now, int wat) {
	visited[now] = 1;
	if (now == 1 + N + M + 1)
		return wat;
	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int& capacity = vect[now][i].capacity;
		int pay = vect[now][i].pay;
		int& rcapacity = vect[next][vect[now][i].revidx].capacity;

		if (!visited[next] && dist[now] + pay == dist[next] && capacity > 0) {
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
	cin >> N >> M;

	[&]() {
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			a = 1, b = 1 + i;
			vect[a].push_back({ b,tmp,0,(int)vect[b].size() });
			vect[b].push_back({ a,0,0,(int)vect[a].size() - 1 });
		}
		for (int i = 1; i <= M; i++) {
			cin >> tmp;
			a = 1 + N + i, b = 1 + N + M + 1;
			vect[a].push_back({ b,tmp,0,(int)vect[b].size() });
			vect[b].push_back({ a, 0,0,(int)vect[a].size() - 1 });
		}
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++)
				cin >> c[i][j];
		}
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> tmp;
				a = 1 + j, b = 1 + N + i;
				vect[a].push_back({ b,c[i][j],tmp,(int)vect[b].size() });
				vect[b].push_back({ a, 0, -tmp,(int)vect[a].size() - 1 });
			}
		}
	}();
	
	while (spfa()) {
		memset(idx, 0, sizeof idx);
		while (1) {
			int flow = dfs(1, 1e9);
			memset(visited, 0, sizeof(visited));
			if (!flow)
				break;
			fl += flow;
			ct += flow * dist[1 + N + M + 1];
		}
	}

	cout << fl << '\n' << ct;
	return 0;
}