#include <bits/stdc++.h>
using namespace std;
int T, a, b, parent[1024][11], level[1024];

void dfs(int now, int depth) {
	if (now > 1023) return;
	parent[now][0] = now / 2;
	level[now] = depth;
	dfs(now * 2, depth + 1);
	dfs(now * 2 + 1, depth + 1);
	return;
}

void setParent() {
	for (int i = 1; i <= ceil(log2(1023)); i++) {
		for (int j = 1; j <= 1023; j++)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
	}
}

int LCA() {
	if (level[a] < level[b])
		swap(a, b);

	int dif = level[a] - level[b];

	for (int i = 0; dif > 0; i++) {
		if (dif % 2) 
			a = parent[a][i];
		dif >>= 1;
	}

	if (a == b) return a;

	for (int i = ceil(log2(1023)) - 1; i >= 0; i--) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];
}

int main() {
	dfs(1, 1);
	setParent();
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> a >> b;
		cout << LCA()*10 << '\n';
	}
	return 0;
}