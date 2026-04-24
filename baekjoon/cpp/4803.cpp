#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, tree, visited[501], tc;
vector<int> vect[501];
int dfs(int now, int before) {
	if (vect[now].size() == 0)
		return 1;

	int ret = 1;
	for (int i = 0; i < vect[now].size(); i++) {
		int next = vect[now][i];

		if (next == before) continue;

		if (!visited[next]) {
			visited[next] = 1;
			ret = min(ret, dfs(next, now));
		}
		else
			return 0;
	}

	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n >> m) {
		tc++;
		tree = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= n; i++)
			vect[i].clear();
		if (!n && !m)
			break;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			vect[a].push_back(b);
			vect[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				int result = dfs(i, -1);
				if (result) tree++;
			}
		}
		cout << "Case " << tc << ": ";
		if (!tree)
			cout << "No trees.\n";
		else if (tree == 1)
			cout << "There is one tree.\n";
		else cout << "A forest of " << tree << " trees.\n";
	}
	return 0;
}