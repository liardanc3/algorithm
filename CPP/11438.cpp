#include <bits/stdc++.h>
using namespace std;


vector<int> vect[100001];
int N, M, a, b, level[100001], parent[100001][20], len;

void dfs(int now, int depth) {
	level[now] = depth;

	for (int next : vect[now]) {
		if (!level[next]) {
			parent[next][0] = now;
			dfs(next, depth + 1);
		}
	}

	return;
}

int LCA(int a, int b) {
	if (level[a] < level[b])
		swap(a, b);

	int dif = level[a] - level[b];
	for (int i = 0; dif > 0; i++) {
		if (dif % 2)
			a = parent[a][i];
		dif >>= 1;
	}

	if (a == b) return a;

	for (int i = len - 1; i >= 0; i--) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		len = ceil(log2(N));
		for (int i = 1; i < N; i++) {
			cin >> a >> b;
			vect[a].push_back(b);
			vect[b].push_back(a);
		}
		dfs(1, 1);
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= N; j++)
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}();
	cin >> M;
	while (M--) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}