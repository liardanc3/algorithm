#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect[30001];
int N, M, a, b, visited[30001], cnt, t, flag;
int dfs(int now, int root) {

	int p = visited[now] = cnt++;

	int child = 0;
	for (int next : vect[now]) {
		if (!visited[next]) {
			child++;

			int nextp = dfs(next, 0);
			if (!root && nextp >= visited[now])
				flag = 1;

			p = min(p, nextp);
		}
		else
			p = min(p, visited[next]);
	}

	if (root && child > 1)
		flag = 1;

	return p;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		flag = 0;
		cnt = 1;
		cin >> N >> M;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= N; i++)
			vect[i].clear();
		while (M--) {
			cin >> a >> b;
			vect[a].push_back(b);
			vect[b].push_back(a);
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i])
				dfs(i, 1);
		}
		flag ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}