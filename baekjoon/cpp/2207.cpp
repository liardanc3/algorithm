#include <bits/stdc++.h>
#define int long long
using namespace std;

stack<int> st;
vector<int> _vect[20202], * vect = &_vect[10101];
int N, M, a, b, _visited[20202], _finished[20202], _sccnum[20202], cnt, sccidx;
int* visited = &_visited[10101], * finished = &_finished[10101], * sccnum = &_sccnum[10101];
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
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> a >> b;
			vect[-a].push_back(b);
			vect[-b].push_back(a);
		}
	}();
	for (int i = -M; i <= M; i++) {
		if (i == 0) continue;
		if (!visited[i]) {
			cnt = 1;
			dfs(i);
		}
	}
	for (int i = 1; i <= M; i++) {
		if (sccnum[i] == sccnum[-i]) {
			cout << "OTL";
			exit(0);
		}
	}
	cout << "^_^";
	return 0;
}