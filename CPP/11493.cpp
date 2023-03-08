#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, pay, revidx;
	node(int n, int c, int p, int r) {
		next = n, capacity = c, pay = p, revidx = r;
	}
}; vector<node> vect[502];

int T, n, m, x, y, idx[502], block[502], coin[502], ret, inq[502], dist[502], visited[502], tmp;
void addedge(int s, int d, int capacity, int pay) {
	vect[s].push_back({ d,capacity, pay, (int)vect[d].size() });
	vect[d].push_back({ s,0,-pay,(int)vect[s].size() - 1 });
}
void init() {
	for (int i = 0; i <= 501; i++)
		vect[i].clear();
	ret = 0;
	cin >> n >> m;
	while (m--) {
		cin >> x >> y;
		addedge(x, y, 1e9, 1);
		addedge(y, x, 1e9, 1);
	}
	for (int i = 1; i <= n; i++) 
		cin >> block[i];
	for (int i = 1; i <= n; i++) 
		cin >> coin[i];
	for (int i = 1; i <= n; i++) {
		if (block[i] && !coin[i])
			addedge(0, i, 1, 0);
		if (!block[i] && coin[i])
			addedge(i, 1 + n, 1, 0);
	}
}
int spfa() {
	memset(dist, 0x3f, sizeof dist);
	queue<int> q; q.push(0);
	inq[0] = 1; dist[0] = 0;
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
					q.push(next);
					inq[next] = 1;
				}
			}
		}
	}
	return dist[n+1] >= 1e9 ? 0 : 1;
}
int dfs(int now, int wat) {
	visited[now] = 1;
	if (now == n+1)
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
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		init();
		while (spfa()) {
			memset(idx, 0, sizeof(idx));
			int flow = dfs(0, 1e9);
			memset(visited, 0, sizeof(visited));
			if (!flow)
				break;
			ret += dist[1 + n];
		}
		cout << ret << '\n';
	}

	return 0;
}