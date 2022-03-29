#include <bits/stdc++.h>
using namespace std;
int n, a, b, visited[51], mn = 1e9;
vector<int> vect[51], ans;
void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	int depth = -1;
	while (!q.empty()) {
		depth++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front(); q.pop();

			for (int j = 0; j < vect[now].size(); j++) {
				int next = vect[now][j];
				if (!visited[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}
		}
	}
	if (depth < mn) {
		mn = depth;
		ans.clear();
		ans.push_back(start);
	}
	else if (depth == mn)
		ans.push_back(start);
}
int main() {
	cin >> n;
	while (cin >> a >> b) {
		if (a + b == -2) break;
		vect[a].push_back(b);
		vect[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		bfs(i);
	}
	cout << mn << ' ' << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	return 0;
}