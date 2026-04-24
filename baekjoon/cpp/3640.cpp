#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct node {
	int next, capacity, pay, revidx;
	node(int n, int c, int p, int r) {
		next = n, capacity = c, pay = p, revidx = r;
	}
}; vector<node> vect[2002];

int t, v, e, a, b, c, dist[2002], inq[2002], mx, fl;
pii rev[2002];
int spfa() {
	memset(rev, 0, sizeof rev);
	fill(dist, dist + 2002, 1e9);
	memset(inq, 0, sizeof inq);
	inq[2] = 1; dist[2] = 0;
	queue<int> q; q.push(2);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		inq[now] = 0;

		int tick = -1;
		for (node n : vect[now]) {
			tick++;
			int next = n.next;
			int capacity = n.capacity;
			int pay = n.pay;
			int revidx = n.revidx;

			if (dist[now] + pay < dist[next] && capacity > 0) {
				dist[next] = dist[now] + pay;
				rev[next] = { now, tick };
				if (!inq[next]) {
					inq[next] = 1;
					q.push(next);
				}
			}
		}
	}
	return dist[2 * v + 1] == 1e9 ? 0 : 1;
}
void dfs(int next, int wat) {
	if (next == 2)
		return;

	int now = rev[next].first;
	int tick = rev[next].second;

	vect[now][tick].capacity -= 1;
	vect[next][vect[now][tick].revidx].capacity += 1;
	
	dfs(now, min(wat,vect[now][tick].capacity));
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (cin >> v >> e) {
		if (cin.eof())
			exit(0);

		[&]() {
			for (int i = 1; i <= 2*v+1; i++)
				vect[i].clear();
			mx = 0;
		}();


		[&]() {
			while (e--) {
				cin >> a >> b >> c;

				int out = 2 * a + 1, nxt = 2 * b;

				// out -> nxt;
				vect[out].push_back({ nxt, 1, c, (int)vect[nxt].size() });
				vect[nxt].push_back({ out,0, -c,(int)vect[out].size() - 1 });
			}
			for (int i = 1; i <= v; i++) {
				int in = i * 2, out = i * 2 + 1;

				// in -> out
				vect[in].push_back({ out, (i == 1 || i == v) ? 2 : 1,0,(int)vect[out].size() });
				vect[out].push_back({ in, 0, 0, (int)vect[in].size() - 1 });
			}
		}();

		spfa();
		mx += dist[2 * v + 1];
		dfs(2 * v + 1, 1e9);
		spfa();
		cout << mx + dist[2 * v + 1] << '\n';
	}
	return 0;
}