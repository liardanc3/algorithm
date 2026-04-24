#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;

priority_queue<tii, vector<tii>, greater<tii>> pq;
vector<pii> mstvect[50001];
vector<tii> erased;

int N, M, a, b, c, level[50001], parent[50001][18], dist[50001][18], tree[50001], len, start, m, mn = 1e11, mst;
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
void MST() {
	while (!pq.empty() && m < N - 1) {
		int cost = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());

		pq.pop();

		if (getRoot(a) == getRoot(b)) {
			erased.push_back({ cost,a,b });
			continue;
		}
			
		mstvect[a].push_back({ b,cost });
		mstvect[b].push_back({ a,cost });
		m++;
		mst += cost;
		tree[getRoot(a)] = getRoot(b);
	}
	return;
}
void dfs(int now, int depth) {
	level[now] = depth;
	for (pii next : mstvect[now]) {
		if (level[next.first])
			continue;

		parent[next.first][0] = now;
		dist[next.first][0] = next.second;
		dfs(next.first, depth + 1);
	}
	return;
}
int LCA(int a, int b, int cost) {
	int mx = -1;
	if (level[a] < level[b])
		swap(a, b);

	int dif = level[a] - level[b];
	for (int i = 0; dif > 0; i++) {
		if (dif % 2) {
			if (dist[a][i] != cost) {
				mx = max(mx, dist[a][i]);
				a = parent[a][i];
			}
			else {
				for (int j = 0; j < (1 << i); j++) {
					if(dist[a][0] != cost)
						mx = max(mx, dist[a][0]);
					a = parent[a][0];
				}
			}
		}
		dif >>= 1;
	}

	if (a == b)
		return mx;

	for (int i = len; i >= 0; i--) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			if (dist[a][i] != cost) {
				mx = max(mx, dist[a][i]);
				a = parent[a][i];
			}
			else {
				for (int j = 0; j < (1 << i); j++) {
					if (dist[a][0] != cost)
						mx = max(mx, dist[a][0]);
					a = parent[a][0];
				}
			}
			if (dist[b][i] != cost) {
				mx = max(mx, dist[b][i]);
				b = parent[b][i];
			}
			else {
				for (int j = 0; j < (1 << i); j++) {
					if (dist[b][0] != cost)
						mx = max(mx, dist[b][0]);
					b = parent[b][0];
				}
			}
		}
	}

	if (dist[a][0] != cost)
		mx = max(mx, dist[a][0]);
	if (dist[b][0] != cost)
		mx = max(mx, dist[b][0]);
	return mx;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			tree[i] = i;
		len = ceil(log2(N));
		for (int i = 1; i <= M; i++) {
			cin >> a >> b >> c;
			pq.push({ c,a,b });
		}
		start = get<1>(pq.top());
		MST();
	}();
	if (m != N - 1 || (pq.empty() && erased.empty()))
		cout << -1;
	else {
		[&]() {
			dfs(start, 1);
			for (int i = 1; i <= len; i++) {
				for (int j = 1; j <= N; j++) {
					parent[j][i] = parent[parent[j][i - 1]][i - 1];
					dist[j][i] = max(dist[j][i - 1], dist[parent[j][i - 1]][i - 1]);
				}
			}
		}();
		for (tii t : erased)
			pq.push(t);
		while (!pq.empty()) {
			int cost = get<0>(pq.top());
			int a = get<1>(pq.top());
			int b = get<2>(pq.top());

			pq.pop();

			int lca = LCA(a, b, cost);
			if (cost > lca && lca != -1)
				mn = min(mn, mst + cost - lca);
		}
		mn == 1e11 ? cout << -1 : cout << mn;
	}
	return 0;
}