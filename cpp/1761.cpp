#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> vect[40001];
int N, M, a, b, c, level[40001], parent[40001][17], len, dist[40001][17], lca;

void dfs(int now, int depth) {
	level[now] = depth;
	for (pii next : vect[now]) {
		if (level[next.first]) continue;

		parent[next.first][0] = now;
		dist[next.first][0] = next.second;
		dfs(next.first, depth + 1);
	}
	return;
}

int LCA(int a, int b) {
	int ans = 0;
	if (level[a] < level[b])
		swap(a, b);

	int dif = level[a] - level[b];
	for (int i = 0; dif > 0; i++) {
		if (dif % 2) {
			ans += dist[a][i];
			a = parent[a][i];
		}
		dif >>= 1;
	}

	if (a == b) return ans;

	for (int i = len; i >= 0; i--) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			ans += dist[a][i];
			ans += dist[b][i];
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return ans + dist[a][0] + dist[b][0];
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		len = ceil(log2(N));
		for (int i = 1; i < N; i++) {
			cin >> a >> b >> c;
			vect[a].push_back({ b,c });
			vect[b].push_back({ a,c });
		}
		dfs(1, 1);
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= N; j++) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
				dist[j][i] = dist[j][i - 1] + dist[parent[j][i - 1]][i - 1];
			}
		}

	}();
	cin >> M;
	while (M--) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}

	return 0;
}