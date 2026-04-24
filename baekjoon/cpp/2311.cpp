#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
	int next, capacity, pay, revidx;
	node(int n, int c, int p, int r) {
		next = n, capacity = c, pay = p, revidx = r;
	}
}; vector<node> vect[20002];

int N, M, a, b, c, dist[20002], visited[20002], idx[20002], inq[20002], t;
void setedge(int a, int b, int capacity, int cost) {
	vect[a].push_back({ b,capacity,cost,(int)vect[b].size() });
	vect[b].push_back({ a,0,-cost,(int)vect[a].size() - 1 });
}
void spfa() {
	fill(dist, dist + 20002, 1e9);
	queue<int> q; q.push(1);
	inq[1] = 1; dist[1] = 0;
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
}
int dfs(int now, int wat) {
	visited[now] = 1;
	if (now == N)
		return 1;

	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int& capacity = vect[now][i].capacity;
		int& rcapacity = vect[next][vect[now][i].revidx].capacity;
		int pay = vect[now][i].pay;

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
signed main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> c;

		int in = N + 2 * i;
		int out = N + 2 * i + 1;

		// a -> in
		setedge(a, in, 1, 0);

		// in -> out
		setedge(in, out, 1, c);

		// out -> b
		setedge(out, b, 1, 0);

		// b -> in
		setedge(b, in, 1, 0);

		// out -> a
		setedge(out, a, 1, 0);
	}
	spfa();;
	t += dist[N];
	dfs(1, 1e9);
	spfa();
	cout << t + dist[N];
	return 0;
}