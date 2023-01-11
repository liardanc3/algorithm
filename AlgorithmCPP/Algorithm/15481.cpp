#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;
vector<pii> vect[200001], mstuse[200001];
priority_queue<tii, vector<tii>, greater<tii>> pq;
vector<tii> edge;

int N, M, a, b, c, level[200001], parent[200001][19], dist[200001][19], len, tree[200001], mst, m, start;
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
void MST() {
	while (!pq.empty() && m < N - 1) {
		int cost = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());

		pq.pop();

		if (getRoot(a) == getRoot(b))
			continue;

		mstuse[a].push_back({ b,cost });
		mstuse[b].push_back({ a,cost });
		tree[getRoot(a)] = getRoot(b);
		m++;
		mst += cost;
	}
	return;
}
void dfs(int now, int depth) {
	level[now] = depth;
	for (pii next : mstuse[now]) {
		if (level[next.first])
			continue;

		parent[next.first][0] = now;
		dist[next.first][0] = next.second;
		dfs(next.first, depth + 1);
	}
	return;
}
int LCA(int a, int b) {
	int mx = 0;
	if (level[a] < level[b])
		swap(a, b);

	int dif = level[a] - level[b];
	for (int i = 0; dif > 0; i++) {
		if (dif % 2) {
			mx = max(mx, dist[a][i]);
			a = parent[a][i];
		}
		dif >>= 1;
	}

	if (a == b)
		return mx;

	for (int i = len; i >= 0; i--) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			mx = max(mx, max(dist[a][i], dist[b][i]));
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	mx = max(mx, max(dist[a][0], dist[b][0]));
	return mx;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		len = ceil(log2(N));
		for (int i = 1; i <= N; i++)
			tree[i] = i;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			edge.push_back({ a,b,c });
			pq.push({ c,a,b });
			vect[a].push_back({ b,c });
			vect[b].push_back({ a,c });
		}
		start = get<1>(pq.top());
		MST();
		dfs(start, 1);
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= N; j++) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
				dist[j][i] = max(dist[j][i - 1], dist[parent[j][i - 1]][i - 1]);
			}
		}
	}();
	for (int i = 0; i < M; i++) {
		int a = get<0>(edge[i]);
		int b = get<1>(edge[i]);
		int cost = get<2>(edge[i]);

		int lca = LCA(a, b);
		cout << mst + cost - lca << '\n';
	}
	return 0;
}