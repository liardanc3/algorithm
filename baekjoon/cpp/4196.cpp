#include <bits/stdc++.h>
using namespace std;

stack<int> st;
vector<int> vect[100001];
int N, M, visited[100001], finished[100001];
int cnt, a, b, ans, t, in[100001], ck[100001], scc;
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
		++scc;
		while (st.top() != now) {
			finished[st.top()] = 1;
			ck[st.top()] = scc;
			st.pop();
		}
		finished[st.top()] = 1;
		ck[st.top()] = scc;
		st.pop();
	}
	return p;
}
void DFS(int now, int sccnum) {
	for (int next : vect[now]) {
		if (!visited[next]) {
			visited[next] = 1;
			if (ck[next] != sccnum)
				in[ck[next]] = 1;
			DFS(next, sccnum);
		}
		else if (visited[next] && ck[next] != sccnum)
			in[ck[next]] = 1;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		ans = 0, scc = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			vect[i].clear();
		memset(visited, 0, sizeof(visited));
		memset(in, 0, sizeof(in));
		memset(ck, 0, sizeof(ck));
		memset(finished, 0, sizeof(finished));
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			vect[a].push_back(b);
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				cnt = 1;
				dfs(i);
			}
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) 
				DFS(i, ck[i]);
		}
		for (int i = 1; i <= scc; i++) {
			if (!in[i])
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}