#include <bits/stdc++.h>
#include <assert.h>
#define int long long

using namespace std;

vector<int> vect[10001];
vector<vector<int>> SCC;
vector<int> scc;

stack<int> st;
int N, M, a, b, visited[10001], finished[10001], cnt;

int dfs(int now) {
	int p = visited[now] = cnt++;
	st.push(now);
	
	for (int next : vect[now]) {
		if (!visited[next])
			p = min(p, dfs(next));
		else if (!finished[next])
			p = min(p, visited[next]);
	}

	if (p == visited[now]) {
		scc.clear();
		while (st.top() != now) {
			scc.push_back(st.top());
			finished[st.top()] = 1;
			st.pop();
		}
		scc.push_back(st.top());
		finished[st.top()] = 1;
		st.pop();
		SCC.push_back(scc);
	}

	return p;
}

signed main() {
	[&]() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			vect[a].push_back(b);
		}
	}();
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cnt = 1;
			dfs(i);
		}
	}
	for (int i = 0; i < SCC.size(); i++)
		sort(SCC[i].begin(), SCC[i].end());
	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << '\n';
	for (vector<int> v : SCC) {
		for (int i : v)
			cout << i << ' ';
		cout << "-1\n";
	}
	return 0;
}