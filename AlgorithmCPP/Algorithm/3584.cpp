#include <bits/stdc++.h>
using namespace std;

int T, N, a, b, tree[10001], parent[10001][15], level[10001], visited[10001], len;
vector<int> vect[10001], ans;

void dfs(int now, int depth) {
	visited[now] = 1;
	level[now] = depth;

	for (int next : vect[now]) {
		if (visited[next]) continue;
		parent[next][0] = now;
		dfs(next, depth + 1);
	}

	return;
}

int findRoot() {
	for (int i = 1; i <= N; i++)
		if (!tree[i]) return i;
}

void setParent() {
	int root = findRoot();
	dfs(root, 1);
	for (int j = 1; j <= len; j++) {
		for (int i = 1; i <= N; i++)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
	}
}

int LCA() {
	if (level[a] < level[b])
		swap(a, b);

	int gap = level[a] - level[b];
	for (int i = 0; gap > 0; i++) {
		if (gap % 2)
			a = parent[a][i];
		gap = gap >> 1;
	}

	if (a == b) return a;

	for (int i = len-1; i >= 0; i--) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		memset(visited, 0, sizeof(visited));
		memset(tree, 0, sizeof(tree));
		memset(parent, 0, sizeof(parent));
		memset(level, 0, sizeof(level));
		cin >> N;
		len = ceil(log2(N));
		for (int i = 1; i <= N; i++)
			vect[i].clear();
		for (int i = 1; i < N; i++) {
			cin >> a >> b;
			tree[b] = a;
			vect[a].push_back(b);
		}
		cin >> a >> b;
		setParent();
		ans.push_back(LCA());
	}
	for (int ret : ans)
		cout << ret << '\n';
	return 0;
}