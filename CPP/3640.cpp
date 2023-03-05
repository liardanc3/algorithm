#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;

struct node {
	int next, capacity, pay, revidx;
	node(int n, int c, int p, int r) {
		next = n, capacity = c, pay = p, revidx = r;
	}
}; vector<node> vect[2001];

int t, v, e, a, b, c, visited[2001], idx[2001], dist[2001], inq[2001];
int spfa() {
	fill(dist, dist + 2001, 1e9);
	inq[2] = 1; dist[2] = 0;
	queue<int> q; q.push(1);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		inq[now] = 0;

		for (node n : vect[now]) {
			int next = n.next;
			int capacity = n.capacity;
			int pay = n.pay;

			if (dist[now] + pay < dist[next] && capacity > 0) {
				dist[next] = dist[now] + pay;
				if (!inq[next]) {
					inq[next] = 1;
					q.push(next);
				}
			}
		}
	}
	return dist[2 * v] == 1e9 ? 0 : 1;
}
signed main() {
	fastio;
	while (cin >> v) {
		if (cin.eof())
			break;
		for (int i = 1; i <= v; i++)
			vect[i].clear();
		cin >> e;
		while (e--) {
			cin >> a >> b >> c;

			int in = 2 * a, out = 2 * a + 1, nxt = 2 * b;

			// in -> out;
			vect[in].push_back({ out, a == 1 || a == 2 ? 1'000'000'000 : 1,0,(int)vect[b].size() });
			vect[out].push_back({ in, 0, 0, (int)vect[out].size() - 1 });

			// out -> nxt;

		}

	}

	return 0;
}