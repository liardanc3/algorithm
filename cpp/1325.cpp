#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, visited[10001], mx, hack[10001];
vector<int> vect[10001], ans;
void dfs(int now, int root) {
	visited[now] = 1;
	hack[root]++;
	for (int next : vect[now]) {
		if (!visited[next])
			dfs(next, root);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	while (M--) {
		cin >> a >> b;
		vect[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, i);
		mx = max(mx, hack[i]);
		memset(visited, 0, sizeof(visited));
	}
	for (int i = 1; i <= N; i++) {
		if (mx == hack[i])
			cout << i << ' ';
	}
	return 0;
}