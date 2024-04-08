#include <bits/stdc++.h>
#define int long long
using namespace std;

stack<int> st;
vector<int> _vect[2020], * vect = &_vect[1010];
int _visited[2020], _finished[2020], _sccnum[2020], sccidx, cnt;
int* visited = &_visited[1010], * finished = &_finished[1010], * sccnum = &_sccnum[1010];
int N, M, a, b;
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
	while (cin >> N) {
		if (cin.eof())
			break;
		sccidx = 0;
		while (!st.empty())
			st.pop();
		memset(_visited, 0, sizeof(_visited));
		memset(_finished, 0, sizeof(_finished));
		memset(_sccnum, 0, sizeof(_sccnum));
		for (int i = -N; i <= N; i++)
			vect[i].clear();
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			vect[-a].push_back(b);
			vect[-b].push_back(a);
		}	
		for (int i = -N; i <= N; i++) {
			if (i == 0)
				continue;
			if (!visited[i]) {
				cnt = 1;
				dfs(i);
			}
		}
		for (int i = 1; i <= N; i++) {
			if (sccnum[i] == sccnum[-i]) {
				cout << 0 << '\n';
				break;
			}
			if (i == N)
				cout << 1 << '\n';
		}
	}
	return 0;
}