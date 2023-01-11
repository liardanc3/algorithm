#include <bits/stdc++.h>
using namespace std;

stack<int> st;
vector<int> vect[100000];
int t, cnt, N, M, a, b, in[100000], visited[100000], finished[100000];
int sccidx, sccnum[100000], sccin[100000];
int findscc(int now) {
	int p = visited[now] = cnt++;
	st.push(now);

	for (int next : vect[now]) {
		if (!visited[next])
			p = min(p, findscc(next));
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
void dfs(int now, int scc) {
	for (int next : vect[now]) {
		if (!visited[next]) {
			visited[next] = 1;
			if (scc != sccnum[next])
				sccin[sccnum[next]] = 1;
			dfs(next, sccnum[next]);
		}
		else if (visited[next] && scc != sccnum[next])
			sccin[sccnum[next]] = 1;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		[&]() {
			cin >> N >> M;
			sccidx = 0;
			for (int i = 0; i < N; i++)
				vect[i].clear();
			memset(in, 0, sizeof(in));
			memset(visited, 0, sizeof(visited));
			memset(finished, 0, sizeof(finished));
			memset(sccin, 0, sizeof(sccin));
			memset(sccnum, 0, sizeof(sccnum));
			for (int i = 0; i < M; i++) {
				cin >> a >> b;
				vect[a].push_back(b);
				in[b]++;
			}
			vector<int> tmp;
			for (int i = 0; i < N; i++) {
				if (!in[i])
					tmp.push_back(i);
			}
			if (tmp.size() > 1)
				cout << "Confused\n";
			else if (tmp.size() == 1)
				cout << tmp[0] << '\n';
			else {
				for (int i = 0; i < N; i++)
					if (!visited[i]) {
						cnt = 1;
						findscc(i);
					}

				memset(visited, 0, sizeof(visited));
				for (int i = 0; i < N; i++)
					if (!visited[i])
						dfs(i, sccnum[i]);
				tmp.clear();
				for (int i = 1; i <= sccidx; i++) {
					if (!sccin[i])
						tmp.push_back(i);
				}
				if (tmp.size() != 1)
					cout << "Confused\n";
				else {
					for (int i = 0; i < N; i++) {
						if (tmp[0] == sccnum[i])
							cout << i << '\n';
					}
				}
			}
		}();
		cout << '\n';
	}
	return 0;
}