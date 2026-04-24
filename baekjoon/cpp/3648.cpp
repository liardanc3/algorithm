#include <bits/stdc++.h>
#define int long long
using namespace std;

stack<int> st;
vector<int> _vect[2020], * vect = &_vect[1010];
int n, m, a, b, _visited[2020], _finished[2020], _sccnum[2020], cnt, sccidx;
int* visited = &_visited[1010], * finished = &_finished[1010], * sccnum = &_sccnum[1010];
int dfs(int now) {
	int p = visited[now] = cnt++;
	st.push(now);

	for (int next : vect[now]) {
		if (!visited[next])
			p = min(p, dfs(next));
		else if (visited[next] && !finished[next])
			p = min(p, visited[next]);
	}

	if (p == visited[now]) {
		sccidx++;
		while (st.top() != now) {
			finished[st.top()] = 1;
			sccnum[st.top()] = sccidx;
			st.pop();
		}
		finished[st.top()] = 1;
		sccnum[st.top()] = sccidx;
		st.pop();
	}
	return p;
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (cin >> n >> m) {
		if (cin.eof())
			break;
		[&]() {
			while (!st.empty())
				st.pop();
			for (int i = -n; i <= n; i++)
				vect[i].clear();
			memset(_finished, 0, sizeof(_finished));
			memset(_visited, 0, sizeof(_visited));
			memset(_sccnum, 0, sizeof(_sccnum));
			sccidx = 0;
			vect[-1].push_back(1);
			for (int i = 0; i < m; i++) {
				cin >> a >> b;
				vect[-a].push_back(b);
				vect[-b].push_back(a);
			}
			for (int i = -n; i <= n; i++) {
				if (i == 0) continue;
				if (!visited[i]) {
					cnt = 1;
					dfs(i);
				}
			}
			for (int i = 1; i <= n; i++) {
				if (sccnum[i] == sccnum[-i]) {
					cout << "no\n";
					break;
				}
				if (i == n)
					cout << "yes\n";
			}
		}();
	}
	return 0;
}