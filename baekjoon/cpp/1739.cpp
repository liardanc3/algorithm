#include <bits/stdc++.h>
using namespace std;

stack<int> st;
vector<int> _vect[4040], * vect = &_vect[2020];
int _visited[4040], _finished[4040], _sccnum[4040];
int* visited = &_visited[2020], * finished = &_finished[2020], * sccnum = &_sccnum[2020];
int T, N, M, K, a, b, c, d, sccidx, cnt;
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
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		[&]() {
			while (!st.empty())
				st.pop();
			memset(_finished, 0, sizeof(_finished));
			memset(_visited, 0, sizeof(_visited));
			memset(_sccnum, 0, sizeof(_sccnum));
			cin >> N >> M >> K;
			for (int i = -(N + M); i <= (N + M); i++)
				vect[i].clear();
			sccidx = 0;
			for (int i = 0; i < K; i++) {
				cin >> a >> b >> c >> d;
				a += M, c += M;
				if (a < c) {
					if (b == d) 
						vect[-b].push_back(b);
					else if (b < d) {
						vect[-a].push_back(b);
						vect[-b].push_back(a);

						vect[-a].push_back(c);
						vect[-c].push_back(a);
						
						vect[-d].push_back(b);
						vect[-b].push_back(d);

						vect[-d].push_back(c);
						vect[-c].push_back(d);
					}
					else {
						vect[a].push_back(b);
						vect[-b].push_back(-a);

						vect[a].push_back(-c);
						vect[c].push_back(-a);

						vect[-d].push_back(b);
						vect[-b].push_back(d);

						vect[-d].push_back(-c);
						vect[c].push_back(d);
					}
				}
				else if (a > c) {
					if (b == d) 
						vect[d].push_back(-d);
					else if (b < d) {
						vect[-a].push_back(c);
						vect[-c].push_back(a);

						vect[d].push_back(c);
						vect[-c].push_back(-d);

						vect[-a].push_back(-b);
						vect[b].push_back(a);

						vect[d].push_back(-b);
						vect[b].push_back(-d);
					}
					else {
						vect[a].push_back(-b);
						vect[b].push_back(-a);
				
						vect[a].push_back(-c);
						vect[c].push_back(-a);
						
						vect[d].push_back(-b);
						vect[b].push_back(-d);

						vect[d].push_back(-c);
						vect[c].push_back(-d);
					}
				}
				else {
					if (b > d)
						vect[a].push_back(-a);
					else if (b < d) 
						vect[-a].push_back(a);
				}
			}
			for (int i = -(N + M); i <= (N + M); i++) {
				if (i == 0)
					continue;
				if (!visited[i]) {
					cnt = 1;
					dfs(i);
				}
			}
			for (int i = 1; i <= (N + M); i++) {
				//cout << "sccnum[" << i << "] = " << sccnum[i] << '\n';
				//cout << "sccnum[" << -i << "] = " << sccnum[-i] << '\n';
				if (sccnum[i] == sccnum[-i]) {
					cout << "No\n";
					break;
				}
				if (i == (N + M))
					cout << "Yes\n";
			}
		}();
	}
	return 0;
}