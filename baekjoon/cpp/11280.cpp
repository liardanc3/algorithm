#include <bits/stdc++.h>
#define int long long
using namespace std;

stack<int> st;
vector<int> _vect[20202], * vect = &_vect[10101];
int N, M, a, b, _visited[20202], * visited = &_visited[10101], sccidx;
int cnt, _finished[20202], * finished = &_finished[10101], _sccnum[20202], * sccnum = &_sccnum[10101];
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
		++sccidx;
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
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			cin >> a >> b;
			vect[-1 * a].push_back(b);
			vect[-1 * b].push_back(a);
		}
	}();
	for (int i = -N; i <= N; i++) {
		if (i == 0) continue;
		if (!visited[i]) {
			cnt = 1;
			dfs(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (sccnum[i] == sccnum[-i]) {
			cout << 0;
			exit(0);
		}
	}
	cout << 1;
	return 0;
}