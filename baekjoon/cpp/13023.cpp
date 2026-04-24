#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, visited[2000];
vector<int> vect[2000];
int dfs(int now, int depth) {
	if (depth == 4) return 1;
	int ret = 0;
	visited[now] = 1;
	for (int i = 0; i < vect[now].size() && !ret; i++) {
		int next = vect[now][i];

		if (!visited[next])
			ret = max(ret, dfs(next, depth + 1));
	}
	visited[now] = 0;
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vect[a].push_back(b);
		vect[b].push_back(a);
	}
	int flag = 0;
	for (int i = 0; i < n && !flag; i++) {
		flag = dfs(i, 0);
	}
	cout << flag;
	return 0;
}